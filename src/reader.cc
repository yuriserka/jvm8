#include "reader.h"

#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include "utils/constantPool.h"
#include "utils/errors.h"
#include "utils/flags.h"
#include "utils/infos.h"
#include "utils/utf8.h"
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
  if (Utils::Flags::options.kVERBOSE) {
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
  // this->readMethods();
  // this->readAttributes();
}

void Reader::readMagic() {
  this->readBytes(&this->classfile->magic);
  if (Utils::Flags::options.kVERBOSE) {
    state.copyfmt(std::cout);
    std::cout << "Read classfile->magic = '"
              << "0x" << std::setfill('0') << std::setw(4) << std::hex
              << std::uppercase << this->classfile->magic << "'\n";
    std::cout.copyfmt(state);
  }
  if (this->classfile->magic != 0xCAFEBABE) {
    std::stringstream err;
    err << "Magic number not equal to 0xCAFEBABE";
    throw Utils::Errors::Exception(Utils::Errors::KMAGIC, err.str());
  }
}

void Reader::readMinorVersion() {
  this->readBytes(&this->classfile->minor_version);
  if (Utils::Flags::options.kVERBOSE) {
    state.copyfmt(std::cout);
    std::cout << "Read classfile->minor_version = '" << std::hex
              << std::uppercase << this->classfile->minor_version << "'\n";
    std::cout.copyfmt(state);
  }
  if (this->classfile->minor_version > Utils::Versions::Java8) {
    std::stringstream err;
    err << "Minor version superior to 0x" << std::hex << std::uppercase
        << Utils::Versions::Java8;
    throw Utils::Errors::Exception(Utils::Errors::kMINOR, err.str());
  }
}

void Reader::readMajorVersion() {
  this->readBytes(&this->classfile->major_version);
  if (Utils::Flags::options.kVERBOSE) {
    state.copyfmt(std::cout);
    std::cout << "Read classfile->major_version = '"
              << "0x" << std::hex << std::uppercase
              << this->classfile->major_version << "'\n";
    std::cout.copyfmt(state);
  }
  if (this->classfile->major_version < Utils::Versions::Java8) {
    std::stringstream err;
    err << "Major version inferior to 0x" << std::hex << std::uppercase
        << Utils::Versions::Java8;
    throw Utils::Errors::Exception(Utils::Errors::kMAJOR, err.str());
  }
}

void Reader::readConstantPool() {
  this->readConstantPoolCount();
  this->classfile->constant_pool.resize(this->classfile->constant_pool_count -
                                        1);
  this->readConstantPoolInfo();
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "Read classfile->constant_pool\n";
  }
}

