#ifndef INCLUDE_UTILS_ARRAY_T_H_
#define INCLUDE_UTILS_ARRAY_T_H_

#include <stack>
#include <vector>
#include "utils/external/any.h"
#include "utils/reference_kind.h"

namespace Utils {
class Array_t {
 public:
  Array_t(const int &max_len, const int &atype) : items(max_len) {
    this->max_length = max_len;
    this->type = atype;
  }

 private:
  int length;
  int max_length;
  int type;
  std::vector<Any> items;
};
}  // namespace Utils

#endif  // INCLUDE_UTILS_ARRAY_T_H_
