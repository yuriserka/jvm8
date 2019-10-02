#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_SHORT_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_SHORT_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Short {
class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kSALOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kSASTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Push : public Instruction {
 public:
  Push() : Instruction(Opcodes::kSIPUSH) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Short
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_SHORT_H_
