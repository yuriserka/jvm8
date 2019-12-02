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
class BaseMisc : public Instruction {
 public:
  explicit BaseMisc(const Utils::Types::u1 &tag) : Instruction(tag) {}

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
    ;
  }
};

class Checkcast : public Instruction {
 public:
  Checkcast() : Instruction(Opcodes::kCHECKCAST) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
/**
 * @brief Check whether object is of given type
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Dup : public BaseMisc {
 public:
  Dup() : BaseMisc(Opcodes::kDUP) {}
/**
 * @brief Duplicate the top operand stack value
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class DupX1 : public BaseMisc {
 public:
  DupX1() : BaseMisc(Opcodes::kDUP_X1) {}
/**
 * @brief Duplicate the top operand stack value and insert two values down
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class DupX2 : public BaseMisc {
 public:
  DupX2() : BaseMisc(Opcodes::kDUP_X2) {}
/**
 * @brief Duplicate the top operand stack value and insert two or three values down
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Dup2 : public BaseMisc {
 public:
  Dup2() : BaseMisc(Opcodes::kDUP2) {}
/**
 * @brief Duplicate the top one or two operand stack values
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Dup2X1 : public BaseMisc {
 public:
  Dup2X1() : BaseMisc(Opcodes::kDUP2_X1) {}
/**
 * @brief Duplicate the top one or two operand stack values and insert two or three values down
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Dup2X2 : public BaseMisc {
 public:
  Dup2X2() : BaseMisc(Opcodes::kDUP2_X2) {}
/**
 * @brief Duplicate the top one or two operand stack values and insert two, three, or four values down
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class GetField : public Instruction {
 public:
  GetField() : Instruction(Opcodes::kGETFIELD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
/**
 * @brief Fetch field from object
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class GetStatic : public Instruction {
 public:
  GetStatic() : Instruction(Opcodes::kGETSTATIC) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
/**
 * @brief Get static field from class
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Goto : public Instruction {
 public:
  Goto() : Instruction(Opcodes::kGOTO) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    int16_t offset = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " "
          << (static_cast<int16_t>(*pc) + offset) << " (" << std::showpos
          << offset << ")\n";
    *delta_code = 2;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    int16_t offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::toString(offset)};
  }
/**
 * @brief Branch always
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class GotoWide : public Instruction {
 public:
  GotoWide() : Instruction(Opcodes::kGOTO_W) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " " << *pc + offset << " ("
          << std::showpos << offset << ")\n";
    *delta_code = 4;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    *delta_code = 4;
    return {Utils::String::toString(offset)};
  }
/**
 * @brief Branch always(wide index)
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class InstanceOf : public Instruction {
 public:
  InstanceOf() : Instruction(Opcodes::kINSTANCEOF) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    return {};
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
  }
/**
 * @brief Determine if object is of given type
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class LookupSwitch : public Instruction {
 public:
  LookupSwitch() : Instruction(Opcodes::kLOOKUPSWITCH) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << " ";
    ++*code_it;
    auto getAlinhamento = [](int a) -> int { return a ? (4 - a) : 0; };

    auto alinhamento = (*pc + 1) % 4;
    *code_it += getAlinhamento(alinhamento) - 1;

    auto getU4 = [](std::vector<Utils::Types::u1>::iterator *code_it) -> int {
      auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                    (*++*code_it << 8) | *++*code_it;

      return offset;
    };

    auto default_bytes = getU4(code_it);
    auto npairs = getU4(code_it);
    (*ss) << npairs << "\n";

    auto oldFlags = ss->flags();
    for (int i = 0; i < npairs; ++i) {
      auto match = static_cast<int>(getU4(code_it));
      auto offset = static_cast<int>(getU4(code_it));

      (*ss) << std::string(delta_tab, '\t') << match << ": " << (*pc + offset)
            << " (";
      (*ss) << std::showpos << offset << ")\n";
      ss->flags(oldFlags);
    }

    (*ss) << std::string(delta_tab, '\t')
          << "default: " << (*pc + default_bytes) << " (" << std::showpos
          << default_bytes << ")"
          << "\n";
    *delta_code = getAlinhamento(alinhamento) + 4 + 4 + 8 * npairs;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    ++*code_it;
    std::vector<std::string> args;
    auto getAlinhamento = [](int a) -> int { return a ? (4 - a) : 0; };

    auto alinhamento = (*pc + 1) % 4;
    *code_it += getAlinhamento(alinhamento) - 1;
    args.push_back(Utils::String::toString(alinhamento - 1));

    auto getU4 = [](std::vector<Utils::Types::u1>::iterator *code_it) -> int {
      auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                    (*++*code_it << 8) | *++*code_it;

      return offset;
    };

    auto default_bytes = getU4(code_it);
    args.push_back(Utils::String::toString(default_bytes));
    auto npairs = getU4(code_it);
    args.push_back(Utils::String::toString(npairs));
    std::vector<int> match_offset_pairs;
    for (int i = 0; i < npairs; ++i) {
      auto match = static_cast<int>(getU4(code_it));
      auto offset = static_cast<int>(getU4(code_it));

      args.push_back(Utils::String::toString(match));
      args.push_back(Utils::String::toString(offset));
    }
    *delta_code = getAlinhamento(alinhamento) + 4 + 4 + 8 * npairs;

    return args;
  }
/**
 * @brief Access jump table by key match and jump
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class MultiDimArray : public Instruction {
 public:
  MultiDimArray() : Instruction(Opcodes::kMULTIANEWARRAY) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    unsigned char dims = *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 3;
    return {kpool_index, int{dims}};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 3;
    return {Utils::String::toString(+(*++*code_it))};
  }
/**
 * @brief Create new multidimensional array
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class New : public Instruction {
 public:
  New() : Instruction(Opcodes::kNEW) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
/**
 * @brief Create new object
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class NewArray : public Instruction {
 public:
  NewArray() : Instruction(Opcodes::kNEWARRAY) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    unsigned char atype = *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " " << atype << " "
          << this->getType(atype);
    *delta_code = 1;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    unsigned char atype = *++*code_it;
    *delta_code = 1;
    return {Utils::String::toString(int{atype})};
  }
/**
 * @brief Create new array
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;

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

class Nop : public BaseMisc {
 public:
  Nop() : BaseMisc(Opcodes::kNOP) {}
/**
 * @brief Do nothing
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Pop : public BaseMisc {
 public:
  Pop() : BaseMisc(Opcodes::kPOP) {}
/**
 * @brief Pop the top operand stack value
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Pop2 : public BaseMisc {
 public:
  Pop2() : BaseMisc(Opcodes::kPOP2) {}
/**
 * @brief Pop the top one or two operand stack values
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class PutField : public Instruction {
 public:
  PutField() : Instruction(Opcodes::kPUTFIELD) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
/**
 * @brief Set field in object
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class PutStatic : public Instruction {
 public:
  PutStatic() : Instruction(Opcodes::kPUTSTATIC) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto kpool_index = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " #" << kpool_index << " ";
    *delta_code = 2;
    return {kpool_index};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    *ret = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {};
  }
/**
 * @brief Set static field in class
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Ret : public Instruction {
 public:
  Ret() : Instruction(Opcodes::kRET) {}

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
/**
 * @brief Return from subroutine
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Return : public BaseMisc {
 public:
  Return() : BaseMisc(Opcodes::kRETURN) {}
/**
 * @brief Return void from method
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class Swap : public BaseMisc {
 public:
  Swap() : BaseMisc(Opcodes::kSWAP) {}
/**
 * @brief Swap the top two operand stack values
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class TableSwitch : public Instruction {
 public:
  TableSwitch() : Instruction(Opcodes::kTABLESWITCH) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    (*ss) << Opcodes::getMnemonic(this->opcode) << " ";
    ++*code_it;
    auto getAlinhamento = [](int a) -> int { return a ? (4 - a) : 0; };

    auto alinhamento = (*pc + 1) % 4;
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
    (*ss) << low << " to " << high << "\n";
    auto oldFlags = ss->flags();
    for (int i = low; i < high + 1; ++i) {
      auto offset = static_cast<int>(getU4(code_it));
      (*ss) << std::string(delta_tab, '\t') << i << ": " << (*pc + offset)
            << " (";
      (*ss) << std::showpos << offset << ")\n";
      ss->flags(oldFlags);
    }
    (*ss) << std::string(delta_tab, '\t')
          << "default: " << (*pc + default_bytes) << " (" << std::showpos
          << default_bytes << ")"
          << "\n";
    *delta_code = getAlinhamento(alinhamento) + 4 + 4 + 4 + 4 * qtd_entries;
    return {};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    ++*code_it;
    std::vector<std::string> args;
    auto getAlinhamento = [](int a) -> int { return a ? (4 - a) : 0; };

    auto alinhamento = (*pc + 1) % 4;
    *code_it += getAlinhamento(alinhamento) - 1;
    args.push_back(Utils::String::toString(alinhamento - 1));

    auto getU4 = [](std::vector<Utils::Types::u1>::iterator *code_it) -> int {
      auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                    (*++*code_it << 8) | *++*code_it;

      return offset;
    };

    auto default_bytes = getU4(code_it);
    args.push_back(Utils::String::toString(default_bytes));
    auto low = getU4(code_it);
    args.push_back(Utils::String::toString(low));
    auto high = getU4(code_it);
    args.push_back(Utils::String::toString(high));
    auto qtd_entries = high - low + 1;

    for (int i = low; i < high + 1; ++i) {
      auto offset = static_cast<int>(getU4(code_it));
      args.push_back(Utils::String::toString(offset));
    }
    *delta_code = getAlinhamento(alinhamento) + 4 + 4 + 4 + 4 * qtd_entries;

    return args;
  }
/**
 * @brief Access jump table by index and jump
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

/**
 * Procurar tentar endender melhor
 * */
class Wide : public BaseMisc {
 public:
  Wide() : BaseMisc(Opcodes::kWIDE) {}
/**
 * @brief Extend local variable index by additional bytes
 * 
 * @param code_iterator 
 * @param th 
 * @param delta_code 
 * @param wide 
 * @param pc 
 * @return std::vector<int> 
 */
  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};
}  // namespace Misc
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_MISC_H_
