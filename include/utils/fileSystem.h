#ifndef INCLUDE_UTILS_FILESYSTEM_H_
#define INCLUDE_UTILS_FILESYSTEM_H_

#include <dirent.h>
#include <string>
#include <vector>
#include "utils/errors.h"

namespace Utils {
namespace FileSystem {

inline void makeDirectory(const std::string &path) {
  std::string comando;
#if defined(_WIN32) || defined(WIN32)
  comando = "cmd /C create_dir.bat " + path;
#else
  comando = "mkdir -p " + path;
#endif
  auto ret = system(comando.c_str());
  if (ret == -1) {
    throw Errors::Exception(Errors::kMKDIR, "Error creating directory " + path);
  }
}

inline std::vector<std::string> getFileNames(const std::string &path) {
  struct dirent *entry;
  DIR *dir = opendir(path.c_str());

  if (!dir) {
    throw Errors::Exception(Errors::kLS,
                            "Error getting files of directory " + path);
  }
  std::vector<std::string> files;
  while ((entry = readdir(dir)) != NULL) {
    auto f = std::string(entry->d_name);

    auto extension_delim = f.find_last_of('.') != std::string::npos;
    if (!extension_delim) {
      continue;
    }

    std::string extension_name = f.substr(f.find_last_of('.') + 1, f.length());
    if (extension_name.empty()) {
      continue;
    }

    if (!extension_name.compare("class")) {
      files.push_back(entry->d_name);
    }
  }
  closedir(dir);

  return files;
}
}  // namespace FileSystem
}  // namespace Utils

#endif  // INCLUDE_UTILS_FILESYSTEM_H_
