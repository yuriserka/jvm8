#ifndef INCLUDE_UTILS_OBJECT_H_
#define INCLUDE_UTILS_OBJECT_H_

#include <map>
#include "utils/array_t.h"
#include "utils/external/any.h"
#include "utils/field_t.h"
#include "utils/reference_kind.h"

// java/lang/String
// java/lang/Object
// [...
namespace Utils {
struct Object {
  Object() = default;

  ~Object() {
    if (this->data.is<Array_t *>()) {
      delete this->data.as<Array_t *>();
    }
  }

  template <typename T>
  Object(T v) {
    this->data = v;
  }

  template <typename T>
  Object(T v, int ref_type) {
    this->data = v;
    this->type = ref_type;
  }

  void addField(const std::string &field_name, const Field_t &f) {
    this->fields[field_name] = f;
  }

  int type;
  Any data;
  std::map<std::string, Field_t> fields;
};
}  // namespace Utils

#endif  // INCLUDE_UTILS_OBJECT_H_
