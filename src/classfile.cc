#include "classfile.h"

#include <iomanip>
#include <map>
#include <sstream>
#include "utils/accessFlags.h"
#include "utils/serializers/infoSerializer.h"
#include "utils/utf8.h"
#include "utils/versions.h"

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

void ClassFile::deleteConstantPool() {
  for (int i = 0; i < this->constant_pool_count - 1; ++i) {
    auto cpi = this->constant_pool[i];
    switch (cpi.base->tag) {
      namespace cp = Utils::ConstantPool;
      namespace info = Utils::Infos;
      case cp::CONSTANT_Class:
        cpi.deleteclass<info::CONSTANT_Class_info>();
        break;
      case cp::CONSTANT_Double:
        cpi.deleteclass<info::CONSTANT_Double_info>();
        ++i;
        break;
      case cp::CONSTANT_Fieldref:
        cpi.deleteclass<info::CONSTANT_FieldRef_info>();
        break;
      case cp::CONSTANT_Float:
        cpi.deleteclass<info::CONSTANT_Float_info>();
        break;
      case cp::CONSTANT_Integer:
        cpi.deleteclass<info::CONSTANT_Integer_info>();
        break;
      case cp::CONSTANT_InterfaceMethodref:
        cpi.deleteclass<info::CONSTANT_InterfaceMethodref_info>();
        break;
      case cp::CONSTANT_Long:
        cpi.deleteclass<info::CONSTANT_Long_info>();
        ++i;
        break;
      case cp::CONSTANT_Methodref:
        cpi.deleteclass<info::CONSTANT_Methodref_info>();
        break;
      case cp::CONSTANT_NameAndType:
        cpi.deleteclass<info::CONSTANT_NameAndType_info>();
        break;
      case cp::CONSTANT_String:
        cpi.deleteclass<info::CONSTANT_String_info>();
        break;
      case cp::CONSTANT_Utf8:
        cpi.deleteclass<info::CONSTANT_Utf8_info>();
        break;
    }
  }
}

void ClassFile::deleteFieldsAttributes() {
  for (auto i = 0; i < this->fields_count; ++i) {
    auto field_attrs = this->fields[i].attributes;
    this->deleteAttributes(field_attrs);
  }
}

void ClassFile::deleteMethodsAttributes() {
  for (auto i = 0; i < this->methods_count; ++i) {
    auto method_attrs = this->methods[i].attributes;
    this->deleteAttributes(method_attrs);
  }
}

void ClassFile::deleteAttributes(
    std::vector<Utils::Attributes::attribute_info> &attributes) {
  for (size_t i = 0; i < attributes.size(); ++i) {
    auto attr = attributes[i];
    auto utf8nameindex =
        this->constant_pool[attr.base->attribute_name_index - 1];
    auto kutf8 = utf8nameindex.getClass<Utils::Infos::CONSTANT_Utf8_info>();
    auto attrName = Utf8(kutf8);
    auto attrtype = getAttributeType(attrName);

    switch (attrtype) {
      namespace attrs = Utils::Attributes;
      case attrs::kCODE:
        attr.deleteclass<Utils::Attributes::Code_attribute>();
        break;
      case attrs::kCONSTANTVALUE:
        attr.deleteclass<Utils::Attributes::ConstantValue_attribute>();
        break;
      case attrs::kDEPRECATED:
        attr.deleteclass<Utils::Attributes::Deprecated_attribute>();
        break;
      case attrs::kEXCEPTIONS:
        attr.deleteclass<Utils::Attributes::Exceptions_attribute>();
        break;
      case attrs::kLINENUMBERTABLE:
        attr.deleteclass<Utils::Attributes::LineNumberTable_attribute>();
        break;
      case attrs::kLOCALVARIABLETABLE:
        attr.deleteclass<Utils::Attributes::LocalVariableTable_attribute>();
        break;
      case attrs::kSOURCEFILE:
        attr.deleteclass<Utils::Attributes::SourceFile_attribute>();
        break;
    }
  }
}

// clang-format off
void to_json(json &j, ClassFile *cf) {
  auto is = Utils::Infos::Serializer(cf->constant_pool);
  std::stringstream ss;
  j = json {
    {"magic",  [&ss] (const ClassFile *cf) -> std::string {
        ss << "0x" << std::setfill('0') << std::setw(8) << std::hex
          << std::uppercase << cf->magic;
        auto str = ss.str();
        ss.str(std::string());
        return str;
      }(cf)
    },
    {"version", {
        {"minor", cf->minor_version},
        {"major", cf->major_version},
        {"name", Utils::Versions::getVersion(cf->major_version)}
      }
    },
    {"constant pool", {
        {"count", cf->constant_pool_count},
        {"entries", json::array()}
      }
    },
    {"access flags", {
        {"value", [&ss] (const ClassFile *cf) -> std::string {
            ss << "0x" << std::setfill('0') << std::setw(4) << std::hex
              << std::uppercase << cf->access_flags;
            auto str = ss.str();
            ss.str(std::string());        
            return str;
          }(cf)
        },
        {"flags name", Utils::Access::getClassAccessType(cf->access_flags)}
      }
    },
    {"this class", {}},
    {"super class", {}},
    {"interfaces", {
        {"count", cf->interfaces_count},
        {"indices", cf->interfaces}
      }
    },
    {"fields", {
        {"count", cf->fields_count}
        //, {"entries", cf->fields}
      }
    },
    {"methods", {
        {"count", cf->methods_count}
        //, {"entries", cf->methods}
      }
    },
    {"attributes", {
        {"count", cf->attributes_count}
        //, {"entries", cf->attributes}
      }
    }
  };
  // clang-format on

  Utils::Infos::to_json(j.at("constant pool").at("entries"), is);

  Utils::Infos::to_json(j.at("this class"),
                        cf->constant_pool[cf->this_class - 1]
                            .getClass<Utils::Infos::CONSTANT_Class_info>(),
                        cf->constant_pool);

  Utils::Infos::to_json(j.at("super class"),
                        cf->constant_pool[cf->super_class - 1]
                            .getClass<Utils::Infos::CONSTANT_Class_info>(),
                        cf->constant_pool);
}
