#include "instructions/instruction_set/invokes.h"

#include "utils/flags.h"
#include "utils/memory_areas/method_area.h"
#include "utils/memory_areas/thread.h"

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
std::string print_handler(Utils::Frame *curr_frame, char type) {
  std::stringstream ss;
  switch (type) {
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
    case ')': {
      break;
    }
  }
  return ss.str();
}

std::vector<int> Virtual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  auto index = (*++*code_iterator << 8) | *++*code_iterator;
  std::stringstream ss;

  auto ref = th->method_area->runtime_constant_pool[index - 1];

  std::string classname, methodname, descriptor;
  Utils::getReference(th->method_area->runtime_classfile, index, &classname,
                      &methodname, &descriptor);

  *delta_code = 2;
  auto ref_val = classname + "." + methodname;
  if (!ref_val.compare("java/io/PrintStream.print") ||
      !ref_val.compare("java/io/PrintStream.println") ||
      !ref_val.compare("java/io/PrintStream.append")) {
    if (Utils::Flags::options.kDEBUG) {
      std::cout << "Interceptando " << Opcodes::getMnemonic(this->opcode)
                << " " << ref_val << "\n";
    }
    std::cout << print_handler(th->current_frame, descriptor[1]);
    if (!ref_val.compare("java/io/PrintStream.println")) {
      std::cout << "\n";
    }
    return {};
  }

  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->changeContext(classname, methodname, descriptor);

  return {};
}
// ----------------------------------------------------------------------------

}  // namespace Invokes
}  // namespace Instructions
