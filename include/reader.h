#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_

#include <string>
#include <fstream>
#include <algorithm>
#include "./classfile.h"

class Reader {
 public:
    explicit Reader(std::string fpath);

    ~Reader() {
        if (this->file.is_open()) {
            this->file.close();
        }
    }

    void readClassFile(ClassFile *cf);

    void readMagic(ClassFile *cf);
    void readMinorVersion(ClassFile *cf);
    void readMajorVersion(ClassFile *cf);
    void readConstantPoolCount(ClassFile *cf);

 private:
    template <class T>
    inline void endianSwap(T *objp) {
        unsigned char *memp = reinterpret_cast<unsigned char *>(objp);
        std::reverse(memp, memp + sizeof(T));
    }

    template <typename T>
    inline T readNBytes(size_t n) {
        T out;
        this->file.read(reinterpret_cast<char *>(&out), sizeof(T));
        this->endianSwap(&out);

        return out;
    }

    std::fstream file;
    std::string fname;
};

#endif  // INCLUDE_READER_H_
