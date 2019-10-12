#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_SHORT_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_SHORT_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Short {
class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kSALOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kSASTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Push : public Instruction {
 public:
  Push() : Instruction(Opcodes::kSIPUSH) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide) override {
    auto s = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << s << "\n";
    *delta_code = 2;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto s = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(s)};
  }
};
}  // namespace Short
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_SHORT_H_
