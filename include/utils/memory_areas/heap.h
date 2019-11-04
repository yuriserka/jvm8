#ifndef INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_
#define INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_

#include <vector>
#include "utils/external/any.h"

namespace MemoryAreas {
class Heap {
 public:
  Heap() = default;

 private:
  std::vector<Any> object_refs;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_
