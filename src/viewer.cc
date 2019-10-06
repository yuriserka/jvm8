#include "viewer.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "instructions/printer.h"
#include "utils/accessFlags.h"
#include "utils/constantPool.h"
#include "utils/memory.h"
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
  for (int i = 0; i < this->classfile->constant_pool_count - 1; ++i) {
    auto jmpNextIndex = this->printConstantPoolInfo(i, 0, false);
    if (jmpNextIndex) {
      std::cout << "[" << ++i + 1 << "]"
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

template <typename T>
void Viewer::print4bytesNumeral(const T *kinfo, const int &depth,
                                const bool &inner) {
  switch (kinfo->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_INTEGER: {
      state.copyfmt(std::cout);
      std::cout << std::string(depth, '\t') << "Bytes: "
                << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->bytes << "\n";
      std::cout.copyfmt(state);

      std::cout << std::string(depth, '\t') << "Value: " << kinfo->bytes
                << "\n";
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      state.copyfmt(std::cout);
      std::cout << std::string(depth, '\t') << "Bytes: "
                << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->bytes << "\n";
      std::cout.copyfmt(state);

      float f = Utils::copyCast<float>(&kinfo->bytes);
      std::cout << std::string(depth, '\t') << "Value: " << f << "\n";
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
    case cp::kCONSTANT_LONG: {
      state.copyfmt(std::cout);
      std::cout << std::string(depth, '\t') << "High Bytes: ";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->high_bytes << "\n";

      std::cout << std::string(depth, '\t') << "Low Bytes: ";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->low_bytes << "\n";
      std::cout.copyfmt(state);

      std::cout << std::string(depth, '\t') << "Long: " << u8val << "\n";
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      state.copyfmt(std::cout);
      std::cout << std::string(depth, '\t') << "High Bytes: ";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->high_bytes << "\n";

      std::cout << std::string(depth, '\t') << "Low Bytes: ";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->low_bytes << "\n";
      std::cout.copyfmt(state);

      double d = Utils::copyCast<double>(&u8val);
      std::cout << std::string(depth, '\t') << "Double: " << d << "\n";
      break;
    }
  }
}

enum name_and_type_aux_fmt { kNAMETYPEname, kNAMETYPEdesc };

bool Viewer::printConstantPoolInfo(const int &index, const int &depth,
                                   const bool &inner,
                                   const bool &innerNameAndType,
                                   const int &utf8fmt) {
  auto cpi = this->classfile->constant_pool[index];
  bool jmpNextIndex = false;
  if (!inner) {
    std::cout << std::string(depth, '\t') << "[" << index + 1 << "] ";
    auto name = Utils::ConstantPool::getConstantTypename(cpi.base->tag);
    std::cout << "CONSTANT_" << name << "_info\n";
  }
  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<info::CONSTANT_Class_info>();
      if (!inner) {
        std::cout << std::string(depth + 1, '\t') << "Class Name: "
                  << "'cp_info #" << kclass_info->name_index << "' ";
      }
      this->printConstantPoolInfo(kclass_info->name_index - 1,
                                  inner ? depth : depth + 1, true);
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<info::CONSTANT_FieldRef_info>();
      this->printReferences(kfieldref_info, depth + 1);
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<info::CONSTANT_Methodref_info>();
      this->printReferences(kmethodref_info, depth + 1);
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info =
          cpi.getClass<info::CONSTANT_InterfaceMethodref_info>();
      this->printReferences(kImethodref_info, depth + 1);
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<info::CONSTANT_String_info>();
      if (!inner) {
        std::cout << std::string(depth + 1, '\t') << "String: 'cp_info #"
                  << kstring_info->string_index << "' ";
      }
      this->printConstantPoolInfo(kstring_info->string_index - 1,
                                  inner ? depth : depth + 1, true);
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<info::CONSTANT_Integer_info>();
      this->print4bytesNumeral(kinteger_info, depth + 1, inner);
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<info::CONSTANT_Float_info>();
      this->print4bytesNumeral(kfloat_info, depth + 1, inner);
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<info::CONSTANT_Long_info>();
      this->print8bytesNumeral(klong_info, depth + 1, inner);
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<info::CONSTANT_Double_info>();
      this->print8bytesNumeral(kdouble_info, depth + 1, inner);
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<info::CONSTANT_NameAndType_info>();
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
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<info::CONSTANT_Utf8_info>();
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
            toprint += L">\n";
            break;
          }
          default:
            break;
        }
      } else if (inner) {
        toprint = L"<" + toprint + L">";
      }
      std::wcout << toprint.c_str();
      std::cout << (innerNameAndType ? "" : "\n");
      break;
    }
  }
  if (!inner) std::cout << "\n";
  return jmpNextIndex;
}

