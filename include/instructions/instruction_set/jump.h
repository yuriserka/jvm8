#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_JUMP_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_JUMP_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/num2str.h"

namespace Instructions {
namespace Jump {
class JumpSubRoutine : public Instruction {
 public:
  JumpSubRoutine() : Instruction(Opcodes::kJSR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << " ";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::to_string(+offset)};
  }
};

class JumpSubRoutineWide : public Instruction {
 public:
  JumpSubRoutineWide() : Instruction(Opcodes::kJSR_W) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << " ";
    *delta_code = 4;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::to_string(+offset)};
  }
};
}  // namespace Jump
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_JUMP_H_
