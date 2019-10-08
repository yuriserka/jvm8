#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_REFERENCE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_REFERENCE_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Reference {
class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kAALOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kAASTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ConstNull : public Instruction {
 public:
  ConstNull() : Instruction(Opcodes::kACONST_NULL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kALOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << +index << "\n";
    *delta_code = 1;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto index = *++*code_it;
    *delta_code = 1;
    return {Utils::String::to_string(+index)};
  }
};

class Load_0 : public Instruction {
 public:
  Load_0() : Instruction(Opcodes::kALOAD_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Load_1 : public Instruction {
 public:
  Load_1() : Instruction(Opcodes::kALOAD_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Load_2 : public Instruction {
 public:
  Load_2() : Instruction(Opcodes::kALOAD_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Load_3 : public Instruction {
 public:
  Load_3() : Instruction(Opcodes::kALOAD_3) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class NewArray : public Instruction {
 public:
  NewArray() : Instruction(Opcodes::kANEWARRAY) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kARETURN) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ArrayLength : public Instruction {
 public:
  ArrayLength() : Instruction(Opcodes::kARRAYLENGTH) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Store : public Instruction {
 public:
  Store() : Instruction(Opcodes::kASTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << +index << "\n";
    *delta_code = 1;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto index = *++*code_it;
    *delta_code = 1;
    return {Utils::String::to_string(+index)};
  }
};

class Store_0 : public Instruction {
 public:
  Store_0() : Instruction(Opcodes::kASTORE_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Store_1 : public Instruction {
 public:
  Store_1() : Instruction(Opcodes::kASTORE_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Store_2 : public Instruction {
 public:
  Store_2() : Instruction(Opcodes::kASTORE_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Store_3 : public Instruction {
 public:
  Store_3() : Instruction(Opcodes::kASTORE_3) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Throw : public Instruction {
 public:
  Throw() : Instruction(Opcodes::kATHROW) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};
}  // namespace Reference
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_REFERENCE_H_
