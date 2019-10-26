#include "utils/serializers/methodSerializer.h"

#include "utils/accessFlags.h"
#include "utils/serializers/attributeSerializer.h"
#include "utils/serializers/constpoolSerializer.h"

namespace Utils {
namespace Infos {
static void create_json_str(json *j, const method_info &method) {
  std::stringstream ss;
  ss << "0x" << std::setfill('0') << std::setw(4) << std::hex << std::uppercase
     << method.access_flags;
  // clang-format off
  *j = {
    {"name", {
        {"cp_entry_index", method.name_index}
      }
    },
    {"descriptor", {
        {"cp_entry_index", method.descriptor_index}
      }
    },
    {"access flags", {
        {"bytes", ss.str()},
        {"values", Access::getMethodAccessType(method.access_flags)}
      }
    },
    {"attributes", json::array()}
  };
  // clang-format on
}

void MethodSerializer::to_json(json *j, const int &methodindex) {
  auto is = ConstantPool::ConstantPoolSerializer(this->cf);
  method_info method = this->cf->methods[methodindex];
  create_json_str(j, method);
  is.to_json(&(*j).at("/name"_json_pointer), method.name_index - 1);
  is.to_json(&(*j).at("/descriptor"_json_pointer), method.descriptor_index - 1);
  auto as = Attributes::AttributeSerializer(this->cf, method.attributes);
  for (auto i = 0; i < method.attributes_count; ++i) {
    as.to_json(&(*j).at("/attributes"_json_pointer)[i], i);
  }
}
}  // namespace Infos
}  // namespace Utils
