#include "viewer.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "instructions/printer.h"
#include "utils/accessFlags.h"
#include "utils/constantPool.h"
#include "utils/memory.h"
#include "utils/reference_kind.h"
#include "utils/string.h"
#include "utils/table.h"
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
    auto jmpNextIndex = this->printConstantPoolInfo(i, 0, false);
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

template <typename T>
void Viewer::printReferences(const T *kinfo, const int &tab_shift) {
  state.copyfmt(std::cout);
  std::cout << std::string(tab_shift, '\t') << "Class name: "
            << "'cp_info #" << kinfo->class_index << "' ";
  this->printConstantPoolInfo(kinfo->class_index, 0, true);
  std::cout.copyfmt(state);

  state.copyfmt(std::cout);
  std::cout << std::string(tab_shift, '\t') << "Name and type: "
            << "'cp_info #" << kinfo->name_and_type_index << "' ";
  this->printConstantPoolInfo(kinfo->name_and_type_index, 0, true, true);
  std::cout.copyfmt(state);
}

template <typename T>
void Viewer::print4bytesNumeral(const T *kinfo, const int &tab_shift,
                                const bool &inner) {
  switch (kinfo->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_INTEGER: {
      state.copyfmt(std::cout);
      std::cout << std::string(tab_shift, '\t') << "Bytes: "
                << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->bytes << "\n";
      std::cout.copyfmt(state);

      std::cout << std::string(tab_shift, '\t') << "Value: " << kinfo->bytes
                << "\n";
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      state.copyfmt(std::cout);
      std::cout << std::string(tab_shift, '\t') << "Bytes: "
                << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->bytes << "\n";
      std::cout.copyfmt(state);

      float f = Utils::copyCast<float>(&kinfo->bytes);
      std::cout << std::string(tab_shift, '\t') << "Value: " << f << "\n";
      break;
    }
  }
}

template <typename T>
void Viewer::print8bytesNumeral(const T *kinfo, const int &tab_shift,
                                const bool &inner) {
  auto u8val = (static_cast<Utils::Types::u8>(kinfo->high_bytes) << 32 |
                kinfo->low_bytes);
  switch (kinfo->tag) {
    namespace cp = Utils::ConstantPool;
    namespace types = Utils::Types;
    case cp::kCONSTANT_LONG: {
      state.copyfmt(std::cout);
      std::cout << std::string(tab_shift, '\t') << "High Bytes: ";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->high_bytes << "\n";

      std::cout << std::string(tab_shift, '\t') << "Low Bytes: ";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->low_bytes << "\n";
      std::cout.copyfmt(state);

      std::cout << std::string(tab_shift, '\t') << "Long: " << u8val << "\n";
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      state.copyfmt(std::cout);
      std::cout << std::string(tab_shift, '\t') << "High Bytes: ";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->high_bytes << "\n";

      std::cout << std::string(tab_shift, '\t') << "Low Bytes: ";
      std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex
                << std::uppercase << kinfo->low_bytes << "\n";
      std::cout.copyfmt(state);

      double d = Utils::copyCast<double>(&u8val);
      std::cout << std::string(tab_shift, '\t') << "Double: " << d << "\n";
      break;
    }
  }
}

enum name_and_type_aux_fmt { kNAMETYPEname, kNAMETYPEdesc };

