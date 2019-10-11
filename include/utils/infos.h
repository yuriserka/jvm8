#ifndef INCLUDE_UTILS_INFOS_H_
#define INCLUDE_UTILS_INFOS_H_

#include <vector>
#include "utils/attributes.h"
#include "utils/types.h"

namespace types = Utils::Types;

namespace Utils {
namespace Infos {
struct field_info {
  field_info() = default;

  ~field_info() = default;

  Utils::Types::u2 access_flags;
  Utils::Types::u2 name_index;
  Utils::Types::u2 descriptor_index;
  Utils::Types::u2 attributes_count;
  std::vector<Utils::Attributes::attribute_info> attributes;
};

struct method_info {
  method_info() = default;

  ~method_info() = default;

  Utils::Types::u2 access_flags;
  Utils::Types::u2 name_index;
  Utils::Types::u2 descriptor_index;
  Utils::Types::u2 attributes_count;
  std::vector<Utils::Attributes::attribute_info> attributes;
};
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_UTILS_INFOS_H_
