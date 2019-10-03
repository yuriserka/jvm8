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
};

class ToFloat : public Instruction {
 public:
  ToFloat() : Instruction(Opcodes::kL2F) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Add : public Instruction {
 public:
  Add() : Instruction(Opcodes::kLADD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class And : public Instruction {
 public:
  And() : Instruction(Opcodes::kLAND) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Compare : public Instruction {
 public:
  Compare() : Instruction(Opcodes::kLCMP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Const_1 : public Instruction {
 public:
  Const_1() : Instruction(Opcodes::kLCONST_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Load_0 : public Instruction {
 public:
  Load_0() : Instruction(Opcodes::kLLOAD_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Load_2 : public Instruction {
 public:
  Load_2() : Instruction(Opcodes::kLLOAD_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Mul : public Instruction {
 public:
  Mul() : Instruction(Opcodes::kLMUL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Or : public Instruction {
 public:
  Or() : Instruction(Opcodes::kLOR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kLRETURN) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class ArithmeticShiftRight : public Instruction {
 public:
  ArithmeticShiftRight() : Instruction(Opcodes::kLSHR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Store_0 : public Instruction {
 public:
  Store_0() : Instruction(Opcodes::kLSTORE_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Store_2 : public Instruction {
 public:
  Store_2() : Instruction(Opcodes::kLSTORE_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Sub : public Instruction {
 public:
  Sub() : Instruction(Opcodes::kLSUB) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
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
};

class Xor : public Instruction {
 public:
  Xor() : Instruction(Opcodes::kLXOR) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Long
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_LONG_H_
