#ifndef INCLUDE_UTILS_CLASS_T_H_
#define INCLUDE_UTILS_CLASS_T_H_

#include <map>
#include "utils/external/any.h"
#include "utils/field_t.h"
#include "utils/object.h"

namespace Utils {
struct Class_t {
  Class_t() = default;

  Class_t(const std::string &class_name) { this->class_name = class_name; }

  void addField(const Any &val, const std::string &field_name,
                const std::string &descriptor) {
    auto f = Field_t(val);
    if (!descriptor.compare("java/lang/String") ||
        !descriptor.compare("java/lang/Object")) {
      f.data = new Object(val);
    }
    this->fields[field_name] = f;
  }

  Field_t &getField(const std::string &field_name) {
    return this->fields[field_name];
  }

  std::string class_name;
  std::map<std::string, Field_t> fields;
};
}  // namespace Utils

#endif  // INCLUDE_UTILS_CLASS_T_H_
