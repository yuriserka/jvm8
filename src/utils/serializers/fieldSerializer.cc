#include "utils/serializers/fieldSerializer.h"

#include "utils/accessFlags.h"
#include "utils/serializers/attributeSerializer.h"
#include "utils/serializers/infoSerializer.h"

namespace Utils {
namespace Infos {
static void create_json_str(json *j, const field_info &field) {
  std::stringstream ss;
  ss << "0x" << std::setfill('0') << std::setw(4) << std::hex << std::uppercase
     << field.access_flags;
  // clang-format off
  *j = {
    {"name", {
        {"cp_entry_index", field.name_index},
        {"info", {}}
      }
    },
    {"descriptor", {
        {"cp_entry_index", field.descriptor_index},
        {"info", {}}
      }
    },
    {"access flags", {
        {"bytes", ss.str()},
        {"values", Utils::Access::getFieldAccessType(field.access_flags)}
      }
    },
    {"attributes", json::array()}
  };
  // clang-format on
}

void FieldSerializer::to_json(json *j, const int &fieldindex) {
  auto is = ConstantPoolSerializer(this->cf);
  field_info field = this->cf->fields[fieldindex];
  create_json_str(j, field);
  is.to_json(&(*j).at("/name/info"_json_pointer), field.name_index - 1);
  is.to_json(&(*j).at("/descriptor/info"_json_pointer),
             field.descriptor_index - 1);
  auto as = Utils::Attributes::AttributeSerializer(this->cf, field.attributes);
  for (auto i = 0; i < field.attributes_count; ++i) {
    as.to_json(&(*j).at("/attributes"_json_pointer)[i], i);
  }
}
}  // namespace Infos
}  // namespace Utils