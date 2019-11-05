#ifndef INCLUDE_UTILS_STRING_H_
#define INCLUDE_UTILS_STRING_H_

#include <codecvt>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

// #include "utils/constantPool.h"

namespace Utils {

namespace ConstantPool {
// forward declaration
class CONSTANT_Utf8_info;
}  // namespace ConstantPool

namespace String {
template <typename T>
inline std::string toString(const T &num) {
  std::ostringstream ss;
  ss << num;
  return ss.str();
}

inline std::wstring toWString(const std::string &str) {
  using convert_typeX = std::codecvt_utf8<wchar_t>;
  std::wstring_convert<convert_typeX, wchar_t> converterX;

  return converterX.from_bytes(str);
}

std::string getUtf8Modified(const ConstantPool::CONSTANT_Utf8_info *kutf8Info);

std::vector<std::string> split(const std::string &s, char delimiter);
}  // namespace String
}  // namespace Utils

#endif  // INCLUDE_UTILS_STRING_H_
