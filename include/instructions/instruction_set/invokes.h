#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INVOKES_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INVOKES_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/num2str.h"

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

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 4;
    return {Utils::to_string(+(*++*code_it)), Utils::to_string(+(*++*code_it))};
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

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 4;
    return {Utils::to_string(+(*++*code_it)), Utils::to_string(+(*++*code_it))};
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

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
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

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
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

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};
}  // namespace Invokes
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INVOKES_H_
