#include "reader.h"

#include <iostream>
#include <sstream>
#include <iomanip>
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
    this->readNBytes(&this->classfile->magic);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->magic = '"
                  << "0x" << std::hex << std::uppercase << this->classfile->magic << "'\n";
        std::cout.copyfmt(state);
    }
    if (this->classfile->magic != 0xCAFEBABE) {
        std::stringstream err;
        err << "[ERROR]: " << "Magic number not equal to 0xCAFEBABE";
        throw Utils::Errors::Exception(Utils::Errors::KMAGIC, err.str());
    }
}

void Reader::readMinorVersion() {
    this->readNBytes(&this->classfile->minor_version);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->minor_version = '"
                  << "0x" << std::hex << std::uppercase << this->classfile->minor_version
                  << "'\n";
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
    this->readNBytes(&this->classfile->major_version);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->major_version = '"
                  << "0x" << std::hex << std::uppercase << this->classfile->major_version
                  << "'\n";
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
    this->readNBytes(&this->classfile->constant_pool_count);
    if (Utils::Flags::kVERBOSE) {
        std::cout << "Read classfile->constant_pool_count = '"
            << this->classfile->constant_pool_count << "'\n";
    }
}

void Reader::readConstantPoolInfo() {
    for (auto i = 0; i < this->classfile->constant_pool_count-1; ++i) {
        auto constpool = &this->classfile->constant_pool[i];
        this->readNBytes(&constpool->tag);

        switch (constpool->tag) {
            namespace cp = ::Utils::ConstantPool;
            namespace i = ::Utils::Infos;
        case cp::CONSTANT_Class: {
            auto cpClassInfo = constpool->info.classinfo_ =
                new i::CONSTANT_Class_info(constpool->tag);
            this->readNBytes(&cpClassInfo->name_index);
            break;
        }
        case cp::CONSTANT_Fieldref: {
            auto cpClassInfo = constpool->info.fieldref_ =
                new i::CONSTANT_FieldRef_info(constpool->tag);
            this->readNBytes(&cpClassInfo->class_index);
            this->readNBytes(&cpClassInfo->name_and_type_index);
            break;            
        }
        case cp::CONSTANT_Methodref: {
            auto cpClassInfo = constpool->info.methodref_ =
                new i::CONSTANT_Methodref_info(constpool->tag);
            this->readNBytes(&cpClassInfo->class_index);
            this->readNBytes(&cpClassInfo->name_and_type_index);
            break;
        }
        case cp::CONSTANT_InterfaceMethodref: {
            auto cpClassInfo = constpool->info.Imethodref_ =
                new i::CONSTANT_InterfaceMethodref_info(constpool->tag);
            this->readNBytes(&cpClassInfo->class_index);
            this->readNBytes(&cpClassInfo->name_and_type_index);
            break;
        }
        case cp::CONSTANT_String: {
            auto cpClassInfo = constpool->info.string_ =
                new i::CONSTANT_String_info(constpool->tag);
                this->readNBytes(&cpClassInfo->string_index);
            break;
        }
        case cp::CONSTANT_Integer: {
            auto cpClassInfo = constpool->info.integer_ =
                new i::CONSTANT_Integer_info(constpool->tag);
            this->readNBytes(&cpClassInfo->bytes);
            break;
        }
        case cp::CONSTANT_Float: {
            auto cpClassInfo = constpool->info.float_ =
                new i::CONSTANT_Float_info(constpool->tag);
            this->readNBytes(&cpClassInfo->bytes);
            break;
        }
        case cp::CONSTANT_Long: {
            auto cpClassInfo = constpool->info.long_ =
                new i::CONSTANT_Long_info(constpool->tag);
            this->readNBytes(&cpClassInfo->high_bytes);
            this->readNBytes(&cpClassInfo->low_bytes);
            break;
        }
        case cp::CONSTANT_Double: {
            auto cpClassInfo = constpool->info.double_ =
                new i::CONSTANT_Double_info(constpool->tag);
            this->readNBytes(&cpClassInfo->high_bytes);
            this->readNBytes(&cpClassInfo->low_bytes);
            break;
        }
        case cp::CONSTANT_NameAndType: {
            auto cpClassInfo = constpool->info.nameandtype_ =
                new i::CONSTANT_NameAndType_info(constpool->tag);
            this->readNBytes(&cpClassInfo->name_index);
            this->readNBytes(&cpClassInfo->descriptor_index);
            break;
        }
        case cp::CONSTANT_Utf8: {
            auto cpClassInfo = constpool->info.utf8_ =
                new i::CONSTANT_Utf8_info(constpool->tag);
            this->readNBytes(&cpClassInfo->length);
            cpClassInfo->bytes.resize(cpClassInfo->length);
            for (size_t i = 0; i < cpClassInfo->length; ++i) {
                this->readNBytes(&cpClassInfo->bytes[i]);
            }
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
