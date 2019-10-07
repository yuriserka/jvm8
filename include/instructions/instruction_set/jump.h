#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_JUMP_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_JUMP_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Jump {
class JumpSubRoutine : public Instruction {
 public:
  JumpSubRoutine(Viewer *v) : Instruction(Opcodes::kJSR, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    // std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << " ";
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(+offset)};
  }
};

class JumpSubRoutineWide : public Instruction {
 public:
  JumpSubRoutineWide(Viewer *v) : Instruction(Opcodes::kJSR_W, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    // std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << " ";
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 4;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(+offset)};
  }
};
}  // namespace Jump
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_JUMP_H_
