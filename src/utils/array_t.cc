#include "utils/array_t.h"

#include "utils/errors.h"
#include "utils/object.h"

namespace Utils {
// Array_t::~Array_t() {
//   if (this->items.begin()->is<Object *>()) {
//     this->items.remove_if([](Utils::Object *obj) {
//       delete obj;
//       return true;
//     });
//   }
// }

MultiArray_t::MultiArray_t(const int &dims, int *dims_sizes) {
  this->arrays = new Array_t(dims_sizes[0]);
  for (int i = 0; i < dims - 1; ++i) {
    auto count = dims_sizes[i];
    for (int d = 0; d < count; ++d) {
      auto arrayobj = new Object(
          new Array_t(dims_sizes[i + 1], Utils::Reference::kREF_ARRAY),
          "internal_array");
      this->arrays->insert(arrayobj, d);
    }
  }
}

MultiArray_t::~MultiArray_t() {
  this->arrays->getCollection().remove_if([](Utils::Object *obj) {
    delete obj;
    return true;
  });
  delete this->arrays;
}
}  // namespace Utils
