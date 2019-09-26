#ifndef INCLUDE_UTILS_CONSTANTPOOL_H_
#define INCLUDE_UTILS_CONSTANTPOOL_H_

#include <string>
#include "utils/types.h"

namespace Utils {
namespace ConstantPool {
enum ConstantTypes {
  kCONSTANT_CLASS = 7,
  kCONSTANT_FIELDREF = 9,
  kCONSTANT_METHODREF = 10,
  kCONSTANT_INTERFACEMETHODREF = 11,
  kCONSTANT_STRING = 8,
  kCONSTANT_INTEGER = 3,
  kCONSTANT_FLOAT = 4,
  kCONSTANT_LONG = 5,
  kCONSTANT_DOUBLE = 6,
  kCONSTANT_NAMEANDTYPE = 12,
  kCONSTANT_UTF8 = 1,
  kCONSTANT_METHODHANDLE = 15,
  kCONSTANT_METHODTYPE = 16,
  kCONSTANT_INVOKEDYNAMIC = 18
};
std::string getConstantTypename(const Utils::Types::u1 &ct);
}  // namespace ConstantPool
}  // namespace Utils

#endif  // INCLUDE_UTILS_CONSTANTPOOL_H_
