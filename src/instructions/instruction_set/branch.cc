#include "instructions/instruction_set/branch.h"
#include "utils/memory_areas/thread.h"

namespace Instructions {
namespace Branch {
std::vector<int> RefCompareEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> RefCompareNotEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> IntegerCompareEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> IntegerCompareGreaterEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> IntegerCompareGreaterThan::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> IntegerCompareLessEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> IntegerCompareLessThan::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> IntegerCompareNotEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> EqualZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> GreaterEqualZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> GreaterThanZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> LessEqualZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> LessThanZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> NotEqualZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> NonNull::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> RefNull::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Branch
}  // namespace Instructions
