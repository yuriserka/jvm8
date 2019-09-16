#include "reader.h"

#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include "utils/constantPool.h"
#include "utils/errors.h"
#include "utils/flags.h"
#include "utils/infos.h"
#include "utils/versions.h"

static std::ios state(NULL);

Reader::Reader(ClassFile *cf, const std::string &fpath) {
  this->fname = fpath.substr(fpath.find_last_of("/\\") + 1);
  this->file = std::fstream(fpath, std::ios::binary | std::ios::in);
  this->classfile = cf;

  if (!this->file.is_open()) {
    throw Utils::Errors::Exception(
        Utils::Errors::kCLASSFILE,
        "classfile: " + this->fname + " cannot be opened.");
  }
  if (Utils::Flags::kVERBOSE) {
    std::cout << "classfile: '" << this->fname << "' opened\n";
  }
}

void Reader::readClassFile() {
  this->readMagic();
  this->readMinorVersion();
  this->readMajorVersion();
  this->readConstantPool();
  this->readAccessFlags();
  this->readThisClass();
  this->readSuperClass();
  this->readInterfaces();
  this->readFields();
  this->readMethods();
  this->readAttributes();
}

void Reader::readMagic() {
  this->readBytes(&this->classfile->magic);
  if (Utils::Flags::kVERBOSE) {
    state.copyfmt(std::cout);
    std::cout << "Read classfile->magic = '"
              << "0x" << std::hex << std::uppercase << this->classfile->magic
              << "'\n";
    std::cout.copyfmt(state);
  }
  if (this->classfile->magic != 0xCAFEBABE) {
    std::stringstream err;
    err << "[ERROR]: "
        << "Magic number not equal to 0xCAFEBABE";
    throw Utils::Errors::Exception(Utils::Errors::KMAGIC, err.str());
  }
}

void Reader::readMinorVersion() {
  this->readBytes(&this->classfile->minor_version);
  if (Utils::Flags::kVERBOSE) {
    state.copyfmt(std::cout);
    std::cout << "Read classfile->minor_version = '"
              << "0x" << std::hex << std::uppercase
              << this->classfile->minor_version << "'\n";
    std::cout.copyfmt(state);
  }
  if (this->classfile->minor_version > Utils::Versions::Java8) {
    std::stringstream err;
    err << "[ERROR]: "
        << "Minor version superior to 0x" << std::hex << std::uppercase
        << Utils::Versions::Java8 << "\n";
    throw Utils::Errors::Exception(Utils::Errors::kMINOR, err.str());
  }
}

void Reader::readMajorVersion() {
  this->readBytes(&this->classfile->major_version);
  if (Utils::Flags::kVERBOSE) {
    state.copyfmt(std::cout);
    std::cout << "Read classfile->major_version = '"
              << "0x" << std::hex << std::uppercase
              << this->classfile->major_version << "'\n";
    std::cout.copyfmt(state);
  }
  if (this->classfile->major_version < Utils::Versions::Java8) {
    std::stringstream err;
    err << "[ERROR]: "
        << "Major version inferior to 0x" << std::hex << std::uppercase
        << Utils::Versions::Java8 << "\n";
    throw Utils::Errors::Exception(Utils::Errors::kMAJOR, err.str());
  }
}

void Reader::readConstantPool() {
  this->readConstantPoolCount();
  this->classfile->constant_pool.resize(this->classfile->constant_pool_count -
                                        1);
  this->readConstantPoolInfo();
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->constant_pool\n";
  }
}

void Reader::readConstantPoolCount() {
  this->readBytes(&this->classfile->constant_pool_count);
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->constant_pool_count = '"
              << this->classfile->constant_pool_count << "'\n";
  }
}

/**
 * @brief fancy way to create any class with many args as necessary for the
 * constructor.
 *
 * @tparam T the class that will be created.
 * @tparam TArgs will be a list of all the args types passed.
 * @param[in] mArgs the multiple arguments used in constructor of class T.
 * @returns a pointer to the class.
 */
// template <typename T, typename... TArgs>
// T *createClass(TArgs &&...mArgs) {
//     void *objptr = std::malloc(sizeof(T));
//     auto constinfo = new (objptr) T(std::forward<TArgs>(mArgs)...);

//     return constinfo;
// }

