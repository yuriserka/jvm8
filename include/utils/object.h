#ifndef INCLUDE_UTILS_OBJECT_H_
#define INCLUDE_UTILS_OBJECT_H_

#include <ostream>
#include "utils/external/any.h"
#include "utils/reference_kind.h"

namespace Utils {
class Object {
 public:
  Object() {
    this->type = Reference::objectref_types::kREF_NULL;
    this->data = Any();
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

// Any a = Object<double>(54.55521);
//   std::cout << a.is<Object<double>>() << "  " << a.as<Object<double>>() <<
//   "\n";

#endif  // INCLUDE_UTILS_OBJECT_H_
