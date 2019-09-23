#include "viewer.h"

#include <algorithm>
#include <codecvt>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include "utils/accessFlags.h"
#include "utils/constantPool.h"
#include "utils/utf8.h"
#include "utils/versions.h"

static std::ios state(NULL);

void Viewer::printClassFile() {
  std::cout << "\tVisualizing ClassFile structure for " << this->classname
            << "\n";
  this->printMagic();
  this->printVersion();
  this->printConstantPool();
  this->printAccessFlags();
  this->printThisClass();
  this->printSuperClass();
  this->printInterfaces();
  this->printFields();
  this->printMethods();
  this->printAttributes(this->classfile->attributes,
                        this->classfile->attributes_count, 0);
}

void Viewer::printMagic() {
  state.copyfmt(std::cout);
  std::cout << "Magic: '"
            << "0x" << std::setfill('0') << std::setw(4) << std::hex
            << std::uppercase << this->classfile->magic << "'\n";
  std::cout.copyfmt(state);
}

void Viewer::printVersion() {
  std::cout << "Version: '"
            << Utils::Versions::getVersion(this->classfile->major_version)
            << ", " << this->classfile->major_version << "."
            << this->classfile->minor_version << "'\n";
}

void Viewer::printConstantPool() {
  std::cout << "Constant Pool Count: " << this->classfile->constant_pool_count
            << "\n";
  std::cout << "Constant Pool:\n";
  for (int i = 0; i < this->classfile->constant_pool_count - 1; ++i) {
    auto jmpNextIndex = this->printConstantPoolInfo(i, 1, false);
    if (jmpNextIndex) {
      std::cout << std::string(1, '\t') << "cp_info '#" << ++i + 1 << "': ";
      std::cout << "(large numeric continued)\n\n";
    }
  }
}

template <typename T>
void Viewer::printReferences(const T *kinfo, const int &depth,
                             const bool &inner) {
  if (!inner) {
    std::cout << std::string(depth, '\t') << "Class name: "
              << "cp_info '#" << kinfo->class_index << "'\n";
  }
  this->printConstantPoolInfo(kinfo->class_index - 1, depth, true);
  if (!inner) {
    std::cout << std::string(depth, '\t') << "Name and Type Index: "
              << "cp_info '#" << kinfo->name_and_type_index << "'\n";
  }
  this->printConstantPoolInfo(kinfo->name_and_type_index - 1, depth, true);
}

template <typename T, typename U>
static T copyCast(const U *in) {
  T dest;
  std::memcpy(&dest, in, sizeof(U));

  return dest;
}

template <typename T>
void Viewer::print4bytesNumeral(const T *kinfo, const int &depth,
                                const bool &inner) {
  switch (kinfo->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::CONSTANT_Integer: {
      state.copyfmt(std::cout);
      std::cout << std::string(depth, '\t') << "Bytes: '"
                << "0x" << std::setfill('0') << std::setw(4) << std::hex
                << std::uppercase << kinfo->bytes << "'\n";
      std::cout.copyfmt(state);
      std::cout << std::string(depth, '\t') << "Value: '" << kinfo->bytes
                << "'\n";
      break;
    }
    case cp::CONSTANT_Float: {
      state.copyfmt(std::cout);
      std::cout << std::string(depth, '\t') << "Bytes: '"
                << "0x" << std::setfill('0') << std::setw(4) << std::hex
                << std::uppercase << kinfo->bytes << "'\n";
      std::cout.copyfmt(state);
      float f = copyCast<float>(&kinfo->bytes);
      std::cout << std::string(depth, '\t') << "Value: '" << f << "'\n";
      break;
    }
  }
}

template <typename T>
void Viewer::print8bytesNumeral(const T *kinfo, const int &depth,
                                const bool &inner) {
  auto u8val = (static_cast<Utils::Types::u8>(kinfo->high_bytes) << 32 |
                kinfo->low_bytes);
  switch (kinfo->tag) {
    namespace cp = Utils::ConstantPool;
    namespace types = Utils::Types;
    case cp::CONSTANT_Long: {
      std::cout << std::string(depth, '\t') << "High Bytes: '";
      state.copyfmt(std::cout);
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->high_bytes << "'\n";
      std::cout << std::string(depth, '\t') << "Low Bytes: '";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->low_bytes << "'\n";
      std::cout.copyfmt(state);
      std::cout << std::string(depth, '\t') << "Long: '" << u8val << "'\n";
      break;
    }
    case cp::CONSTANT_Double: {
      std::cout << std::string(depth, '\t') << "High Bytes: ";
      state.copyfmt(std::cout);
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->high_bytes << "'\n";
      std::cout << std::string(depth, '\t') << "Low Bytes: ";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->low_bytes << "'\n";
      std::cout.copyfmt(state);
      double d = copyCast<double>(&u8val);
      std::cout << std::string(depth, '\t') << "Double: '" << d << "'\n";
      break;
    }
  }
}

