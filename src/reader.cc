#include "../include/reader.h"
#include "../include/flags.h"
#include "../include/errors.h"

#include <iostream>

auto kJAVAVERSION = 0x34;

Reader::Reader(std::string fpath) {
    this->file.open(fpath, std::ios::in | std::ios::binary);
    this->fname = fpath.substr(fpath.find_last_of("/\\")+1);
    // fpath.substr(fpath.find_last_of('\\'), fpath.find_last_of('.'));

    if (!this->file.is_open()) {
        throw Utils::Errors::Exception(Utils::Errors::kCLASSFILE, "classfile: " + this->fname + " cannot be opened.");
    }
    if (Utils::Flags::kVERBOSE) {
        std::cout << "classfile: '" << this->fname << "' opened\n";
    }
}

void Reader::readClassFile(ClassFile *cf)  {
    this->readMagic(cf);
    this->readMinorVersion(cf);
    //if (cf->minor_version > kJAVAVERSION) {
        // throw Utils::Errors::ErrorObject(Utils::Errors::kMINOR,
            // "Minor version superior to 0x" + std::hex + std::uppercase + kJAVAVERSION + "\n");
    //}
    this->readMajorVersion(cf);
    if (cf->major_version < kJAVAVERSION) {
        std::cerr << "Major version inferior to " <<
            "0x" << std::hex << std::uppercase << kJAVAVERSION << "\n";
        delete cf;
        std::exit(Utils::Errors::kMAJOR);
    }
}

void Reader::readMagic(ClassFile *cf) {
    cf->magic = this->readNBytes<Utils::Types::u4>();
    if (Utils::Flags::kVERBOSE) {
        std::cout << "Read classfile->magic = '" <<
            "0x" << std::hex << std::uppercase << cf->magic << "'\n";
    }
}

void Reader::readMinorVersion(ClassFile *cf) {
    cf->minor_version = this->readNBytes<Utils::Types::u2>();
    if (Utils::Flags::kVERBOSE) {
        std::cout << "Read classfile->minor_version = '" <<
            "0x" << std::hex << std::uppercase << cf->minor_version << "'\n";
    }
}

void Reader::readMajorVersion(ClassFile *cf) {
    cf->major_version = this->readNBytes<Utils::Types::u2>();
    if (Utils::Flags::kVERBOSE) {
        std::cout << "Read classfile->major_version = '" <<
            "0x" << std::hex << std::uppercase << cf->major_version << "'\n";
    }
}