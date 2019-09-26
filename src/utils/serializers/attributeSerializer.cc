#include "utils/serializers/attributeSerializer.h"

#include "utils/serializers/infoSerializer.h"
#include "utils/utf8.h"

namespace Utils {
namespace Attributes {
static void create_json_str(json *j, const ConstantValue_attribute *kval_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {
            {"cp_entry_index", kval_attr->attribute_name_index},
            {"info", {}}
          }
        },
        {"length", kval_attr->attribute_length}
      }
    },
    {"specific info", {
          {"constant value", {
            {"cp_entry_index", kval_attr->constantvalue_index},
            {"info", {}}
          }
        }
      }
    },
  };
  // clang-format on
}

// static void create_json_str(json *j, const Code_attribute *code_attr) {
//   // clang-format off
//   *j = {
//     {"generic info", {
//         {"name", {
//             {"cp_entry_index", code_attr->attribute_name_index},
//             {"info", {}}
//           }
//         },
//         {"length", code_attr->attribute_length}
//       }
//     },
//     {"specific info", {
//           {"Bytecode", {
//             {"cp_entry_index", kval_attr->constantvalue_index},
//             {"info", {}}
//           }
//         }
//       }
//     },
//   };
//   // clang-format on
// }

void AttributeSerializer::to_json(json *j, const int &attrindex) {
  auto is = Utils::Infos::Serializer(this->cf);
  auto attr = this->attrs[attrindex];

  auto utf8nameindex =
      this->cf->constant_pool[attr.base->attribute_name_index - 1];
  auto kutf8 = utf8nameindex.getClass<Utils::Infos::CONSTANT_Utf8_info>();
  auto attrName = Utf8(kutf8);
  auto attrtype = getAttributeType(attrName.str);

  switch (attrtype) {
    case kCONSTANTVALUE: {
      auto kval = attr.getClass<ConstantValue_attribute>();
      create_json_str(j, kval);
      is.kPoolInfo_to_JSON(&(*j).at("/generic info/name/info"_json_pointer),
                           kval->attribute_name_index - 1);
      is.kPoolInfo_to_JSON(
          &(*j).at("/specific info/constant value/info"_json_pointer),
          kval->constantvalue_index - 1);
      break;
    }
    default:
      break;
  }
}
}  // namespace Attributes
}  // namespace Utils
