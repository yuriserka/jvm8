#include "utils/memory_areas/heap.h"

#include "utils/class_t.h"
#include "utils/helper_functions.h"
#include "utils/memory_areas/method_area.h"

namespace MemoryAreas {
void Heap::addClass(Thread *th, const std::string &name) {
  if (this->isInitialized(name)) {
    return;
  }
  this->initialized_classes.push_back(new Utils::Class_t(name));
  try {
    th->method_area->getMethod("<clinit>", "()V");
    th->changeContext(name, "<clinit>", "()V", false);
  } catch (const Utils::Errors::Exception &e) {
    return;
  }
}
}  // namespace MemoryAreas