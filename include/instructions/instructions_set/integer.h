#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INTEGER_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INTEGER_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Integer {
class ToByte : public Instruction {
 public:
  ToByte() : Instruction(Opcodes::kI2B) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ToChar : public Instruction {
 public:
  ToChar() : Instruction(Opcodes::kI2C) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ToDouble : public Instruction {
 public:
  ToDouble() : Instruction(Opcodes::kI2D) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ToFloat : public Instruction {
 public:
  ToFloat() : Instruction(Opcodes::kI2F) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ToLong : public Instruction {
 public:
  ToLong() : Instruction(Opcodes::kI2L) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ToShort : public Instruction {
 public:
  ToShort() : Instruction(Opcodes::kI2S) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Add : public Instruction {
 public:
  Add() : Instruction(Opcodes::kIADD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kIALOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class And : public Instruction {
 public:
  And() : Instruction(Opcodes::kIAND) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kIASTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

// class ICONST_M1 : public Instruction {
//  public:
//   I2B() : Instruction(Opcodes::kI2B) {}

//   inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
//   std::string *out_str) override
//   {}
// };

class Const_0 : public Instruction {
 public:
  Const_0() : Instruction(Opcodes::kICONST_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_1 : public Instruction {
 public:
  Const_1() : Instruction(Opcodes::kICONST_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_2 : public Instruction {
 public:
  Const_2() : Instruction(Opcodes::kICONST_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_3 : public Instruction {
 public:
  Const_3() : Instruction(Opcodes::kICONST_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_4 : public Instruction {
 public:
  Const_4() : Instruction(Opcodes::kICONST_4) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_5 : public Instruction {
 public:
  Const_5() : Instruction(Opcodes::kICONST_5) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Div : public Instruction {
 public:
  Div() : Instruction(Opcodes::kIDIV) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Inc : public Instruction {
 public:
  Inc() : Instruction(Opcodes::kIINC) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    auto index = *++*code_it;
    auto k = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << unsigned(index) << " " << signed(k)
              << "\n";
    *delta_code = 2;
    return 0;
  }
};

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kILOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << unsigned(index)
              << "\n";
    *delta_code = 1;
    return 0;
  }
};

class Load_0 : public Instruction {
 public:
  Load_0() : Instruction(Opcodes::kILOAD_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_1 : public Instruction {
 public:
  Load_1() : Instruction(Opcodes::kILOAD_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_2 : public Instruction {
 public:
  Load_2() : Instruction(Opcodes::kILOAD_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_3 : public Instruction {
 public:
  Load_3() : Instruction(Opcodes::kILOAD_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

// class IMPDEP1 : public Instruction {
//  public:
//   I2B() : Instruction(Opcodes::kI2B) {}

//   inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
//   std::string *out_str) override
//   {}
// };

// class IMPDEP2 : public Instruction {
//  public:
//   I2B() : Instruction(Opcodes::kI2B) {}

//   inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
//   std::string *out_str) override
//   {}
// };

class Mul : public Instruction {
 public:
  Mul() : Instruction(Opcodes::kIMUL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Neg : public Instruction {
 public:
  Neg() : Instruction(Opcodes::kINEG) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Or : public Instruction {
 public:
  Or() : Instruction(Opcodes::kIOR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Rem : public Instruction {
 public:
  Rem() : Instruction(Opcodes::kIREM) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kIRETURN) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ShiftLeft : public Instruction {
 public:
  ShiftLeft() : Instruction(Opcodes::kISHL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ArithmeticShiftRight : public Instruction {
 public:
  ArithmeticShiftRight() : Instruction(Opcodes::kISHR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store : public Instruction {
 public:
  Store() : Instruction(Opcodes::kISTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_0 : public Instruction {
 public:
  Store_0() : Instruction(Opcodes::kISTORE_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_1 : public Instruction {
 public:
  Store_1() : Instruction(Opcodes::kISTORE_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_2 : public Instruction {
 public:
  Store_2() : Instruction(Opcodes::kISTORE_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_3 : public Instruction {
 public:
  Store_3() : Instruction(Opcodes::kISTORE_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Sub : public Instruction {
 public:
  Sub() : Instruction(Opcodes::kISUB) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class LogicalShiftRight : public Instruction {
 public:
  LogicalShiftRight() : Instruction(Opcodes::kIUSHR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Xor : public Instruction {
 public:
  Xor() : Instruction(Opcodes::kIXOR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Integer
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_INTEGER_H_
