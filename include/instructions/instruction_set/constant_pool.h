#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CONSTANT_POOL_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CONSTANT_POOL_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace ConstantPool {
class LoadCat1 : public Instruction {
 public:
  LoadCat1(Viewer *v) : Instruction(Opcodes::kLDC, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << +kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 1;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = +(*++*code_it);
    *delta_code = 1;
    return {};
  }
};

class LoadCat1Wide : public Instruction {
 public:
  LoadCat1Wide(Viewer *v) : Instruction(Opcodes::kLDC_W, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class LoadCat2 : public Instruction {
 public:
  LoadCat2(Viewer *v) : Instruction(Opcodes::kLDC2_W, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};
}  // namespace ConstantPool
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_CONSTANT_POOL_H_
