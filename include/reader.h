#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_

#include <string>
#include <fstream>
#include <algorithm>
#include "./classfile.h"

class Reader {
 public:
    explicit Reader(ClassFile *cf, const std::string &fpath);

    ~Reader() {
        if (this->file.is_open()) {
            this->file.close();
        }
    }

    void readClassFile();
    std::string fname;

 private:
    void readMagic();
    void readMinorVersion();
    void readMajorVersion();
    void readConstantPool();
    void readConstantPoolCount();
    void readConstantPoolInfo();

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
    ClassFile *classfile;
};

#endif  // INCLUDE_READER_H_
