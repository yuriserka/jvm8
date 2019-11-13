#ifndef INCLUDE_UTILS_MEMORY_AREAS_JVM_STACK_H_
#define INCLUDE_UTILS_MEMORY_AREAS_JVM_STACK_H_

#include <stack>
#include "utils/frame.h"

namespace MemoryAreas {
class JavaStack {
 public:
  ~JavaStack() {
    while (!this->frames.empty()) {
      this->frames.pop();
    }
  }

  void push(Utils::Frame *frame) { this->frames.push(frame); }

  void pop() { this->frames.pop(); }

  Utils::Frame *top() { return this->frames.top(); }

  size_t size() { return this->frames.size(); }

 private:
  std::stack<Utils::Frame *> frames;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_JVM_STACK_H_
