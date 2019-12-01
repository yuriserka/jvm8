#ifndef INCLUDE_UTILS_ARRAY_T_H_
#define INCLUDE_UTILS_ARRAY_T_H_

#include <list>
#include <stack>
#include "utils/external/any.h"
#include "utils/reference_kind.h"

namespace Utils {
class Array_t {
 public:
  Array_t(const int &max_len, const int &atype) : items(max_len) {
    this->max_length = max_len;
    this->type = atype;
  }

  Array_t(const int &max_len) : items(max_len) { this->max_length = max_len; }

  ~Array_t() = default;

  template <typename T>
  void insert(T value, int index) {
    auto element = std::next(this->items.begin(), index);
    *element = value;
  }

  int length() { return this->items.size(); }

  template <typename T>
  T get(const int &index) {
    auto element = std::next(this->items.begin(), index);
    return element->as<T>();
  }

  std::list<Any> getCollection() { return this->items; }

 private:
  int max_length;
  int type;
  std::list<Any> items;
};

class MultiArray_t {
 public:
  MultiArray_t(const int &dims, int *dims_sizes);

  ~MultiArray_t();

  Array_t *arrays;
};
}  // namespace Utils

#endif  // INCLUDE_UTILS_ARRAY_T_H_
