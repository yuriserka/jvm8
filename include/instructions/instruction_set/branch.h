#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BRANCH_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BRANCH_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Branch {
class RefCompareEqual : public Instruction {
 public:
  RefCompareEqual(Viewer *v) : Instruction(Opcodes::kIF_ACMPEQ, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override;

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) override;
};

class RefCompareNotEqual : public Instruction {
 public:
  RefCompareNotEqual(Viewer *v) : Instruction(Opcodes::kIF_ACMPNE, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareEqual : public Instruction {
 public:
  IntegerCompareEqual(Viewer *v) : Instruction(Opcodes::kIF_ICMPEQ, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareGreaterEqual : public Instruction {
 public:
  IntegerCompareGreaterEqual(Viewer *v) : Instruction(Opcodes::kIF_ICMPGE, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareGreaterThan : public Instruction {
 public:
  IntegerCompareGreaterThan(Viewer *v) : Instruction(Opcodes::kIF_ICMPGT, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareLessEqual : public Instruction {
 public:
  IntegerCompareLessEqual(Viewer *v) : Instruction(Opcodes::kIF_ICMPLE, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareLessThan : public Instruction {
 public:
  IntegerCompareLessThan(Viewer *v) : Instruction(Opcodes::kIF_ICMPLT, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareNotEqual : public Instruction {
 public:
  IntegerCompareNotEqual(Viewer *v) : Instruction(Opcodes::kIF_ICMPNE, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class EqualZero : public Instruction {
 public:
  EqualZero(Viewer *v) : Instruction(Opcodes::kIFEQ, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class GreaterEqualZero : public Instruction {
 public:
  GreaterEqualZero(Viewer *v) : Instruction(Opcodes::kIFGE, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class GreaterThanZero : public Instruction {
 public:
  GreaterThanZero(Viewer *v) : Instruction(Opcodes::kIFGT, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class LessEqualZero : public Instruction {
 public:
  LessEqualZero(Viewer *v) : Instruction(Opcodes::kIFLE, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class LessThanZero : public Instruction {
 public:
  LessThanZero(Viewer *v) : Instruction(Opcodes::kIFLT, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class NotEqualZero : public Instruction {
 public:
  NotEqualZero(Viewer *v) : Instruction(Opcodes::kIFNE, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class NonNull : public Instruction {
 public:
  NonNull(Viewer *v) : Instruction(Opcodes::kIFNONNULL, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class RefNull : public Instruction {
 public:
  RefNull(Viewer *v) : Instruction(Opcodes::kIFNULL, v) {}

  void toBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                  const int &code_pos, int *delta_code,
                  const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " "
              << static_cast<int>(char(offset + offset)) << " (" << std::showpos
              << static_cast<int>(char(offset)) << ")\n";
    *delta_code = 2;
  }

  std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};
}  // namespace Branch
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BRANCH_H_