void Reader::readConstantPoolInfo() {
  for (auto i = 0; i < this->classfile->constant_pool_count - 1; ++i) {
    this->classfile->constant_pool[i] = Utils::Infos::cp_info();
    auto constpool = &this->classfile->constant_pool[i];
    Utils::Types::u1 tag;
    this->readBytes(&tag);

    switch (tag) {
      namespace cp = Utils::ConstantPool;
      namespace info = Utils::Infos;
      case cp::CONSTANT_Class: {
        auto kclassinfo = constpool->setBase<info::CONSTANT_Class_info>(tag);
        this->readBytes(&kclassinfo->name_index);
        break;
      }
      case cp::CONSTANT_Fieldref: {
        auto kfieldref = constpool->setBase<info::CONSTANT_FieldRef_info>(tag);
        this->readBytes(&kfieldref->class_index);
        this->readBytes(&kfieldref->name_and_type_index);
        break;
      }
      case cp::CONSTANT_Methodref: {
        auto kmethodref =
            constpool->setBase<info::CONSTANT_Methodref_info>(tag);
        this->readBytes(&kmethodref->class_index);
        this->readBytes(&kmethodref->name_and_type_index);
        break;
      }
      case cp::CONSTANT_InterfaceMethodref: {
        auto kInterfacemethodref =
            constpool->setBase<info::CONSTANT_InterfaceMethodref_info>(tag);
        this->readBytes(&kInterfacemethodref->class_index);
        this->readBytes(&kInterfacemethodref->name_and_type_index);
        break;
      }
      case cp::CONSTANT_String: {
        auto kstring = constpool->setBase<info::CONSTANT_String_info>(tag);
        this->readBytes(&kstring->string_index);
        break;
      }
      case cp::CONSTANT_Integer: {
        auto kinteger = constpool->setBase<info::CONSTANT_Integer_info>(tag);
        this->readBytes(&kinteger->bytes);
        break;
      }
      case cp::CONSTANT_Float: {
        auto kfloat = constpool->setBase<info::CONSTANT_Float_info>(tag);
        this->readBytes(&kfloat->bytes);
        break;
      }
      case cp::CONSTANT_Long: {
        auto klong = constpool->setBase<info::CONSTANT_Long_info>(tag);
        this->readBytes(&klong->high_bytes);
        this->readBytes(&klong->low_bytes);
        break;
      }
      case cp::CONSTANT_Double: {
        auto kdouble = constpool->setBase<info::CONSTANT_Double_info>(tag);
        this->readBytes(&kdouble->high_bytes);
        this->readBytes(&kdouble->low_bytes);
        break;
      }
      case cp::CONSTANT_NameAndType: {
        auto knameandtype =
            constpool->setBase<info::CONSTANT_NameAndType_info>(tag);
        this->readBytes(&knameandtype->name_index);
        this->readBytes(&knameandtype->descriptor_index);
        break;
      }
      case cp::CONSTANT_Utf8: {
        auto kutf8 = constpool->setBase<info::CONSTANT_Utf8_info>(tag);
        this->readBytes(&kutf8->length);
        kutf8->bytes.resize(unsigned(kutf8->length));
        for (size_t i = 0; i < kutf8->bytes.size(); ++i) {
          this->readBytes(&kutf8->bytes[i]);
          auto ubyte = unsigned(kutf8->bytes[i]);
          if (ubyte == 0x0000 || (ubyte >= 0x00F0 && ubyte <= 0x00FF)) {
            std::stringstream err;
            err << "[ERROR]: "
                << "No byte may have the value 0x0000 or "
                << "lie in the range [0x00f0, 0x00FF]";
            throw Utils::Errors::Exception(Utils::Errors::kUTF8, err.str());
          }
        }
        break;
      }
      case cp::CONSTANT_MethodHandle: {
        auto kmethodhandler =
            constpool->setBase<info::CONSTANT_MethodHandle_info>(tag);
        this->readBytes(&kmethodhandler->reference_kind);
        if (kmethodhandler->reference_kind < 1 ||
            kmethodhandler->reference_kind > 9) {
          std::stringstream err;
          err << "[ERROR]: "
              << " reference_kind item must be in the range 1 to 9";
          throw Utils::Errors::Exception(Utils::Errors::kREFKIND, err.str());
        }
        this->readBytes(&kmethodhandler->reference_index);
        if (kmethodhandler->reference_kind >= 1 &&
            kmethodhandler->reference_kind <= 4) {
          constpool->setBase<info::CONSTANT_FieldRef_info>(tag);
        } else if (kmethodhandler->reference_kind == 5 ||
                   kmethodhandler->reference_kind == 8) {
          constpool->setBase<info::CONSTANT_Methodref_info>(tag);
        } else if (kmethodhandler->reference_kind == 6 ||
                   kmethodhandler->reference_kind == 7) {
          if (this->classfile->major_version < Utils::Versions::Java8) {
            constpool->setBase<info::CONSTANT_Methodref_info>(tag);
          }
        } else {
          constpool->setBase<info::CONSTANT_InterfaceMethodref_info>(tag);
        }
        break;
      }
      case cp::CONSTANT_MethodType: {
        auto kmethodtype =
            constpool->setBase<info::CONSTANT_MethodType_info>(tag);
        this->readBytes(&kmethodtype->descriptor_index);
        break;
      }
      case cp::CONSTANT_InvokeDynamic: {
        auto kinvokedynamic =
            constpool->setBase<info::CONSTANT_InvokeDynamic_info>(tag);
        this->readBytes(&kinvokedynamic->bootstrap_method_attr_index);
        this->readBytes(&kinvokedynamic->name_and_type_index);
        break;
      }
      default: {
        std::stringstream err;
        err << "[ERROR]: "
            << "Unknown constant pool tag = '" << unsigned(tag) << "'\n";
        throw Utils::Errors::Exception(Utils::Errors::kCONSTANTPOOL, err.str());
      }
    }
  }
}

