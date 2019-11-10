#include "instructions/instruction_set/byte.h"

#include "utils/array_t.h"
#include "utils/flags.h"
#include "utils/memory_areas/method_area.h"
#include "utils/memory_areas/thread.h"

namespace Instructions {
namespace Byte {
std::vector<int> LoadFromArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  // auto arrayref = th->current_frame->popOperand<Utils::Array_t *>();
  // int index = th->current_frame->popOperand<int>();
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> StoreIntoArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Push::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  signed char byte = *++*code_iterator;
  *delta_code = 1;

  th->current_frame->pushOperand<int>(byte);

  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Byte
}  // namespace Instructions