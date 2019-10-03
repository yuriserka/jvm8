#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CHAR_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CHAR_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Char {
class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kCALOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kCASTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Char
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CHAR_H_
