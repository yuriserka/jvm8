#ifndef INCLUDE_UTILS_FIELD_T_H_
#define INCLUDE_UTILS_FIELD_T_H_

#include "utils/array_t.h"
#include "utils/external/any.h"

namespace Utils {
struct Field_t {
  Field_t() = default;

  Field_t(Any v) { this->data = v; }

  ~Field_t() {
    if (this->data.is<Array_t *>()) {
      delete this->data.as<Array_t *>();
    }
  }

  Any data;
};
}  // namespace Utils

#endif  // INCLUDE_UTILS_FIELD_T_H_
