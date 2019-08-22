#ifndef READER_H
#define READER_H

#include "./classfile.h"

#include <string>
#include <fstream>
#include <sstream>
#include <type_traits>

class Reader {
  public:
    Reader(std::string fpath);

    ~Reader() {
        if (this->file.is_open()) {
            this->file.close();
        }
    }

    void readClassFile(ClassFile *cf);

    void readMagic(ClassFile *cf);
    void readMinorVersion(ClassFile *cf);
    void readMajorVersion(ClassFile *cf);
  private:
    template <typename T>
    T readNBytes() {
        int n = 1;
        if (std::is_same<T, Utils::Types::u2>::value) {
            n = 2;
        } else if (std::is_same<T, Utils::Types::u4>::value) {
            n = 4;
        } else {
            n = 8;
        }

        std::stringstream ss;
        for (auto i = 0; i < n; ++i) {
            auto b = this->file.get();
            ss << std::hex << b;
        }
        T Nbytes;
        ss >> std::hex >> Nbytes;
        return Nbytes;
    }

    std::fstream file;
    std::string fname;
};


#endif