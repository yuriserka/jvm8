#ifndef INCLUDE_VIEWER_H_
#define INCLUDE_VIEWER_H_

#include <string>
#include "classfile.h"

class Viewer {
 public:
    explicit Viewer(ClassFile *cf, const std::string &fname) {
        this->classfile = cf;
        this->classname = fname;
    }

    void printClassFile();

 private:
    void printMagic();
    void printVersion();
    void printConstantPool();
    void printConstantPoolInfo(int index, int depth, bool inner);

    std::string classname;
    ClassFile *classfile;
};

#endif  // INCLUDE_VIEWER_H_
