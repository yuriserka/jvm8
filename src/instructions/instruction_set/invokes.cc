#include "instructions/instruction_set/invokes.h"

#include <cmath>
#include <iomanip>
#include "utils/accessFlags.h"
#include "utils/flags.h"
#include "utils/memory_areas/heap.h"
#include "utils/memory_areas/method_area.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
namespace Invokes {
std::vector<int> Dynamic::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Interface::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Especial::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto index = (*++*code_iterator << 8) | *++*code_iterator;
  std::stringstream ss;

  std::string classname, methodname, descriptor;
  Utils::getReference(th->method_area->runtime_classfile, index, &classname,
                      &methodname, &descriptor);

  // classname != java/lang/StringBuilder e != java/lang/String
  if (classname.compare("java/lang/StringBuilder") &&
      classname.compare("java/lang/String")) {
    th->changeContext(classname, methodname, descriptor, true);
    // auto m = Utils::getMethod(th->method_area->runtime_classfile,
    // methodname); auto accessflags =
    // Utils::Access::getMethodAccessType(m.access_flags); if
    // (std::find(accessflags.begin(), accessflags.end(), "protected") !=
    //     accessflags.end()) {

    // }
  } else {
    // idealmente era pra popar uma referencia duplicada e rodar o método init.
    // o init do StringBuilder n precisa de argumentos, mas o do String sim
    // https://stackoverflow.com/questions/12438567/java-bytecode-dup
    std::string string_init_arg = "";
    if (!classname.compare("java/lang/String")) {
      // vem do LDC
      string_init_arg = th->current_frame->popOperand<Utils::Object *>()
                            ->data.as<std::string>();
    }
    auto ref = th->current_frame->popOperand<Utils::Object *>();
    ref->data = string_init_arg;
    if (Utils::Flags::options.kDEBUG) {
      std::cout << "Ignorando " << Opcodes::getMnemonic(this->opcode) << " "
                << (classname + "." + methodname) << "\n";
    }
  }

  *delta_code = 2;
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Static::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;

  std::string classname, methodname, descriptor;
  Utils::getReference(th->method_area->runtime_classfile, kpool_index,
                      &classname, &methodname, &descriptor);
  th->heap->addClass(th, classname);
  th->changeContext(classname, methodname, descriptor, false);
  return {};
}
// ----------------------------------------------------------------------------
static std::string getStringForType(Utils::Frame *frame,
                                    const std::string &descriptor) {
  std::stringstream ss;
  // descriptor = (Tipo_argumentos)Tipo_Retorno
  char method_descriptor = descriptor[1];
  switch (method_descriptor) {
    case 'B': {
      ss << static_cast<int8_t>(frame->popOperand<int>());
      break;
    }
    case 'C': {
      ss << static_cast<char>(frame->popOperand<int>());
      break;
    }
    case 'D': {
      double d;
      double val = frame->popOperand<double>();
      if (!std::modf(val, &d)) {
        ss << std::fixed << std::setprecision(1) << d;
      } else {
        ss << val;
      }
      break;
    }
    case 'F': {
      float f;
      float val = frame->popOperand<float>();
      if (!std::modf(val, &f)) {
        ss << std::fixed << std::setprecision(1) << f;
      } else {
        ss << val;
      }
      break;
    }
    case 'I': {
      ss << frame->popOperand<int>();
      break;
    }
    case 'J': {
      ss << frame->popOperand<long>();
      break;
    }
    case 'S': {
      ss << static_cast<short>(frame->popOperand<int>());
      break;
    }
    case 'Z': {
      if (!frame->popOperand<int>()) {
        ss << "false";
      } else {
        ss << "true";
      }
      break;
    }
    // sem parametros
    case ')': {
      break;
    }
    // LOBJREF;
    default: {
      auto refname = descriptor.substr(descriptor.find_first_of('(') + 1,
                                       descriptor.find_first_of(';'));
      auto objectref = frame->popOperand<Utils::Object *>();
      if (!objectref) {
        ss << "null";
        break;
      }
      if (!refname.compare("Ljava/lang/String;")) {
        ss << objectref->data.as<std::string>();
      } else {
        const void *address = static_cast<const void *>(objectref);
        auto classname = refname.substr(1, refname.find_first_of(';') - 1);
        std::replace(classname.begin(), classname.end(), '/', '.');
        ss << classname << "@" << address;
      }
      break;
    }
  }
  return ss.str();
}

static std::string print_handler(Utils::Frame *curr_frame,
                                 const std::string &descriptor) {
  std::stringstream ss;
  ss << getStringForType(curr_frame, descriptor);
  return ss.str();
}

static void append_handler(MemoryAreas::Thread *th,
                           const std::string &descriptor) {
  std::stringstream ss;
  ss << getStringForType(th->current_frame, descriptor);
  auto objectref = th->current_frame->popOperand<Utils::Object *>();
  auto fstr = objectref->data.as<std::string>();

  objectref->data = fstr + ss.str();
  th->current_frame->pushOperand(objectref);
}

std::vector<int> Virtual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  auto index = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  std::stringstream ss;

  std::string classname, methodname, descriptor;
  Utils::getReference(th->method_area->runtime_classfile, index, &classname,
                      &methodname, &descriptor);

  if (!methodname.compare("print") || !methodname.compare("println") ||
      !methodname.compare("append")) {
    if (Utils::Flags::options.kDEBUG) {
      auto ref_val = classname + "." + methodname + ":" + descriptor;
      std::cout << "Interceptando " << Opcodes::getMnemonic(this->opcode) << " "
                << ref_val << "\n";
    }
    if (!methodname.compare("append")) {
      append_handler(th, descriptor);
    } else {
      std::cout << print_handler(th->current_frame, descriptor);
    }
    if (!methodname.compare("println")) {
      std::cout << "\n";
    }
  } else {
    if (Utils::Flags::options.kDEBUG) {
      std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    }
    // method != toString
    if (methodname.compare("toString")) {
      // for (auto it = th->heap->initialized_classes.begin();
      //      it != th->heap->initialized_classes.end(); ++it) {
      //   auto classref = *it;
      //   classname = th->method_area->getClassThatImplementsMethod(
      //       classref->class_name, methodname, descriptor);
      //   if (!classname.empty() && !classref->class_name.compare(classname)) {
      //     break;
      //   }
      // try {
      th->changeContext(classname, methodname, descriptor, true);
      //   break;
      // } catch (...) {
      // }
      // }
    }
  }
  return {};
}
// ----------------------------------------------------------------------------

}  // namespace Invokes
}  // namespace Instructions
