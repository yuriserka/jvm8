#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_BYTE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_BYTE_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Byte {
class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kBALOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kBASTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Push : public Instruction {
 public:
  Push() : Instruction(Opcodes::kBIPUSH) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    signed char byte = *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " " << int{byte} << "\n";
    *delta_code = 1;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    signed char byte = *++*code_it;
    *delta_code = 1;
    return {Utils::String::toString(int{byte})};
  }
};
}  // namespace Byte
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_BYTE_H_
