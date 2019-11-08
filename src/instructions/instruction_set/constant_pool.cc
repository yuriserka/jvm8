#include "instructions/instruction_set/constant_pool.h"
#include "utils/memory_areas/thread.h"

namespace Instructions {
namespace ConstantPool {
std::vector<int> LoadCat1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> LoadCat1Wide::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> LoadCat2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace ConstantPool
}  // namespace Instructions
