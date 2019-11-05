#include "interpreter.h"

#include "utils/flags.h"
#include "utils/memory_areas/thread.h"

void Interpreter::run() {
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "\n\tInterpreting ClassFile " << this->classname << "\n\n";
  }
  threads[0].executeMethod("main");
}

void Interpreter::init() {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "criando as coisas pra thread...\n";
  }
  this->method_area = new MemoryAreas::MethodArea(this->entry_class);
  this->heap = new MemoryAreas::Heap();
  this->threads.emplace_back(this->method_area, this->heap, this->entry_class);

  //  every class has at least one <init> method responsible for initializing
  //  the class variables explicitly declared in that class.
  // mas como saber qual init se tiver mais de 1???
  threads[0].executeMethod("<init>");
}