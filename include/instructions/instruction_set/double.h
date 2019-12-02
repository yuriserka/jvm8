#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_DOUBLE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_DOUBLE_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Double {
class BaseDouble : public Instruction {
 public:
  explicit BaseDouble(const Utils::Types::u1 &tag) : Instruction(tag) {}

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

class ToFloat : public BaseDouble {
 public:
  ToFloat() : BaseDouble(Opcodes::kD2F) {}
  /**
   * @brief Convert double to float
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

class ToInteger : public BaseDouble {
 public:
  ToInteger() : BaseDouble(Opcodes::kD2I) {}
  /**
   * @brief Convert double to integer
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

class ToLong : public BaseDouble {
 public:
  ToLong() : BaseDouble(Opcodes::kD2L) {}
  /**
   * @brief Convert double to long
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

class Add : public BaseDouble {
 public:
  Add() : BaseDouble(Opcodes::kDADD) {}
  /**
   * @brief Add double
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

class LoadFromArray : public BaseDouble {
 public:
  LoadFromArray() : BaseDouble(Opcodes::kDALOAD) {}
  /**
   * @brief Load double from array
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

class StoreIntoArray : public BaseDouble {
 public:
  StoreIntoArray() : BaseDouble(Opcodes::kDASTORE) {}
  /**
   * @brief Store double into local variable
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

class CompareGreater : public BaseDouble {
 public:
  CompareGreater() : BaseDouble(Opcodes::kDCMPG) {}
  /**
   * @brief Compare double (val1 > val2)
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

class CompareLess : public BaseDouble {
 public:
  CompareLess() : BaseDouble(Opcodes::kDCMPL) {}
  /**
   * @brief Compare double (val1 < val2)
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

class Const_0 : public BaseDouble {
 public:
  Const_0() : BaseDouble(Opcodes::kDCONST_0) {}
  /**
   * @brief Push double
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

class Const_1 : public BaseDouble {
 public:
  Const_1() : BaseDouble(Opcodes::kDCONST_1) {}
  /**
   * @brief Push double
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

class Div : public BaseDouble {
 public:
  Div() : BaseDouble(Opcodes::kDDIV) {}
  /**
   * @brief Divide double
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

class Load : public Instruction {
 public:
  Load() : Instruction(Opcodes::kDLOAD) {}

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
   * @brief Load double from local variable
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

class Load_0 : public BaseDouble {
 public:
  Load_0() : BaseDouble(Opcodes::kDLOAD_0) {}
  /**
   * @brief Load double from local variable
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

class Load_1 : public BaseDouble {
 public:
  Load_1() : BaseDouble(Opcodes::kDLOAD_1) {}
  /**
   * @brief Load double from local variable
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

class Load_2 : public BaseDouble {
 public:
  Load_2() : BaseDouble(Opcodes::kDLOAD_2) {}
  /**
   * @brief Load double from local variable
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

class Load_3 : public BaseDouble {
 public:
  Load_3() : BaseDouble(Opcodes::kDLOAD_3) {}
  /**
   * @brief Load double from local variable
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

class Mul : public BaseDouble {
 public:
  Mul() : BaseDouble(Opcodes::kDMUL) {}
  /**
   * @brief Multiply double
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

class Neg : public BaseDouble {
 public:
  Neg() : BaseDouble(Opcodes::kDNEG) {}
  /**
   * @brief Negate double
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

class Rem : public BaseDouble {
 public:
  Rem() : BaseDouble(Opcodes::kDREM) {}
  /**
   * @brief Remainder double
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

class Return : public BaseDouble {
 public:
  Return() : BaseDouble(Opcodes::kDRETURN) {}
  /**
   * @brief Return double from method
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

class Store : public Instruction {
 public:
  Store() : Instruction(Opcodes::kDSTORE) {}

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
   * @brief Store double into local variable
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

class Store_0 : public BaseDouble {
 public:
  Store_0() : BaseDouble(Opcodes::kDSTORE_0) {}
  /**
   * @brief Store double into local variable
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

class Store_1 : public BaseDouble {
 public:
  Store_1() : BaseDouble(Opcodes::kDSTORE_1) {}
  /**
   * @brief Store double into local variable
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

class Store_2 : public BaseDouble {
 public:
  Store_2() : BaseDouble(Opcodes::kDSTORE_2) {}
  /**
   * @brief Store double into local variable
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

class Store_3 : public BaseDouble {
 public:
  Store_3() : BaseDouble(Opcodes::kDSTORE_3) {}
  /**
   * @brief Store double into local variable
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

class Sub : public BaseDouble {
 public:
  Sub() : BaseDouble(Opcodes::kDSUB) {}
  /**
   * @brief Subtract double
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
}  // namespace Double
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_DOUBLE_H_
