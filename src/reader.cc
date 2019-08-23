#include "../include/reader.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include "../include/flags.h"
#include "../include/errors.h"
#include "../include/versions.h"

static std::ios state(NULL);

Reader::Reader(std::string fpath) {
    this->fname = fpath.substr(fpath.find_last_of("/\\") + 1);
    this->file = std::fstream(fpath, std::ios::binary | std::ios::in);

    if (!this->file.is_open()) {
        throw Utils::Errors::Exception(Utils::Errors::kCLASSFILE, "classfile: " + this->fname + " cannot be opened.");
    }
    if (Utils::Flags::kVERBOSE) {
        std::cout << "classfile: '" << this->fname << "' opened\n";
    }
}

void Reader::readClassFile(ClassFile *cf) {
    this->readMagic(cf);
    this->readMinorVersion(cf);
    if (cf->minor_version > Utils::Versions::Java8) {
        std::stringstream err;
        err << "[ERROR]: "
            << "Minor version superior to 0x" << std::hex << std::uppercase << Utils::Versions::Java8 << "\n";
        throw Utils::Errors::Exception(Utils::Errors::kMINOR, err.str());
    }
    this->readMajorVersion(cf);
    if (cf->major_version < Utils::Versions::Java8) {
        std::stringstream err;
        err << "[ERROR]: "
            << "Major version inferior to 0x" << std::hex << std::uppercase << Utils::Versions::Java8 << "\n";
        throw Utils::Errors::Exception(Utils::Errors::kMINOR, err.str());
    }
    if (Utils::Flags::kVERBOSE) {
        std::cout << "Version: " << cf->major_version << "." << cf->minor_version << "\n";
    }
    std::cout << "Java Version: " << Utils::Versions::getVersion(cf->major_version) << "\n";
    this->readConstantPoolCount(cf);
}

void Reader::readMagic(ClassFile *cf) {
    cf->magic = this->readNBytes<Utils::Types::u4>(4);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->magic = '"
                  << "0x" << std::hex << std::uppercase << cf->magic << "'\n";
        std::cout.copyfmt(state);
    }
}

void Reader::readMinorVersion(ClassFile *cf) {
    cf->minor_version = this->readNBytes<Utils::Types::u2>(2);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->minor_version = '"
                  << "0x" << std::hex << std::uppercase << cf->minor_version << "'\n";
        std::cout.copyfmt(state);
    }
}

void Reader::readMajorVersion(ClassFile *cf) {
    cf->major_version = this->readNBytes<Utils::Types::u2>(2);
    if (Utils::Flags::kVERBOSE) {
        state.copyfmt(std::cout);
        std::cout << "Read classfile->major_version = '"
                  << "0x" << std::hex << std::uppercase << cf->major_version << "'\n";
        std::cout.copyfmt(state);
    }
}

void Reader::readConstantPoolCount(ClassFile *cf) {
    cf->constant_pool_count = this->readNBytes<Utils::Types::u2>(2);
    if (Utils::Flags::kVERBOSE) {
        std::cout << "Read classfile->constant_pool_count = '" << cf->constant_pool_count << "'\n";
    }
}