bool Viewer::printConstantPoolInfo(const int &index, const int &depth,
                                   const bool &inner) {
  auto constpool = this->classfile->constant_pool[index];
  bool jmpNextIndex = false;
  if (!inner) {
    std::cout << std::string(depth, '\t') << "cp_info '#" << index + 1 << "': ";
    auto name = Utils::ConstantPool::getConstantTypename(constpool.base->tag);
    std::cout << "CONSTANT_" << name << "_info\n";
  }
  switch (constpool.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::CONSTANT_Class: {
      auto kclass_info = constpool.getClass<info::CONSTANT_Class_info>();
      if (!inner) {
        std::cout << std::string(depth + 1, '\t') << "Name index = 'cp_info #"
                  << kclass_info->name_index << "'\n";
      }
      this->printConstantPoolInfo(kclass_info->name_index - 1,
                                  inner ? depth : depth + 1, true);
      break;
    }
    case cp::CONSTANT_Fieldref: {
      auto kfieldref_info = constpool.getClass<info::CONSTANT_FieldRef_info>();
      this->printReferences(kfieldref_info, depth + 1, inner);
      break;
    }
    case cp::CONSTANT_Methodref: {
      auto kmethodref_info =
          constpool.getClass<info::CONSTANT_Methodref_info>();
      this->printReferences(kmethodref_info, depth + 1, inner);
      break;
    }
    case cp::CONSTANT_InterfaceMethodref: {
      auto kImethodref_info =
          constpool.getClass<info::CONSTANT_InterfaceMethodref_info>();
      this->printReferences(kImethodref_info, depth + 1, inner);
      break;
    }
    case cp::CONSTANT_String: {
      auto kstring_info = constpool.getClass<info::CONSTANT_String_info>();
      if (!inner) {
        std::cout << std::string(depth + 1, '\t') << "String index = 'cp_info #"
                  << kstring_info->string_index << "'\n";
      }
      this->printConstantPoolInfo(kstring_info->string_index - 1,
                                  inner ? depth : depth + 1, true);
      break;
    }
    case cp::CONSTANT_Integer: {
      auto kinteger_info = constpool.getClass<info::CONSTANT_Integer_info>();
      this->print4bytesNumeral(kinteger_info, depth + 1, inner);
      break;
    }
    case cp::CONSTANT_Float: {
      auto kfloat_info = constpool.getClass<info::CONSTANT_Float_info>();
      this->print4bytesNumeral(kfloat_info, depth + 1, inner);
      break;
    }
    case cp::CONSTANT_Long: {
      auto klong_info = constpool.getClass<info::CONSTANT_Long_info>();
      this->print8bytesNumeral(klong_info, depth + 1, inner);
      jmpNextIndex = true;
      break;
    }
    case cp::CONSTANT_Double: {
      auto kdouble_info = constpool.getClass<info::CONSTANT_Double_info>();
      this->print8bytesNumeral(kdouble_info, depth + 1, inner);
      jmpNextIndex = true;
      break;
    }
    case cp::CONSTANT_NameAndType: {
      auto knametype_info =
          constpool.getClass<info::CONSTANT_NameAndType_info>();
      if (!inner) {
        std::cout << std::string(depth + 1, '\t') << "Name index = 'cp_info #"
                  << knametype_info->name_index << "'\n";
      }
      this->printConstantPoolInfo(knametype_info->name_index - 1,
                                  inner ? depth : depth + 1, true);
      if (!inner) {
        std::cout << std::string(depth + 1, '\t')
                  << "Descriptor index = 'cp_info #"
                  << knametype_info->descriptor_index << "'\n";
      }
      this->printConstantPoolInfo(knametype_info->descriptor_index - 1,
                                  inner ? depth : depth + 1, true);
      break;
    }
    case cp::CONSTANT_Utf8: {
      auto kutf8_info = constpool.getClass<info::CONSTANT_Utf8_info>();
      if (!inner) {
        std::cout << std::string(depth + 1, '\t')
                  << "Length of byte array: " << kutf8_info->length << "\n";
        std::cout << std::string(depth + 1, '\t') << "String: ";
      }
      auto utf8string = Utf8(kutf8_info);
      std::cout << (inner ? std::string(depth + 1, '\t') : "");
      std::wcout << L"\"" << utf8string << L"\"\n";
      break;
    }
  }
  if (!inner) std::cout << "\n";
  return jmpNextIndex;
}

template <typename T>
void Viewer::printAccessFlags(const T *obj, const int &depth,
                              std::vector<std::string> (*getAccessTypeFunc)(
                                  const Utils::Types::u2 &accessType)) {
  auto flags = getAccessTypeFunc(obj->access_flags);
  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << "Access Flags: '"
            << "0x" << std::setfill('0') << std::setw(4) << std::hex
            << std::uppercase << obj->access_flags << "' [";
  std::cout.copyfmt(state);
  for (size_t i = 0; i < flags.size(); ++i) {
    std::cout << flags[i] << (i < flags.size() - 1 ? " " : "]\n");
  }
}

void Viewer::printAccessFlags() {
  this->printAccessFlags(this->classfile, 0, Utils::Access::getClassAccessType);
}

void Viewer::printThisClass() {
  std::cout << "This class: \n";
  this->printConstantPoolInfo(this->classfile->this_class - 1, 0, true);
}

