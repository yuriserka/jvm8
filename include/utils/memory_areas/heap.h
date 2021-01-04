#ifndef INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_
#define INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_

#include <algorithm>
#include <list>
#include <vector>

#include "utils/class_t.h"
#include "utils/helper_functions.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace MemoryAreas {
class Heap {
 public:
  Heap() = default;

  ~Heap() {
    this->object_refs.remove_if([](Utils::Object *obj) {
      delete obj;
      return true;
    });
    this->initialized_classes.remove_if([](Utils::Class_t *classref) {
      delete classref;
      return true;
    });
  }

  void addClass(Thread *th, const std::string &name);

  Utils::Class_t *getClass(const std::string &name) {
    return *std::find_if(this->initialized_classes.begin(),
                         this->initialized_classes.end(),
                         [&name](const Utils::Class_t *c) {
                           return !c->class_name.compare(name);
                         });
  }

  bool isInitialized(const std::string &name) {
    return std::find_if(this->initialized_classes.begin(),
                        this->initialized_classes.end(),
                        [&name](const Utils::Class_t *c) {
                          return !c->class_name.compare(name);
                        }) != this->initialized_classes.end();
  }

  Utils::Object *pushReference(Utils::Object *obj) {
    this->object_refs.push_back(obj);

    auto it = std::next(this->object_refs.begin(), this->last_obj_index++);
    return *it;
  }
  std::list<Utils::Class_t *> initialized_classes;

 private:
  int last_obj_index = 0;
  std::list<Utils::Object *> object_refs;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_HEAP_H_
