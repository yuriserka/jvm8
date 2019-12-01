#include "interpreter.h"

#include "utils/flags.h"
#include "utils/memory_areas/thread.h"

void Interpreter::run() {
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "\n\tInterpreting ClassFile " << this->classname << "\n\n";
  }
  threads[0].executeMethod("main", "([Ljava/lang/String;)V");
}

void Interpreter::init() {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "criando as coisas pra thread...\n";
  }
  auto this_class = Utils::getClassName(this->entry_class);
  this->method_area = new MemoryAreas::MethodArea(this->entry_class);
  this->method_area->loadClass(this_class);

  this->heap = new MemoryAreas::Heap();
  this->threads.emplace_back(this->method_area, this->heap, this->entry_class);
  try {
    threads[0].method_area->getMethod("<clinit>", "()V");
    this->heap->addClass(&this->threads[0], this_class);
    threads[0].changeContext(this_class, "<clinit>", "()V", false);
  } catch (const Utils::Errors::Exception &e) {
  }
}