#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INTEGER_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INTEGER_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Integer {
class ToByte : public Instruction {
 public:
  ToByte() : Instruction(Opcodes::kI2B) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ToChar : public Instruction {
 public:
  ToChar() : Instruction(Opcodes::kI2C) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ToDouble : public Instruction {
 public:
  ToDouble() : Instruction(Opcodes::kI2D) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ToFloat : public Instruction {
 public:
  ToFloat() : Instruction(Opcodes::kI2F) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ToLong : public Instruction {
 public:
  ToLong() : Instruction(Opcodes::kI2L) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ToShort : public Instruction {
 public:
  ToShort() : Instruction(Opcodes::kI2S) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Add : public Instruction {
 public:
  Add() : Instruction(Opcodes::kIADD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kIALOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class And : public Instruction {
 public:
  And() : Instruction(Opcodes::kIAND) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
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
  StoreIntoArray() : Instruction(Opcodes::kIASTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Const_m1 : public Instruction {
 public:
  Const_m1() : Instruction(Opcodes::kICONST_M1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Const_0 : public Instruction {
 public:
  Const_0() : Instruction(Opcodes::kICONST_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Const_1 : public Instruction {
 public:
  Const_1() : Instruction(Opcodes::kICONST_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Const_2 : public Instruction {
 public:
  Const_2() : Instruction(Opcodes::kICONST_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Const_3 : public Instruction {
 public:
  Const_3() : Instruction(Opcodes::kICONST_3) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Const_4 : public Instruction {
 public:
  Const_4() : Instruction(Opcodes::kICONST_4) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Const_5 : public Instruction {
 public:
  Const_5() : Instruction(Opcodes::kICONST_5) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Div : public Instruction {
 public:
  Div() : Instruction(Opcodes::kIDIV) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Inc : public Instruction {
 public:
  Inc() : Instruction(Opcodes::kIINC) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    auto index = *++*code_it;
    auto k = *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << +index << " by " << static_cast<int>(char(k)) << "\n";
    *delta_code = 2;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto index = *++*code_it;
    auto k = *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(+index),
            Utils::String::to_string(static_cast<int>(char(k)))};
  }
};

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kILOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    auto index = *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << +index << "\n";
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
  Load_0() : Instruction(Opcodes::kILOAD_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
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
  Load_1() : Instruction(Opcodes::kILOAD_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
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
  Load_2() : Instruction(Opcodes::kILOAD_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
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
  Load_3() : Instruction(Opcodes::kILOAD_3) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

// class IMPDEP1 : public Instruction {
//  public:
//   I2B() : Instruction(Opcodes::kI2B) {}

//   inline std::vector<int> toBytecode(std::vector<Utils::Types::u1>::iterator
//   *code_it, int *delta_code, const bool &wide, std::string *out_str) override
//   {}
// };

// class IMPDEP2 : public Instruction {
//  public:
//   I2B() : Instruction(Opcodes::kI2B) {}

//   inline std::vector<int> toBytecode(std::vector<Utils::Types::u1>::iterator
//   *code_it, int *delta_code, const bool &wide, std::string *out_str) override
//   {}
// };

class Mul : public Instruction {
 public:
  Mul() : Instruction(Opcodes::kIMUL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Neg : public Instruction {
 public:
  Neg() : Instruction(Opcodes::kINEG) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Or : public Instruction {
 public:
  Or() : Instruction(Opcodes::kIOR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Rem : public Instruction {
 public:
  Rem() : Instruction(Opcodes::kIREM) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kIRETURN) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ShiftLeft : public Instruction {
 public:
  ShiftLeft() : Instruction(Opcodes::kISHL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class ArithmeticShiftRight : public Instruction {
 public:
  ArithmeticShiftRight() : Instruction(Opcodes::kISHR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
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
  Store() : Instruction(Opcodes::kISTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    auto index = *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << +index << "\n";
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
  Store_0() : Instruction(Opcodes::kISTORE_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
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
  Store_1() : Instruction(Opcodes::kISTORE_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
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
  Store_2() : Instruction(Opcodes::kISTORE_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
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
  Store_3() : Instruction(Opcodes::kISTORE_3) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Sub : public Instruction {
 public:
  Sub() : Instruction(Opcodes::kISUB) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class LogicalShiftRight : public Instruction {
 public:
  LogicalShiftRight() : Instruction(Opcodes::kIUSHR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Xor : public Instruction {
 public:
  Xor() : Instruction(Opcodes::kIXOR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index, const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};
}  // namespace Integer
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INTEGER_H_
