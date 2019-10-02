#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MISC_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MISC_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Misc {
class Breakpoint : public Instruction {
 public:
  Breakpoint() : Instruction(Opcodes::kBREAKPOINT) {}
  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Checkcast : public Instruction {
 public:
  Checkcast() : Instruction(Opcodes::kCHECKCAST) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Dup : public Instruction {
 public:
  Dup() : Instruction(Opcodes::kDUP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class DupX1 : public Instruction {
 public:
  DupX1() : Instruction(Opcodes::kDUP_X1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class DupX2 : public Instruction {
 public:
  DupX2() : Instruction(Opcodes::kDUP_X2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Dup2 : public Instruction {
 public:
  Dup2() : Instruction(Opcodes::kDUP2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Dup2X1 : public Instruction {
 public:
  Dup2X1() : Instruction(Opcodes::kDUP2_X1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Dup2X2 : public Instruction {
 public:
  Dup2X2() : Instruction(Opcodes::kDUP2_X2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class GetField : public Instruction {
 public:
  GetField() : Instruction(Opcodes::kGETFIELD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class GetStatic : public Instruction {
 public:
  GetStatic() : Instruction(Opcodes::kGETSTATIC) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Goto : public Instruction {
 public:
  Goto() : Instruction(Opcodes::kGOTO) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class GotoWide : public Instruction {
 public:
  GotoWide() : Instruction(Opcodes::kGOTO_W) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class InstanceOf : public Instruction {
 public:
  InstanceOf() : Instruction(Opcodes::kINSTANCEOF) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class LookupSwitch : public Instruction {
 public:
  LookupSwitch() : Instruction(Opcodes::kLOOKUPSWITCH) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class MULTIANEWARRAY : public Instruction {
 public:
  MULTIANEWARRAY() : Instruction(Opcodes::kMULTIANEWARRAY) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class New : public Instruction {
 public:
  New() : Instruction(Opcodes::kNEW) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class NewArray : public Instruction {
 public:
  NewArray() : Instruction(Opcodes::kNEWARRAY) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Nop : public Instruction {
 public:
  Nop() : Instruction(Opcodes::kNOP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Pop : public Instruction {
 public:
  Pop() : Instruction(Opcodes::kPOP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Pop2 : public Instruction {
 public:
  Pop2() : Instruction(Opcodes::kPOP2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class PutField : public Instruction {
 public:
  PutField() : Instruction(Opcodes::kPUTFIELD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    auto kpool_index = *++*code_it << 8 | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class PutStatic : public Instruction {
 public:
  PutStatic() : Instruction(Opcodes::kPUTSTATIC) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Ret : public Instruction {
 public:
  Ret() : Instruction(Opcodes::kRET) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kRETURN) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Swap : public Instruction {
 public:
  Swap() : Instruction(Opcodes::kSWAP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class TableSwitch : public Instruction {
 public:
  TableSwitch() : Instruction(Opcodes::kTABLESWITCH) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Wide : public Instruction {
 public:
  Wide() : Instruction(Opcodes::kWIDE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Misc
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MISC_H_
