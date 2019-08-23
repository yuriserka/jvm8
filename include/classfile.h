#ifndef INCLUDE_CLASSFILE_H_
#define INCLUDE_CLASSFILE_H_

#include "./types.h"

struct ClassFile {
    Utils::Types::u4 magic;
    Utils::Types::u2 minor_version;
    Utils::Types::u2 major_version;
    Utils::Types::u2 constant_pool_count;
};

#endif  // INCLUDE_CLASSFILE_H_
