#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CONSTANT_POOL_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CONSTANT_POOL_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace ConstantPool {
class LoadCat1 : public Instruction {
 public:
  LoadCat1() : Instruction(Opcodes::kLDC) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    auto kpool_index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #"
              << unsigned(kpool_index) << " ";
    *delta_code = 1;
    return kpool_index;
  }
};

class LoadCat1Wide : public Instruction {
 public:
  LoadCat1Wide() : Instruction(Opcodes::kLDC_W) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #"
              << unsigned(kpool_index) << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class LoadCat2 : public Instruction {
 public:
  LoadCat2() : Instruction(Opcodes::kLDC2_W) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #"
              << unsigned(kpool_index) << " ";
    *delta_code = 2;
    return kpool_index;
  }
};
}  // namespace ConstantPool
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CONSTANT_POOL_H_
