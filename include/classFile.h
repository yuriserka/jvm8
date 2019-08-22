#ifndef CLASSFILE_H
#define CLASSFILE_H

#include "./types.h"

struct ClassFile {
    Utils::Types::u4 magic;
    Utils::Types::u2 minor_version;
    Utils::Types::u2 major_version;
};

#endif