void Viewer::printConstantPoolInfo(const int &index) {
  auto cpi = this->classfile->constant_pool[index];
  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<info::CONSTANT_Class_info>();
      this->printConstantPoolInfo(kclass_info->name_index - 1);
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<info::CONSTANT_FieldRef_info>();
      this->printConstantPoolInfo(kfieldref_info->class_index - 1);
      this->printConstantPoolInfo(kfieldref_info->name_and_type_index - 1);
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<info::CONSTANT_Methodref_info>();
      this->printConstantPoolInfo(kmethodref_info->class_index - 1);
      this->printConstantPoolInfo(kmethodref_info->name_and_type_index - 1);
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info =
          cpi.getClass<info::CONSTANT_InterfaceMethodref_info>();
      this->printConstantPoolInfo(kImethodref_info->class_index - 1);
      this->printConstantPoolInfo(kImethodref_info->name_and_type_index - 1);
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<info::CONSTANT_String_info>();
      this->printConstantPoolInfo(kstring_info->string_index - 1);
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<info::CONSTANT_Integer_info>();
      std::cout << kinteger_info->bytes;
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<info::CONSTANT_Float_info>();
      std::cout << Utils::copyCast<float>(&kfloat_info->bytes);
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<info::CONSTANT_Long_info>();
      auto u8val =
          (static_cast<Utils::Types::u8>(klong_info->high_bytes) << 32 |
           klong_info->low_bytes);
      std::cout << u8val;
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<info::CONSTANT_Double_info>();
      auto u8val =
          (static_cast<Utils::Types::u8>(kdouble_info->high_bytes) << 32 |
           kdouble_info->low_bytes);
      std::cout << Utils::copyCast<double>(&u8val);
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<info::CONSTANT_NameAndType_info>();
      this->printConstantPoolInfo(knametype_info->name_index - 1);
      this->printConstantPoolInfo(knametype_info->descriptor_index - 1);
      break;
    }
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<info::CONSTANT_Utf8_info>();
      auto utf8string = Utf8(kutf8_info);
      std::wcout << utf8string;
      break;
    }
  }
}

std::wstring Viewer::getBytecodeOperandString(const int &index,
                                              const bool &putdot) {
  auto cpi = this->classfile->constant_pool[index];
  std::wstringstream ss;
  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<info::CONSTANT_Class_info>();
      ss << this->getBytecodeOperandString(kclass_info->name_index - 1)
         << (putdot ? "." : "");
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<info::CONSTANT_FieldRef_info>();
      ss << this->getBytecodeOperandString(kfieldref_info->class_index - 1)
         << this->getBytecodeOperandString(kfieldref_info->name_and_type_index -
                                           1);
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<info::CONSTANT_Methodref_info>();
      ss << this->getBytecodeOperandString(kmethodref_info->class_index - 1)
         << this->getBytecodeOperandString(
                kmethodref_info->name_and_type_index - 1);
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info =
          cpi.getClass<info::CONSTANT_InterfaceMethodref_info>();
      ss << this->getBytecodeOperandString(kImethodref_info->class_index - 1)
         << this->getBytecodeOperandString(
                kImethodref_info->name_and_type_index - 1);
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<info::CONSTANT_String_info>();
      ss << this->getBytecodeOperandString(kstring_info->string_index - 1);
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<info::CONSTANT_Integer_info>();
      ss << kinteger_info->bytes;
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<info::CONSTANT_Float_info>();
      ss << std::fixed << std::setprecision(2)
         << Utils::copyCast<float>(&kfloat_info->bytes);
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<info::CONSTANT_Long_info>();
      auto u8val =
          (static_cast<Utils::Types::u8>(klong_info->high_bytes) << 32 |
           klong_info->low_bytes);
      ss << u8val;
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<info::CONSTANT_Double_info>();
      auto u8val =
          (static_cast<Utils::Types::u8>(kdouble_info->high_bytes) << 32 |
           kdouble_info->low_bytes);
      ss << std::fixed << std::setprecision(2)
         << Utils::copyCast<double>(&u8val);
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<info::CONSTANT_NameAndType_info>();
      ss << this->getBytecodeOperandString(knametype_info->name_index - 1);
      break;
    }
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<info::CONSTANT_Utf8_info>();
      auto utf8string = Utf8(kutf8_info);
      ss << utf8string.toString();
      break;
    }
  }
  return ss.str();
}

