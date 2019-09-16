#ifndef INCLUDE_UTILS_UTF8_H_
#define INCLUDE_UTILS_UTF8_H_

#include <iostream>
#include "utils/infos.h"

class Utf8 {
 public:
  explicit Utf8(const Utils::Infos::CONSTANT_Utf8_info *kutf8Info);

  friend std::wostream &operator<<(std::wostream &out, const Utf8 &str) {
    out << str.toString();
    return out;
  }

  const wchar_t *toString() const { return str.c_str(); }

 private:
  std::wstring str;
};

#endif  // INCLUDE_UTILS_UTF8_H_
