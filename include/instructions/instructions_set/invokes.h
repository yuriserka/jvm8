#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INVOKES_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INVOKES_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Invokes {
class Dynamic : public Instruction {
 public:
  Dynamic() : Instruction(Opcodes::kINVOKEDYNAMIC) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    *++*code_it;
    *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 4;
    return kpool_index;
  }
};

class Interface : public Instruction {
 public:
  Interface() : Instruction(Opcodes::kINVOKEINTERFACE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    *++*code_it;
    *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 4;
    return kpool_index;
  }
};

class Especial : public Instruction {
 public:
  Especial() : Instruction(Opcodes::kINVOKESPECIAL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class Static : public Instruction {
 public:
  Static() : Instruction(Opcodes::kINVOKESTATIC) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class Virtual : public Instruction {
 public:
  Virtual() : Instruction(Opcodes::kINVOKEVIRTUAL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};
}  // namespace Invokes
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INVOKES_H_
