#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_JUMP_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_JUMP_H_

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
  JumpSubRoutine() : Instruction(Opcodes::kJSR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    int16_t offset = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << offset << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    int16_t offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(offset)};
  }
};

class JumpSubRoutineWide : public Instruction {
 public:
  JumpSubRoutineWide() : Instruction(Opcodes::kJSR_W) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << offset << " ";
    *delta_code = 4;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(offset)};
  }
};
}  // namespace Jump
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_JUMP_H_
