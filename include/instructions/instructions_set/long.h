#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_LONG_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_LONG_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Long {
class ToDouble : public Instruction {
 public:
  ToDouble() : Instruction(Opcodes::kL2D) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ToFloat : public Instruction {
 public:
  ToFloat() : Instruction(Opcodes::kL2F) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ToInteger : public Instruction {
 public:
  ToInteger() : Instruction(Opcodes::kL2I) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Add : public Instruction {
 public:
  Add() : Instruction(Opcodes::kLADD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kLALOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class And : public Instruction {
 public:
  And() : Instruction(Opcodes::kLAND) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kLASTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Compare : public Instruction {
 public:
  Compare() : Instruction(Opcodes::kLCMP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Const_0 : public Instruction {
 public:
  Const_0() : Instruction(Opcodes::kLCONST_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Const_1 : public Instruction {
 public:
  Const_1() : Instruction(Opcodes::kLCONST_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Div : public Instruction {
 public:
  Div() : Instruction(Opcodes::kLDIV) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kLLOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << +index << "\n";
    *delta_code = 1;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto index = *++*code_it;
    *delta_code = 1;
    return {std::to_string(+index)};
  }
};

class Load_0 : public Instruction {
 public:
  Load_0() : Instruction(Opcodes::kLLOAD_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Load_1 : public Instruction {
 public:
  Load_1() : Instruction(Opcodes::kLLOAD_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Load_2 : public Instruction {
 public:
  Load_2() : Instruction(Opcodes::kLLOAD_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Load_3 : public Instruction {
 public:
  Load_3() : Instruction(Opcodes::kLLOAD_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Mul : public Instruction {
 public:
  Mul() : Instruction(Opcodes::kLMUL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Neg : public Instruction {
 public:
  Neg() : Instruction(Opcodes::kLNEG) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Or : public Instruction {
 public:
  Or() : Instruction(Opcodes::kLOR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Rem : public Instruction {
 public:
  Rem() : Instruction(Opcodes::kLREM) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kLRETURN) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ShiftLeft : public Instruction {
 public:
  ShiftLeft() : Instruction(Opcodes::kLSHL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ArithmeticShiftRight : public Instruction {
 public:
  ArithmeticShiftRight() : Instruction(Opcodes::kLSHR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Store : public Instruction {
 public:
  Store() : Instruction(Opcodes::kLSTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << +index << "\n";
    *delta_code = 1;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto index = *++*code_it;
    *delta_code = 1;
    return {std::to_string(+index)};
  }
};

class Store_0 : public Instruction {
 public:
  Store_0() : Instruction(Opcodes::kLSTORE_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Store_1 : public Instruction {
 public:
  Store_1() : Instruction(Opcodes::kLSTORE_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Store_2 : public Instruction {
 public:
  Store_2() : Instruction(Opcodes::kLSTORE_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Store_3 : public Instruction {
 public:
  Store_3() : Instruction(Opcodes::kLSTORE_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Sub : public Instruction {
 public:
  Sub() : Instruction(Opcodes::kLSUB) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class LogicalShiftRight : public Instruction {
 public:
  LogicalShiftRight() : Instruction(Opcodes::kLUSHR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Xor : public Instruction {
 public:
  Xor() : Instruction(Opcodes::kLXOR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};
}  // namespace Long
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_LONG_H_
