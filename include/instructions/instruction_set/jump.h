#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_JUMP_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_JUMP_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Jump {
class JumpSubRoutine : public Instruction {
 public:
  JumpSubRoutine() : Instruction(Opcodes::kJSR) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    int16_t offset = (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " " << offset << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    int16_t offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::toString(offset)};
  }
/**
 * @brief Jump subroutine
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

class JumpSubRoutineWide : public Instruction {
 public:
  JumpSubRoutineWide() : Instruction(Opcodes::kJSR_W) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc,
      const int &delta_tab) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    (*ss) << Opcodes::getMnemonic(this->opcode) << " " << offset << " ";
    *delta_code = 4;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide, int *pc) override {
    auto offset = (*++*code_it << 24) | (*++*code_it << 16) |
                  (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::toString(offset)};
  }
/**
 * @brief Jump subroutine(wide)
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
}  // namespace Jump
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_JUMP_H_
