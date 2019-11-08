#include "instructions/instruction_set/byte.h"
#include "utils/memory_areas/thread.h"

namespace Instructions {
namespace Byte {
std::vector<int> LoadFromArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> StoreIntoArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Push::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  signed char byte = *++*code_iterator;
  *delta_code = 1;

  th->current_frame->pushOperand<int>(byte);

  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Byte
}  // namespace Instructions