bool Viewer::printConstantPoolInfo(const int &index, const int &tab_shift,
                                   const bool &inner,
                                   const bool &innerNameAndType,
                                   const int &utf8fmt) {
  bool jmpNextIndex = false;
  if (!index) {
    std::cout << "invalid constant pool reference";
    return jmpNextIndex;
  }
  auto cpi = this->classfile->constant_pool[index - 1];
  if (!inner) {
    std::cout << std::string(tab_shift, '\t') << "[" << index << "] ";
    auto name = Utils::ConstantPool::getConstantTypename(cpi.base->tag);
    std::cout << "CONSTANT_" << name << "_info\n";
  }
  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<info::CONSTANT_Class_info>();
      if (!inner) {
        std::cout << std::string(tab_shift + 1, '\t') << "Class Name: "
                  << "'cp_info #" << kclass_info->name_index << "' ";
      }
      this->printConstantPoolInfo(kclass_info->name_index,
                                  inner ? tab_shift : tab_shift + 1, true);
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<info::CONSTANT_FieldRef_info>();
      this->printReferences(kfieldref_info, tab_shift + 1);
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<info::CONSTANT_Methodref_info>();
      this->printReferences(kmethodref_info, tab_shift + 1);
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info =
          cpi.getClass<info::CONSTANT_InterfaceMethodref_info>();
      this->printReferences(kImethodref_info, tab_shift + 1);
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<info::CONSTANT_String_info>();
      if (!inner) {
        std::cout << std::string(tab_shift + 1, '\t') << "String: 'cp_info #"
                  << kstring_info->string_index << "' ";
      }
      this->printConstantPoolInfo(kstring_info->string_index,
                                  inner ? tab_shift : tab_shift + 1, true);
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<info::CONSTANT_Integer_info>();
      this->print4bytesNumeral(kinteger_info, tab_shift + 1, inner);
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<info::CONSTANT_Float_info>();
      this->print4bytesNumeral(kfloat_info, tab_shift + 1, inner);
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<info::CONSTANT_Long_info>();
      this->print8bytesNumeral(klong_info, tab_shift + 1, inner);
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<info::CONSTANT_Double_info>();
      this->print8bytesNumeral(kdouble_info, tab_shift + 1, inner);
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<info::CONSTANT_NameAndType_info>();
      if (!inner) {
        std::cout << std::string(tab_shift + 1, '\t') << "Name: "
                  << "'cp_info #" << knametype_info->name_index << "' ";
        this->printConstantPoolInfo(knametype_info->name_index,
                                    inner ? tab_shift : tab_shift + 1, true);
      } else {
        this->printConstantPoolInfo(knametype_info->name_index,
                                    inner ? tab_shift : tab_shift + 1, true,
                                    true, kNAMETYPEname);
      }
      if (!inner) {
        std::cout << std::string(tab_shift + 1, '\t')
                  << "Descriptor: 'cp_info #"
                  << knametype_info->descriptor_index << "' ";
        this->printConstantPoolInfo(knametype_info->descriptor_index,
                                    inner ? tab_shift : tab_shift + 1, true);
      } else {
        this->printConstantPoolInfo(knametype_info->descriptor_index,
                                    inner ? tab_shift : tab_shift + 1, true,
                                    true, kNAMETYPEdesc);
      }
      break;
    }
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<info::CONSTANT_Utf8_info>();
      auto utf8string = Utf8(kutf8_info);
      if (!inner) {
        std::cout << std::string(tab_shift + 1, '\t')
                  << "Length of byte array: " << kutf8_info->length << "\n"
                  << std::string(tab_shift + 1, '\t')
                  << "Length of string: " << utf8string.str.size() << "\n";
        std::cout << std::string(tab_shift + 1, '\t') << "String: ";
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
    case cp::kCONSTANT_METHODHANDLE: {
      auto methodhandle_info = cpi.getClass<info::CONSTANT_MethodHandle_info>();
      if (!inner) {
        std::cout << std::string(tab_shift + 1, '\t') << "Reference kind: "
                  << Utils::Reference::getReferenceType(
                         methodhandle_info->reference_kind)
                  << "\n";
        std::cout << std::string(tab_shift + 1, '\t') << "Reference index: "
                  << "'cp_info #" << methodhandle_info->reference_index << "' ";
      }
      std::wcout << "<"
                 << this->getConstantPoolInfo(
                        methodhandle_info->reference_index)
                 << ">\n";
      break;
    }
    case cp::kCONSTANT_METHODTYPE: {
      auto methodtype_info = cpi.getClass<info::CONSTANT_MethodType_info>();
      if (!inner) {
        std::cout << std::string(tab_shift + 1, '\t') << "Type: "
                  << "'cp_info #" << methodtype_info->descriptor_index << "' ";
      }
      this->printConstantPoolInfo(methodtype_info->descriptor_index,
                                  inner ? tab_shift : tab_shift + 1, true);
      break;
    }
    case cp::kCONSTANT_INVOKEDYNAMIC: {
      auto invokedynamic_info =
          cpi.getClass<info::CONSTANT_InvokeDynamic_info>();
      if (!inner) {
        std::cout << std::string(tab_shift + 1, '\t') << "Name and type: "
                  << "'cp_info #" << invokedynamic_info->name_and_type_index
                  << "' ";
      }
      this->printConstantPoolInfo(invokedynamic_info->name_and_type_index,
                                  inner ? tab_shift : tab_shift + 1, true);
      if (!inner) {
        std::cout << std::string(tab_shift + 1, '\t') << "Bootstrap method: "
                  << "'BootstrapMethods #"
                  << invokedynamic_info->bootstrap_method_attr_index << "'\n";
      }
      break;
    }
  }
  if (!inner) std::cout << "\n";
  return jmpNextIndex;
}

