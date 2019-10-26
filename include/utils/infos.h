#ifndef INCLUDE_UTILS_INFOS_H_
#define INCLUDE_UTILS_INFOS_H_

#include <vector>
#include "utils/attributes.h"
#include "utils/types.h"

namespace Utils {
namespace Infos {
struct field_info {
  field_info() = default;

  ~field_info() = default;

  Types::u2 access_flags;
  Types::u2 name_index;
  Types::u2 descriptor_index;
  Types::u2 attributes_count;
  std::vector<Attributes::attribute_info> attributes;
};

struct method_info {
  method_info() = default;

  ~method_info() = default;

  Types::u2 access_flags;
  Types::u2 name_index;
  Types::u2 descriptor_index;
  Types::u2 attributes_count;
  std::vector<Attributes::attribute_info> attributes;
};
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_UTILS_INFOS_H_
