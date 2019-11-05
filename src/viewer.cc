#include "viewer.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "instructions/printer.h"
#include "utils/accessFlags.h"
#include "utils/constantPool.h"
#include "utils/flags.h"
#include "utils/memory.h"
#include "utils/reference_kind.h"
#include "utils/string.h"
#include "utils/versions.h"

static std::ios state(NULL);

static void makeTitle(const std::string &title, const int &size,
                      const int &width, const int &depht = 0) {
  state.copyfmt(std::cout);
  std::cout << std::string(depht, '\t') << std::setfill('*') << std::setw(size)
            << "\n";
  std::cout.copyfmt(state);
  std::cout << std::setw(width) << title << "\n";
  state.copyfmt(std::cout);
  std::cout << std::string(depht, '\t') << std::setfill('*') << std::setw(size)
            << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printClassFile() {
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "\n\tVisualizing ClassFile structure for " << this->classname
              << "\n\n";
  }
  makeTitle("General Information", 80, 50);
  // this->printMagic();
  this->printVersion();
  this->printConstantPoolCount();
  this->printAccessFlags();
  this->printThisClass();
  this->printSuperClass();
  this->printInterfacesCount();
  this->printFieldsCount();
  this->printMethodsCount();
  this->printAttributesCount(0, this->classfile->attributes_count);

  this->printConstantPool();
  this->printInterfaces();
  this->printFields();
  this->printMethods();
  this->printAttributes(this->classfile->attributes,
                        this->classfile->attributes_count, 0, 80, 45);
}

