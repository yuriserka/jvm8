#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MONITOR_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MONITOR_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Monitor {
class Enter : public Instruction {
 public:
  Enter(Viewer *v) : Instruction(Opcodes::kMONITORENTER, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Exit : public Instruction {
 public:
  Exit(Viewer *v) : Instruction(Opcodes::kMONITOREXIT, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};
}  // namespace Monitor
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MONITOR_H_
