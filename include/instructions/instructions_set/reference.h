#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_REFERENCE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_REFERENCE_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Reference {
class LoadFromArray : public Instruction {
 public:
  LoadFromArray() : Instruction(Opcodes::kAALOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class StoreIntoArray : public Instruction {
 public:
  StoreIntoArray() : Instruction(Opcodes::kAASTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ConstNull : public Instruction {
 public:
  ConstNull() : Instruction(Opcodes::kACONST_NULL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kALOAD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << unsigned(index) << "\n";
    *delta_code = 1;
    return 0;
  }
};

class Load_0 : public Instruction {
 public:
  Load_0() : Instruction(Opcodes::kALOAD_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_1 : public Instruction {
 public:
  Load_1() : Instruction(Opcodes::kALOAD_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_2 : public Instruction {
 public:
  Load_2() : Instruction(Opcodes::kALOAD_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Load_3 : public Instruction {
 public:
  Load_3() : Instruction(Opcodes::kALOAD_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class NewArray : public Instruction {
 public:
  NewArray() : Instruction(Opcodes::kANEWARRAY) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kARETURN) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class ArrayLength : public Instruction {
 public:
  ArrayLength() : Instruction(Opcodes::kARRAYLENGTH) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store : public Instruction {
 public:
  Store() : Instruction(Opcodes::kASTORE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << unsigned(index) << "\n";
    *delta_code = 1;
    return 0;
  }
};

class Store_0 : public Instruction {
 public:
  Store_0() : Instruction(Opcodes::kASTORE_0) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_1 : public Instruction {
 public:
  Store_1() : Instruction(Opcodes::kASTORE_1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_2 : public Instruction {
 public:
  Store_2() : Instruction(Opcodes::kASTORE_2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Store_3 : public Instruction {
 public:
  Store_3() : Instruction(Opcodes::kASTORE_3) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Throw : public Instruction {
 public:
  Throw() : Instruction(Opcodes::kATHROW) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Reference
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_REFERENCE_H_
