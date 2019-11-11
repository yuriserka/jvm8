#include "instructions/instruction_set/invokes.h"

#include "utils/accessFlags.h"
#include "utils/flags.h"
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

  auto ref = th->method_area->runtime_constant_pool[index - 1];

  std::string classname, methodname, descriptor;
  Utils::getReference(th->method_area->runtime_classfile, index, &classname,
                      &methodname, &descriptor);

  // classname != java/lang/StringBuilder
  if (classname.compare("java/lang/StringBuilder")) {
    th->changeContext(classname, methodname, descriptor);
    // auto m = Utils::getMethod(th->method_area->runtime_classfile,
    // methodname); auto accessflags =
    // Utils::Access::getMethodAccessType(m.access_flags); if
    // (std::find(accessflags.begin(), accessflags.end(), "protected") !=
    //     accessflags.end()) {

    // }
  } else {
    // idealmente era pra popar uma referencia duplicada e rodar o método init,
    // ent sla ne?//
    // https://stackoverflow.com/questions/12438567/java-bytecode-dup
    th->current_frame->popOperand<Utils::Object>();
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
  return {};
}
// ----------------------------------------------------------------------------
static std::string print_handler(Utils::Frame *curr_frame,
                                 std::string descriptor) {
  std::stringstream ss;
  // descriptor = (Tipo_argumento)Tipo_Retorno
  char method_descriptor = descriptor[1];
  switch (method_descriptor) {
    case 'B': {
      ss << curr_frame->popOperand<int8_t>();
      break;
    }
    case 'C': {
      ss << static_cast<char>(curr_frame->popOperand<int>());
      break;
    }
    case 'D': {
      ss << curr_frame->popOperand<double>();
      break;
    }
    case 'F': {
      ss << curr_frame->popOperand<float>();
      break;
    }
    case 'I': {
      ss << curr_frame->popOperand<int>();
      break;
    }
    case 'J': {
      ss << curr_frame->popOperand<long>();
      break;
    }
    case 'S': {
      ss << curr_frame->popOperand<short>();
      break;
    }
    case 'Z': {
      if (!curr_frame->popOperand<int>()) {
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
                                       descriptor.find_last_of(';'));
      if (!refname.compare("Ljava/lang/String;")) {
        auto stringref = curr_frame->popOperand<Utils::Object>();
        ss << stringref.data.as<std::string>();
      } else {
        auto top = curr_frame->popOperand<Utils::Object>();
        const void *address = static_cast<const void *>(&top);
        ss << refname.substr(1, refname.find_first_of(';') - 1) << "@" << address;
      }
      break;
    }
  }
  return ss.str();
}

static void append_handler(Utils::Frame *curr_frame, std::string descriptor) {
  std::stringstream ss;
  // descriptor = (Tipo_argumento)Tipo_Retorno
  char method_descriptor = descriptor[1];
  Utils::Object objref;
  switch (method_descriptor) {
    case 'B': {
      ss << curr_frame->popOperand<int8_t>();
      break;
    }
    case 'C': {
      ss << static_cast<char>(curr_frame->popOperand<int>());
      break;
    }
    case 'D': {
      ss << curr_frame->popOperand<double>();
      break;
    }
    case 'F': {
      ss << curr_frame->popOperand<float>();
      break;
    }
    case 'I': {
      ss << curr_frame->popOperand<int>();
      break;
    }
    case 'J': {
      ss << curr_frame->popOperand<long>();
      break;
    }
    case 'S': {
      ss << curr_frame->popOperand<short>();
      break;
    }
    case 'Z': {
      if (!curr_frame->popOperand<int>()) {
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
      if (!refname.compare("Ljava/lang/String;")) {
        auto sstr =
            curr_frame->popOperand<Utils::Object>().data.as<std::string>();
        ss << sstr;
      } else {
        auto top = curr_frame->popOperand<Utils::Object>();
        const void *address = static_cast<const void *>(&top);
        ss << refname.substr(1, refname.find_first_of(';') - 1) << "@" << address;
      }
      break;
    }
  }
  // isso tem que ser um Object{type: kSTR_StringBuilder}
  auto fstr = curr_frame->popOperand<Utils::Object>().data.as<std::string>();
  std::string str = fstr + ss.str();
  objref.data = str;
  objref.type = Utils::Reference::kSTR_STRINGBUILDER;
  curr_frame->pushOperand(objref);
}

std::vector<int> Virtual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  auto index = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  std::stringstream ss;

  auto ref = th->method_area->runtime_constant_pool[index - 1];

  std::string classname, methodname, descriptor;
  Utils::getReference(th->method_area->runtime_classfile, index, &classname,
                      &methodname, &descriptor);

  if (!methodname.compare("print") || !methodname.compare("println") ||
      !methodname.compare("append")) {
    if (Utils::Flags::options.kDEBUG) {
      auto ref_val = classname + "." + methodname;
      std::cout << "Interceptando " << Opcodes::getMnemonic(this->opcode) << " "
                << ref_val << "\n";
    }
    if (methodname.compare("append")) {
      std::cout << print_handler(th->current_frame, descriptor);
    } else {
      append_handler(th->current_frame, descriptor);
    }
    if (!methodname.compare("println")) {
      std::cout << "\n";
    }
  } else {
    if (Utils::Flags::options.kDEBUG) {
      std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    }
    if (!methodname.compare("toString")) {
      th->current_frame->pushOperand(
          th->current_frame->popOperand<Utils::Object>());
    } else {
      th->changeContext(classname, methodname, descriptor);
    }
  }
  return {};
}
// ----------------------------------------------------------------------------

}  // namespace Invokes
}  // namespace Instructions