void Viewer::printMagic() {
  state.copyfmt(std::cout);
  std::cout << "Magic: " << std::setw(16) << ' ' << "0x" << std::setfill('0')
            << std::setw(4) << std::hex << std::uppercase
            << this->classfile->magic << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printVersion() {
  state.copyfmt(std::cout);
  std::cout << "Minor version: " << std::setw(8) << ' '
            << this->classfile->minor_version << "\n";
  std::cout << "Major version: " << std::setw(8) << ' '
            << this->classfile->major_version << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printConstantPool() {
  makeTitle("Constant Pool", 80, 45);
  for (int i = 1; i < this->classfile->constant_pool_count; ++i) {
    auto jmpNextIndex = this->printConstantPoolInfo(i, 0);
    if (jmpNextIndex) {
      std::cout << "[" << ++i << "]"
                << " (large numeric continued)\n\n";
    }
  }
}

void Viewer::printConstantPoolCount() {
  state.copyfmt(std::cout);
  std::cout << "Constant Pool Count: " << std::setw(2) << ' '
            << this->classfile->constant_pool_count << "\n";
  std::cout.copyfmt(state);
}

bool Viewer::printConstantPoolInfo(const int index, const int delta_tab) {
  bool jmpNextIndex = false;
  auto kpool = this->classfile->constant_pool;
  auto cpi = this->classfile->constant_pool[index - 1];

  std::cout << std::string(delta_tab, '\t') << "[" << index << "] ";
  auto name = Utils::ConstantPool::getConstantTypename(cpi.base->tag);
  std::cout << "CONSTANT_" << name << "_info\n";

  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<cp::CONSTANT_Class_info>();
      std::cout << kclass_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<cp::CONSTANT_FieldRef_info>();
      std::cout << kfieldref_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<cp::CONSTANT_Methodref_info>();
      std::cout << kmethodref_info->getGeneralInfo(kpool, delta_tab + 1)
                << "\n";
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info =
          cpi.getClass<cp::CONSTANT_InterfaceMethodref_info>();
      std::cout << kImethodref_info->getGeneralInfo(kpool, delta_tab + 1)
                << "\n";
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<cp::CONSTANT_String_info>();
      std::cout << kstring_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<cp::CONSTANT_Integer_info>();
      std::cout << kinteger_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<cp::CONSTANT_Float_info>();
      std::cout << kfloat_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<cp::CONSTANT_Long_info>();
      std::cout << klong_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<cp::CONSTANT_Double_info>();
      std::cout << kdouble_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<cp::CONSTANT_NameAndType_info>();
      std::cout << knametype_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<cp::CONSTANT_Utf8_info>();
      std::cout << kutf8_info->getGeneralInfo(delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_METHODHANDLE: {
      auto kmethodhandle_info = cpi.getClass<cp::CONSTANT_MethodHandle_info>();
      std::cout << kmethodhandle_info->getGeneralInfo(kpool, delta_tab + 1)
                << "\n";
      break;
    }
    case cp::kCONSTANT_METHODTYPE: {
      auto methodtype_info = cpi.getClass<cp::CONSTANT_MethodType_info>();
      std::cout << methodtype_info->getGeneralInfo(kpool, delta_tab + 1)
                << "\n";
      break;
    }
    case cp::kCONSTANT_INVOKEDYNAMIC: {
      auto invokedynamic_info = cpi.getClass<cp::CONSTANT_InvokeDynamic_info>();
      std::cout << invokedynamic_info->getGeneralInfo(kpool, delta_tab + 1)
                << "\n";
      break;
    }
  }
  std::cout << "\n";
  std::cout.clear();

  return jmpNextIndex;
}

std::string Viewer::getConstantPoolInfo(const int &index, const bool &dot) {
  std::stringstream ss;
  if (!index) {
    ss << "invalid constant pool reference";
    return ss.str();
  }
  auto cpi = this->classfile->constant_pool[index - 1];
  auto kpool = this->classfile->constant_pool;

  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<cp::CONSTANT_Class_info>();
      ss << kclass_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<cp::CONSTANT_FieldRef_info>();
      ss << kfieldref_info->getValue(kpool, dot);
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<cp::CONSTANT_Methodref_info>();
      ss << kmethodref_info->getValue(kpool, dot);
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info =
          cpi.getClass<cp::CONSTANT_InterfaceMethodref_info>();
      ss << kImethodref_info->getValue(kpool, dot);
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<cp::CONSTANT_String_info>();
      ss << kstring_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<cp::CONSTANT_Integer_info>();
      ss << kinteger_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<cp::CONSTANT_Float_info>();
      ss << kfloat_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<cp::CONSTANT_Long_info>();
      ss << klong_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<cp::CONSTANT_Double_info>();
      ss << kdouble_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<cp::CONSTANT_NameAndType_info>();
      ss << knametype_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<cp::CONSTANT_Utf8_info>();
      ss << kutf8_info->getValue();
      break;
    }
    case cp::kCONSTANT_METHODHANDLE: {
      auto kmethodhandle_info = cpi.getClass<cp::CONSTANT_MethodHandle_info>();
      ss << kmethodhandle_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_METHODTYPE: {
      auto kmethodtype_info = cpi.getClass<cp::CONSTANT_MethodType_info>();
      ss << kmethodtype_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_INVOKEDYNAMIC: {
      auto kinvokedynamic_info =
          cpi.getClass<cp::CONSTANT_InvokeDynamic_info>();
      ss << kinvokedynamic_info->getValue(kpool);
      break;
    }
  }
  return ss.str();
}

void Viewer::printAccessFlags() {
  auto flags = Utils::Access::getClassAccessType(this->classfile->access_flags);
  state.copyfmt(std::cout);
  std::cout << "Access Flags: " << std::setw(11);
  std::cout << "0x" << std::setfill('0') << std::setw(4) << std::hex
            << std::uppercase << this->classfile->access_flags;
  std::cout.copyfmt(state);
  std::cout << " [";
  for (size_t i = 0; i < flags.size(); ++i) {
    std::cout << flags[i] << (i < flags.size() - 1 ? " " : "");
  }
  std::cout << "]\n";
}

void Viewer::printThisClass() {
  std::cout << "This class: " << std::setw(11) << ' ' << "#"
            << this->classfile->this_class << " ";
  std::cout << "<"
            << this->getConstantPoolInfo(this->classfile->this_class, false)
            << ">\n";
}

void Viewer::printSuperClass() {
  std::cout << "Super class: " << std::setw(10) << ' ' << "#"
            << this->classfile->super_class << " ";
  std::cout << "<"
            << this->getConstantPoolInfo(this->classfile->super_class, false)
            << ">\n";
}

void Viewer::printInterfaces() {
  makeTitle("Interfaces", 80, 40);
  for (auto i = 0; i < this->classfile->interfaces_count; ++i) {
    this->printInterfaceInfo(i, 1);
  }
}

void Viewer::printInterfacesCount() {
  state.copyfmt(std::cout);
  std::cout << "Interfaces Count: " << std::setw(6)
            << this->classfile->interfaces_count << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printInterfaceInfo(const int &index, const int &tab_shift) {
  auto interfaceidx = this->classfile->interfaces[index];
  std::cout << std::string(tab_shift, '\t') << "Interface " << index << "\n";
  std::cout << std::string(tab_shift + 1, '\t') << "Interface: #"
            << interfaceidx << " ";
  std::cout << "<" << this->getConstantPoolInfo(interfaceidx, false) << ">\n";
}

void Viewer::printFields() {
  makeTitle("Fields", 80, 35);
  for (auto i = 0; i < this->classfile->fields_count; ++i) {
    this->printFieldInfo(i, 1);
  }
}

void Viewer::printFieldsCount() {
  state.copyfmt(std::cout);
  std::cout << "Fields Count: " << std::setw(10)
            << this->classfile->fields_count << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printFieldInfo(const int &index, const int &tab_shift) {
  auto field = this->classfile->fields[index];
  std::cout << std::string(tab_shift, '\t') << "[" << index << "] ";
  std::cout << this->getConstantPoolInfo(field.name_index, false) << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Name: #" << field.name_index
            << " ";
  std::cout << "<" << this->getConstantPoolInfo(field.name_index, false)
            << ">\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Descriptor: #"
            << field.descriptor_index << " ";
  std::cout << "<" << this->getConstantPoolInfo(field.descriptor_index, false)
            << ">\n"
            << std::string(tab_shift + 1, '\t')
            << Utils::Access::getAccessFlags(field.access_flags,
                                             Utils::Access::getFieldAccessType);

  this->printAttributes(field.attributes, field.attributes_count, tab_shift + 1,
                        20, 30);
}

void Viewer::printMethods() {
  makeTitle("Methods", 80, 45);
  for (auto i = 0; i < this->classfile->methods_count; ++i) {
    this->printMethodInfo(i, 1);
  }
}

void Viewer::printMethodsCount() {
  state.copyfmt(std::cout);
  std::cout << "Methods Count: " << std::setw(9)
            << this->classfile->methods_count << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printMethodInfo(const int &index, const int &tab_shift) {
  auto method = this->classfile->methods[index];
  std::cout << std::string(tab_shift, '\t') << "[" << index << "] ";
  std::cout << this->getConstantPoolInfo(method.name_index, false) << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Name: #"
            << method.name_index << " ";
  std::cout << "<" << this->getConstantPoolInfo(method.name_index, false)
            << ">\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Descriptor: #"
            << method.descriptor_index << " ";
  std::cout << "<" << this->getConstantPoolInfo(method.descriptor_index, false)
            << ">\n"
            << std::string(tab_shift + 1, '\t')
            << Utils::Access::getAccessFlags(
                   method.access_flags, Utils::Access::getMethodAccessType);

  this->printAttributes(method.attributes, method.attributes_count,
                        tab_shift + 1, 20, 30);
}

void Viewer::printAttributes(
    const std::vector<Utils::Attributes::attribute_info> &attributes,
    const int &attr_count, const int &tab_shift, const int &qtd_stars,
    const int &width_shift) {
  if (!attr_count) {
    return;
  }
  makeTitle("Attributes", qtd_stars, width_shift, tab_shift);
  for (auto i = 0; i < attr_count; ++i) {
    auto attr = attributes[i];
    this->printAttributeInfo(&attr, i, tab_shift + 1);
  }
}

void Viewer::printAttributesCount(const int &tab_shift, const int &attr_count) {
  state.copyfmt(std::cout);
  std::cout << std::string(tab_shift, '\t')
            << "Attributes Count: " << std::setw(6) << attr_count << "\n";
  std::cout.copyfmt(state);
}

std::string Viewer::getAttributeHeader(
    const Utils::Attributes::attribute_info *attr, const int &tab_shift) {
  std::stringstream ss;
  ss << std::string(tab_shift, '\t') << "Generic Info: \n";
  ss << std::string(tab_shift + 1, '\t') << "Attribute name index: #"
     << attr->base->attribute_name_index << " ";
  auto name =
      this->classfile->constant_pool[attr->base->attribute_name_index - 1]
          .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>();
  ss << "<" << name->getValue() << ">\n";

  ss << std::string(tab_shift + 1, '\t')
     << "Attribute length: " << attr->base->attribute_length << "\n";

  return ss.str();
}

void Viewer::printAttributeInfo(
    const Utils::Attributes::attribute_info *attribute, const int &index,
    const int &tab_shift) {
  auto kpool = this->classfile->constant_pool;
  auto kutf8_info = kpool[attribute->base->attribute_name_index - 1]
                        .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>();
  auto attr_name = Utils::String::getUtf8Modified(kutf8_info);

  std::cout << std::string(tab_shift, '\t') << "[" << index << "] " << attr_name
            << "\n";

  std::cout << this->getAttributeHeader(attribute, tab_shift + 1);
  std::cout << std::string(tab_shift + 1, '\t') << "Specific Info: \n";

  auto attrtype = Utils::Attributes::getAttributeType(attr_name);
  switch (attrtype) {
    namespace attrs = Utils::Attributes;
    case attrs::kCONSTANTVALUE: {
      auto kval_attr = attribute->getClass<attrs::ConstantValue_attribute>();
      std::cout << kval_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kCODE: {
      auto code_attr = attribute->getClass<attrs::Code_attribute>();
      std::cout << code_attr->getSpecificInfo(this, this->classfile,
                                              tab_shift + 2);
      this->printAttributes(code_attr->attributes, code_attr->attributes_count,
                            tab_shift + 1, 20, 47);
      break;
    }
    case attrs::kEXCEPTIONS: {
      auto exception_attr = attribute->getClass<attrs::Exceptions_attribute>();
      std::cout << exception_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kINNERCLASSES: {
      auto innerclass_attr =
          attribute->getClass<attrs::InnerClasses_attribute>();
      std::cout << innerclass_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kENCLOSINGMETHOD: {
      auto enclosing_attr =
          attribute->getClass<attrs::EnclosingMethod_attribute>();
      std::cout << enclosing_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kSIGNATURE: {
      auto signature_attr = attribute->getClass<attrs::Signature_attribute>();
      std::cout << signature_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kSOURCEFILE: {
      auto sourcefile_attr = attribute->getClass<attrs::SourceFile_attribute>();
      std::cout << sourcefile_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kLINENUMBERTABLE: {
      auto lnt_attr = attribute->getClass<attrs::LineNumberTable_attribute>();
      std::cout << lnt_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kLOCALVARIABLETABLE: {
      auto localvar_attr =
          attribute->getClass<attrs::LocalVariableTable_attribute>();
      std::cout << localvar_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kBOOTSTRAPMETHODS: {
      auto bootstrap_attr =
          attribute->getClass<attrs::BootstrapMethods_attribute>();
      std::cout << bootstrap_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kMETHODPARAMETERS: {
      auto methodparams_attr =
          attribute->getClass<attrs::MethodParameters_attribute>();
      std::cout << methodparams_attr->getSpecificInfo(kpool, tab_shift + 2);
      break;
    }
    case attrs::kINVALID: {
      auto knotimplemented = attribute->getClass<attrs::NotImplemented>();
      std::cout << knotimplemented->getSpecificInfo(tab_shift + 2);
      break;
    }
  }
}
