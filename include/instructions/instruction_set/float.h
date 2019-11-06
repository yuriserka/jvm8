#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_FLOAT_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_FLOAT_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Float {
class ToDouble : public Instruction {
 public:
  ToDouble() : Instruction(Opcodes::kF2D) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class ToInteger : public Instruction {
 public:
  ToInteger() : Instruction(Opcodes::kF2I) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class ToLong : public Instruction {
 public:
  ToLong() : Instruction(Opcodes::kF2L) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Add : public Instruction {
 public:
  Add() : Instruction(Opcodes::kFADD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kFALOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kFASTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class CompareGreater : public Instruction {
 public:
  CompareGreater() : Instruction(Opcodes::kFCMPG) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class CompareLess : public Instruction {
 public:
  CompareLess() : Instruction(Opcodes::kFCMPL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Const_0 : public Instruction {
 public:
  Const_0() : Instruction(Opcodes::kFCONST_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Const_1 : public Instruction {
 public:
  Const_1() : Instruction(Opcodes::kFCONST_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Const_2 : public Instruction {
 public:
  Const_2() : Instruction(Opcodes::kFCONST_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Div : public Instruction {
 public:
  Div() : Instruction(Opcodes::kFDIV) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kFLOAD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << " ";
    if (wide) {
      int16_t index = (*++*code_it << 8) | *++*code_it;
      (*ss) << index;
      *delta_code = 2;
    } else {
      unsigned char index = *++*code_it;
      (*ss) << int{index};
      *delta_code = 1;
    }
    (*ss) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    if (wide) {
      int16_t index = (*++*code_it << 8) | *++*code_it;
      *delta_code = 2;
      return {Utils::String::toString(index)};
    }
    unsigned char index = *++*code_it;
    *delta_code = 1;
    return {Utils::String::toString(int{index})};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Load_0 : public Instruction {
 public:
  Load_0() : Instruction(Opcodes::kFLOAD_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Load_1 : public Instruction {
 public:
  Load_1() : Instruction(Opcodes::kFLOAD_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Load_2 : public Instruction {
 public:
  Load_2() : Instruction(Opcodes::kFLOAD_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Load_3 : public Instruction {
 public:
  Load_3() : Instruction(Opcodes::kFLOAD_3) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Mul : public Instruction {
 public:
  Mul() : Instruction(Opcodes::kFMUL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Neg : public Instruction {
 public:
  Neg() : Instruction(Opcodes::kFNEG) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Rem : public Instruction {
 public:
  Rem() : Instruction(Opcodes::kFREM) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kFRETURN) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Store : public Instruction {
 public:
  Store() : Instruction(Opcodes::kFSTORE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << " ";
    if (wide) {
      int16_t index = (*++*code_it << 8) | *++*code_it;
      (*ss) << index;
      *delta_code = 2;
    } else {
      unsigned char index = *++*code_it;
      (*ss) << int{index};
      *delta_code = 1;
    }
    (*ss) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    if (wide) {
      int16_t index = (*++*code_it << 8) | *++*code_it;
      *delta_code = 2;
      return {Utils::String::toString(index)};
    }
    unsigned char index = *++*code_it;
    *delta_code = 1;
    return {Utils::String::toString(int{index})};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Store_0 : public Instruction {
 public:
  Store_0() : Instruction(Opcodes::kFSTORE_0) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Store_1 : public Instruction {
 public:
  Store_1() : Instruction(Opcodes::kFSTORE_1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Store_2 : public Instruction {
 public:
  Store_2() : Instruction(Opcodes::kFSTORE_2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Store_3 : public Instruction {
 public:
  Store_3() : Instruction(Opcodes::kFSTORE_3) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Sub : public Instruction {
 public:
  Sub() : Instruction(Opcodes::kFSUB) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
  }

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};
}  // namespace Float
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_FLOAT_H_
