#ifndef INCLUDE_INFOS_H_
#define INCLUDE_INFOS_H_

#include <vector>
#include "./types.h"

namespace Utils {
namespace Infos {
class CONSTANT_Class_info;

union info_t {
    CONSTANT_Class_info *classinfo;
};

class CONSTANT_info {
 public:
    CONSTANT_info() = default;

    explicit CONSTANT_info(const Utils::Types::u1 &tag) {
        this->tag = tag;
    }

    Utils::Types::u1 tag;
};

class cp_info : public CONSTANT_info {
 public:
    info_t info;
};

class CONSTANT_Class_info : public CONSTANT_info {
 public:
    explicit CONSTANT_Class_info(const Utils::Types::u1 &tag) : CONSTANT_info(tag) {}
    Utils::Types::u2 name_index;
};
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_INFOS_H_
