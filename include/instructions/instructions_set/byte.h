#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BYTE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BYTE_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Byte {
class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kBALOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kBASTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Push : public Instruction {
 public:
  Push() : Instruction(Opcodes::kBIPUSH) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto byte = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << +byte << "\n";
    *delta_code = 1;
    return 0;
  }
};
}  // namespace Byte
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BYTE_H_
