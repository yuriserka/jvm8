#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_JUMP_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_JUMP_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Jump {
class JumpSubRoutine : public Instruction {
 public:
  JumpSubRoutine() : Instruction(Opcodes::kJSR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << " ";
    *delta_code = 2;
    return 0;
  }
};

class JumpSubRoutineWide : public Instruction {
 public:
  JumpSubRoutineWide() : Instruction(Opcodes::kJSR_W) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) | (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << " ";
    *delta_code = 4;
    return 0;
  }
};
}  // namespace Jump
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_JUMP_H_
