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
    namespace err = Utils::Errors;
    throw err::Exception(err::kMKDIR, "Error creating directory " + path);
  }
}

inline std::vector<std::string> getFileNames(const std::string &path) {
  struct dirent *entry;
  DIR *dir = opendir(path.c_str());

  if (!dir) {
    namespace err = Utils::Errors;
    throw err::Exception(err::kLS, "Error getting files of directory " + path);
  }
  std::vector<std::string> files;
  while ((entry = readdir(dir)) != NULL) {
    auto f = std::string(entry->d_name);
    if (!f.substr(f.find_last_of('.'), f.size()).compare(".java")) continue;
    files.push_back(entry->d_name);
  }
  closedir(dir);

  return files;
}
}  // namespace FileSystem
}  // namespace Utils

#endif  // INCLUDE_UTILS_FILESYSTEM_H_
