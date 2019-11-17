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

  template <typename T>
  void insert(const T &value, int index) {
    this->items[index] = value;
    ++this->len;
  }

  int length() { return this->len; }

  template <typename T>
  T at(const int &index) {
    return this->items[index];
  }

 private:
  int len = 0;
  int max_length;
  int type;
  std::vector<Any> items;
};
}  // namespace Utils

#endif  // INCLUDE_UTILS_ARRAY_T_H_
