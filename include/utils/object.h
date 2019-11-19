#ifndef INCLUDE_UTILS_OBJECT_H_
#define INCLUDE_UTILS_OBJECT_H_

#include <ostream>
#include "utils/array_t.h"
#include "utils/external/any.h"
#include "utils/reference_kind.h"

namespace Utils {
class Object {
 public:
  Object() = default;

  ~Object() {
    if (this->data.is<Array_t *>()) {
      delete this->data.as<Array_t *>();
    }
  }

  template <typename T>
  Object(T v, int ref_type) {
    this->data = v;
    this->type = ref_type;
  }

  int type;
  Any data;
};
}  // namespace Utils

#endif  // INCLUDE_UTILS_OBJECT_H_