void Viewer::printSuperClass() {
  std::cout << "Super class: \n";
  this->printConstantPoolInfo(this->classfile->super_class - 1, 0, true);
}

void Viewer::printInterfaces() {
  std::cout << "Interfaces Count: " << this->classfile->interfaces_count
            << "\n";
  if (!this->classfile->interfaces_count) {
    return;
  }
  std::cout << "Interfaces:\n";
  for (auto i = 0; i < this->classfile->interfaces_count; ++i) {
    this->printInterfacesInfo(i, 1);
  }
}

void Viewer::printInterfacesInfo(const int &index, const int &depth) {
  auto interfaceIdx = this->classfile->interfaces[index];
  std::cout << std::string(depth, '\t') << "interface #" << index
            << " = 'cp_info #" << interfaceIdx << "'\n";
  this->printConstantPoolInfo(interfaceIdx - 1, depth, false);
}

void Viewer::printFields() {
  std::cout << "Fields Count: " << this->classfile->fields_count << "\n";
  if (!this->classfile->fields_count) {
    return;
  }
  std::cout << "Fields:\n";
  for (auto i = 0; i < this->classfile->fields_count; ++i) {
    this->printFieldsInfo(i, 1);
  }
}

void Viewer::printFieldsInfo(const int &index, const int &depth) {
  std::cout << std::string(depth, '\t') << "field #" << index << "\n";
  auto field = this->classfile->fields[index];
  std::cout << std::string(depth + 1, '\t') << "Name index = 'cp_info #"
            << field.name_index << "'\n";
  this->printConstantPoolInfo(field.name_index - 1, 2, true);
  std::cout << std::string(depth + 1, '\t') << "Descriptor index = 'cp_info #"
            << field.descriptor_index << "'\n";
  this->printConstantPoolInfo(field.descriptor_index - 1, 2, true);
  this->printAccessFlags(&field, 2, Utils::Access::getFieldAccessType);
  this->printAttributes(field.attributes, field.attributes_count, 2);
}

void Viewer::printMethods() {
  std::cout << "Methods Count: " << this->classfile->methods_count << "\n";
  if (!this->classfile->methods_count) {
    return;
  }
  std::cout << "Methods:\n";
  for (auto i = 0; i < this->classfile->methods_count; ++i) {
    this->printMethodsInfo(i, 1);
  }
}

void Viewer::printMethodsInfo(const int &index, const int &depth) {
  std::cout << std::string(depth, '\t') << "method #" << index << "\n";
}

void Viewer::printAttributes(
    const std::vector<Utils::Attributes::attribute_info> &attributes,
    const int &attr_count, const int &depth) {
  std::cout << std::string(depth, '\t') << "Attributes Count: " << attr_count
            << "\n";
  if (!attr_count) {
    return;
  }
  std::cout << std::string(depth, '\t') << "Attributes:\n";
  for (auto i = 0; i < attr_count; ++i) {
    auto attr = attributes[i];
    this->printAttributeInfo(attr, i, depth + 1);
  }
}

/**
 *
 * Precisa arrumar um lugar pra colocar essa função, uma vez q ela também é
 * usada no reader.cc. Tava com preguiça de colocar no attributes.h pq tava
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

void Viewer::printAttributeInfo(Utils::Attributes::attribute_info &attribute,
                                const int &index, const int &depth) {
  std::cout << std::string(depth, '\t') << "attribute #" << index << "\n";
  auto utf8nameindex =
      this->classfile->constant_pool[attribute.base->attribute_name_index - 1];
  auto kutf8_info = utf8nameindex.getClass<Utils::Infos::CONSTANT_Utf8_info>();
  auto attrName = Utf8(kutf8_info);
  auto attrtype = getAttributeType(attrName);

  switch (attrtype) {
    namespace attrs = Utils::Attributes;
    case attrs::kCODE: {
      break;
    }
    case attrs::kCONSTANTVALUE: {
      auto kval_attr =
          attribute.getClass<Utils::Attributes::ConstantValue_attribute>();
      std::cout << std::string(depth + 1, '\t') << "Generic Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Attribute name index = 'cp_info #"
                << kval_attr->attribute_name_index << "'\n";
      this->printConstantPoolInfo(kval_attr->attribute_name_index - 1,
                                  depth + 2, true);
      std::cout << std::string(depth + 2, '\t') << "Attribute length = '"
                << kval_attr->attribute_length << "'\n";
      std::cout << std::string(depth + 1, '\t') << "Specific Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Constant Value index = 'cp_info #"
                << kval_attr->constantvalue_index << "'\n";
      this->printConstantPoolInfo(kval_attr->constantvalue_index - 1, depth + 2,
                                  true);
      break;
    }
    case attrs::kDEPRECATED: {
      break;
    }
    case attrs::kEXCEPTIONS: {
      break;
    }
    case attrs::kLINENUMBERTABLE: {
      break;
    }
    case attrs::kLOCALVARIABLETABLE: {
      break;
    }
    case attrs::kSOURCEFILE: {
      break;
    }
  }
}
