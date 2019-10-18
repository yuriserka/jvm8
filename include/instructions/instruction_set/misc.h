#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_MISC_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_MISC_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Misc {
class Checkcast : public Instruction {
 public:
  Checkcast() : Instruction(Opcodes::kCHECKCAST) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " #"
           << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class Dup : public Instruction {
 public:
  Dup() : Instruction(Opcodes::kDUP) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class DupX1 : public Instruction {
 public:
  DupX1() : Instruction(Opcodes::kDUP_X1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class DupX2 : public Instruction {
 public:
  DupX2() : Instruction(Opcodes::kDUP_X2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Dup2 : public Instruction {
 public:
  Dup2() : Instruction(Opcodes::kDUP2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Dup2X1 : public Instruction {
 public:
  Dup2X1() : Instruction(Opcodes::kDUP2_X1) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Dup2X2 : public Instruction {
 public:
  Dup2X2() : Instruction(Opcodes::kDUP2_X2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class GetField : public Instruction {
 public:
  GetField() : Instruction(Opcodes::kGETFIELD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " #"
           << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class GetStatic : public Instruction {
 public:
  GetStatic() : Instruction(Opcodes::kGETSTATIC) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " #"
           << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class Goto : public Instruction {
 public:
  Goto() : Instruction(Opcodes::kGOTO) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    int16_t offset = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << (static_cast<int16_t>(*code_index) + offset) << " ("
           << std::showpos << offset << ")\n";
    *delta_code = 2;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    int16_t offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(offset)};
  }
};

class GotoWide : public Instruction {
 public:
  GotoWide() : Instruction(Opcodes::kGOTO_W) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << *code_index + offset << " (" << std::showpos << offset << ")\n";
    *delta_code = 4;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    *delta_code = 4;
    return {Utils::String::to_string(offset)};
  }
};

class InstanceOf : public Instruction {
 public:
  InstanceOf() : Instruction(Opcodes::kINSTANCEOF) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " #"
           << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
  }
};

class LookupSwitch : public Instruction {
 public:
  LookupSwitch() : Instruction(Opcodes::kLOOKUPSWITCH) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " ";
    ++*code_it;
    auto getAlinhamento = [](int a) -> int { return a ? (4 - a) : 0; };

    auto alinhamento = (*code_index + 1) % 4;
    *code_it += getAlinhamento(alinhamento) - 1;

    auto getU4 = [](std::vector<Utils::Types::u1>::iterator *code_it) -> int {
      auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                    (*++*code_it << 8) | *++*code_it;
      return offset;
    };

    auto default_bytes = getU4(code_it);
    auto npairs = getU4(code_it);
    (*wss) << npairs << "\n";

    auto oldFlags = wss->flags();
    for (int i = 0; i < npairs; ++i) {
      auto match = static_cast<int>(getU4(code_it));
      auto offset = static_cast<int>(getU4(code_it));

      (*wss) << std::wstring(delta_tab, '\t') << match << ": "
             << (*code_index + offset) << " (";
      (*wss) << std::showpos << offset << ")\n";
      wss->flags(oldFlags);
    }

    (*wss) << std::wstring(delta_tab, '\t')
           << "default: " << (*code_index + default_bytes) << " ("
           << std::showpos << default_bytes << ")"
           << "\n";
    *delta_code = getAlinhamento(alinhamento) + 4 + 4 + 8 * npairs;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    ++*code_it;
    std::vector<std::string> args;
    auto getAlinhamento = [](int a) -> int { return a ? (4 - a) : 0; };

    auto alinhamento = (*code_index + 1) % 4;
    *code_it += getAlinhamento(alinhamento) - 1;
    args.push_back(Utils::String::to_string(alinhamento - 1));

    auto getU4 = [](std::vector<Utils::Types::u1>::iterator *code_it) -> int {
      auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                    (*++*code_it << 8) | *++*code_it;
      return offset;
    };

    auto default_bytes = getU4(code_it);
    args.push_back(Utils::String::to_string(default_bytes));
    auto npairs = getU4(code_it);
    args.push_back(Utils::String::to_string(npairs));
    std::vector<int> match_offset_pairs;
    for (int i = 0; i < npairs; ++i) {
      auto match = static_cast<int>(getU4(code_it));
      auto offset = static_cast<int>(getU4(code_it));

      args.push_back(Utils::String::to_string(match));
      args.push_back(Utils::String::to_string(offset));
    }
    *delta_code = getAlinhamento(alinhamento) + 4 + 4 + 8 * npairs;
    return args;
  }
};

class MultiDimArray : public Instruction {
 public:
  MultiDimArray() : Instruction(Opcodes::kMULTIANEWARRAY) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    unsigned char dims = *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " #"
           << kpool_index << " ";
    *delta_code = 3;
    return {kpool_index, int{dims}};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 3;
    return {Utils::String::to_string(+(*++*code_it))};
  }
};

class New : public Instruction {
 public:
  New() : Instruction(Opcodes::kNEW) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " #"
           << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class NewArray : public Instruction {
 public:
  NewArray() : Instruction(Opcodes::kNEWARRAY) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    unsigned char atype = *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << atype << " " << Utils::String::to_wide(this->getType(atype));
    *delta_code = 1;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    unsigned char atype = *++*code_it;
    *delta_code = 1;
    return {Utils::String::to_string(int{atype})};
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
  Nop() : Instruction(Opcodes::kNOP) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Pop : public Instruction {
 public:
  Pop() : Instruction(Opcodes::kPOP) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Pop2 : public Instruction {
 public:
  Pop2() : Instruction(Opcodes::kPOP2) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class PutField : public Instruction {
 public:
  PutField() : Instruction(Opcodes::kPUTFIELD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " #"
           << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class PutStatic : public Instruction {
 public:
  PutStatic() : Instruction(Opcodes::kPUTSTATIC) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " #"
           << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
};

class Ret : public Instruction {
 public:
  Ret() : Instruction(Opcodes::kRET) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    unsigned char index = *++*code_it;
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " "
           << int{index} << "\n";
    *delta_code = 1;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    unsigned char index = *++*code_it;
    *delta_code = 1;
    return {Utils::String::to_string(int{index})};
  }
};

class Return : public Instruction {
 public:
  Return() : Instruction(Opcodes::kRETURN) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class Swap : public Instruction {
 public:
  Swap() : Instruction(Opcodes::kSWAP) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};

class TableSwitch : public Instruction {
 public:
  TableSwitch() : Instruction(Opcodes::kTABLESWITCH) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode)) << " ";
    ++*code_it;
    auto getAlinhamento = [](int a) -> int { return a ? (4 - a) : 0; };

    auto alinhamento = (*code_index + 1) % 4;
    *code_it += getAlinhamento(alinhamento) - 1;

    auto getU4 = [](std::vector<Utils::Types::u1>::iterator *code_it) -> int {
      auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                    (*++*code_it << 8) | *++*code_it;
      return offset;
    };

    auto default_bytes = getU4(code_it);
    auto low = getU4(code_it);
    auto high = getU4(code_it);
    auto qtd_entries = high - low + 1;
    (*wss) << low << " to " << high << "\n";
    auto oldFlags = wss->flags();
    for (int i = low; i < high + 1; ++i) {
      auto offset = static_cast<int>(getU4(code_it));
      (*wss) << std::wstring(delta_tab, '\t') << i << ": "
             << (*code_index + offset) << " (";
      (*wss) << std::showpos << offset << ")\n";
      wss->flags(oldFlags);
    }
    (*wss) << std::wstring(delta_tab, '\t')
           << "default: " << (*code_index + default_bytes) << " ("
           << std::showpos << default_bytes << ")"
           << "\n";
    *delta_code = getAlinhamento(alinhamento) + 4 + 4 + 4 + 4 * qtd_entries;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    ++*code_it;
    std::vector<std::string> args;
    auto getAlinhamento = [](int a) -> int { return a ? (4 - a) : 0; };

    auto alinhamento = (*code_index + 1) % 4;
    *code_it += getAlinhamento(alinhamento) - 1;
    args.push_back(Utils::String::to_string(alinhamento - 1));

    auto getU4 = [](std::vector<Utils::Types::u1>::iterator *code_it) -> int {
      auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                    (*++*code_it << 8) | *++*code_it;
      return offset;
    };

    auto default_bytes = getU4(code_it);
    args.push_back(Utils::String::to_string(default_bytes));
    auto low = getU4(code_it);
    args.push_back(Utils::String::to_string(low));
    auto high = getU4(code_it);
    args.push_back(Utils::String::to_string(high));
    auto qtd_entries = high - low + 1;

    for (int i = low; i < high + 1; ++i) {
      auto offset = static_cast<int>(getU4(code_it));
      args.push_back(Utils::String::to_string(offset));
    }
    *delta_code = getAlinhamento(alinhamento) + 4 + 4 + 4 + 4 * qtd_entries;
    return args;
  }
};

/**
 * Procurar tentar endender melhor
 * */
class Wide : public Instruction {
 public:
  Wide() : Instruction(Opcodes::kWIDE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::wstringstream *wss, const bool &wide, int *code_index,
      const int &delta_tab) override {
    (*wss) << Utils::String::to_wide(Opcodes::getMnemonic(this->opcode))
           << "\n";
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *code_index) override {
    return {};
  }
};
}  // namespace Misc
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_MISC_H_
