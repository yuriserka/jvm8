#include "viewer.h"

#include <algorithm>
#include <codecvt>
#include <cstring>
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
  this->printAttributes();
}

void Viewer::printMagic() {
  state.copyfmt(std::cout);
  std::cout << "Magic: '"
            << "0x" << std::hex << std::uppercase << this->classfile->magic
            << "'\n";
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
  for (auto i = 0; i < this->classfile->constant_pool_count - 1; ++i) {
    this->printConstantPoolInfo(i, 2, false);
  }
}

template <typename T>
void Viewer::printReferences(const T *kinfo, const int &depth,
                             const bool &inner) {
  if (!inner) {
    std::cout << std::string(depth, '\t')
              << "Class Index: " << kinfo->class_index << "\n";
  }
  this->printConstantPoolInfo(kinfo->class_index - 1, depth + 1, true);
  if (!inner) {
    std::cout << std::string(depth, '\t')
              << "Name and Type Index: " << kinfo->name_and_type_index << "\n";
  }
  this->printConstantPoolInfo(kinfo->name_and_type_index - 1, depth + 1, true);
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
                << "0x" << std::hex << std::uppercase << kinfo->bytes << "'\n";
      std::cout.copyfmt(state);
      std::cout << std::string(depth, '\t') << "Value: '" << kinfo->bytes
                << "'\n";
      break;
    }
    case cp::CONSTANT_Float: {
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
      std::cout << std::string(depth, '\t') << "Value: '" << u8val << "'\n";
      break;
    }
    case cp::CONSTANT_Double: {
      double d = copyCast<double>(&u8val);
      std::cout << std::string(depth, '\t') << "Value: '" << d << "'\n";
      break;
    }
  }
}

void Viewer::printConstantPoolInfo(const int &index, const int &depth,
                                   const bool &inner) {
  auto constpool = this->classfile->constant_pool[index];
  if (!inner) {
    std::cout << "\tcp_info '#" << index + 1 << "': ";
    auto name = Utils::ConstantPool::getConstantTypename(constpool.base->tag);
    std::cout << "CONSTANT_" << name << "_info\n";
  }
  switch (constpool.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::CONSTANT_Class: {
      auto kclassinfo = constpool.getClass<info::CONSTANT_Class_info>();
      if (!inner) {
        std::cout << std::string(depth, '\t') << "Name index = 'cp_info #"
                  << kclassinfo->name_index << "'\n";
      }
      this->printConstantPoolInfo(kclassinfo->name_index - 1,
                                  inner ? depth : depth + 1, true);
      break;
    }
    case cp::CONSTANT_Fieldref: {
      auto kfieldrefinfo = constpool.getClass<info::CONSTANT_FieldRef_info>();
      this->printReferences(kfieldrefinfo, depth, inner);
      break;
    }
    case cp::CONSTANT_Methodref: {
      auto kmethodrefinfo = constpool.getClass<info::CONSTANT_Methodref_info>();
      this->printReferences(kmethodrefinfo, depth, inner);
      break;
    }
    case cp::CONSTANT_InterfaceMethodref: {
      auto kImethodrefinfo =
          constpool.getClass<info::CONSTANT_InterfaceMethodref_info>();
      this->printReferences(kImethodrefinfo, depth, inner);
      break;
    }
    case cp::CONSTANT_String: {
      auto kstringinfo = constpool.getClass<info::CONSTANT_String_info>();
      if (!inner) {
        std::cout << std::string(depth, '\t') << "String index = 'cp_info #"
                  << kstringinfo->string_index << "'\n";
      }
      this->printConstantPoolInfo(kstringinfo->string_index - 1,
                                  inner ? depth : depth + 1, true);
      break;
    }
    case cp::CONSTANT_Integer: {
      auto kintegerinfo = constpool.getClass<info::CONSTANT_Integer_info>();
      this->print4bytesNumeral(kintegerinfo, depth, inner);
      break;
    }
    case cp::CONSTANT_Float: {
      auto kfloatinfo = constpool.getClass<info::CONSTANT_Float_info>();
      this->print4bytesNumeral(kfloatinfo, depth, inner);
      break;
    }
    case cp::CONSTANT_Long: {
      auto klonginfo = constpool.getClass<info::CONSTANT_Long_info>();
      this->print8bytesNumeral(klonginfo, depth, inner);
      break;
    }
    case cp::CONSTANT_Double: {
      auto kdoubleinfo = constpool.getClass<info::CONSTANT_Double_info>();
      this->print8bytesNumeral(kdoubleinfo, depth, inner);
      break;
    }
    case cp::CONSTANT_NameAndType: {
      auto knametypeinfo =
          constpool.getClass<info::CONSTANT_NameAndType_info>();
      if (!inner) {
        std::cout << std::string(depth, '\t') << "Name index = 'cp_info #"
                  << knametypeinfo->name_index << "'\n";
      }
      this->printConstantPoolInfo(knametypeinfo->name_index - 1,
                                  inner ? depth : depth + 1, true);
      if (!inner) {
        std::cout << std::string(depth, '\t') << "Descriptor index = 'cp_info #"
                  << knametypeinfo->descriptor_index << "'\n";
      }
      this->printConstantPoolInfo(knametypeinfo->descriptor_index - 1,
                                  inner ? depth : depth + 1, true);
      break;
    }
    case cp::CONSTANT_Utf8: {
      auto kutf8 = constpool.getClass<info::CONSTANT_Utf8_info>();
      if (!inner) {
        std::cout << std::string(depth, '\t')
                  << "Length of byte array: " << kutf8->length << "\n";
        std::cout << std::string(depth, '\t') << "String: ";
      }
      auto utf8string = Utf8(kutf8);
      std::cout << (inner ? std::string(depth, '\t') : "");
      std::wcout << L"\"" << utf8string << L"\"\n";
      break;
    }
  }
  if (!inner) std::cout << "\n";
}

void Viewer::printAccessFlags() {
  auto flags = Utils::Access::getClassAccessType(this->classfile->access_flags);
  state.copyfmt(std::cout);
  std::cout << "Access Flags: '"
            << "0x" << std::hex << std::uppercase
            << this->classfile->access_flags << "' [";
  std::cout.copyfmt(state);
  for (size_t i = 0; i < flags.size(); ++i) {
    std::cout << flags[i] << (i < flags.size() - 1 ? " " : "]\n");
  }
}

void Viewer::printThisClass() {
  std::cout << "This class: \n";
  this->printConstantPoolInfo(this->classfile->this_class - 1, 1, false);
}

void Viewer::printSuperClass() {
  std::cout << "Super class: \n";
  this->printConstantPoolInfo(this->classfile->super_class - 1, 1, false);
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

void Viewer::printAttributes() {
  std::cout << "Attributes Count: " << this->classfile->attributes_count
            << "\n";
  if (!this->classfile->attributes_count) {
    return;
  }
  std::cout << "Attributes:\n";
  for (auto i = 0; i < this->classfile->attributes_count; ++i) {
    this->printAttributesInfo(i, 1);
  }
}

void Viewer::printAttributesInfo(const int &index, const int &depth) {
  std::cout << std::string(depth, '\t') << "attribute #" << index << "\n";
}
