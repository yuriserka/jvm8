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
  std::cout << "\n\tVisualizing ClassFile structure for " << this->classname
            << "\n";
  makeTitle("General Information", 80, 50);
  this->printMagic();
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
                        this->classfile->attributes_count, 0);
}

void Viewer::printMagic() {
  state.copyfmt(std::cout);
  std::cout << "Magic: " << std::setw(16) << ' ' << "'0x" << std::setfill('0')
            << std::setw(4) << std::hex << std::uppercase
            << this->classfile->magic << "'\n";
  std::cout.copyfmt(state);
}

void Viewer::printVersion() {
  state.copyfmt(std::cout);
  std::cout << "Minor version: " << std::setw(8) << ' ' << "'"
            << this->classfile->minor_version << "'\n";
  std::cout << "Major version: " << std::setw(8) << ' ' << "'"
            << this->classfile->major_version << "'\n";
  std::cout.copyfmt(state);
}

void Viewer::printConstantPool() {
  makeTitle("Constant Pool", 80, 45);
  for (int i = 0; i < this->classfile->constant_pool_count - 1; ++i) {
    auto jmpNextIndex = this->printConstantPoolInfo(i, 0, false);
    if (jmpNextIndex) {
      std::cout << "[" << ++i + 1 << "]"
                << "(large numeric continued)\n";
    }
  }
}

void Viewer::printConstantPoolCount() {
  state.copyfmt(std::cout);
  std::cout << "Constant Pool Count: " << std::setw(2) << ' ' << "'"
            << this->classfile->constant_pool_count << "'\n";
  std::cout.copyfmt(state);
}

template <typename T>
void Viewer::printReferences(const T *kinfo, const int &depth) {
  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << "Class name: "
            << "'cp_info #" << kinfo->class_index << "' ";
  this->printConstantPoolInfo(kinfo->class_index - 1, 0, true);
  std::cout.copyfmt(state);

  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << "Name and type: "
            << "'cp_info #" << kinfo->name_and_type_index << "' ";

  this->printConstantPoolInfo(kinfo->name_and_type_index - 1, 0, true, true);
  std::cout.copyfmt(state);
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
      std::cout << std::string(depth, '\t') << "Bytes: "
                << "'0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->bytes << "'\n";
      std::cout.copyfmt(state);
      std::cout << std::string(depth, '\t') << "Value: '" << kinfo->bytes
                << "'\n";
      break;
    }
    case cp::CONSTANT_Float: {
      state.copyfmt(std::cout);
      std::cout << std::string(depth, '\t') << "Bytes: "
                << "'0x" << std::setfill('0') << std::setw(8) << std::hex
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
      state.copyfmt(std::cout);
      std::cout << std::string(depth, '\t') << "High Bytes: ";
      std::cout << "'0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->high_bytes << "'\n";

      std::cout << std::string(depth, '\t') << "Low Bytes: ";
      std::cout << "'0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->low_bytes << "'\n";
      std::cout.copyfmt(state);

      std::cout << std::string(depth, '\t') << "Long: '" << u8val << "'\n";
      break;
    }
    case cp::CONSTANT_Double: {
      state.copyfmt(std::cout);
      std::cout << std::string(depth, '\t') << "High Bytes: ";
      std::cout << "'0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->high_bytes << "'\n";

      std::cout << std::string(depth, '\t') << "Low Bytes: ";
      std::cout << "'0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->low_bytes << "'\n";
      std::cout.copyfmt(state);

      double d = copyCast<double>(&u8val);
      std::cout << std::string(depth, '\t') << "Double: '" << d << "'\n";
      break;
    }
  }
}

enum name_and_type_aux_fmt { kNAMETYPEname, kNAMETYPEdesc };

