#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BRANCH_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BRANCH_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instructions_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Branch {
class RefCompareEqual : public Instruction {
 public:
  RefCompareEqual() : Instruction(Opcodes::kIF_ACMPEQ) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class RefCompareNotEqual : public Instruction {
 public:
  RefCompareNotEqual() : Instruction(Opcodes::kIF_ACMPNE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class IntegerCompareEqual : public Instruction {
 public:
  IntegerCompareEqual() : Instruction(Opcodes::kIF_ICMPEQ) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class IntegerCompareGreaterEqual : public Instruction {
 public:
  IntegerCompareGreaterEqual() : Instruction(Opcodes::kIF_ICMPGE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class IntegerCompareGreaterThan : public Instruction {
 public:
  IntegerCompareGreaterThan() : Instruction(Opcodes::kIF_ICMPGT) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class IntegerCompareLessEqual : public Instruction {
 public:
  IntegerCompareLessEqual() : Instruction(Opcodes::kIF_ICMPLE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class IntegerCompareLessThan : public Instruction {
 public:
  IntegerCompareLessThan() : Instruction(Opcodes::kIF_ICMPLT) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class IntegerCompareNotEqual : public Instruction {
 public:
  IntegerCompareNotEqual() : Instruction(Opcodes::kIF_ICMPNE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class EqualZero : public Instruction {
 public:
  EqualZero() : Instruction(Opcodes::kIFEQ) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class GreaterEqualZero : public Instruction {
 public:
  GreaterEqualZero() : Instruction(Opcodes::kIFGE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class GreaterThanZero : public Instruction {
 public:
  GreaterThanZero() : Instruction(Opcodes::kIFGT) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class LessEqualZero : public Instruction {
 public:
  LessEqualZero() : Instruction(Opcodes::kIFLE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class LessThanZero : public Instruction {
 public:
  LessThanZero() : Instruction(Opcodes::kIFLT) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class NotEqualZero : public Instruction {
 public:
  NotEqualZero() : Instruction(Opcodes::kIFNE) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class NonNull : public Instruction {
 public:
  NonNull() : Instruction(Opcodes::kIFNONNULL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};

class RefNull : public Instruction {
 public:
  RefNull() : Instruction(Opcodes::kIFNULL) {}

  inline int toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                        int *delta_code, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " " << offset << "\n";
    *delta_code = 2;
    return 0;
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {std::to_string(offset)};
  }
};
}  // namespace Branch
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BRANCH_H_
