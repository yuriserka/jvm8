#ifndef INCLUDE_UTILS_MEMORY_AREAS_THREAD_H_
#define INCLUDE_UTILS_MEMORY_AREAS_THREAD_H_

#include "utils/memory_areas/java_stack.h"

namespace MemoryAreas {

class Heap;
class MethodArea;

class Thread {
 public:
  Thread(MethodArea *method_area, Heap *heap, const ClassFile *cf) {
    this->method_area = method_area;
    this->heap = heap;
    this->current_class = cf;
    this->current_frame = nullptr;
  }

  void executeMethod(const std::string &method_name,
                     const std::string &descriptor,
                     const bool &popObjectRef = false);

  void changeContext(const std::string &classname, const std::string &method,
                     const std::string &arguments, const bool &popObjectRef);

  void storeArguments(const std::string &args, Utils::Frame *new_frame,
                      const bool &popObjectRef);

  template <typename T>
  void pushReturnValue(const T &val) {
    auto curr_frame = this->jvm_stack.top();
    this->jvm_stack.pop();
    auto caller_frame = this->jvm_stack.top();
    caller_frame->pushOperand<T>(val);
    this->jvm_stack.push(curr_frame);
  }

  MethodArea *method_area;
  Heap *heap;
  Utils::Frame *current_frame;

 private:
  const ClassFile *current_class;
  JavaStack jvm_stack;

  std::string current_method;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_THREAD_H_
