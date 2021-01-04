#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_REFERENCE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_REFERENCE_H_

#include <iostream>
#include <string>
#include <vector>

#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Reference {
class BaseReference : public Instruction {
 public:
  explicit BaseReference(const Utils::Types::u1 &tag) : Instruction(tag) {}

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
  }
};

class LoadFromArray : public BaseReference {
 public:
  LoadFromArray() : BaseReference(Opcodes::kAALOAD) {}
  /**
   * @brief Load reference from array
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

class StoreIntoArray : public BaseReference {
 public:
  StoreIntoArray() : BaseReference(Opcodes::kAASTORE) {}
  /**
   * @brief Store into reference array
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

class ConstNull : public BaseReference {
 public:
  ConstNull() : BaseReference(Opcodes::kACONST_NULL) {}
  /**
   * @brief Push null
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
  Load() : Instruction(Opcodes::kALOAD) {}

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
    auto index = *++*code_it;
    *delta_code = 1;
    return {Utils::String::toString(+index)};
  }
  /**
   * @brief Load reference from local variable
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

class Load_0 : public BaseReference {
 public:
  Load_0() : BaseReference(Opcodes::kALOAD_0) {}
  /**
   * @brief Load reference from local variable
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

class Load_1 : public BaseReference {
 public:
  Load_1() : BaseReference(Opcodes::kALOAD_1) {}
  /**
   * @brief Load reference from local variable
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

class Load_2 : public BaseReference {
 public:
  Load_2() : BaseReference(Opcodes::kALOAD_2) {}
  /**
   * @brief Load reference from local variable
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

class Load_3 : public BaseReference {
 public:
  Load_3() : BaseReference(Opcodes::kALOAD_3) {}
  /**
   * @brief Load reference from local variable
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
  NewArray() : Instruction(Opcodes::kANEWARRAY) {}

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
   * @brief Create new array of reference
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

class Return : public BaseReference {
 public:
  Return() : BaseReference(Opcodes::kARETURN) {}
  /**
   * @brief Return reference from method
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

class ArrayLength : public BaseReference {
 public:
  ArrayLength() : BaseReference(Opcodes::kARRAYLENGTH) {}
  /**
   * @brief Get length of array
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
  Store() : Instruction(Opcodes::kASTORE) {}

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
   * @brief Store reference into local variable
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

class Store_0 : public BaseReference {
 public:
  Store_0() : BaseReference(Opcodes::kASTORE_0) {}
  /**
   * @brief Store reference into local variable
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

class Store_1 : public BaseReference {
 public:
  Store_1() : BaseReference(Opcodes::kASTORE_1) {}
  /**
   * @brief Store reference into local variable
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

class Store_2 : public BaseReference {
 public:
  Store_2() : BaseReference(Opcodes::kASTORE_2) {}
  /**
   * @brief Store reference into local variable
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

class Store_3 : public BaseReference {
 public:
  Store_3() : BaseReference(Opcodes::kASTORE_3) {}
  /**
   * @brief Store reference into local variable
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

class Throw : public BaseReference {
 public:
  Throw() : BaseReference(Opcodes::kATHROW) {}
  /**
   * @brief Throw exception or error
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
}  // namespace Reference
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_REFERENCE_H_
