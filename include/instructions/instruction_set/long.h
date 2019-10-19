#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_LONG_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_LONG_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Long {
class ToDouble : public Instruction {
 public:
  ToDouble() : Instruction(Opcodes::kL2D) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class ToFloat : public Instruction {
 public:
  ToFloat() : Instruction(Opcodes::kL2F) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class ToInteger : public Instruction {
 public:
  ToInteger() : Instruction(Opcodes::kL2I) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Add : public Instruction {
 public:
  Add() : Instruction(Opcodes::kLADD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kLALOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class And : public Instruction {
 public:
  And() : Instruction(Opcodes::kLAND) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kLASTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Compare : public Instruction {
 public:
  Compare() : Instruction(Opcodes::kLCMP) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Const_0 : public Instruction {
 public:
  Const_0() : Instruction(Opcodes::kLCONST_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Const_1 : public Instruction {
 public:
  Const_1() : Instruction(Opcodes::kLCONST_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Div : public Instruction {
 public:
  Div() : Instruction(Opcodes::kLDIV) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kLLOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " ";
    if (wide) {
      int16_t index = (*++*code_it << 8) | *++*code_it;
      (*wss) << index;
      *delta_code = 2;
    } else {
      unsigned char index = *++*code_it;
      (*wss) << int{index};
      *delta_code = 1;
    }
    (*wss) << "\n";
    return {};
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    if (wide) {
      int16_t index = (*++*code_it << 8) | *++*code_it;
      *delta_code = 2;
      return {Utils::String::to_string(index)};
    }
    unsigned char index = *++*code_it;
    *delta_code = 1;
    return {Utils::String::to_string(int{index})};
  }
};

class Load_0 : public Instruction {
 public:
  Load_0() : Instruction(Opcodes::kLLOAD_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Load_1 : public Instruction {
 public:
  Load_1() : Instruction(Opcodes::kLLOAD_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Load_2 : public Instruction {
 public:
  Load_2() : Instruction(Opcodes::kLLOAD_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Load_3 : public Instruction {
 public:
  Load_3() : Instruction(Opcodes::kLLOAD_3) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Mul : public Instruction {
 public:
  Mul() : Instruction(Opcodes::kLMUL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Neg : public Instruction {
 public:
  Neg() : Instruction(Opcodes::kLNEG) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Or : public Instruction {
 public:
  Or() : Instruction(Opcodes::kLOR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Rem : public Instruction {
 public:
  Rem() : Instruction(Opcodes::kLREM) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kLRETURN) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class ShiftLeft : public Instruction {
 public:
  ShiftLeft() : Instruction(Opcodes::kLSHL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class ArithmeticShiftRight : public Instruction {
 public:
  ArithmeticShiftRight() : Instruction(Opcodes::kLSHR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Store : public Instruction {
 public:
  Store() : Instruction(Opcodes::kLSTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " ";
    if (wide) {
      int16_t index = (*++*code_it << 8) | *++*code_it;
      (*wss) << index;
      *delta_code = 2;
    } else {
      unsigned char index = *++*code_it;
      (*wss) << int{index};
      *delta_code = 1;
    }
    (*wss) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    if (wide) {
      int16_t index = (*++*code_it << 8) | *++*code_it;
      *delta_code = 2;
      return {Utils::String::to_string(index)};
    }
    unsigned char index = *++*code_it;
    *delta_code = 1;
    return {Utils::String::to_string(int{index})};
  }
};

class Store_0 : public Instruction {
 public:
  Store_0() : Instruction(Opcodes::kLSTORE_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Store_1 : public Instruction {
 public:
  Store_1() : Instruction(Opcodes::kLSTORE_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Store_2 : public Instruction {
 public:
  Store_2() : Instruction(Opcodes::kLSTORE_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Store_3 : public Instruction {
 public:
  Store_3() : Instruction(Opcodes::kLSTORE_3) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Sub : public Instruction {
 public:
  Sub() : Instruction(Opcodes::kLSUB) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class LogicalShiftRight : public Instruction {
 public:
  LogicalShiftRight() : Instruction(Opcodes::kLUSHR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Xor : public Instruction {
 public:
  Xor() : Instruction(Opcodes::kLXOR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};
}  // namespace Long
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_LONG_H_
