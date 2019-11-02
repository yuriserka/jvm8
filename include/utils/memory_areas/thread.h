#ifndef INCLUDE_UTILS_MEMORY_AREAS_THREAD_H_
#define INCLUDE_UTILS_MEMORY_AREAS_THREAD_H_

#include <stack>
#include "utils/frame.h"
#include "utils/infos.h"

namespace MemoryAreas {
class Thread {
 public:
  Thread(const ClassFile *cf) { this->current_class = cf; }

  ~Thread() { delete this->current_frame; }
  void executeMethod(const std::string &method_name);

 private:
  Utils::Frame *current_frame;
  const ClassFile *current_class;
  std::stack<Utils::Frame *> jvm_stack;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_THREAD_H_
