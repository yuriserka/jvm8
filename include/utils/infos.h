#ifndef INCLUDE_UTILS_INFOS_H_
#define INCLUDE_UTILS_INFOS_H_

#include <vector>
#include "utils/types.h"

namespace types = Utils::Types;

namespace Utils {
namespace Infos {
class BaseInfo {
 public:
    BaseInfo() = default;

    explicit BaseInfo(const types::u1 &tag) {
        this->tag = tag;
    }

    ~BaseInfo() = default;

    types::u1 tag;
};

class cp_info : public BaseInfo {
 public:
    cp_info() = default;

    ~cp_info() {
        std::free(this->info);
    }

    void *info;
};

class CONSTANT_Class_info : public BaseInfo {
 public:
    explicit CONSTANT_Class_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u2 name_index;
};

class CONSTANT_FieldRef_info : public BaseInfo {
 public:
    explicit CONSTANT_FieldRef_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u2 class_index;
    types::u2 name_and_type_index;
};

class CONSTANT_Methodref_info : public BaseInfo {
 public:
    explicit CONSTANT_Methodref_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u2 class_index;
    types::u2 name_and_type_index;
};

class CONSTANT_InterfaceMethodref_info : public BaseInfo {
 public:
    explicit CONSTANT_InterfaceMethodref_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u2 class_index;
    types::u2 name_and_type_index;
};

class CONSTANT_String_info : public BaseInfo {
 public:
    explicit CONSTANT_String_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u2 string_index;
};

class CONSTANT_Integer_info : public BaseInfo {
 public:
    explicit CONSTANT_Integer_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u4 bytes;
};

class CONSTANT_Float_info : public BaseInfo {
 public:
    explicit CONSTANT_Float_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u4 bytes;
};

class CONSTANT_Long_info : public BaseInfo {
 public:
    explicit CONSTANT_Long_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u4 high_bytes;
    types::u4 low_bytes;
};

class CONSTANT_Double_info : public BaseInfo {
 public:
    explicit CONSTANT_Double_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u4 high_bytes;
    types::u4 low_bytes;
};

class CONSTANT_NameAndType_info : public BaseInfo {
 public:
    explicit CONSTANT_NameAndType_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u2 name_index;
    types::u2 descriptor_index;
};

class CONSTANT_Utf8_info : public BaseInfo {
 public:
    explicit CONSTANT_Utf8_info(const types::u1 &tag) : BaseInfo(tag) {}
    types::u2 length;
    std::vector<types::u1> bytes;
};
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_UTILS_INFOS_H_
