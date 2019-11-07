#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_BRANCH_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_BRANCH_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Branch {
class BaseBranch : public Instruction {
 public:
  explicit BaseBranch(const Utils::Types::u1 &tag) : Instruction(tag) {}
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
};

class RefCompareEqual : public BaseBranch {
 public:
  RefCompareEqual() : BaseBranch(Opcodes::kIF_ACMPEQ) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class RefCompareNotEqual : public BaseBranch {
 public:
  RefCompareNotEqual() : BaseBranch(Opcodes::kIF_ACMPNE) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class IntegerCompareEqual : public BaseBranch {
 public:
  IntegerCompareEqual() : BaseBranch(Opcodes::kIF_ICMPEQ) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class IntegerCompareGreaterEqual : public BaseBranch {
 public:
  IntegerCompareGreaterEqual() : BaseBranch(Opcodes::kIF_ICMPGE) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class IntegerCompareGreaterThan : public BaseBranch {
 public:
  IntegerCompareGreaterThan() : BaseBranch(Opcodes::kIF_ICMPGT) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class IntegerCompareLessEqual : public BaseBranch {
 public:
  IntegerCompareLessEqual() : BaseBranch(Opcodes::kIF_ICMPLE) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class IntegerCompareLessThan : public BaseBranch {
 public:
  IntegerCompareLessThan() : BaseBranch(Opcodes::kIF_ICMPLT) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class IntegerCompareNotEqual : public BaseBranch {
 public:
  IntegerCompareNotEqual() : BaseBranch(Opcodes::kIF_ICMPNE) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class EqualZero : public BaseBranch {
 public:
  EqualZero() : BaseBranch(Opcodes::kIFEQ) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class GreaterEqualZero : public BaseBranch {
 public:
  GreaterEqualZero() : BaseBranch(Opcodes::kIFGE) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class GreaterThanZero : public BaseBranch {
 public:
  GreaterThanZero() : BaseBranch(Opcodes::kIFGT) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class LessEqualZero : public BaseBranch {
 public:
  LessEqualZero() : BaseBranch(Opcodes::kIFLE) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class LessThanZero : public BaseBranch {
 public:
  LessThanZero() : BaseBranch(Opcodes::kIFLT) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class NotEqualZero : public BaseBranch {
 public:
  NotEqualZero() : BaseBranch(Opcodes::kIFNE) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class NonNull : public BaseBranch {
 public:
  NonNull() : BaseBranch(Opcodes::kIFNONNULL) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};

class RefNull : public BaseBranch {
 public:
  RefNull() : BaseBranch(Opcodes::kIFNULL) {}

  std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) override;
};
}  // namespace Branch
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_BRANCH_H_
