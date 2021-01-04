#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_CHAR_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_CHAR_H_

#include <iostream>
#include <string>
#include <vector>

#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Char {
class BaseChar : public Instruction {
 public:
  explicit BaseChar(const Utils::Types::u1 &tag) : Instruction(tag) {}

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

class LoadFromArray : public BaseChar {
 public:
  LoadFromArray() : BaseChar(Opcodes::kCALOAD) {}
  /**
   * @brief Load char from array
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

class StoreIntoArray : public BaseChar {
 public:
  StoreIntoArray() : BaseChar(Opcodes::kCASTORE) {}
  /**
   * @brief Store into char array
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
}  // namespace Char
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_CHAR_H_
