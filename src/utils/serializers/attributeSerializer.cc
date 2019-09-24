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

/**
 *
 * Precisa arrumar um lugar pra colocar essa função, uma vez q ela também é
 * usada no viewer.cc. Tava com preguiça de colocar no attributes.h pq tava
 * dando dependencia circular, mas vai ter que quebrar a cabeça e arrumar.
 *
 * */
static int getAttributeType(const Utf8 &attrname) {
  std::map<Utf8, int> attrTypes = {
      {Utf8("Code"), Utils::Attributes::kCODE},
      {Utf8("ConstantValue"), Utils::Attributes::kCONSTANTVALUE},
      {Utf8("Deprecated"), Utils::Attributes::kDEPRECATED},
      {Utf8("Exceptions"), Utils::Attributes::kEXCEPTIONS},
      {Utf8("LineNumberTable"), Utils::Attributes::kLINENUMBERTABLE},
      {Utf8("LocalVariableTable"), Utils::Attributes::kLOCALVARIABLETABLE},
      {Utf8("SourceFile"), Utils::Attributes::kSOURCEFILE}};

  try {
    auto type = attrTypes.at(attrname);
    return type;
  } catch (const std::exception &e) {
    //   std::stringstream err;
    // err << "Invalid Attribute";
    // throw Utils::Errors::Exception(Utils::Errors::kATTRIBUTE, err.str());
    return Utils::Attributes::kINVALID;
  }
}

void AttributeSerializer::to_json(json *j, const int &attrindex) {
  auto is = Utils::Infos::Serializer(this->cf);
  auto attr = this->attrs[attrindex];

  auto utf8nameindex =
      this->cf->constant_pool[attr.base->attribute_name_index - 1];
  auto kutf8 = utf8nameindex.getClass<Utils::Infos::CONSTANT_Utf8_info>();
  auto attrName = Utf8(kutf8);
  auto attrtype = getAttributeType(attrName);

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
