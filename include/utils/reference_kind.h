#ifndef INCLUDE_UTILS_REFERENCE_KIND_H_
#define INCLUDE_UTILS_REFERENCE_KIND_H_

#include <string>
#include "utils/types.h"

namespace Utils {
namespace Reference {
std::string getReferenceType(const Utils::Types::u2 &ref_index);

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
}  // namespace Reference
}  // namespace Utils

#endif  // INCLUDE_UTILS_REFERENCE_KIND_H_
