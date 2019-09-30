#ifndef INCLUDE_INSTRUCTIONS_PRINTER_H_
#define INCLUDE_INSTRUCTIONS_PRINTER_H_

#include <vector>
#include "utils/infos.h"
#include "utils/types.h"

class Viewer;

namespace Instructions {
int printBytecode(std::vector<Utils::Types::u1>::iterator *opcode, Viewer *v);
}

#endif  // INCLUDE_INSTRUCTIONS_PRINTER_H_
