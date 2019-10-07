#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BYTE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BYTE_H_

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
  LoadFromArray(Viewer *v) : Instruction(Opcodes::kBALOAD, v) {}

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

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray(Viewer *v) : Instruction(Opcodes::kBASTORE, v) {}

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

class Push : public Instruction {
 public:
  Push(Viewer *v) : Instruction(Opcodes::kBIPUSH, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto byte = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(byte)) << "\n";
    *delta_code = 1;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto byte = *++*code_it;
    *delta_code = 1;
    return {Utils::String::to_string(static_cast<int>(char(byte)))};
  }
};
}  // namespace Byte
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BYTE_H_
