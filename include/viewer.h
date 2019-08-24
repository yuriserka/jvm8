#ifndef INCLUDE_VIEWER_H_
#define INCLUDE_VIEWER_H_

#include <string>
#include "./classfile.h"

class Viewer {
 public:
    explicit Viewer(ClassFile *cf, const std::string &fname) {
        this->cf = cf;
        this->classname = fname;
    }

    void printClassFile();
    void printMagic();
    void printVersion();
    void printConstantPool();

 private:
    std::string classname;
    ClassFile *cf;
};

#endif  // INCLUDE_VIEWER_H_