bool Viewer::printConstantPoolInfo(const int &index, const int &depth,
                                   const bool &inner,
                                   const bool &innerNameAndType,
                                   const int &utf8fmt) {
  auto constpool = this->classfile->constant_pool[index];
  bool jmpNextIndex = false;
  if (!inner) {
    std::cout << std::string(depth, '\t') << "[" << index + 1 << "] ";
    auto name = Utils::ConstantPool::getConstantTypename(constpool.base->tag);
    std::cout << "CONSTANT_" << name << "_info\n";
  }
  switch (constpool.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::CONSTANT_Class: {
      auto kclass_info = constpool.getClass<info::CONSTANT_Class_info>();
      if (!inner) {
        std::cout << std::string(depth + 1, '\t') << "Class Name: "
                  << "'cp_info #" << kclass_info->name_index << "' ";
      }
      this->printConstantPoolInfo(kclass_info->name_index - 1,
                                  inner ? depth : depth + 1, true);
      break;
    }
    case cp::CONSTANT_Fieldref: {
      auto kfieldref_info = constpool.getClass<info::CONSTANT_FieldRef_info>();
      this->printReferences(kfieldref_info, depth + 1);
      break;
    }
    case cp::CONSTANT_Methodref: {
      auto kmethodref_info =
          constpool.getClass<info::CONSTANT_Methodref_info>();
      this->printReferences(kmethodref_info, depth + 1);
      break;
    }
    case cp::CONSTANT_InterfaceMethodref: {
      auto kImethodref_info =
          constpool.getClass<info::CONSTANT_InterfaceMethodref_info>();
      this->printReferences(kImethodref_info, depth + 1);
      break;
    }
    case cp::CONSTANT_String: {
      auto kstring_info = constpool.getClass<info::CONSTANT_String_info>();
      if (!inner) {
        std::cout << std::string(depth + 1, '\t') << "String: 'cp_info #"
                  << kstring_info->string_index << "'";
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
        std::cout << std::string(depth + 1, '\t') << "Name: "
                  << "'cp_info #" << knametype_info->name_index << "' ";
        this->printConstantPoolInfo(knametype_info->name_index - 1,
                                    inner ? depth : depth + 1, true);
      } else {
        this->printConstantPoolInfo(knametype_info->name_index - 1,
                                    inner ? depth : depth + 1, true, true,
                                    kNAMETYPEname);
      }
      if (!inner) {
        std::cout << std::string(depth + 1, '\t') << "Descriptor: 'cp_info #"
                  << knametype_info->descriptor_index << "' ";
        this->printConstantPoolInfo(knametype_info->descriptor_index - 1,
                                    inner ? depth : depth + 1, true);
      } else {
        this->printConstantPoolInfo(knametype_info->descriptor_index - 1,
                                    inner ? depth : depth + 1, true, true,
                                    kNAMETYPEdesc);
      }
      break;
    }
    case cp::CONSTANT_Utf8: {
      auto kutf8_info = constpool.getClass<info::CONSTANT_Utf8_info>();
      auto utf8string = Utf8(kutf8_info);
      if (!inner) {
        std::cout << std::string(depth + 1, '\t')
                  << "Length of byte array: " << kutf8_info->length << "\n"
                  << std::string(depth + 1, '\t')
                  << "Length of string: " << utf8string.str.size() << "\n";
        std::cout << std::string(depth + 1, '\t') << "String: ";
      }
      std::wstring toprint = utf8string.str;
      if (innerNameAndType) {
        switch (utf8fmt) {
          case name_and_type_aux_fmt::kNAMETYPEname: {
            toprint = L"<" + toprint + L":";
            break;
          }
          case name_and_type_aux_fmt::kNAMETYPEdesc: {
            toprint += L">";
            break;
          }
          default:
            break;
        }
      } else if (inner) {
        toprint = L"<" + toprint + L">";
      }
      std::wcout << toprint << (innerNameAndType ? "" : "\n");
      break;
    }
  }
  if (!inner) std::cout << "\n";
  return jmpNextIndex;
}

template <typename T>
void Viewer::printAccessFlags(const T *obj, const int &depth, const int &width,
                              std::vector<std::string> (*getAccessTypeFunc)(
                                  const Utils::Types::u2 &accessType)) {
  auto flags = getAccessTypeFunc(obj->access_flags);
  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << "Access Flags: " << std::setw(width);
  std::cout << "'0x" << std::setfill('0') << std::setw(4) << std::hex
            << std::uppercase << obj->access_flags << "'";
  std::cout.copyfmt(state);
  std::cout << " [";
  for (size_t i = 0; i < flags.size(); ++i) {
    std::cout << flags[i] << (i < flags.size() - 1 ? " " : "]\n");
  }
}

void Viewer::printAccessFlags() {
  this->printAccessFlags(this->classfile, 0, 12,
                         Utils::Access::getClassAccessType);
}

void Viewer::printThisClass() {
  state.copyfmt(std::cout);
  std::cout << "This class: " << std::setw(11) << ' ' << "'cp_info #"
            << this->classfile->this_class << "' ";
  this->printConstantPoolInfo(this->classfile->this_class - 1, 0, true);
  std::cout.copyfmt(state);
}

void Viewer::printSuperClass() {
  state.copyfmt(std::cout);
  std::cout << "Super class: " << std::setw(10) << ' ' << "'cp_info #"
            << this->classfile->super_class << "'";
  this->printConstantPoolInfo(this->classfile->super_class - 1, 0, true);
  std::cout.copyfmt(state);
}

void Viewer::printInterfaces() {
  makeTitle("Interfaces", 80, 40);
  if (!this->classfile->interfaces_count) {
    return;
  }
  std::cout << "Interfaces:\n";
  for (auto i = 0; i < this->classfile->interfaces_count; ++i) {
    this->printInterfacesInfo(i, 1);
  }
}