void Reader::readConstantPoolCount() {
  this->readBytes(&this->classfile->constant_pool_count);
  if (Utils::Flags::options.kVERBOSE) {
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
        auto kclass_info = constpool->setBase<info::CONSTANT_Class_info>(tag);
        this->readBytes(&kclass_info->name_index);
        break;
      }
      case cp::CONSTANT_Fieldref: {
        auto kfieldref_info =
            constpool->setBase<info::CONSTANT_FieldRef_info>(tag);
        this->readBytes(&kfieldref_info->class_index);
        this->readBytes(&kfieldref_info->name_and_type_index);
        break;
      }
      case cp::CONSTANT_Methodref: {
        auto kmethodref_info =
            constpool->setBase<info::CONSTANT_Methodref_info>(tag);
        this->readBytes(&kmethodref_info->class_index);
        this->readBytes(&kmethodref_info->name_and_type_index);
        break;
      }
      case cp::CONSTANT_InterfaceMethodref: {
        auto kInterfacemethodref_info =
            constpool->setBase<info::CONSTANT_InterfaceMethodref_info>(tag);
        this->readBytes(&kInterfacemethodref_info->class_index);
        this->readBytes(&kInterfacemethodref_info->name_and_type_index);
        break;
      }
      case cp::CONSTANT_String: {
        auto kstring_info = constpool->setBase<info::CONSTANT_String_info>(tag);
        this->readBytes(&kstring_info->string_index);
        break;
      }
      case cp::CONSTANT_Integer: {
        auto kinteger_info =
            constpool->setBase<info::CONSTANT_Integer_info>(tag);
        this->readBytes(&kinteger_info->bytes);
        break;
      }
      case cp::CONSTANT_Float: {
        auto kfloat_info = constpool->setBase<info::CONSTANT_Float_info>(tag);
        this->readBytes(&kfloat_info->bytes);
        break;
      }
      case cp::CONSTANT_Long: {
        auto klong_info = constpool->setBase<info::CONSTANT_Long_info>(tag);
        this->readBytes(&klong_info->high_bytes);
        this->readBytes(&klong_info->low_bytes);
        break;
      }
      case cp::CONSTANT_Double: {
        auto kdouble_info = constpool->setBase<info::CONSTANT_Double_info>(tag);
        this->readBytes(&kdouble_info->high_bytes);
        this->readBytes(&kdouble_info->low_bytes);
        break;
      }
      case cp::CONSTANT_NameAndType: {
        auto knameandtype_info =
            constpool->setBase<info::CONSTANT_NameAndType_info>(tag);
        this->readBytes(&knameandtype_info->name_index);
        this->readBytes(&knameandtype_info->descriptor_index);
        break;
      }
      case cp::CONSTANT_Utf8: {
        auto kutf8_info = constpool->setBase<info::CONSTANT_Utf8_info>(tag);
        this->readBytes(&kutf8_info->length);
        kutf8_info->bytes.resize(unsigned(kutf8_info->length));
        for (size_t i = 0; i < kutf8_info->bytes.size(); ++i) {
          this->readBytes(&kutf8_info->bytes[i]);
          auto ubyte = unsigned(kutf8_info->bytes[i]);
          if (ubyte == 0x0000 || (ubyte >= 0x00F0 && ubyte <= 0x00FF)) {
            std::stringstream err;
            err << "No byte may have the value 0x0000 or "
                << "lie in the range [0x00f0, 0x00FF]";
            throw Utils::Errors::Exception(Utils::Errors::kUTF8, err.str());
          }
        }
        break;
      }
      case cp::CONSTANT_MethodHandle: {
        auto kmethodhandler_info =
            constpool->setBase<info::CONSTANT_MethodHandle_info>(tag);
        this->readBytes(&kmethodhandler_info->reference_kind);
        if (kmethodhandler_info->reference_kind < 1 ||
            kmethodhandler_info->reference_kind > 9) {
          std::stringstream err;
          err << " reference_kind item must be in the range 1 to 9";
          throw Utils::Errors::Exception(Utils::Errors::kREFKIND, err.str());
        }
        this->readBytes(&kmethodhandler_info->reference_index);
        if (kmethodhandler_info->reference_kind >= 1 &&
            kmethodhandler_info->reference_kind <= 4) {
          constpool->setBase<info::CONSTANT_FieldRef_info>(tag);
        } else if (kmethodhandler_info->reference_kind == 5 ||
                   kmethodhandler_info->reference_kind == 8) {
          constpool->setBase<info::CONSTANT_Methodref_info>(tag);
        } else if (kmethodhandler_info->reference_kind == 6 ||
                   kmethodhandler_info->reference_kind == 7) {
          if (this->classfile->major_version < Utils::Versions::Java8) {
            constpool->setBase<info::CONSTANT_Methodref_info>(tag);
          }
        } else {
          constpool->setBase<info::CONSTANT_InterfaceMethodref_info>(tag);
        }
        break;
      }
      case cp::CONSTANT_MethodType: {
        auto kmethodtype_info =
            constpool->setBase<info::CONSTANT_MethodType_info>(tag);
        this->readBytes(&kmethodtype_info->descriptor_index);
        break;
      }
      case cp::CONSTANT_InvokeDynamic: {
        auto kinvokedynamic_info =
            constpool->setBase<info::CONSTANT_InvokeDynamic_info>(tag);
        this->readBytes(&kinvokedynamic_info->bootstrap_method_attr_index);
        this->readBytes(&kinvokedynamic_info->name_and_type_index);
        break;
      }
      default: {
        std::stringstream err;
        err << "Unknown constant pool tag = '" << unsigned(tag) << "'";
        throw Utils::Errors::Exception(Utils::Errors::kCONSTANTPOOL, err.str());
      }
    }
  }
}

void Reader::readAccessFlags() {
  this->readBytes(&this->classfile->access_flags);
  if (Utils::Flags::options.kVERBOSE) {
    state.copyfmt(std::cout);
    std::cout << "Read classfile->access_flags = '"
              << "0x" << std::setfill('0') << std::setw(4) << std::hex
              << std::uppercase << this->classfile->access_flags << "'\n";
    std::cout.copyfmt(state);
  }
}

void Reader::readThisClass() {
  this->readBytes(&this->classfile->this_class);
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "Read classfile->this_class = 'cp_info #"
              << this->classfile->this_class << "'\n";
  }
}

void Reader::readSuperClass() {
  this->readBytes(&this->classfile->super_class);
  if (Utils::Flags::options.kVERBOSE) {
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
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "Read classfile->interfaces\n";
  }
}

void Reader::readInterfaceCount() {
  this->readBytes(&this->classfile->interfaces_count);
  if (Utils::Flags::options.kVERBOSE) {
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
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "Read classfile->fields\n";
  }
}

void Reader::readFieldsCount() {
  this->readBytes(&this->classfile->fields_count);
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "Read classfile->fields_count = '"
              << this->classfile->fields_count << "'\n";
  }
}

