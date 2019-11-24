#include "reader.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include "utils/constantPool.h"
#include "utils/errors.h"
#include "utils/fileSystem.h"
#include "utils/flags.h"
#include "utils/infos.h"
#include "utils/string.h"
#include "utils/versions.h"

static std::ios state(NULL);

Reader::Reader(ClassFile *cf, const std::string &fpath) {
  this->fname = fpath.substr(fpath.find_last_of("/\\") + 1);
  std::string p;

  auto has_path = fpath.find(Utils::Flags::options.kPATH);
  if (has_path == std::string::npos) {
    p = Utils::Flags::options.kPATH + []() -> std::string {
      auto has_end_slash = Utils::Flags::options.kPATH.find_last_of("/\\");
      if (has_end_slash != Utils::Flags::options.kPATH.size() - 1) {
        return "/";
      }
      return "";
    }() + fpath;
  } else {
    p = fpath;
  }
  this->path = p.substr(0, p.find_last_of("/\\") + 1);

  this->file.open(p, std::ios::binary | std::ios::in);
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
  if (!Utils::Flags::options.kIGNORE) {
    auto minver = Utils::String::toString(this->classfile->minor_version);
    auto maxver =
        Utils::String::toString(Utils::Versions::getJava8version()) + minver;

    auto v =
        stod(Utils::String::toString(this->classfile->major_version) + minver);
    if (v < std::stod(minver + ".0") || v > std::stod(maxver)) {
      std::stringstream ss;
      ss << "This JVM implementation support a class file of version v "
         << "if and only if v lies in range " << this->classfile->minor_version
         << ".0 ≤ v ≤ " << Utils::Versions::getJava8version() << "."
         << this->classfile->minor_version;
      throw Utils::Errors::Exception(Utils::Errors::kMAJOR, ss.str());
    }
  }
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
  // if (this->classfile->minor_version > Utils::Versions::getJava8version()) {
  //   std::stringstream err;
  //   err << "Minor version superior to 0x" << std::hex << std::uppercase
  //       << Utils::Versions::getJava8version();
  //   throw Utils::Errors::Exception(Utils::Errors::kMINOR, err.str());
  // }
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
  // if (this->classfile->major_version < Utils::Versions::getJava8version()) {
  //   std::stringstream err;
  //   err << "Major version inferior to 0x" << std::hex << std::uppercase
  //       << Utils::Versions::getJava8version();
  //   throw Utils::Errors::Exception(Utils::Errors::kMAJOR, err.str());
  // }
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

void Reader::readConstantPoolInfo() {
  for (auto i = 0; i < this->classfile->constant_pool_count - 1; ++i) {
    this->classfile->constant_pool[i] = Utils::ConstantPool::cp_info();
    auto constpool = &this->classfile->constant_pool[i];
    Utils::Types::u1 tag;
    this->readBytes(&tag, false);

    switch (tag) {
      namespace cp = Utils::ConstantPool;
      case cp::kCONSTANT_CLASS: {
        auto kclass_info = constpool->setBase<cp::CONSTANT_Class_info>(tag);
        this->readBytes(&kclass_info->name_index);
        break;
      }
      case cp::kCONSTANT_FIELDREF: {
        auto kfieldref_info =
            constpool->setBase<cp::CONSTANT_FieldRef_info>(tag);
        this->readBytes(&kfieldref_info->class_index);
        this->readBytes(&kfieldref_info->name_and_type_index);
        break;
      }
      case cp::kCONSTANT_METHODREF: {
        auto kmethodref_info =
            constpool->setBase<cp::CONSTANT_Methodref_info>(tag);
        this->readBytes(&kmethodref_info->class_index);
        this->readBytes(&kmethodref_info->name_and_type_index);
        break;
      }
      case cp::kCONSTANT_INTERFACEMETHODREF: {
        auto kInterfacemethodref_info =
            constpool->setBase<cp::CONSTANT_InterfaceMethodref_info>(tag);
        this->readBytes(&kInterfacemethodref_info->class_index);
        this->readBytes(&kInterfacemethodref_info->name_and_type_index);
        break;
      }
      case cp::kCONSTANT_STRING: {
        auto kstring_info = constpool->setBase<cp::CONSTANT_String_info>(tag);
        this->readBytes(&kstring_info->string_index);
        break;
      }
      case cp::kCONSTANT_INTEGER: {
        auto kinteger_info = constpool->setBase<cp::CONSTANT_Integer_info>(tag);
        this->readBytes(&kinteger_info->bytes);
        break;
      }
      case cp::kCONSTANT_FLOAT: {
        auto kfloat_info = constpool->setBase<cp::CONSTANT_Float_info>(tag);
        this->readBytes(&kfloat_info->bytes);
        break;
      }
      case cp::kCONSTANT_LONG: {
        auto klong_info = constpool->setBase<cp::CONSTANT_Long_info>(tag);
        this->readBytes(&klong_info->high_bytes);
        this->readBytes(&klong_info->low_bytes);
        ++i;
        break;
      }
      case cp::kCONSTANT_DOUBLE: {
        auto kdouble_info = constpool->setBase<cp::CONSTANT_Double_info>(tag);
        this->readBytes(&kdouble_info->high_bytes);
        this->readBytes(&kdouble_info->low_bytes);
        ++i;
        break;
      }
      case cp::kCONSTANT_NAMEANDTYPE: {
        auto knameandtype_info =
            constpool->setBase<cp::CONSTANT_NameAndType_info>(tag);
        this->readBytes(&knameandtype_info->name_index);
        this->readBytes(&knameandtype_info->descriptor_index);
        break;
      }
      case cp::kCONSTANT_UTF8: {
        auto kutf8_info = constpool->setBase<cp::CONSTANT_Utf8_info>(tag);
        this->readBytes(&kutf8_info->length);
        kutf8_info->bytes.resize(kutf8_info->length);
        for (auto i = 0; i < kutf8_info->length; ++i) {
          this->readBytes(&kutf8_info->bytes[i], false);
          auto ubyte = +kutf8_info->bytes[i];
          if (ubyte == 0x0000 || (ubyte >= 0x00F0 && ubyte <= 0x00FF)) {
            std::stringstream err;
            err << "No byte may have the value 0x0000 or "
                << "lie in the range [0x00f0, 0x00FF]";
            throw Utils::Errors::Exception(Utils::Errors::kUTF8, err.str());
          }
        }
        break;
      }
      case cp::kCONSTANT_METHODHANDLE: {
        auto kmethodhandler_info =
            constpool->setBase<cp::CONSTANT_MethodHandle_info>(tag);
        this->readBytes(&kmethodhandler_info->reference_kind, false);
        if (kmethodhandler_info->reference_kind < 1 ||
            kmethodhandler_info->reference_kind > 9) {
          std::stringstream err;
          err << " reference_kind item must be in the range 1 to 9";
          throw Utils::Errors::Exception(Utils::Errors::kREFKIND, err.str());
        }
        this->readBytes(&kmethodhandler_info->reference_index);
        break;
      }
      case cp::kCONSTANT_METHODTYPE: {
        auto kmethodtype_info =
            constpool->setBase<cp::CONSTANT_MethodType_info>(tag);
        this->readBytes(&kmethodtype_info->descriptor_index);
        break;
      }
      case cp::kCONSTANT_INVOKEDYNAMIC: {
        auto kinvokedynamic_info =
            constpool->setBase<cp::CONSTANT_InvokeDynamic_info>(tag);
        this->readBytes(&kinvokedynamic_info->bootstrap_method_attr_index);
        this->readBytes(&kinvokedynamic_info->name_and_type_index);
        break;
      }
      default: {
        std::stringstream err;
        err << "Unknown constant pool tag = '" << +tag << "'";
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
    std::cout << "Read classfile->this_class = #" << this->classfile->this_class
              << "\n";
  }
}

void Reader::readSuperClass() {
  this->readBytes(&this->classfile->super_class);
  if (Utils::Flags::options.kVERBOSE) {
    if (!this->classfile->super_class) {
      std::cout << "Read classfile->super_class = none\n";
    } else {
      std::cout << "Read classfile->super_class = #"
                << this->classfile->super_class << "\n";
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
    this->readBytes(&this->classfile->interfaces[i]);
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
  auto kpool = this->classfile->constant_pool;
  for (auto i = 0; i < this->classfile->fields_count; ++i) {
    this->classfile->fields[i] = Utils::Infos::field_info();
    auto field = &this->classfile->fields[i];

    this->readBytes(&field->access_flags);

    this->readBytes(&field->name_index);
    this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Utf8_info>(
        field->name_index, "name_index", Utils::ConstantPool::kCONSTANT_UTF8);

    this->readBytes(&field->descriptor_index);
    this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Utf8_info>(
        field->descriptor_index, "descriptor_index",
        Utils::ConstantPool::kCONSTANT_UTF8);

    this->readBytes(&field->attributes_count);
    field->attributes.resize(field->attributes_count);

    this->readAttributesInfo(&field->attributes);
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

    this->readAttributesInfo(&method->attributes);
  }
}

void Reader::readAttributes() {
  this->readAttributesCount();
  this->classfile->attributes.resize(this->classfile->attributes_count);
  this->readAttributesInfo(&this->classfile->attributes);
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

void Reader::kpoolValidEntry(const Utils::Types::u2 &index,
                             const std::string &indexname) {
  try {
    this->classfile->constant_pool.at(index - 1);
  } catch (const std::exception &e) {
    throw Utils::Errors::Exception(Utils::Errors::kATTRIBUTE,
                                   "The value of " + indexname +
                                       "must be a valid index into the "
                                       "constant_pool table");
  }
}

void Reader::readAttributesInfo(
    std::vector<Utils::Attributes::attribute_info> *attributes) {
  for (size_t i = 0; i < attributes->size(); ++i) {
    attributes->at(i) = Utils::Attributes::attribute_info();
    Utils::Attributes::attribute_info *attr = &attributes->at(i);
    Utils::Types::u2 nameidx;
    Utils::Types::u4 attrlen;

    this->readBytes(&nameidx);
    auto kutf8 = this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Utf8_info>(
        nameidx, "name_index", Utils::ConstantPool::kCONSTANT_UTF8);

    this->readBytes(&attrlen);

    auto attrName = Utils::String::getUtf8Modified(kutf8);
    auto attrtype = Utils::Attributes::getAttributeType(attrName);

    switch (attrtype) {
      namespace attrs = Utils::Attributes;
      case attrs::kCONSTANTVALUE: {
        auto kvalue_attr =
            attr->setBase<attrs::ConstantValue_attribute>(nameidx, attrlen);
        this->readBytes(&kvalue_attr->constantvalue_index);

        this->kpoolValidEntry(kvalue_attr->constantvalue_index,
                              "constantvalue_index");
        break;
      }
      case attrs::kCODE: {
        auto code_attr = attr->setBase<attrs::Code_attribute>(nameidx, attrlen);
        this->readBytes(&code_attr->max_stack);
        this->readBytes(&code_attr->max_locals);

        this->readBytes(&code_attr->code_length);
        if (code_attr->code_length <= 0 || code_attr->code_length >= 65536) {
          throw Utils::Errors::Exception(
              Utils::Errors::kATTRIBUTE,
              "The value of code_length must be greater than zero and less "
              "than 65536.");
        }
        code_attr->code.resize(code_attr->code_length);
        for (size_t i = 0; i < code_attr->code_length; ++i) {
          this->readBytes(&code_attr->code[i], false);
        }

        this->readBytes(&code_attr->exception_table_length);
        code_attr->exception_table.resize(code_attr->exception_table_length);
        for (auto i = 0; i < code_attr->exception_table_length; ++i) {
          code_attr->exception_table[i] = excption_info();
          auto excpt = &code_attr->exception_table[i];
          this->readBytes(&excpt->start_pc);
          try {
            code_attr->code.at(excpt->start_pc);
          } catch (const std::exception &e) {
            throw Utils::Errors::Exception(Utils::Errors::kATTRIBUTE,
                                           "The value of start_pc must be a "
                                           "valid index into the code array");
          }
          this->readBytes(&excpt->end_pc);
          try {
            code_attr->code.at(excpt->end_pc);
          } catch (const std::exception &e) {
            throw Utils::Errors::Exception(Utils::Errors::kATTRIBUTE,
                                           "The value of end_pc must be a "
                                           "valid index into the code array");
          }
          this->readBytes(&excpt->handler_pc);
          try {
            code_attr->code.at(excpt->handler_pc);
          } catch (const std::exception &e) {
            throw Utils::Errors::Exception(Utils::Errors::kATTRIBUTE,
                                           "The value of handler_pc must be a "
                                           "valid index into the code array");
          }
          this->readBytes(&excpt->catch_type);
          if (excpt->catch_type != 0) {
            this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Class_info>(
                excpt->catch_type, "catch_type",
                Utils::ConstantPool::kCONSTANT_CLASS);
          }
        }
        this->readBytes(&code_attr->attributes_count);
        code_attr->attributes.resize(code_attr->attributes_count);
        this->readAttributesInfo(&code_attr->attributes);

        for (auto &attr_info : code_attr->attributes) {
          auto linenumbertb =
              attr_info
                  .getClass<Utils::Attributes::LineNumberTable_attribute>();
          if (linenumbertb) {
            auto lnt = linenumbertb->line_number_table;
            auto found = std::find_if(
                lnt.begin(), lnt.end(),
                [&code_attr](const lineNumberTable_info &lnt_info) {
                  return lnt_info.start_pc >= code_attr->code_length;
                });
            if (found != lnt.end()) {
              throw Utils::Errors::Exception(
                  Utils::Errors::kATTRIBUTE,
                  "The value of start_pc must be less than the value "
                  "of the code_length");
            }
          }
        }

        for (auto &attr_info : code_attr->attributes) {
          auto localvar =
              attr_info
                  .getClass<Utils::Attributes::LocalVariableTable_attribute>();
          if (localvar) {
            auto lvt = localvar->local_variable_table;
            for (auto lvt_info : lvt) {
              try {
                code_attr->code.at(lvt_info.start_pc);
              } catch (const std::exception &e) {
                throw Utils::Errors::Exception(
                    Utils::Errors::kATTRIBUTE,
                    "The value of start_pc must be a valid index into "
                    "the code array");
              }
              try {
                code_attr->code.at(lvt_info.start_pc + lvt_info.length - 1);
              } catch (const std::exception &e) {
                throw Utils::Errors::Exception(
                    Utils::Errors::kATTRIBUTE,
                    "The value of start_pc + length must be a valid "
                    "index into the code array");
              }
            }
          }
        }
        break;
      }
      case attrs::kEXCEPTIONS: {
        auto exceptions_attr =
            attr->setBase<attrs::Exceptions_attribute>(nameidx, attrlen);
        this->readBytes(&exceptions_attr->number_of_exceptions);

        exceptions_attr->exception_index_table.resize(
            exceptions_attr->number_of_exceptions);

        for (auto i = 0; i < exceptions_attr->number_of_exceptions; ++i) {
          this->readBytes(&exceptions_attr->exception_index_table[i]);
          auto exceptit = exceptions_attr->exception_index_table[i];
          this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Class_info>(
              exceptit, "exception_index_table",
              Utils::ConstantPool::kCONSTANT_CLASS);
        }
        break;
      }
      case attrs::kINNERCLASSES: {
        auto innerclass_attr =
            attr->setBase<attrs::InnerClasses_attribute>(nameidx, attrlen);
        this->readBytes(&innerclass_attr->number_of_classes);
        innerclass_attr->classes.resize(innerclass_attr->number_of_classes);

        for (auto i = 0; i < innerclass_attr->number_of_classes; ++i) {
          innerclass_attr->classes[i] = innerClasses_info();
          auto inner_info = &innerclass_attr->classes[i];
          this->readBytes(&inner_info->inner_class_info_index);
          this->readBytes(&inner_info->outer_class_info_index);
          this->readBytes(&inner_info->inner_name_index);
          this->readBytes(&inner_info->inner_class_access_flags);
        }
        break;
      }
      case attrs::kENCLOSINGMETHOD: {
        auto enclosing_attr =
            attr->setBase<attrs::EnclosingMethod_attribute>(nameidx, attrlen);
        this->readBytes(&enclosing_attr->class_index);
        this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Class_info>(
            enclosing_attr->class_index, "class_index",
            Utils::ConstantPool::kCONSTANT_CLASS);
        this->readBytes(&enclosing_attr->method_index);
        if (enclosing_attr->method_index) {
          this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_NameAndType_info>(
              enclosing_attr->method_index, "method_index",
              Utils::ConstantPool::kCONSTANT_NAMEANDTYPE);
        }
        break;
      }
      case attrs::kSYNTHETIC: {
        attr->setBase<attrs::Synthetic_attribute>(nameidx, attrlen);
        break;
      }
      case attrs::kSIGNATURE: {
        auto signature_attr =
            attr->setBase<attrs::Signature_attribute>(nameidx, attrlen);
        this->readBytes(&signature_attr->signature_index);
        this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Utf8_info>(
            signature_attr->signature_index, "signature_index",
            Utils::ConstantPool::kCONSTANT_UTF8);
        break;
      }
      case attrs::kSOURCEFILE: {
        auto sourcefile_attr =
            attr->setBase<attrs::SourceFile_attribute>(nameidx, attrlen);
        this->readBytes(&sourcefile_attr->sourcefile_index);

        auto class_name =
            this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Utf8_info>(
                    sourcefile_attr->sourcefile_index, "sourcefile_index",
                    Utils::ConstantPool::kCONSTANT_UTF8)
                ->getValue();
        class_name = class_name.substr(0, class_name.find_last_of('.'));

        auto path_files = Utils::FileSystem::getFileNames(this->path);

        auto it_class_file = std::find_if(
            path_files.begin(), path_files.end(),
            [&class_name](const std::string &s) {
              return !class_name.compare(s.substr(0, s.find_last_of('.')));
            });
        if (it_class_file == path_files.end()) {
          throw Utils::Errors::Exception(
              Utils::Errors::kSOURCE,
              "Class file " + class_name + " not found on path " + this->path);
        }
        break;
      }
      case attrs::kLINENUMBERTABLE: {
        auto linenumbertb_attr =
            attr->setBase<attrs::LineNumberTable_attribute>(nameidx, attrlen);
        this->readBytes(&linenumbertb_attr->line_number_table_length);
        linenumbertb_attr->line_number_table.resize(
            linenumbertb_attr->line_number_table_length);

        for (auto i = 0; i < linenumbertb_attr->line_number_table_length; ++i) {
          linenumbertb_attr->line_number_table[i] = lineNumberTable_info();
          auto lnt_info = &linenumbertb_attr->line_number_table[i];
          this->readBytes(&lnt_info->start_pc);
          this->readBytes(&lnt_info->line_number);
        }
        break;
      }
      case attrs::kLOCALVARIABLETABLE: {
        auto localvar_attr = attr->setBase<attrs::LocalVariableTable_attribute>(
            nameidx, attrlen);
        this->readBytes(&localvar_attr->local_variable_table_length);
        localvar_attr->local_variable_table.resize(
            localvar_attr->local_variable_table_length);

        for (auto i = 0; i < localvar_attr->local_variable_table_length; ++i) {
          localvar_attr->local_variable_table[i] = localVariableTable_info();
          auto localvar_info = &localvar_attr->local_variable_table[i];
          this->readBytes(&localvar_info->start_pc);
          this->readBytes(&localvar_info->length);

          this->readBytes(&localvar_info->name_index);
          this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Utf8_info>(
              localvar_info->name_index, "name_index",
              Utils::ConstantPool::kCONSTANT_UTF8);

          this->readBytes(&localvar_info->descriptor_index);
          this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Utf8_info>(
              localvar_info->descriptor_index, "descriptor_index",
              Utils::ConstantPool::kCONSTANT_UTF8);

          this->readBytes(&localvar_info->index);
        }
        break;
      }
      case attrs::kDEPRECATED: {
        attr->setBase<attrs::Deprecated_attribute>(nameidx, attrlen);
        break;
      }
      case attrs::kBOOTSTRAPMETHODS: {
        auto bootstrap_attr =
            attr->setBase<attrs::BootstrapMethods_attribute>(nameidx, attrlen);
        this->readBytes(&bootstrap_attr->num_bootstrap_methods);
        bootstrap_attr->bootstrap_methods.resize(
            bootstrap_attr->num_bootstrap_methods);

        for (auto i = 0; i < bootstrap_attr->num_bootstrap_methods; ++i) {
          bootstrap_attr->bootstrap_methods[i] = BootstrapMethods_info();
          auto bootstrap_info = &bootstrap_attr->bootstrap_methods[i];
          this->readBytes(&bootstrap_info->bootstrap_method_ref);

          this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_MethodHandle_info>(
              bootstrap_info->bootstrap_method_ref, "bootstrap_method_ref",
              Utils::ConstantPool::kCONSTANT_METHODHANDLE);

          this->readBytes(&bootstrap_info->num_bootstrap_arguments);
          bootstrap_info->bootstrap_arguments.resize(
              bootstrap_info->num_bootstrap_arguments);
          for (auto j = 0; j < bootstrap_info->num_bootstrap_arguments; ++j) {
            this->readBytes(&bootstrap_info->bootstrap_arguments[j]);
            this->kpoolValidEntry(bootstrap_info->bootstrap_arguments[j],
                                  "bootstrap_arguments");
          }
        }
        break;
      }
      case attrs::kMETHODPARAMETERS: {
        auto methodparams_attr =
            attr->setBase<attrs::MethodParameters_attribute>(nameidx, attrlen);
        this->readBytes(&methodparams_attr->parameters_count, false);
        methodparams_attr->parameters.resize(
            methodparams_attr->parameters_count);

        for (auto i = 0; i < methodparams_attr->parameters_count; ++i) {
          methodparams_attr->parameters[i] = MethodParameters_info();
          auto param = &methodparams_attr->parameters[i];
          this->readBytes(&param->name_index);
          if (param->name_index) {
            this->kpoolValidInfo<Utils::ConstantPool::CONSTANT_Utf8_info>(
                param->name_index, "name_index",
                Utils::ConstantPool::kCONSTANT_UTF8);
          }
          this->readBytes(&param->access_flags);
        }
        break;
      }
      case attrs::kINVALID: {
        if (Utils::Flags::options.kVERBOSE) {
          std::cout << "skipped attribute " << attrName << "\n";
        }
        attr->setBase<attrs::NotImplemented>(nameidx, attrlen);
        for (size_t i = 0; i < attrlen; ++i) {
          Utils::Types::u1 byte;
          this->readBytes(&byte, false);
        }
        break;
      }
    }
  }
}
