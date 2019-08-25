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

Reader::Reader(const std::string &fpath) {
    this->fname = fpath.substr(fpath.find_last_of("/\\") + 1);
    this->file = std::fstream(fpath, std::ios::binary | std::ios::in);

    if (!this->file.is_open()) {
        throw Utils::Errors::Exception(Utils::Errors::kCLASSFILE,
            "classfile: " + this->fname + " cannot be opened.");
    }
    if (Utils::Flags::kVERBOSE) {
        std::cout << "classfile: '" << this->fname << "' opened\n";
    }
}

void Reader::readClassFile(ClassFile *cf) {
    this->readMagic(cf);
    this->readMinorVersion(cf);
    this->readMajorVersion(cf);
    this->readConstantPool(cf);
}

void Reader::readMagic(ClassFile *cf) {
    this->readNBytes(&cf->magic);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->magic = '"
                  << "0x" << std::hex << std::uppercase << cf->magic << "'\n";
        std::cout.copyfmt(state);
    }
    if (cf->magic != 0xCAFEBABE) {
        std::stringstream err;
        err << "[ERROR]: " << "Magic number not equal to 0xCAFEBABE";
        throw Utils::Errors::Exception(Utils::Errors::KMAGIC, err.str());
    }
}

void Reader::readMinorVersion(ClassFile *cf) {
    this->readNBytes(&cf->minor_version);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->minor_version = '"
                  << "0x" << std::hex << std::uppercase << cf->minor_version
                  << "'\n";
        std::cout.copyfmt(state);
    }
    if (cf->minor_version > Utils::Versions::Java8) {
        std::stringstream err;
        err << "[ERROR]: "
            << "Minor version superior to 0x" << std::hex << std::uppercase
            << Utils::Versions::Java8 << "\n";
        throw Utils::Errors::Exception(Utils::Errors::kMINOR, err.str());
    }
}

void Reader::readMajorVersion(ClassFile *cf) {
    this->readNBytes(&cf->major_version);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->major_version = '"
                  << "0x" << std::hex << std::uppercase << cf->major_version
                  << "'\n";
        std::cout.copyfmt(state);
    }
    if (cf->major_version < Utils::Versions::Java8) {
        std::stringstream err;
        err << "[ERROR]: "
            << "Major version inferior to 0x" << std::hex << std::uppercase
            << Utils::Versions::Java8 << "\n";
        throw Utils::Errors::Exception(Utils::Errors::kMAJOR, err.str());
    }
}

void Reader::readConstantPool(ClassFile *cf) {
    this->readConstantPoolCount(cf);
    cf->constant_pool.resize(cf->constant_pool_count - 1);
    this->readConstantPoolInfo(cf);
    if (Utils::Flags::kVERBOSE) {
        std::cout << "Read classfile->constant_pool\n";
    }
}

void Reader::readConstantPoolCount(ClassFile *cf) {
    this->readNBytes(&cf->constant_pool_count);
    if (Utils::Flags::kVERBOSE) {
        std::cout << "Read classfile->constant_pool_count = '"
            << cf->constant_pool_count << "'\n";
    }
}

void Reader::readConstantPoolInfo(ClassFile *cf) {
    for (auto i = 0; i < /*cf->constant_pool_count-1*/1; ++i) {
        auto constpool = &cf->constant_pool[i];
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
