#include "interpreter.h"

#include "utils/flags.h"
#include "utils/memory_areas/thread.h"

void Interpreter::run() {
  auto th =
      MemoryAreas::Thread(this->method_area, this->heap, this->entry_class);
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "\n\tInterpreting ClassFile " << this->classname << "\n\n";
  }
  th.executeMethod("main");
}

void Interpreter::init() {
  this->method_area = new MemoryAreas::MethodArea(this->entry_class);
  this->heap = new MemoryAreas::Heap();
  // std::cout << "criando as coisas pra thread...\n";
}