#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_DOUBLE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_DOUBLE_H_

#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Double {
class ToFloat : public Instruction {
 public:
  ToFloat() : Instruction(Opcodes::kD2F) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ToInteger : public Instruction {
 public:
  ToInteger() : Instruction(Opcodes::kD2I) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ToLong : public Instruction {
 public:
  ToLong() : Instruction(Opcodes::kD2L) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Add : public Instruction {
 public:
  Add() : Instruction(Opcodes::kDADD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kDALOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kDASTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class CompareGreater : public Instruction {
 public:
  CompareGreater() : Instruction(Opcodes::kDCMPG) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class CompareLess : public Instruction {
 public:
  CompareLess() : Instruction(Opcodes::kDCMPL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_0 : public Instruction {
 public:
  Const_0() : Instruction(Opcodes::kDCONST_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_1 : public Instruction {
 public:
  Const_1() : Instruction(Opcodes::kDCONST_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Div : public Instruction {
 public:
  Div() : Instruction(Opcodes::kDDIV) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kDLOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << unsigned(index) << "\n";
    *delta_code = 1;
    return 0;
  }
};

class Load_0 : public Instruction {
 public:
  Load_0() : Instruction(Opcodes::kDLOAD_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_1 : public Instruction {
 public:
  Load_1() : Instruction(Opcodes::kDLOAD_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_2 : public Instruction {
 public:
  Load_2() : Instruction(Opcodes::kDLOAD_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_3 : public Instruction {
 public:
  Load_3() : Instruction(Opcodes::kDLOAD_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Mul : public Instruction {
 public:
  Mul() : Instruction(Opcodes::kDMUL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Neg : public Instruction {
 public:
  Neg() : Instruction(Opcodes::kDNEG) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Rem : public Instruction {
 public:
  Rem() : Instruction(Opcodes::kDREM) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kDRETURN) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store : public Instruction {
 public:
  Store() : Instruction(Opcodes::kDSTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << unsigned(index) << "\n";
    *delta_code = 1;
    return 0;
  }
};

class Store_0 : public Instruction {
 public:
  Store_0() : Instruction(Opcodes::kDSTORE_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_1 : public Instruction {
 public:
  Store_1() : Instruction(Opcodes::kDSTORE_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_2 : public Instruction {
 public:
  Store_2() : Instruction(Opcodes::kDSTORE_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_3 : public Instruction {
 public:
  Store_3() : Instruction(Opcodes::kDSTORE_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Sub : public Instruction {
 public:
  Sub() : Instruction(Opcodes::kDSUB) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Double
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_DOUBLE_H_