template <typename T>
void Viewer::printAccessFlags(const T *obj, const int &depth, const int &width,
                              std::vector<std::string> (*getAccessTypeFunc)(
                                  const Utils::Types::u2 &accessType)) {
  auto flags = getAccessTypeFunc(obj->access_flags);
  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << "Access Flags: " << std::setw(width);
  std::cout << "0x" << std::setfill('0') << std::setw(4) << std::hex
            << std::uppercase << obj->access_flags;
  std::cout.copyfmt(state);
  std::cout << " [";
  for (size_t i = 0; i < flags.size(); ++i) {
    std::cout << flags[i] << (i < flags.size() - 1 ? " " : "");
  }
  std::cout << "]\n";
}

void Viewer::printAccessFlags() {
  this->printAccessFlags(this->classfile, 0, 11,
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
            << this->classfile->super_class << "' ";
  this->printConstantPoolInfo(this->classfile->super_class - 1, 0, true);
  std::cout.copyfmt(state);
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

void Viewer::printInterfaceInfo(const int &index, const int &depth) {
  auto interfaceidx = this->classfile->interfaces[index];
  std::cout << std::string(depth, '\t') << "Interface " << index << "\n";
  std::cout << std::string(depth + 1, '\t') << "Interface: 'cp_info #"
            << interfaceidx << "' ";
  std::cout << "<";
  this->printConstantPoolInfo(interfaceidx - 1);
  std::cout << ">\n";
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

void Viewer::printFieldInfo(const int &index, const int &depth) {
  auto field = this->classfile->fields[index];
  std::cout << std::string(depth, '\t') << "[" << index << "] ";
  this->printConstantPoolInfo(field.name_index - 1);
  std::cout << "\n";

  std::cout << std::string(depth + 1, '\t') << "Name: 'cp_info #"
            << field.name_index << "' ";
  this->printConstantPoolInfo(field.name_index - 1, depth + 1, true);

  std::cout << std::string(depth + 1, '\t') << "Descriptor: 'cp_info #"
            << field.descriptor_index << "' ";
  this->printConstantPoolInfo(field.descriptor_index - 1, depth + 1, true);

  this->printAccessFlags(&field, depth + 1, 0,
                         Utils::Access::getFieldAccessType);
  this->printAttributes(field.attributes, field.attributes_count, depth + 1, 20,
                        30);
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

void Viewer::printMethodInfo(const int &index, const int &depth) {
  auto method = this->classfile->methods[index];
  std::cout << std::string(depth, '\t') << "[" << index << "] ";
  this->printConstantPoolInfo(method.name_index - 1);
  std::cout << "\n";

  std::cout << std::string(depth + 1, '\t') << "Name: 'cp_info #"
            << method.name_index << "' ";
  this->printConstantPoolInfo(method.name_index - 1, depth + 1, true);

  std::cout << std::string(depth + 1, '\t') << "Descriptor: 'cp_info #"
            << method.descriptor_index << "' ";
  this->printConstantPoolInfo(method.descriptor_index - 1, depth + 1, true);

  this->printAccessFlags(&method, depth + 1, 0,
                         Utils::Access::getMethodAccessType);
  this->printAttributes(method.attributes, method.attributes_count, depth + 1,
                        20, 30);
}

void Viewer::printAttributes(
    const std::vector<Utils::Attributes::attribute_info> &attributes,
    const int &attr_count, const int &depth, const int &qtd_stars,
    const int &width_shift) {
  if (!attr_count) {
    return;
  }
  makeTitle("Attributes", qtd_stars, width_shift, depth);
  for (auto i = 0; i < attr_count; ++i) {
    auto attr = attributes[i];
    this->printAttributeInfo(&attr, i, depth + 1);
  }
}

void Viewer::printAttributesCount(const int &depth, const int &attr_count) {
  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << "Attributes Count: " << std::setw(6)
            << attr_count << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printTable(const std::vector<std::string> vars,
                        Utils::Attributes::Code_attribute *code_attr,
                        const int &depth) {
  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << std::left;
  for (size_t i = 0; i < vars.size(); ++i) {
    auto var = vars[i];
    std::cout << "[" << var << "] |" << (i < vars.size() - 1 ? " " : "");
  }
  std::cout.copyfmt(state);

  std::cout << '\n';
  for (auto i = 0; i < code_attr->exception_table_length; ++i) {
    auto except = code_attr->exception_table[i];
    state.copyfmt(std::cout);
    std::cout << std::right;
    std::cout << std::string(depth, '\t') << std::left << std::setw(5) << i;

    std::cout << std::left << " | " << except.start_pc << " | " << except.end_pc
              << " | " << except.handler_pc << " | ";

    std::cout << "'cp_info #" << except.catch_type << "' ";
    this->printConstantPoolInfo(except.catch_type - 1);
    std::cout << " |" << '\n';
    std::cout.copyfmt(state);
  }
}

void Viewer::printTable(const std::vector<std::string> vars,
                        Utils::Attributes::LineNumberTable_attribute *lnt_attr,
                        const int &depth) {
  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << std::left;
  for (size_t i = 0; i < vars.size(); ++i) {
    auto var = vars[i];
    std::cout << "[" << var << "] |" << (i < vars.size() - 1 ? " " : "");
  }
  std::cout.copyfmt(state);

  std::cout << '\n';
  for (auto i = 0; i < lnt_attr->line_number_table_length; ++i) {
    auto lnt_info = lnt_attr->line_number_table[i];
    state.copyfmt(std::cout);
    std::cout << std::string(depth, '\t') << std::setw(5) << i << " | "
              << std::setw(10) << lnt_info.start_pc << " | " << std::setw(13)
              << lnt_info.line_number << " |" << '\n';
    std::cout.copyfmt(state);
  }
}

void Viewer::printTable(
    const std::vector<std::string> vars,
    Utils::Attributes::InnerClasses_attribute *innerclass_attr,
    const int &depth) {
  state.copyfmt(std::cout);
  std::cout << std::string(depth, '\t') << std::left;
  for (size_t i = 0; i < vars.size(); ++i) {
    auto var = vars[i];
    std::cout << "[" << var << "] |" << (i < vars.size() - 1 ? " " : "");
  }
  std::cout.copyfmt(state);

  std::cout << '\n';
  for (auto i = 0; i < innerclass_attr->number_of_classes; ++i) {
    auto innerclass = innerclass_attr->classes[i];
    state.copyfmt(std::cout);
    std::cout << std::right;
    std::cout << std::string(depth, '\t') << std::setw(5) << i;

    std::cout << std::left;
    std::cout << " | "
              << "'cp_info #" << innerclass.inner_class_info_index << "' ";
    this->printConstantPoolInfo(innerclass.inner_class_info_index - 1);

    std::cout << " | "
              << "'cp_info #" << innerclass.outer_class_info_index << "' ";
    this->printConstantPoolInfo(innerclass.outer_class_info_index - 1);

    std::cout << " | "
              << "'cp_info #" << innerclass.inner_name_index << "' ";
    this->printConstantPoolInfo(innerclass.inner_name_index - 1);

    std::cout << " | " << std::setw(-3) << "0x" << std::setfill('0')
              << std::setw(4) << std::hex << std::uppercase
              << innerclass.inner_class_access_flags;
    std::cout.copyfmt(state);
    std::cout << " [";
    auto flags = Utils::Access::getNestedClassAccessType(
        innerclass.inner_class_access_flags);
    for (size_t i = 0; i < flags.size(); ++i) {
      std::cout << flags[i] << (i < flags.size() - 1 ? " " : "");
    }
    std::cout << "] |\n";
  }
}

void Viewer::printAttributeInfo(Utils::Attributes::attribute_info *attribute,
                                const int &index, const int &depth) {
  auto utf8nameindex =
      this->classfile->constant_pool[attribute->base->attribute_name_index - 1];
  auto kutf8_info = utf8nameindex.getClass<Utils::Infos::CONSTANT_Utf8_info>();
  auto attrName = Utf8(kutf8_info);
  auto attrtype = Utils::Attributes::getAttributeType(attrName.str);

  std::cout << std::string(depth, '\t') << "[" << index << "] ";
  std::wcout << attrName << "\n";

  switch (attrtype) {
    namespace attrs = Utils::Attributes;
    case attrs::kCODE: {
      auto code_attr = attribute->getClass<attrs::Code_attribute>();
      std::cout << std::string(depth + 1, '\t') << "Generic Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Attribute name index: 'cp_info #"
                << code_attr->attribute_name_index << "' ";
      std::cout << "<";
      this->printConstantPoolInfo(code_attr->attribute_name_index - 1);
      std::cout << ">\n";

      std::cout << std::string(depth + 2, '\t')
                << "Attribute length: " << code_attr->attribute_length << "\n";

      std::cout << std::string(depth + 1, '\t') << "Specific Info: \n";
      std::cout << std::string(depth + 2, '\t') << "Bytecode: \n";
      int i = 0;
      auto codeArr = code_attr->code;
      for (auto it = codeArr.begin(); it != codeArr.end(); ++it) {
        std::cout << std::string(depth + 3, '\t') << i << ": ";
        Instructions::printBytecode(&it, this, &i);
      }

      std::cout << std::string(depth + 2, '\t') << "Exception table: \n";
      std::vector<std::string> except_vars = {
          "Nr.", "Start PC", "End PC", "Handler PC", "Catch type",
      };
      this->printTable(except_vars, code_attr, depth + 3);

      std::cout << std::string(depth + 2, '\t') << "Misc: \n";
      std::cout << std::string(depth + 3, '\t')
                << "Maximum local variables: " << code_attr->max_locals << "\n";
      std::cout << std::string(depth + 3, '\t')
                << "Code length: " << code_attr->code_length << "\n";
      this->printAttributes(code_attr->attributes, code_attr->attributes_count,
                            depth + 1, 20, 47);
      break;
    }
    case attrs::kCONSTANTVALUE: {
      auto kval_attr = attribute->getClass<attrs::ConstantValue_attribute>();
      std::cout << std::string(depth + 1, '\t') << "Generic Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Attribute name index: 'cp_info #"
                << kval_attr->attribute_name_index << "' ";
      std::cout << "<";
      this->printConstantPoolInfo(kval_attr->attribute_name_index - 1);
      std::cout << ">\n";

      std::cout << std::string(depth + 2, '\t')
                << "Attribute length: " << kval_attr->attribute_length << "\n";

      std::cout << std::string(depth + 1, '\t') << "Specific Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Constant value index: 'cp_info #"
                << kval_attr->constantvalue_index << "' ";
      std::cout << "<";
      this->printConstantPoolInfo(kval_attr->constantvalue_index - 1);
      std::cout << ">\n";
      break;
    }
    case attrs::kDEPRECATED: {
      auto deprecated_attr = attribute->getClass<attrs::Deprecated_attribute>();
      std::cout << std::string(depth + 1, '\t') << "Generic Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Attribute name index: 'cp_info #"
                << deprecated_attr->attribute_name_index << "' ";
      std::cout << "<";
      this->printConstantPoolInfo(deprecated_attr->attribute_name_index - 1);
      std::cout << ">\n";

      std::cout << std::string(depth + 2, '\t')
                << "Attribute length: " << deprecated_attr->attribute_length
                << "\n";

      std::cout << std::string(depth + 1, '\t') << "Specific Info: \n";
      break;
    }
    case attrs::kEXCEPTIONS: {
      break;
    }
    case attrs::kLINENUMBERTABLE: {
      auto lnt_attr = attribute->getClass<attrs::LineNumberTable_attribute>();
      std::cout << std::string(depth + 1, '\t') << "Generic Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Attribute name index: 'cp_info #"
                << lnt_attr->attribute_name_index << "' ";
      std::cout << "<";
      this->printConstantPoolInfo(lnt_attr->attribute_name_index - 1);
      std::cout << ">\n";

      std::cout << std::string(depth + 2, '\t')
                << "Attribute length: " << lnt_attr->attribute_length << "\n";

      std::cout << std::string(depth + 1, '\t') << "Specific Info: \n";
      std::vector<std::string> vars = {"Nr.", "Start PC", "Line number"};
      this->printTable(vars, lnt_attr, depth + 3);
      break;
    }
    case attrs::kLOCALVARIABLETABLE: {
      break;
    }
    case attrs::kSOURCEFILE: {
      auto sourcefile_attr = attribute->getClass<attrs::SourceFile_attribute>();
      std::cout << std::string(depth + 1, '\t') << "Generic Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Attribute name index: 'cp_info #"
                << sourcefile_attr->attribute_name_index << "' ";
      std::cout << "<";
      this->printConstantPoolInfo(sourcefile_attr->attribute_name_index - 1);
      std::cout << ">\n";

      std::cout << std::string(depth + 2, '\t')
                << "Attribute length: " << sourcefile_attr->attribute_length
                << "\n";

      std::cout << std::string(depth + 1, '\t') << "Specific Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Constant value index: 'cp_info #"
                << sourcefile_attr->sourcefile_index << "' ";
      std::cout << "<";
      this->printConstantPoolInfo(sourcefile_attr->sourcefile_index - 1);
      std::cout << ">\n";
      break;
    }
    case attrs::kINNERCLASS: {
      auto innerclass_attr =
          attribute->getClass<attrs::InnerClasses_attribute>();
      std::cout << std::string(depth + 1, '\t') << "Generic Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Attribute name index: 'cp_info #"
                << innerclass_attr->attribute_name_index << "' ";
      std::cout << "<";
      this->printConstantPoolInfo(innerclass_attr->attribute_name_index - 1);
      std::cout << ">\n";

      std::cout << std::string(depth + 2, '\t')
                << "Attribute length: " << innerclass_attr->attribute_length
                << "\n";

      std::cout << std::string(depth + 1, '\t') << "Specific Info: \n";

      std::vector<std::string> inner_vars = {
          "Nr.", "Inner Class", "Outer Class", "Inner Name", "Access Flags",
      };
      this->printTable(inner_vars, innerclass_attr, depth + 2);
      break;
    }
    case attrs::kINVALID: {
      auto not_implemented = attribute->getClass<attrs::NotImplemented>();
      std::cout << std::string(depth + 1, '\t') << "Generic Info: \n";
      std::cout << std::string(depth + 2, '\t')
                << "Attribute name index: 'cp_info #"
                << not_implemented->attribute_name_index << "' ";
      std::cout << "<";
      this->printConstantPoolInfo(not_implemented->attribute_name_index - 1);
      std::cout << ">\n";

      std::cout << std::string(depth + 2, '\t')
                << "Attribute length: " << not_implemented->attribute_length
                << "\n";

      std::cout << std::string(depth + 1, '\t') << "Specific Info: \n";
      std::cout << std::string(depth + 2, '\t') << "NOT IMPLEMENTED\n";
    }
  }
}
