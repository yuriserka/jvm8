#ifndef INCLUDE_UTILS_UTF8_H_
#define INCLUDE_UTILS_UTF8_H_

#include <iostream>
#include <string>
#include "utils/constantpool.h"

class Utf8 {
 public:
  explicit Utf8(const Utils::ConstantPool::CONSTANT_Utf8_info *kutf8Info);

  explicit Utf8(const std::string &str) {
    this->str = std::wstring(str.begin(), str.end());
  }

  friend std::wostream &operator<<(std::wostream &out, const Utf8 &str) {
    out << str.toString();
    return out;
  }

  inline friend const bool operator==(const Utf8 &lhs, const Utf8 &rhs) {
    return lhs.str.compare(rhs.toString()) == 0 ? true : false;
  }

  inline friend const bool operator<(const Utf8 &lhs, const Utf8 &rhs) {
    return lhs.str.compare(rhs.toString()) < 0 ? true : false;
  }

  inline friend const bool operator>(const Utf8 &lhs, const Utf8 &rhs) {
    return lhs.str.compare(rhs.toString()) > 0 ? true : false;
  }

  const wchar_t *toString() const { return str.c_str(); }

  std::wstring str;
};

#endif  // INCLUDE_UTILS_UTF8_H_
