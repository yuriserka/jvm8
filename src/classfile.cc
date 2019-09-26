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
      case cp::kCONSTANT_CLASS:
        cpi.deleteclass<info::CONSTANT_Class_info>();
        break;
      case cp::kCONSTANT_DOUBLE:
        cpi.deleteclass<info::CONSTANT_Double_info>();
        ++i;
        break;
      case cp::kCONSTANT_FIELDREF:
        cpi.deleteclass<info::CONSTANT_FieldRef_info>();
        break;
      case cp::kCONSTANT_FLOAT:
        cpi.deleteclass<info::CONSTANT_Float_info>();
        break;
      case cp::kCONSTANT_INTEGER:
        cpi.deleteclass<info::CONSTANT_Integer_info>();
        break;
      case cp::kCONSTANT_INTERFACEMETHODREF:
        cpi.deleteclass<info::CONSTANT_InterfaceMethodref_info>();
        break;
      case cp::kCONSTANT_LONG:
        cpi.deleteclass<info::CONSTANT_Long_info>();
        ++i;
        break;
      case cp::kCONSTANT_METHODREF:
        cpi.deleteclass<info::CONSTANT_Methodref_info>();
        break;
      case cp::kCONSTANT_NAMEANDTYPE:
        cpi.deleteclass<info::CONSTANT_NameAndType_info>();
        break;
      case cp::kCONSTANT_STRING:
        cpi.deleteclass<info::CONSTANT_String_info>();
        break;
      case cp::kCONSTANT_UTF8:
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
      case attrs::kCODE: {
        auto code_attr = attr.getClass<attrs::Code_attribute>();
        this->deleteAttributes(&code_attr->attributes);
        attr.deleteclass<attrs::Code_attribute>();
        break;
      }
      case attrs::kCONSTANTVALUE:
        attr.deleteclass<attrs::ConstantValue_attribute>();
        break;
      case attrs::kDEPRECATED:
        attr.deleteclass<attrs::Deprecated_attribute>();
        break;
      case attrs::kEXCEPTIONS:
        attr.deleteclass<attrs::Exceptions_attribute>();
        break;
      case attrs::kLINENUMBERTABLE:
        attr.deleteclass<attrs::LineNumberTable_attribute>();
        break;
      case attrs::kLOCALVARIABLETABLE:
        attr.deleteclass<attrs::LocalVariableTable_attribute>();
        break;
      case attrs::kSOURCEFILE:
        attr.deleteclass<attrs::SourceFile_attribute>();
        break;
    }
  }
}
