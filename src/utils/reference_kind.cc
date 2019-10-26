#include "utils/reference_kind.h"

#include <map>

namespace Utils {
namespace Reference {
std::string getReferenceType(const Types::u2 &ref_index) {
  std::map<Types::u2, std::string> reftypes = {
      {kREF_getField, "REF_getField"},
      {kREF_getStatic, "REF_getStatic"},
      {kREF_putField, "REF_putField"},
      {kREF_putStatic, "REF_putStatic"},
      {kREF_invokeVirtual, "REF_invokeVirtual"},
      {kREF_invokeStatic, "REF_invokeStatic"},
      {kREF_invokeSpecial, "REF_invokeSpecial"},
      {kREF_newInvokeSpecial, "REF_newInvokeSpecial"},
      {kREF_invokeInterface, "REF_invokeInterface"}};
  return reftypes.at(ref_index);
}
}  // namespace Reference
}  // namespace Utils
