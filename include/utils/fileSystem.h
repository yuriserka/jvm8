#ifndef INCLUDE_UTILS_FILESYSTEM_H_
#define INCLUDE_UTILS_FILESYSTEM_H_

#include <string>
#include "utils/errors.h"

namespace Utils {
inline void makeDirectory(const std::string &path) {
  std::string comando;
#ifdef _WIN32
  comando = "cmd /C create_dir.bat " + path;
#else
  comando = "mkdir -p " + path;
#endif
  auto ret = system(comando.c_str());
  if (ret == -1) {
    throw Utils::Errors::Exception(Utils::Errors::kMKDIR,
                                   "Error creating directory " + path);
  }
}
}  // namespace Utils

#endif  // INCLUDE_UTILS_FILESYSTEM_H_
