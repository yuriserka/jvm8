#ifndef INCLUDE_UTILS_FILESYSTEM_H_
#define INCLUDE_UTILS_FILESYSTEM_H_

#include <string>
#include "utils/errors.h"

namespace Utils {
inline void makeDirectory(const std::string &path) {
  std::string comando = "mkdir " + path;
  system(comando.c_str());
}
}  // namespace Utils

#endif  // INCLUDE_UTILS_FILESYSTEM_H_