void Viewer::printInterfacesCount() {
  state.copyfmt(std::cout);
  std::cout << "Interfaces Count: " << std::setw(6) << "'"
            << this->classfile->interfaces_count << "'\n";
  std::cout.copyfmt(state);
}

void Viewer::printInterfacesInfo(const int &index, const int &depth) {
  auto interfaceIdx = this->classfile->interfaces[index];
  std::cout << std::string(depth, '\t') << "interface #" << index
            << ": 'cp_info #" << interfaceIdx << "'\n";
  this->printConstantPoolInfo(interfaceIdx - 1, depth, false);
}

void Viewer::printFields() {
  makeTitle("Fields", 80, 35);
  if (!this->classfile->fields_count) {
    return;
  }
  for (auto i = 0; i < this->classfile->fields_count; ++i) {
    this->printFieldsInfo(i, 1);
  }
}

void Viewer::printFieldsCount() {
  state.copyfmt(std::cout);
  std::cout << "Fields Count: " << std::setw(10) << "'"
            << this->classfile->fields_count << "'\n";
  std::cout.copyfmt(state);
}

void Viewer::printFieldsInfo(const int &index, const int &depth) {
  auto field = this->classfile->fields[index];
  std::cout << std::string(depth, '\t') << "[" << index << "] ";
  this->printConstantPoolInfo(field.name_index - 1, 2, true);
  std::cout << std::string(depth + 1, '\t') << "Name: 'cp_info #"
            << field.name_index << "' ";
  this->printConstantPoolInfo(field.name_index - 1, 2, true);
  std::cout << std::string(depth + 1, '\t') << "Descriptor: 'cp_info #"
            << field.descriptor_index << "' ";
  this->printConstantPoolInfo(field.descriptor_index - 1, 2, true);
  this->printAccessFlags(&field, 2, 6, Utils::Access::getFieldAccessType);
  this->printAttributes(field.attributes, field.attributes_count, 2);
}

void Viewer::printMethods() {
  makeTitle("Methods", 80, 45);
  if (!this->classfile->methods_count) {
    return;
  }
  std::cout << "Methods:\n";
  for (auto i = 0; i < this->classfile->methods_count; ++i) {
    this->printMethodsInfo(i, 1);
  }
}

void Viewer::printMethodsCount() {
  state.copyfmt(std::cout);
  std::cout << "Methods Count: " << std::setw(9) << "'"
            << this->classfile->methods_count << "'\n";
  std::cout.copyfmt(state);
}

void Viewer::printMethodsInfo(const int &index, const int &depth) {
  std::cout << std::string(depth, '\t') << "method #" << index << "\n";
}

void Viewer::printAttributes(
    const std::vector<Utils::Attributes::attribute_info> &attributes,
    const int &attr_count, const int &depth) {
  if (!attr_count) {
    return;
  }
  makeTitle("Attributes", !depth ? 80 : 20, !depth ? 45 : 30, depth);
  for (auto i = 0; i < attr_count; ++i) {
    auto attr = attributes[i];
    this->printAttributeInfo(&attr, i, depth + 1);
  }
}

void Viewer::printAttributesCount(const int &depth, const int &attr_count) {
  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << "Attributes Count: " << std::setw(6)
            << "'" << attr_count << "'\n";
  std::cout.copyfmt(state);
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

void Viewer::printAttributeInfo(Utils::Attributes::attribute_info *attribute,
                                const int &index, const int &depth) {
  auto utf8nameindex =
      this->classfile->constant_pool[attribute->base->attribute_name_index - 1];
  auto kutf8_info = utf8nameindex.getClass<Utils::Infos::CONSTANT_Utf8_info>();
  auto attrName = Utf8(kutf8_info);
  auto attrtype = getAttributeType(attrName);
  std::cout << std::string(depth, '\t') << "[" << index << "] ";
  std::wcout << attrName << "\n";

  switch (attrtype) {
    namespace attrs = Utils::Attributes;
    case attrs::kCODE: {
      break;
    }
    case attrs::kCONSTANTVALUE: {
      auto kval_attr =
          attribute->getClass<Utils::Attributes::ConstantValue_attribute>();
      std::cout << std::string(depth + 1, '\t') << "Generic Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Attribute name index: 'cp_info #"
                << kval_attr->attribute_name_index << "' ";
      this->printConstantPoolInfo(kval_attr->attribute_name_index - 1,
                                  depth + 2, true);
      std::cout << std::string(depth + 2, '\t') << "Attribute length = '"
                << kval_attr->attribute_length << "'\n";
      std::cout << std::string(depth + 1, '\t') << "Specific Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Constant value index: 'cp_info #"
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
