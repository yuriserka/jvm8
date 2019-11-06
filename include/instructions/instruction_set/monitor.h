#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_MONITOR_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_MONITOR_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"

namespace Instructions {
namespace Monitor {
class Enter : public Instruction {
 public:
  Enter() : Instruction(Opcodes::kMONITORENTER) {}

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

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};

class Exit : public Instruction {
 public:
  Exit() : Instruction(Opcodes::kMONITOREXIT) {}

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

  inline std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      const bool &wide, int *pc = nullptr) override {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    return {};
  }
};
}  // namespace Monitor
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_MONITOR_H_
