#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_DOUBLE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_DOUBLE_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Double {
class ToFloat : public Instruction {
 public:
  ToFloat() : Instruction(Opcodes::kD2F) {}

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
  ToInteger() : Instruction(Opcodes::kD2I) {}

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
  ToLong() : Instruction(Opcodes::kD2L) {}

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
  Add() : Instruction(Opcodes::kDADD) {}

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
  LoadFromArray() : Instruction(Opcodes::kDALOAD) {}

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
  StoreIntoArray() : Instruction(Opcodes::kDASTORE) {}

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
  CompareGreater() : Instruction(Opcodes::kDCMPG) {}

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
  CompareLess() : Instruction(Opcodes::kDCMPL) {}

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
  Const_0() : Instruction(Opcodes::kDCONST_0) {}

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
  Const_1() : Instruction(Opcodes::kDCONST_1) {}

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
  Div() : Instruction(Opcodes::kDDIV) {}

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
  Load() : Instruction(Opcodes::kDLOAD) {}

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
  Load_0() : Instruction(Opcodes::kDLOAD_0) {}

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
  Load_1() : Instruction(Opcodes::kDLOAD_1) {}

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
  Load_2() : Instruction(Opcodes::kDLOAD_2) {}

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
  Load_3() : Instruction(Opcodes::kDLOAD_3) {}

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
  Mul() : Instruction(Opcodes::kDMUL) {}

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
  Neg() : Instruction(Opcodes::kDNEG) {}

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
  Rem() : Instruction(Opcodes::kDREM) {}

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
  Return() : Instruction(Opcodes::kDRETURN) {}

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
  Store() : Instruction(Opcodes::kDSTORE) {}

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
  Store_0() : Instruction(Opcodes::kDSTORE_0) {}

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
  Store_1() : Instruction(Opcodes::kDSTORE_1) {}

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
  Store_2() : Instruction(Opcodes::kDSTORE_2) {}

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
  Store_3() : Instruction(Opcodes::kDSTORE_3) {}

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
  Sub() : Instruction(Opcodes::kDSUB) {}

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
}  // namespace Double
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_DOUBLE_H_
