#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_FLOAT_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_FLOAT_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Float {
class ToDouble : public Instruction {
 public:
  ToDouble() : Instruction(Opcodes::kF2D) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ToInteger : public Instruction {
 public:
  ToInteger() : Instruction(Opcodes::kF2I) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ToLong : public Instruction {
 public:
  ToLong() : Instruction(Opcodes::kF2L) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Add : public Instruction {
 public:
  Add() : Instruction(Opcodes::kFADD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kFALOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kFASTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class CompareGreater : public Instruction {
 public:
  CompareGreater() : Instruction(Opcodes::kFCMPG) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class CompareLess : public Instruction {
 public:
  CompareLess() : Instruction(Opcodes::kFCMPL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_0 : public Instruction {
 public:
  Const_0() : Instruction(Opcodes::kFCONST_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_1 : public Instruction {
 public:
  Const_1() : Instruction(Opcodes::kFCONST_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Const_2 : public Instruction {
 public:
  Const_2() : Instruction(Opcodes::kFCONST_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Div : public Instruction {
 public:
  Div() : Instruction(Opcodes::kFDIV) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kFLOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_0 : public Instruction {
 public:
  Load_0() : Instruction(Opcodes::kFLOAD_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_1 : public Instruction {
 public:
  Load_1() : Instruction(Opcodes::kFLOAD_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_2 : public Instruction {
 public:
  Load_2() : Instruction(Opcodes::kFLOAD_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_3 : public Instruction {
 public:
  Load_3() : Instruction(Opcodes::kFLOAD_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Mul : public Instruction {
 public:
  Mul() : Instruction(Opcodes::kFMUL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Neg : public Instruction {
 public:
  Neg() : Instruction(Opcodes::kFNEG) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Rem : public Instruction {
 public:
  Rem() : Instruction(Opcodes::kFREM) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kFRETURN) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store : public Instruction {
 public:
  Store() : Instruction(Opcodes::kFSTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_0 : public Instruction {
 public:
  Store_0() : Instruction(Opcodes::kFSTORE_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_1 : public Instruction {
 public:
  Store_1() : Instruction(Opcodes::kFSTORE_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_2 : public Instruction {
 public:
  Store_2() : Instruction(Opcodes::kFSTORE_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_3 : public Instruction {
 public:
  Store_3() : Instruction(Opcodes::kFSTORE_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Sub : public Instruction {
 public:
  Sub() : Instruction(Opcodes::kFSUB) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        std::string *out_str) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Float
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_FLOAT_H_
