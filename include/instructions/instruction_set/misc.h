#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MISC_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MISC_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Misc {
class Breakpoint : public Instruction {
 public:
  Breakpoint(Viewer *v) : Instruction(Opcodes::kBREAKPOINT, v) {}
  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Checkcast : public Instruction {
 public:
  Checkcast(Viewer *v) : Instruction(Opcodes::kCHECKCAST, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class Dup : public Instruction {
 public:
  Dup(Viewer *v) : Instruction(Opcodes::kDUP, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class DupX1 : public Instruction {
 public:
  DupX1(Viewer *v) : Instruction(Opcodes::kDUP_X1, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class DupX2 : public Instruction {
 public:
  DupX2(Viewer *v) : Instruction(Opcodes::kDUP_X2, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Dup2 : public Instruction {
 public:
  Dup2(Viewer *v) : Instruction(Opcodes::kDUP2, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Dup2X1 : public Instruction {
 public:
  Dup2X1(Viewer *v) : Instruction(Opcodes::kDUP2_X1, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Dup2X2 : public Instruction {
 public:
  Dup2X2(Viewer *v) : Instruction(Opcodes::kDUP2_X2, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class GetField : public Instruction {
 public:
  GetField(Viewer *v) : Instruction(Opcodes::kGETFIELD, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class GetStatic : public Instruction {
 public:
  GetStatic(Viewer *v) : Instruction(Opcodes::kGETSTATIC, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class Goto : public Instruction {
 public:
  Goto(Viewer *v) : Instruction(Opcodes::kGOTO, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    // std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class GotoWide : public Instruction {
 public:
  GotoWide(Viewer *v) : Instruction(Opcodes::kGOTO_W, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    // std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 4;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    *delta_code = 4;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class InstanceOf : public Instruction {
 public:
  InstanceOf(Viewer *v) : Instruction(Opcodes::kINSTANCEOF, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
  }
};

/**
 * Parece bem complicado, pensar melhor depois
 * */
class LookupSwitch : public Instruction {
 public:
  LookupSwitch(Viewer *v) : Instruction(Opcodes::kLOOKUPSWITCH, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class MultiDimArray : public Instruction {
 public:
  MultiDimArray(Viewer *v) : Instruction(Opcodes::kMULTIANEWARRAY, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 3;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 3;
    return {Utils::String::to_string(+(*++*code_it))};
  }
};

class New : public Instruction {
 public:
  New(Viewer *v) : Instruction(Opcodes::kNEW, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class NewArray : public Instruction {
 public:
  NewArray(Viewer *v) : Instruction(Opcodes::kNEWARRAY, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto atype = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << +atype << " "
              << this->getType(+atype);
    *delta_code = 1;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto atype = *++*code_it;
    *delta_code = 1;
    return {this->getType(+atype)};
  }

 private:
  std::string getType(const int &type) {
    switch (type) {
      case kT_BOOLEAN:
        return "(boolean)\n";
      case kT_CHAR:
        return "(char)\n";
      case kT_FLOAT:
        return "(float)\n";
      case kT_DOUBLE:
        return "(double)\n";
      case kT_BYTE:
        return "(byte)\n";
      case kT_SHORT:
        return "(short)\n";
      case kT_INT:
        return "(int)\n";
      case kT_LONG:
        return "(long)\n";
    }
    return "\0";
  }

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
  Nop(Viewer *v) : Instruction(Opcodes::kNOP, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Pop : public Instruction {
 public:
  Pop(Viewer *v) : Instruction(Opcodes::kPOP, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Pop2 : public Instruction {
 public:
  Pop2(Viewer *v) : Instruction(Opcodes::kPOP2, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class PutField : public Instruction {
 public:
  PutField(Viewer *v) : Instruction(Opcodes::kPUTFIELD, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class PutStatic : public Instruction {
 public:
  PutStatic(Viewer *v) : Instruction(Opcodes::kPUTSTATIC, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index
              << " ";
    std::wcout << "<" << this->viewer->getConstantPoolInfo(+kpool_index, false) << ">\n";
    *delta_code = 2;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class Ret : public Instruction {
 public:
  Ret(Viewer *v) : Instruction(Opcodes::kRET, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto index = *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << index << "\n";
    *delta_code = 1;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto index = *++*code_it;
    *delta_code = 1;
    return {Utils::String::to_string(+index)};
  }
};

class Return : public Instruction {
 public:
  Return(Viewer *v) : Instruction(Opcodes::kRETURN, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

class Swap : public Instruction {
 public:
  Swap(Viewer *v) : Instruction(Opcodes::kSWAP, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

/**
 * Parece complicado, olhar melhor depois
 * */
class TableSwitch : public Instruction {
 public:
  TableSwitch(Viewer *v) : Instruction(Opcodes::kTABLESWITCH, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};

/**
 * Procurar tentar endender melhor
 * */
class Wide : public Instruction {
 public:
  Wide(Viewer *v) : Instruction(Opcodes::kWIDE, v) {}

  inline void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    std::cout << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    return {};
  }
};
}  // namespace Misc
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_MISC_H_
