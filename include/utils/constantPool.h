#ifndef INCLUDE_UTILS_CONSTANTPOOL_H_
#define INCLUDE_UTILS_CONSTANTPOOL_H_

#include <string>
#include "utils/types.h"

namespace Utils {
namespace ConstantPool {
enum ConstantTypes {
  CONSTANT_Class = 7,
  CONSTANT_Fieldref = 9,
  CONSTANT_Methodref = 10,
  CONSTANT_InterfaceMethodref = 11,
  CONSTANT_String = 8,
  CONSTANT_Integer = 3,
  CONSTANT_Float = 4,
  CONSTANT_Long = 5,
  CONSTANT_Double = 6,
  CONSTANT_NameAndType = 12,
  CONSTANT_Utf8 = 1,
  CONSTANT_MethodHandle = 15,
  CONSTANT_MethodType = 16,
  CONSTANT_InvokeDynamic = 18
};
std::string getConstantTypename(const Utils::Types::u1 &ct);
}  // namespace ConstantPool
}  // namespace Utils

#endif  // INCLUDE_UTILS_CONSTANTPOOL_H_
