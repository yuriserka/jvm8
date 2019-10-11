#ifndef INCLUDE_UTILS_ACCESSFLAGS_H_
#define INCLUDE_UTILS_ACCESSFLAGS_H_

#include <string>
#include <vector>
#include "utils/types.h"

namespace Utils {
namespace Access {
namespace ClassAccess {
enum {
  kACC_PUBLIC = 0x0001,
  kACC_FINAL = 0x0010,
  kACC_SUPER = 0x0020,
  kACC_INTERFACE = 0x0200,
  kACC_ABSTRACT = 0x0400,
  kACC_SYNTHETIC = 0x1000,
  kACC_ANNOTATION = 0x2000,
  kACC_ENUM = 0x4000
};
}  // namespace ClassAccess

namespace FieldAccess {
enum {
  kACC_PUBLIC = 0x0001,
  kACC_PRIVATE = 0x0002,
  kACC_PROTECTED = 0x0004,
  kACC_STATIC = 0x0008,
  kACC_FINAL = 0x0010,
  kACC_VOLATILE = 0x0040,
  kACC_TRANSIENT = 0x0080,
  kACC_SYNTHETIC = 0x1000,
  kACC_ENUM = 0x4000
};
}  // namespace FieldAccess

namespace MethodAccess {
enum {
  kACC_PUBLIC = 0x0001,
  kACC_PRIVATE = 0x0002,
  kACC_PROTECTED = 0x0004,
  kACC_STATIC = 0x0008,
  kACC_FINAL = 0x0010,
  kACC_SYNCHRONIZED = 0x0020,
  kACC_BRIDGE = 0x0040,
  kACC_VARARGS = 0x0080,
  kACC_NATIVE = 0x0100,
  kACC_ABSTRACT = 0x0400,
  kACC_STRICT = 0x0800,
  kACC_SYNTHETIC = 0x1000
};
}  // namespace MethodAccess

namespace NestedClassAccess {
enum {
  kACC_PUBLIC = 0x0001,
  kACC_PRIVATE = 0x0002,
  kACC_PROTECTED = 0x0004,
  kACC_STATIC = 0x0008,
  kACC_FINAL = 0x0010,
  kACC_INTERFACE = 0x0200,
  kACC_ABSTRACT = 0x0400,
  kACC_SYNTHETIC = 0x1000,
  kACC_ANNOTATION = 0x2000,
  kACC_ENUM = 0x4000
};
}  // namespace NestedClassAccess

namespace MethodParamsAccess {
enum { kACC_FINAL = 0x0010, kACC_SYNTHETIC = 0x1000, kACC_MANDATED = 0x8000 };
}  // namespace MethodParamsAccess

std::wstring getAccessFlags(const Utils::Types::u2 &access_flags,
                            std::vector<std::string> (*getAccessTypeFunc)(
                                const Utils::Types::u2 &accessType));
std::vector<std::string> getClassAccessType(const Utils::Types::u2 &accessType);
std::vector<std::string> getFieldAccessType(const Utils::Types::u2 &accessType);
std::vector<std::string> getMethodAccessType(
    const Utils::Types::u2 &accessType);
std::vector<std::string> getNestedClassAccessType(
    const Utils::Types::u2 &accessType);
std::vector<std::string> getMethodParamsAccessType(
    const Utils::Types::u2 &accessType);
}  // namespace Access
}  // namespace Utils

#endif  // INCLUDE_UTILS_ACCESSFLAGS_H_
