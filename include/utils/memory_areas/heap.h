#ifndef INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_
#define INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_

#include <algorithm>
#include <vector>
#include "utils/external/any.h"
#include "utils/memory_areas/thread.h"

namespace MemoryAreas {
class Heap {
 public:
  Heap() = default;

  void initialize(Thread *th, const std::string &name) {
    this->initialized_classes.push_back(name);
    th->executeMethod("<clinit>");
  }

  bool isInitialized(const std::string &name) {
    return std::find(this->initialized_classes.begin(),
                     this->initialized_classes.end(),
                     name) != this->initialized_classes.end();
  }

 private:
  std::vector<Any> object_refs;
  std::vector<std::string> initialized_classes;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_
