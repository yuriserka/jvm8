#include "../include/reader.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include "../include/flags.h"
#include "../include/errors.h"
#include "../include/versions.h"
#include "../include/constantPool.h"
#include "../include/infos.h"

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
    for (auto i = 0; i < /*this->classfile->constant_pool_count-1*/1; ++i) {
        auto constpool = &this->classfile->constant_pool[i];
        this->readNBytes(&constpool->tag);

        switch (constpool->tag) {
            namespace cp = ::Utils::ConstantPool;
            namespace i = ::Utils::Infos;
        case cp::CONSTANT_Class: {
            auto cpClassInfo = constpool->info.classinfo = new i::CONSTANT_Class_info(constpool->tag);
            this->readNBytes(&cpClassInfo->name_index);
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
