#ifndef INCLUDE_VERSIONS_H_
#define INCLUDE_VERSIONS_H_

#include <string>
#include "utils/types.h"

namespace Utils {
namespace Versions {
std::string getVersion(const Utils::Types::u2 &major_version);
const Utils::Types::u2 Java8 = 0x34;
}  // namespace Versions
}  // namespace Utils

#endif  // INCLUDE_VERSIONS_H_
