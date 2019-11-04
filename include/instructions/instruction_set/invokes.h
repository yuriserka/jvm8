#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_INVOKES_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_INVOKES_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Invokes {
class Dynamic : public Instruction {
 public:
  Dynamic() : Instruction(Opcodes::kINVOKEDYNAMIC) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    *++*code_it;
    *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 4;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 4;
    return {Utils::String::toString(+(*++*code_it)),
            Utils::String::toString(+(*++*code_it))};
  }
};

class Interface : public Instruction {
 public:
  Interface() : Instruction(Opcodes::kINVOKEINTERFACE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    unsigned char count = *++*code_it;
    *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 4;
    return {kpool_index, int{count}};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 4;
    return {Utils::String::toString(+(*++*code_it)),
            Utils::String::toString(+(*++*code_it))};
  }
};

class Especial : public Instruction {
 public:
  Especial() : Instruction(Opcodes::kINVOKESPECIAL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class Static : public Instruction {
 public:
  Static() : Instruction(Opcodes::kINVOKESTATIC) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class Virtual : public Instruction {
 public:
  Virtual() : Instruction(Opcodes::kINVOKEVIRTUAL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};
}  // namespace Invokes
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_INVOKES_H_
