#ifndef INCLUDE_UTILS_NUM2STR_H_
#define INCLUDE_UTILS_NUM2STR_H_

#include <sstream>
#include <string>

namespace Utils {
template <typename T>
inline std::string to_string(const T &num) {
  std::ostringstream ss;
  ss << num;
  return ss.str();
}
}  // namespace Utils

#endif  // INCLUDE_UTILS_NUM2STR_H_