std::wstring Viewer::getConstantPoolInfo(const int &index, const bool &dot) {
  std::wstringstream wss;
  if (!index) {
    wss << "invalid constant pool reference";
    return wss.str();
  }
  auto cpi = this->classfile->constant_pool[index - 1];
  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<info::CONSTANT_Class_info>();
      wss << this->getConstantPoolInfo(kclass_info->name_index, dot)
          << (dot ? "." : "");
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<info::CONSTANT_FieldRef_info>();
      wss << this->getConstantPoolInfo(kfieldref_info->class_index, dot)
          << this->getConstantPoolInfo(kfieldref_info->name_and_type_index,
                                       dot);
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<info::CONSTANT_Methodref_info>();
      wss << this->getConstantPoolInfo(kmethodref_info->class_index, dot)
          << this->getConstantPoolInfo(kmethodref_info->name_and_type_index,
                                       dot);
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info =
          cpi.getClass<info::CONSTANT_InterfaceMethodref_info>();
      wss << this->getConstantPoolInfo(kImethodref_info->class_index, dot)
          << this->getConstantPoolInfo(kImethodref_info->name_and_type_index,
                                       dot);
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<info::CONSTANT_String_info>();
      wss << this->getConstantPoolInfo(kstring_info->string_index, dot);
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<info::CONSTANT_Integer_info>();
      wss << kinteger_info->bytes;
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<info::CONSTANT_Float_info>();
      wss << std::fixed << std::setprecision(2)
          << Utils::copyCast<float>(&kfloat_info->bytes);
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<info::CONSTANT_Long_info>();
      auto u8val =
          (static_cast<Utils::Types::u8>(klong_info->high_bytes) << 32 |
           klong_info->low_bytes);
      wss << u8val;
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<info::CONSTANT_Double_info>();
      auto u8val =
          (static_cast<Utils::Types::u8>(kdouble_info->high_bytes) << 32 |
           kdouble_info->low_bytes);
      wss << std::fixed << std::setprecision(2)
          << Utils::copyCast<double>(&u8val);
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<info::CONSTANT_NameAndType_info>();
      wss << this->getConstantPoolInfo(knametype_info->name_index, dot);
      break;
    }
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<info::CONSTANT_Utf8_info>();
      auto utf8string = Utf8(kutf8_info);
      wss << utf8string.toString();
      break;
    }
    case cp::kCONSTANT_METHODHANDLE: {
      auto kmethodhandle_info =
          cpi.getClass<info::CONSTANT_MethodHandle_info>();
      wss << "Constant_"
          << Utils::String::to_wide(Utils::ConstantPool::getConstantTypename(
                 cp::kCONSTANT_METHODHANDLE))
          << "_info "
          << this->getConstantPoolInfo(kmethodhandle_info->reference_index,
                                       dot);
      break;
    }
    case cp::kCONSTANT_METHODTYPE: {
      auto methodtype_info = cpi.getClass<info::CONSTANT_MethodType_info>();
      wss << this->getConstantPoolInfo(methodtype_info->descriptor_index, dot);
      break;
    }
    case cp::kCONSTANT_INVOKEDYNAMIC: {
      auto invokedynamic_info =
          cpi.getClass<info::CONSTANT_InvokeDynamic_info>();
      wss << this->getConstantPoolInfo(invokedynamic_info->name_and_type_index)
          << ", BootstrapMethods #"
          << invokedynamic_info->bootstrap_method_attr_index;
    } break;
  }
  return wss.str();
}

template <typename T>
void Viewer::printAccessFlags(const T *obj, const int &tab_shift,
                              const int &width,
                              std::vector<std::string> (*getAccessTypeFunc)(
                                  const Utils::Types::u2 &accessType)) {
  auto flags = getAccessTypeFunc(obj->access_flags);
  state.copyfmt(std::cout);
  std::cout << std::string(tab_shift, '\t')
            << "Access Flags: " << std::setw(width);
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
  this->printConstantPoolInfo(this->classfile->this_class, 0, true);
  std::cout.copyfmt(state);
}

