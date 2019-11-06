#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_CONSTANT_POOL_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_CONSTANT_POOL_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace ConstantPool {
class LoadCat1 : public Instruction {
 public:
  LoadCat1() : Instruction(Opcodes::kLDC) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    unsigned char kpool_index = *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << int{kpool_index}
          << " ";
    *delta_code = 1;
    return {int{kpool_index}};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = +(*++*code_it);
    *delta_code = 1;
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class LoadCat1Wide : public Instruction {
 public:
  LoadCat1Wide() : Instruction(Opcodes::kLDC_W) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    int16_t kpool_index = (*++*code_it << 8) | *++*code_it;
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

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class LoadCat2 : public Instruction {
 public:
  LoadCat2() : Instruction(Opcodes::kLDC2_W) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    int16_t kpool_index = (*++*code_it << 8) | *++*code_it;
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

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};
}  // namespace ConstantPool
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_CONSTANT_POOL_H_
