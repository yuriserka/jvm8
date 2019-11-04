#ifndef INCLUDE_UTILS_OBJECT_H_
#define INCLUDE_UTILS_OBJECT_H_

#include <ostream>

namespace Utils {
class Object {
 public:
  template <typename T>
  Object() {
    this->v = T();
  }
  template <typename T>
  Object(T v) {
    this->v = v;
  }
  void *v;

  friend std::ostream &operator<<(std::ostream &out, const Object &a) {
    return out << a.v;
  }
};
}  // namespace Utils

// Any a = Object<double>(54.55521);
//   std::cout << a.is<Object<double>>() << "  " << a.as<Object<double>>() <<
//   "\n";

#endif  // INCLUDE_UTILS_OBJECT_H_
