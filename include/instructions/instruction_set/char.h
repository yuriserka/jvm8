#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CHAR_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CHAR_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Char {
class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kCALOAD) {}

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
  StoreIntoArray() : Instruction(Opcodes::kCASTORE) {}

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
}  // namespace Char
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CHAR_H_
