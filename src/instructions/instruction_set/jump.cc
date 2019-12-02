#include "instructions/instruction_set/jump.h"

#include "utils/flags.h"
#include "utils/memory_areas/thread.h"

namespace Instructions {
// The JSR instruction is actually not even allowed in Java 7 classfiles.
// It is only allowed in version 49.0 or earlier classfiles, corresponding
// to Java 5 or earlier. In practice, it fell out of use long before that.
namespace Jump {
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
std::vector<int> JumpSubRoutine::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  //  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  //   *delta_code = 2;
  return {};
}
// ----------------------------------------------------------------------------
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
std::vector<int> JumpSubRoutineWide::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  // auto offset = (*++*code_iterator << 24) | (*++*code_iterator << 16) |
  //                 (*++*code_iterator << 8) | *++*code_iterator;
  //   *delta_code = 4;
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Jump
}  // namespace Instructions
