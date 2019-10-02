#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MONITOR_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MONITOR_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Monitor {
class Enter : public Instruction {
 public:
  Enter() : Instruction(Opcodes::kMONITORENTER) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Exit : public Instruction {
 public:
  Exit() : Instruction(Opcodes::kMONITOREXIT) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Monitor
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MONITOR_H_