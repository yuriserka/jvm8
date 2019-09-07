#include "reader.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include<memory>
#include "utils/flags.h"
#include "utils/errors.h"
#include "utils/versions.h"
#include "utils/constantPool.h"
#include "utils/infos.h"

static std::ios state(NULL);

Reader::Reader(ClassFile *cf, const std::string &fpath) {
    this->fname = fpath.substr(fpath.find_last_of("/\\") + 1);
    this->file = std::fstream(fpath, std::ios::binary | std::ios::in);
    this->classfile = cf;

    if (!this->file.is_open()) {
        throw Utils::Errors::Exception(Utils::Errors::kCLASSFILE,
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
}

void Reader::readMagic() {
    this->readBytes(&this->classfile->magic);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->magic = '"
                  << "0x" << std::hex << std::uppercase
                  << this->classfile->magic << "'\n";
        std::cout.copyfmt(state);
    }
    if (this->classfile->magic != 0xCAFEBABE) {
        std::stringstream err;
        err << "[ERROR]: " << "Magic number not equal to 0xCAFEBABE";
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
    this->classfile->constant_pool.resize(this->classfile->constant_pool_count - 1);
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
 * @brief fancy way to create any class with many args as necessary for the constructor.
 *
 * @tparam T the class that will be created.
 * @tparam TArgs will be a list of all the args types passed.
 * @param[in] mArgs the multiple arguments used in constructor of class T.
 * @returns a pointer to the class.
 */
template <typename T, typename... TArgs>
T *createClass(TArgs &&...mArgs) {
    T *constinfo = reinterpret_cast<T *>(std::malloc(sizeof(T)));
    new (constinfo) T(std::forward<TArgs>(mArgs)...);

    return constinfo;
}

void Reader::readConstantPoolInfo() {
    for (auto i = 0; i < this->classfile->constant_pool_count-1; ++i) {
        auto constpool = &this->classfile->constant_pool[i];
        this->readBytes(&constpool->tag);

        switch (constpool->tag) {
            namespace cp = Utils::ConstantPool;
            namespace i = Utils::Infos;
        case cp::CONSTANT_Class: {
            auto kclassinfo = createClass<i::CONSTANT_Class_info>(constpool->tag);
            this->readBytes(&kclassinfo->name_index);
            constpool->info = kclassinfo;
            break;
        }
        case cp::CONSTANT_Fieldref: {
            auto kfieldref = createClass<i::CONSTANT_FieldRef_info>(constpool->tag);
            this->readBytes(&kfieldref->class_index);
            this->readBytes(&kfieldref->name_and_type_index);
            constpool->info = kfieldref;
            break;
        }
        case cp::CONSTANT_Methodref: {
            auto kmethodref = createClass<i::CONSTANT_Methodref_info>(constpool->tag);
            this->readBytes(&kmethodref->class_index);
            this->readBytes(&kmethodref->name_and_type_index);
            constpool->info = kmethodref;
            break;
        }
        case cp::CONSTANT_InterfaceMethodref: {
            auto kInterfacemethodref = createClass<i::CONSTANT_InterfaceMethodref_info>(constpool->tag);
            this->readBytes(&kInterfacemethodref->class_index);
            this->readBytes(&kInterfacemethodref->name_and_type_index);
            constpool->info = kInterfacemethodref;
            break;
        }
        case cp::CONSTANT_String: {
            auto kstring = createClass<i::CONSTANT_String_info>(constpool->tag);
            this->readBytes(&kstring->string_index);
            constpool->info = kstring;
            break;
        }
        case cp::CONSTANT_Integer: {
            auto kinteger = createClass<i::CONSTANT_Integer_info>(constpool->tag);
            this->readBytes(&kinteger->bytes);
            constpool->info = kinteger;
            break;
        }
        case cp::CONSTANT_Float: {
            auto kfloat = createClass<i::CONSTANT_Integer_info>(constpool->tag);
            this->readBytes(&kfloat->bytes);
            constpool->info = kfloat;
            break;
        }
        case cp::CONSTANT_Long: {
            auto klong = createClass<i::CONSTANT_Long_info>(constpool->tag);
            this->readBytes(&klong->high_bytes);
            this->readBytes(&klong->low_bytes);
            constpool->info = klong;
            break;
        }
        case cp::CONSTANT_Double: {
            auto kdouble = createClass<i::CONSTANT_Double_info>(constpool->tag);
            this->readBytes(&kdouble->high_bytes);
            this->readBytes(&kdouble->low_bytes);
            constpool->info = kdouble;
            break;
        }
        case cp::CONSTANT_NameAndType: {
            auto knameandtype = createClass<i::CONSTANT_NameAndType_info>(constpool->tag);
            this->readBytes(&knameandtype->name_index);
            this->readBytes(&knameandtype->descriptor_index);
            constpool->info = knameandtype;
            break;
        }
        case cp::CONSTANT_Utf8: {
            auto kutf8 = createClass<i::CONSTANT_Utf8_info>(constpool->tag);
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
                    throw Utils::Errors::Exception(Utils::Errors::kBYTE, err.str());
                }
            }
            constpool->info = kutf8;
            break;
        }
        default: {
            std::stringstream err;
            err << "[ERROR]: "
                << "Unknown constant pool tag = '" << unsigned(constpool->tag)
                << "'\n";
            throw Utils::Errors::Exception(Utils::Errors::kCONSTANTPOOL, err.str());
        }
        }
    }
}
