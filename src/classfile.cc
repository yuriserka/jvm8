#include "classfile.h"

#include <iomanip>
#include <sstream>
#include "utils/utf8.h"

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
    this->deleteAttributes(&field_attrs);
  }
}

void ClassFile::deleteMethodsAttributes() {
  for (auto i = 0; i < this->methods_count; ++i) {
    auto method_attrs = this->methods[i].attributes;
    this->deleteAttributes(&method_attrs);
  }
}

void ClassFile::deleteAttributes(
    std::vector<Utils::Attributes::attribute_info> *attributes) {
  for (size_t i = 0; i < attributes->size(); ++i) {
    Utils::Attributes::attribute_info attr = attributes->at(i);
    auto utf8nameindex =
        this->constant_pool[attr.base->attribute_name_index - 1];
    auto kutf8 = utf8nameindex.getClass<Utils::Infos::CONSTANT_Utf8_info>();
    auto attrName = Utf8(kutf8);
    auto attrtype = Utils::Attributes::getAttributeType(attrName.str);

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
