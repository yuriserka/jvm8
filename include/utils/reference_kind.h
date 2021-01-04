#ifndef INCLUDE_UTILS_REFERENCE_KIND_H_
#define INCLUDE_UTILS_REFERENCE_KIND_H_

#include <string>

#include "utils/types.h"

namespace Utils {
namespace Reference {
std::string getReferenceType(const Types::u2 &ref_index);

enum reftypes {
  kREF_getField = 1,
  kREF_getStatic,
  kREF_putField,
  kREF_putStatic,
  kREF_invokeVirtual,
  kREF_invokeStatic,
  kREF_invokeSpecial,
  kREF_newInvokeSpecial,
  kREF_invokeInterface
};

enum objectref_types {
  kREF_NULL,
  kREF_STRING,
  kREF_CLASS,
  kREF_STRINGBUILDER,
  kREF_ARRAY
};

enum string_types { kSTR_STR, kSTR_STRINGBUILDER, kSTR_INT };

enum array_types {
  kT_BOOLEAN = 4,
  kT_CHAR = 5,
  kT_FLOAT = 6,
  kT_DOUBLE = 7,
  kT_BYTE = 8,
  kT_SHORT = 9,
  kT_INT = 10,
  kT_LONG = 11
};
}  // namespace Reference
}  // namespace Utils

#endif  // INCLUDE_UTILS_REFERENCE_KIND_H_