void Reader::readFieldsInfo() {
  namespace info = Utils::Infos;
  auto kpool = this->classfile->constant_pool;
  for (auto i = 0; i < this->classfile->fields_count; ++i) {
    this->classfile->fields[i] = info::field_info();
    auto field = &this->classfile->fields[i];

    this->readBytes(&field->access_flags);

    this->readBytes(&field->name_index);
    if (!kpool[field->name_index - 1].getClass<info::CONSTANT_Utf8_info>()) {
      std::stringstream err;
      err << "The constant_pool entry at name_index must be a "
             "CONSTANT_Utf8_info";
      throw Utils::Errors::Exception(Utils::Errors::kFIELD, err.str());
    }

    this->readBytes(&field->descriptor_index);
    if (!kpool[field->descriptor_index - 1]
             .getClass<info::CONSTANT_Utf8_info>()) {
      std::stringstream err;
      err << "The constant_pool entry at descriptor_index must be a "
             "CONSTANT_Utf8_info";
      throw Utils::Errors::Exception(Utils::Errors::kFIELD, err.str());
    }

    this->readBytes(&field->attributes_count);
    field->attributes.resize(field->attributes_count);

    this->readAttributesInfo(field->attributes);
  }
}

void Reader::readMethods() {
  this->readMethodsCount();
  this->classfile->methods.resize(this->classfile->methods_count);
  this->readMethodsInfo();
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "Read classfile->methods\n";
  }
}

void Reader::readMethodsCount() {
  this->readBytes(&this->classfile->methods_count);
  if (Utils::Flags::options.kVERBOSE) {
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

    // this->readAttributesInfo(method->attributes);
  }
}

void Reader::readAttributes() {
  this->readAttributesCount();
  this->classfile->fields.resize(this->classfile->attributes_count);
  // this->readAttributesInfo(this->classfile->attributes);
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "Read classfile->attributes\n";
  }
}

void Reader::readAttributesCount() {
  this->readBytes(&this->classfile->attributes_count);
  if (Utils::Flags::options.kVERBOSE) {
    std::cout << "Read classfile->attributes_count = '"
              << this->classfile->attributes_count << "'\n";
  }
}

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

void Reader::readAttributesInfo(
    std::vector<Utils::Attributes::attribute_info> &attributes) {
  for (size_t i = 0; i < attributes.size(); ++i) {
    attributes[i] = Utils::Attributes::attribute_info();
    Utils::Attributes::attribute_info *attr = &attributes[i];
    types::u2 nameidx;
    types::u4 attrlen;
    this->readBytes(&nameidx);
    auto kutf8 = this->classfile->constant_pool[nameidx - 1]
                     .getClass<Utils::Infos::CONSTANT_Utf8_info>();
    if (!kutf8) {
      std::stringstream err;
      err << "The constant_pool entry at name_index must be a "
             "CONSTANT_Utf8_info";
      throw Utils::Errors::Exception(Utils::Errors::kATTRIBUTE, err.str());
    }
    this->readBytes(&attrlen);

    auto attrName = Utf8(kutf8);
    auto attrtype = getAttributeType(attrName);

    switch (attrtype) {
      namespace attrs = Utils::Attributes;
      case attrs::kCODE: {
        // auto code_attr = attr->setBase<attrs::Code_attribute>(nameidx,
        // attrlen);
        break;
      }
      case attrs::kCONSTANTVALUE: {
        auto kvalue_attr =
            attr->setBase<attrs::ConstantValue_attribute>(nameidx, attrlen);
        this->readBytes(&kvalue_attr->constantvalue_index);
        break;
      }
      case attrs::kDEPRECATED: {
        // auto deprecated_attr =
        //     attr->setBase<attrs::Deprecated_attribute>(nameidx, attrlen);
        break;
      }
      case attrs::kEXCEPTIONS: {
        // auto exceptions_attr =
        //     attr->setBase<attrs::Exceptions_attribute>(nameidx, attrlen);
        break;
      }
      case attrs::kLINENUMBERTABLE: {
        // auto linenumbertb_attr =
        //     attr->setBase<attrs::LineNumberTable_attribute>(nameidx,
        //     attrlen);
        break;
      }
      case attrs::kLOCALVARIABLETABLE: {
        // auto localvar_attr =
        // attr->setBase<attrs::LocalVariableTable_attribute>(
        //     nameidx, attrlen);
        break;
      }
      case attrs::kSOURCEFILE: {
        // auto sourcefile_attr =
        //     attr->setBase<attrs::SourceFile_attribute>(nameidx, attrlen);
        break;
      }
      case attrs::kINVALID: {
        if (Utils::Flags::options.kVERBOSE) {
          std::cout << "skipped attribute " << attrName.toString() << "\n";
        }
        break;
      }
    }
    //   std::wcout << L"found you -> " << *ok->toString();
    // } else {
    //   std::cout << "fodac entao nao achei";
    // }
    // attrTable.at(attrName)();
  }
}
