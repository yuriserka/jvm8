#ifndef INCLUDE_UTILS_VERSIONS_H_
#define INCLUDE_UTILS_VERSIONS_H_

#include <string>
#include "utils/types.h"

namespace Utils {
namespace Versions {
std::string getVersion(const Types::u2 &major_version);

inline const Types::u2 getJava8version() { return 0x34; }
}  // namespace Versions
}  // namespace Utils

#endif  // INCLUDE_UTILS_VERSIONS_H_
