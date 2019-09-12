#ifndef INCLUDE_UTILS_ACCESSFLAGS_H_
#define INCLUDE_UTILS_ACCESSFLAGS_H_

#include "utils/types.h"
#include <string>
#include <vector>

namespace Utils {
namespace Access {
enum {
    ACC_PUBLIC = 0x0001,
    ACC_FINAL = 0x0010,
    ACC_SUPER = 0x0020,
    ACC_INTERFACE = 0x0200,
    ACC_ABSTRACT = 0x0400,
    ACC_SYNTHETIC = 0x1000,
    ACC_ANNOTATION = 0x2000,
    ACC_ENUM = 0x4000
};

std::vector<std::string> getClassAccessType(const Utils::Types::u2 &accessType);
} // namespace Access
} // namespace Utils

#endif // INCLUDE_UTILS_ACCESSFLAGS_H_