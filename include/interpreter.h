#ifndef INCLUDE_INTERPRETER_H_
#define INCLUDE_INTERPRETER_H_

#include <string>
#include <vector>
#include "utils/frame.h"
#include "utils/memory_areas/heap.h"
#include "utils/memory_areas/java_stack.h"
#include "utils/memory_areas/method_area.h"
#include "utils/memory_areas/thread.h"

class Interpreter {
 public:
  Interpreter(const ClassFile *cf, const std::string &fname) {
    this->classname = fname;
    this->entry_class = cf;
    this->init();
  }

  ~Interpreter() {
    delete this->method_area;
    delete this->heap;
  }

  void run();

 private:
  void init();

  std::vector<MemoryAreas::Thread> threads;
  MemoryAreas::MethodArea *method_area;
  MemoryAreas::Heap *heap;
  std::string classname;
  const ClassFile *entry_class;
};

#endif  // INCLUDE_INTERPRETER_H_
