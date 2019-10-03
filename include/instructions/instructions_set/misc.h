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
  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Checkcast : public Instruction {
 public:
  Checkcast() : Instruction(Opcodes::kCHECKCAST) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class Dup : public Instruction {
 public:
  Dup() : Instruction(Opcodes::kDUP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class DupX1 : public Instruction {
 public:
  DupX1() : Instruction(Opcodes::kDUP_X1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class DupX2 : public Instruction {
 public:
  DupX2() : Instruction(Opcodes::kDUP_X2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Dup2 : public Instruction {
 public:
  Dup2() : Instruction(Opcodes::kDUP2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Dup2X1 : public Instruction {
 public:
  Dup2X1() : Instruction(Opcodes::kDUP2_X1) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Dup2X2 : public Instruction {
 public:
  Dup2X2() : Instruction(Opcodes::kDUP2_X2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class GetField : public Instruction {
 public:
  GetField() : Instruction(Opcodes::kGETFIELD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class GetStatic : public Instruction {
 public:
  GetStatic() : Instruction(Opcodes::kGETSTATIC) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class Goto : public Instruction {
 public:
  Goto() : Instruction(Opcodes::kGOTO) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto branchoffset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << branchoffset
              << "\n";
    *delta_code = 2;
    return branchoffset;
  }
};

class GotoWide : public Instruction {
 public:
  GotoWide() : Instruction(Opcodes::kGOTO_W) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto branchoffset = (*++*code_it << 24) | (*++*code_it << 16) |
                        (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << branchoffset
              << "\n";
    *delta_code = 4;
    return branchoffset;
  }
};

class InstanceOf : public Instruction {
 public:
  InstanceOf() : Instruction(Opcodes::kINSTANCEOF) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

/**
 * Parece bem complicado, pensar melhor depois
 * */
class LookupSwitch : public Instruction {
 public:
  LookupSwitch() : Instruction(Opcodes::kLOOKUPSWITCH) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class MultiDimArray : public Instruction {
 public:
  MultiDimArray() : Instruction(Opcodes::kMULTIANEWARRAY) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 3;
    return kpool_index;
  }
};

class New : public Instruction {
 public:
  New() : Instruction(Opcodes::kNEW) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class NewArray : public Instruction {
 public:
  NewArray() : Instruction(Opcodes::kNEWARRAY) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto atype = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << +atype << " ";
    switch (+atype) {
      case kT_BOOLEAN:
        std::cout << "(boolean)\n";
        break;
      case kT_CHAR:
        std::cout << "(char)\n";
        break;
      case kT_FLOAT:
        std::cout << "(float)\n";
        break;
      case kT_DOUBLE:
        std::cout << "(double)\n";
        break;
      case kT_BYTE:
        std::cout << "(byte)\n";
        break;
      case kT_SHORT:
        std::cout << "(short)\n";
        break;
      case kT_INT:
        std::cout << "(int)\n";
        break;
      case kT_LONG:
        std::cout << "(long)\n";
        break;
    }
    *delta_code = 1;
    return 0;
  }

 private:
  enum Types {
    kT_BOOLEAN = 4,
    kT_CHAR = 5,
    kT_FLOAT = 6,
    kT_DOUBLE = 7,
    kT_BYTE = 8,
    kT_SHORT = 9,
    kT_INT = 10,
    kT_LONG = 11
  };
};

class Nop : public Instruction {
 public:
  Nop() : Instruction(Opcodes::kNOP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Pop : public Instruction {
 public:
  Pop() : Instruction(Opcodes::kPOP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Pop2 : public Instruction {
 public:
  Pop2() : Instruction(Opcodes::kPOP2) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class PutField : public Instruction {
 public:
  PutField() : Instruction(Opcodes::kPUTFIELD) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class PutStatic : public Instruction {
 public:
  PutStatic() : Instruction(Opcodes::kPUTSTATIC) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    *delta_code = 2;
    return kpool_index;
  }
};

class Ret : public Instruction {
 public:
  Ret() : Instruction(Opcodes::kRET) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << index << "\n";
    *delta_code = 1;
    return 0;
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kRETURN) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

class Swap : public Instruction {
 public:
  Swap() : Instruction(Opcodes::kSWAP) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

/**
 * Parece complicado, olhar melhor depois
 * */
class TableSwitch : public Instruction {
 public:
  TableSwitch() : Instruction(Opcodes::kTABLESWITCH) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};

/**
 * Procurar tentar endender melhor
 * */
class Wide : public Instruction {
 public:
  Wide() : Instruction(Opcodes::kWIDE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
    return 0;
  }
};
}  // namespace Misc
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MISC_H_
