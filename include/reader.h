#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_

#include <string>
#include <fstream>
#include <algorithm>
#include "./classfile.h"

class Reader {
 public:
    explicit Reader(const std::string &fpath);

    ~Reader() {
        if (this->file.is_open()) {
            this->file.close();
        }
    }

    void readClassFile(ClassFile *cf);

    void readMagic(ClassFile *cf);
    void readMinorVersion(ClassFile *cf);
    void readMajorVersion(ClassFile *cf);
    void readConstantPool(ClassFile *cf);
    void readConstantPoolCount(ClassFile *cf);
    void readConstantPoolInfo(ClassFile *cf);

    std::string fname;

 private:
    template <class T>
    inline void endianSwap(T *objp) {
        unsigned char *memp = reinterpret_cast<unsigned char *>(objp);
        std::reverse(memp, memp + sizeof(T));
    }

    template <typename T>
    inline void readNBytes(T *objp) {
        this->file.read(reinterpret_cast<char *>(objp), sizeof(T));
        this->endianSwap(objp);
    }

    std::fstream file;
};

#endif  // INCLUDE_READER_H_
