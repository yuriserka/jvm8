#ifndef INCLUDE_INSTRUCTIONS_PRINTER_H_
#define INCLUDE_INSTRUCTIONS_PRINTER_H_

#include <vector>
#include "utils/types.h"

// forward declaration
namespace MemoryAreas {
class Thread;
}

namespace Instructions {
bool runBytecode(std::vector<Utils::Types::u1>::iterator *opcode,
                 MemoryAreas::Thread *th, int *pc, const bool &wide = false);
}

#endif  // INCLUDE_INSTRUCTIONS_PRINTER_H_