void Viewer::printSuperClass() {
  state.copyfmt(std::cout);
  std::cout << "Super class: " << std::setw(10) << ' ' << "'cp_info #"
            << this->classfile->super_class << "' ";
  this->printConstantPoolInfo(this->classfile->super_class, 0, true);
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

void Viewer::printInterfaceInfo(const int &index, const int &tab_shift) {
  auto interfaceidx = this->classfile->interfaces[index];
  std::cout << std::string(tab_shift, '\t') << "Interface " << index << "\n";
  std::cout << std::string(tab_shift + 1, '\t') << "Interface: 'cp_info #"
            << interfaceidx << "' ";
  std::wcout << "<" << this->getConstantPoolInfo(interfaceidx, false) << ">\n";
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
  std::wcout << this->getConstantPoolInfo(field.name_index, false) << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Name: 'cp_info #"
            << field.name_index << "' ";
  this->printConstantPoolInfo(field.name_index, tab_shift + 1, true);

  std::cout << std::string(tab_shift + 1, '\t') << "Descriptor: 'cp_info #"
            << field.descriptor_index << "' ";
  this->printConstantPoolInfo(field.descriptor_index, tab_shift + 1, true);

  this->printAccessFlags(&field, tab_shift + 1, 0,
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
  std::wcout << this->getConstantPoolInfo(method.name_index, false) << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Name: 'cp_info #"
            << method.name_index << "' ";
  this->printConstantPoolInfo(method.name_index, tab_shift + 1, true);

  std::cout << std::string(tab_shift + 1, '\t') << "Descriptor: 'cp_info #"
            << method.descriptor_index << "' ";
  this->printConstantPoolInfo(method.descriptor_index, tab_shift + 1, true);

  this->printAccessFlags(&method, tab_shift + 1, 0,
                         Utils::Access::getMethodAccessType);
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

void Viewer::printTable(const std::vector<std::string> vars,
                        Utils::Attributes::Code_attribute *code_attr,
                        const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(10);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter endpc_col(8);
  endpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter handlerpc_col(12);
  handlerpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter catchtype_col(35);
  catchtype_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter(
      {nr_col, startpc_col, endpc_col, handlerpc_col, catchtype_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < code_attr->exception_table_length; ++i) {
    auto except = code_attr->exception_table[i];
    std::wstringstream wss;
    wss << "'cp_info #" << except.catch_type << "'\n"
        << this->getConstantPoolInfo(except.catch_type, false);
    formatter << i << except.start_pc << except.end_pc << except.handler_pc
              << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(const std::vector<std::string> vars,
                        Utils::Attributes::LineNumberTable_attribute *lnt_attr,
                        const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(10);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter linenum_col(15);
  linenum_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, startpc_col, linenum_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < lnt_attr->line_number_table_length; ++i) {
    auto lnt_info = lnt_attr->line_number_table[i];
    formatter << i << lnt_info.start_pc << lnt_info.line_number;
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(const std::vector<std::string> vars,
                        Utils::Attributes::Exceptions_attribute *excpt_attr,
                        const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(15);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter linenum_col(30);
  linenum_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, startpc_col, linenum_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < excpt_attr->number_of_exceptions; ++i) {
    auto except = excpt_attr->exception_index_table[i];
    std::wstringstream wss;
    wss << "'cp_info #" << except << "'\n";
    formatter << i << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << this->getConstantPoolInfo(except, false);
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(
    const std::vector<std::string> vars,
    Utils::Attributes::InnerClasses_attribute *innerclass_attr,
    const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter innerclass_col(20);
  innerclass_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter outerclass_col(20);
  outerclass_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter innername_col(20);
  innername_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter accessflags_col(35);
  accessflags_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter(
      {nr_col, innerclass_col, outerclass_col, innername_col, accessflags_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < innerclass_attr->number_of_classes; ++i) {
    auto innerclass = innerclass_attr->classes[i];
    formatter << i;
    std::wstringstream wss;

    wss << "'cp_info #" << innerclass.inner_class_info_index << "'\n"
        << this->getConstantPoolInfo(innerclass.inner_class_info_index, false);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << "'cp_info #" << innerclass.outer_class_info_index << "'\n"
        << this->getConstantPoolInfo(innerclass.outer_class_info_index, false);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << "'cp_info #" << innerclass.inner_name_index << "'\n"
        << this->getConstantPoolInfo(innerclass.inner_name_index, false);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << "0x" << std::setfill(L'0') << std::setw(4) << std::hex
        << std::uppercase << innerclass.inner_class_access_flags << " ";
    auto flags = Utils::Access::getNestedClassAccessType(
        innerclass.inner_class_access_flags);
    wss << " [";
    for (size_t i = 0; i < flags.size(); ++i) {
      wss << Utils::String::to_wide(flags[i])
          << (i < flags.size() - 1 ? L" " : L"");
    }
    wss << " ]";
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(
    const std::vector<std::string> vars,
    Utils::Attributes::LocalVariableTable_attribute *localvar_attr,
    const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(10);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter len_col(8);
  len_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter index_col(8);
  index_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter name_col(15);
  name_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter(
      {nr_col, startpc_col, len_col, index_col, name_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < localvar_attr->local_variable_table_length; ++i) {
    auto localvar_info = localvar_attr->local_variable_table[i];
    formatter << i << localvar_info.start_pc << localvar_info.length
              << localvar_info.index;

    std::wstringstream wss;
    wss << "'cp_info #" << localvar_info.name_index << "'\n"
        << this->getConstantPoolInfo(localvar_info.name_index, false);

    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(
    const std::vector<std::string> vars,
    Utils::Attributes::BootstrapMethods_attribute *bootstrap_attr,
    const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter bootstrap_col(30);
  bootstrap_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter args_col(55);
  args_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, bootstrap_col, args_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < bootstrap_attr->num_bootstrap_methods; ++i) {
    auto bootstrap_info = bootstrap_attr->bootstrap_methods[i];
    formatter << i;

    std::wstringstream wss;
    wss << "'cp_info #" << bootstrap_info.bootstrap_method_ref << "'\n"
        << this->getConstantPoolInfo(bootstrap_info.bootstrap_method_ref,
                                     false);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    for (auto j = 0; j < bootstrap_info.num_bootstrap_arguments; ++j) {
      wss << "'cp_info #" << bootstrap_info.bootstrap_arguments[j] << "' <"
          << this->getConstantPoolInfo(bootstrap_info.bootstrap_arguments[j])
          << ">\n";
    }
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printAttributeInfo(Utils::Attributes::attribute_info *attribute,
                                const int &index, const int &tab_shift) {
  auto utf8nameindex =
      this->classfile->constant_pool[attribute->base->attribute_name_index - 1];
  auto kutf8_info = utf8nameindex.getClass<Utils::Infos::CONSTANT_Utf8_info>();
  auto attrName = Utf8(kutf8_info);
  auto attrtype = Utils::Attributes::getAttributeType(attrName.str);

  std::cout << std::string(tab_shift, '\t') << "[" << index << "] ";
  std::wcout << attrName << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Generic Info: \n";
  std::cout << std::string(tab_shift + 2, '\t')
            << "Attribute name index: 'cp_info #"
            << attribute->base->attribute_name_index << "' ";

  this->printConstantPoolInfo(attribute->base->attribute_name_index, 0, true);

  std::cout << std::string(tab_shift + 2, '\t')
            << "Attribute length: " << attribute->base->attribute_length
            << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Specific Info: \n";

  switch (attrtype) {
    namespace attrs = Utils::Attributes;
    case attrs::kCONSTANTVALUE: {
      auto kval_attr = attribute->getClass<attrs::ConstantValue_attribute>();
      std::cout << std::string(tab_shift + 2, '\t')
                << "Constant value index: 'cp_info #"
                << kval_attr->constantvalue_index << "' ";
      std::wcout << "<"
                 << this->getConstantPoolInfo(kval_attr->constantvalue_index,
                                              false)
                 << ">\n";
      break;
    }
    case attrs::kCODE: {
      auto code_attr = attribute->getClass<attrs::Code_attribute>();
      std::cout << std::string(tab_shift + 2, '\t') << "Bytecode: \n";
      int i = 0;
      auto codeArr = code_attr->code;
      for (auto it = codeArr.begin(); it != codeArr.end(); ++it) {
        std::cout << std::string(tab_shift + 3, '\t') << i << ": ";
        Instructions::printBytecode(&it, this, &i);
      }

      std::cout << std::string(tab_shift + 2, '\t') << "Exception table: \n";
      std::vector<std::string> except_vars = {
          "Nr.", "Start PC", "End PC", "Handler PC", "Catch type",
      };
      this->printTable(except_vars, code_attr, tab_shift + 3);

      std::cout << std::string(tab_shift + 2, '\t') << "Misc: \n";
      std::cout << std::string(tab_shift + 3, '\t')
                << "Maximum local variables: " << code_attr->max_locals << "\n";
      std::cout << std::string(tab_shift + 3, '\t')
                << "Code length: " << code_attr->code_length << "\n";
      this->printAttributes(code_attr->attributes, code_attr->attributes_count,
                            tab_shift + 1, 20, 47);
      break;
    }
    case attrs::kEXCEPTIONS: {
      auto exception_attr = attribute->getClass<attrs::Exceptions_attribute>();
      std::vector<std::string> except_vars = {
          "Nr.",
          "Exception",
          "Verbose",
      };
      this->printTable(except_vars, exception_attr, tab_shift + 2);
      break;
    }
    case attrs::kINNERCLASS: {
      auto innerclass_attr =
          attribute->getClass<attrs::InnerClasses_attribute>();

      std::vector<std::string> inner_vars = {
          "Nr.", "Inner Class", "Outer Class", "Inner Name", "Access Flags",
      };
      this->printTable(inner_vars, innerclass_attr, tab_shift + 2);
      break;
    }
    case attrs::kENCLOSINGMETHOD: {
      auto enclosing_attr =
          attribute->getClass<attrs::EnclosingMethod_attribute>();
      std::cout << std::string(tab_shift + 2, '\t') << "Class index: 'cp_info #"
                << enclosing_attr->class_index << "' ";
      std::wcout << "<"
                 << this->getConstantPoolInfo(enclosing_attr->class_index,
                                              false)
                 << ">\n";

      std::cout << std::string(tab_shift + 2, '\t')
                << "Method index: 'cp_info #" << enclosing_attr->method_index
                << "' <";
      this->printConstantPoolInfo(enclosing_attr->method_index, 0, true, true);
      std::cout << ">\n";
      break;
    }
    case attrs::kSYNTHETIC: {
      break;
    }
    case attrs::kSIGNATURE: {
      auto signature_attr = attribute->getClass<attrs::Signature_attribute>();
      std::cout << std::string(tab_shift + 2, '\t')
                << "Signature index: 'cp_info #"
                << signature_attr->signature_index << "' ";
      std::wcout << "<"
                 << this->getConstantPoolInfo(signature_attr->signature_index,
                                              false)
                 << ">\n";
      break;
    }
    case attrs::kSOURCEFILE: {
      auto sourcefile_attr = attribute->getClass<attrs::SourceFile_attribute>();
      std::cout << std::string(tab_shift + 2, '\t')
                << "Source file name index: 'cp_info #"
                << sourcefile_attr->sourcefile_index << "' ";
      std::wcout << "<"
                 << this->getConstantPoolInfo(sourcefile_attr->sourcefile_index,
                                              false)
                 << ">\n";
      break;
    }
    case attrs::kLINENUMBERTABLE: {
      auto lnt_attr = attribute->getClass<attrs::LineNumberTable_attribute>();
      std::vector<std::string> vars = {"Nr.", "Start PC", "Line number"};
      this->printTable(vars, lnt_attr, tab_shift + 2);
      break;
    }
    case attrs::kLOCALVARIABLETABLE: {
      auto localvar_attr =
          attribute->getClass<attrs::LocalVariableTable_attribute>();
      std::vector<std::string> vars = {"Nr.", "Start PC", "Length", "Index",
                                       "Name"};
      this->printTable(vars, localvar_attr, tab_shift + 2);
      break;
    }
    case attrs::kDEPRECATED: {
      break;
    }
    case attrs::kBOOTSTRAPMETHODS: {
      auto bootstrap_attr =
          attribute->getClass<attrs::BootstrapMethods_attribute>();

      std::vector<std::string> inner_vars = {"Nr.", "Bootstrap Method",
                                             "Arguments"};
      this->printTable(inner_vars, bootstrap_attr, tab_shift + 2);
      break;
    }
    case attrs::kMETHODPARAMETERS: {
      break;
    }
    case attrs::kINVALID: {
      std::cout << std::string(tab_shift + 2, '\t') << "NOT IMPLEMENTED\n";
      break;
    }
  }
}
