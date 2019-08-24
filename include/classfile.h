#ifndef INCLUDE_CLASSFILE_H_
#define INCLUDE_CLASSFILE_H_

#include <vector>
#include "./types.h"
#include "./infos.h"

struct ClassFile {
    Utils::Types::u4 magic;
    Utils::Types::u2 minor_version;
    Utils::Types::u2 major_version;
    Utils::Types::u2 constant_pool_count;
    std::vector<Utils::Infos::cp_info> constant_pool;

    ~ClassFile() {
        for (size_t i = 0; i < this->constant_pool.size(); ++i) {
            auto cpi = this->constant_pool[i];
            if (cpi.info.classinfo) delete cpi.info.classinfo;
        }
    }
};

#endif  // INCLUDE_CLASSFILE_H_