void Reader::readAccessFlags() {
  this->readBytes(&this->classfile->access_flags);
  if (Utils::Flags::kVERBOSE) {
    state.copyfmt(std::cout);
    std::cout << "Read classfile->access_flags = '"
              << "0x" << std::hex << std::uppercase
              << this->classfile->access_flags << "'\n";
    std::cout.copyfmt(state);
  }
}

void Reader::readThisClass() {
  this->readBytes(&this->classfile->this_class);
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->this_class = 'cp_info #"
              << this->classfile->this_class << "'\n";
  }
}

void Reader::readSuperClass() {
  this->readBytes(&this->classfile->super_class);
  if (Utils::Flags::kVERBOSE) {
    if (!this->classfile->super_class) {
      std::cout << "Read classfile->super_class = none\n";
    } else {
      std::cout << "Read classfile->super_class = 'cp_info #"
                << this->classfile->super_class << "'\n";
    }
  }
}

void Reader::readInterfaces() {
  this->readInterfaceCount();
  this->classfile->interfaces.resize(this->classfile->interfaces_count);
  this->readInterfaceInfo();
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->interfaces\n";
  }
}

void Reader::readInterfaceCount() {
  this->readBytes(&this->classfile->interfaces_count);
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->interfaces_count = '"
              << this->classfile->interfaces_count << "'\n";
  }
}

void Reader::readInterfaceInfo() {
  for (auto i = 0; i < this->classfile->interfaces_count; ++i) {
    auto interface = this->classfile->interfaces[i];
    this->readBytes(&interface);
  }
}

void Reader::readFields() {
  this->readFieldsCount();
  this->classfile->fields.resize(this->classfile->fields_count);
  this->readFieldsInfo();
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->fields\n";
  }
}

void Reader::readFieldsCount() {
  this->readBytes(&this->classfile->fields_count);
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->fields_count = '"
              << this->classfile->fields_count << "'\n";
  }
}

void Reader::readFieldsInfo() {
  for (auto i = 0; i < this->classfile->fields_count; ++i) {
    this->classfile->fields[i] = Utils::Infos::field_info();
    auto field = &this->classfile->fields[i];
    this->readBytes(&field->access_flags);
    this->readBytes(&field->name_index);
    this->readBytes(&field->descriptor_index);
    this->readBytes(&field->attributes_count);
    field->attributes.resize(field->attributes_count);
    this->readBytes(&field->descriptor_index);

    // this->readAttributesInfo(&field->attributes);
  }
}

void Reader::readMethods() {
  this->readMethodsCount();
  this->classfile->methods.resize(this->classfile->methods_count);
  this->readMethodsInfo();
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->methods\n";
  }
}

void Reader::readMethodsCount() {
  this->readBytes(&this->classfile->methods_count);
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->methods_count = '"
              << this->classfile->methods_count << "'\n";
  }
}

void Reader::readMethodsInfo() {
  for (auto i = 0; i < this->classfile->methods_count; ++i) {
    this->classfile->methods[i] = Utils::Infos::method_info();
    auto method = &this->classfile->methods[i];
    this->readBytes(&method->access_flags);
    this->readBytes(&method->name_index);
    this->readBytes(&method->descriptor_index);
    this->readBytes(&method->attributes_count);
    method->attributes.resize(method->attributes_count);

    // this->readAttributesInfo(&method->attributes);
  }
}

void Reader::readAttributes() {
  this->readAttributesCount();
  this->classfile->fields.resize(this->classfile->attributes_count);
  // this->readAttributesInfo(&this->classfile->attributes);
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->attributes\n";
  }
}

void Reader::readAttributesCount() {
  this->readBytes(&this->classfile->attributes_count);
  if (Utils::Flags::kVERBOSE) {
    std::cout << "Read classfile->attributes_count = '"
              << this->classfile->attributes_count << "'\n";
  }
}

void Reader::readAttributesInfo(
    std::vector<Utils::Attributes::attribute_info> *attributes) {
  // std::map<std::string, void (*)(Utils::Attributes::attribute_info *)>
  // attributesFunction = {
  //     {"ConstantValue", NULL},
  //     {"Code", NULL},
  //     {"Exceptions", NULL},
  //     {"SourceFile", NULL},
  //     {"LineNumberTable", NULL},
  //     {"LocalVariableTable", NULL},
  //     {"Deprecated", NULL},
  // };
  // for (size_t i = 0; i < attributes.size(); ++i) {
  //     attributes[i] = Utils::Attributes::attribute_info();
  //     auto attr = &attributes[i];
  //     namespace info = Utils::Infos;
  //     types::u2 nameidx;
  //     types::u4 attrlen;
  //     this->readBytes(&nameidx);
  //     this->readBytes(&attrlen);
  //     auto constpool = this->classfile->constant_pool[nameidx];
  //     std::vector<types::u1> nameBytes =
  //     constpool.getClass<info::CONSTANT_Utf8_info>()->bytes;
  //     attributesFunction.at(nameBytes)(attr);
  // }
}
