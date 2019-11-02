#include "interpreter.h"

#include "utils/flags.h"
#include "utils/memory_areas/thread.h"

void Interpreter::run() {
  auto th = MemoryAreas::Thread(this->entry_class);
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "\n\tInterpreting ClassFile " << this->classname << "\n\n";
  }
  th.executeMethod("main");
}