#ifndef INCLUDE_UTILS_MEMORY_AREAS_JVM_STACK_H_
#define INCLUDE_UTILS_MEMORY_AREAS_JVM_STACK_H_

#include <stack>
#include "utils/frame.h"

namespace MemoryAreas {
class JavaStack {
 public:
  void push(Utils::Frame *frame) { this->frames.push(frame); }

  Utils::Frame *pop() {
    auto f = this->frames.top();
    this->frames.pop();
    return f;
  }

  Utils::Frame *top() { return this->frames.top(); }

  size_t size() { return this->frames.size(); }

 private:
  std::stack<Utils::Frame *> frames;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_JVM_STACK_H_
