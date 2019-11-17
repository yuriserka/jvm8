#ifndef INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_
#define INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_

#include <algorithm>
#include <vector>
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

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

  Utils::Object *pushReference(const Utils::Object &obj) {
    this->object_refs.push_back(obj);

    return &this->object_refs[this->last_obj_index++];
  }

 private:
  int last_obj_index = 0;
  std::vector<Utils::Object> object_refs;
  std::vector<std::string> initialized_classes;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_
