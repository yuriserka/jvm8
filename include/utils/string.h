#ifndef INCLUDE_UTILS_STRING_H_
#define INCLUDE_UTILS_STRING_H_

#include <codecvt>
#include <locale>
#include <sstream>
#include <string>

namespace Utils {
namespace String {
template <typename T>
inline std::string to_string(const T &num) {
  std::ostringstream ss;
  ss << num;
  return ss.str();
}

inline std::string to_string(const std::wstring &wstr) {
  using convert_typeX = std::codecvt_utf8<wchar_t>;
  std::wstring_convert<convert_typeX, wchar_t> converterX;

  return converterX.to_bytes(wstr);
}

inline std::wstring to_wide(const std::string &str) {
  using convert_typeX = std::codecvt_utf8<wchar_t>;
  std::wstring_convert<convert_typeX, wchar_t> converterX;

  return converterX.from_bytes(str);
}
}  // namespace String
}  // namespace Utils

#endif  // INCLUDE_UTILS_STRING_H_
