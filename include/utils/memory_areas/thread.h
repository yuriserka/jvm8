#ifndef INCLUDE_UTILS_MEMORY_AREAS_THREAD_H_
#define INCLUDE_UTILS_MEMORY_AREAS_THREAD_H_

#include "utils/memory_areas/heap.h"
#include "utils/memory_areas/java_stack.h"
#include "utils/memory_areas/method_area.h"

namespace MemoryAreas {
class Thread {
 public:
  Thread(MethodArea *method_area, Heap *heap, const ClassFile *cf) {
    this->method_area = method_area;
    this->heap = heap;
    this->current_class = cf;
  }

  void executeMethod(const std::string &method_name);

 private:
  void changeContext(const std::string &classname, const std::string &method,
                     const std::string &arguments);

  MethodArea *method_area;
  Heap *heap;
  const ClassFile *current_class;
  JavaStack jvm_stack;

  Utils::Frame *current_frame;
  std::string current_method;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_THREAD_H_
