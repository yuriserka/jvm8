#ifndef INCLUDE_UTILS_INFOS_H_
#define INCLUDE_UTILS_INFOS_H_

#include <vector>
#include "utils/types.h"
#include "utils/attributes.h"

namespace types = Utils::Types;

namespace Utils {
namespace Infos {
class BaseInfo {
 public:
    BaseInfo() = default;

    explicit BaseInfo(const types::u1 &tag) {
        this->tag = tag;
    }

    virtual ~BaseInfo() = default;

    types::u1 tag;
};

class cp_info {
 public:
    cp_info() = default;
    
    ~cp_info() = default;

    template<typename T>
    void deleteclass() {
        auto derivedptr = this->getClass<T>();
        derivedptr->~T();

        delete derivedptr;
    }

    template<typename T>
    T *setBase(const types::u1 &tag) {
        this->base = new T(tag);
        return this->getClass<T>();
    }

    template<typename T>
    T *getClass() {
        return dynamic_cast<T *>(this->base);
    }

    BaseInfo *base;
};

struct field_info {
    field_info() = default;
    
    ~field_info() = default;

    types::u2 access_flags;
    types::u2 name_index;
    types::u2 descriptor_index;
    types::u2 attributes_count;
    std::vector<Utils::Attributes::attribute_info> attributes;

};

struct method_info {
    method_info() = default;
    
    ~method_info() = default;

    types::u2 access_flags;
    types::u2 name_index;
    types::u2 descriptor_index;
    types::u2 attributes_count;
    std::vector<Utils::Attributes::attribute_info> attributes;
};

class CONSTANT_Class_info : public BaseInfo {
 public:
    explicit CONSTANT_Class_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_Class_info() = default;

    types::u2 name_index;
};

class CONSTANT_FieldRef_info : public BaseInfo {
 public:
    explicit CONSTANT_FieldRef_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_FieldRef_info() = default;

    types::u2 class_index;
    types::u2 name_and_type_index;
};

class CONSTANT_Methodref_info : public BaseInfo {
 public:
    explicit CONSTANT_Methodref_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_Methodref_info() = default;

    types::u2 class_index;
    types::u2 name_and_type_index;
};

class CONSTANT_InterfaceMethodref_info : public BaseInfo {
 public:
    explicit CONSTANT_InterfaceMethodref_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_InterfaceMethodref_info() = default;

    types::u2 class_index;
    types::u2 name_and_type_index;
};

class CONSTANT_String_info : public BaseInfo {
 public:
    explicit CONSTANT_String_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_String_info() = default;

    types::u2 string_index;
};

class CONSTANT_Integer_info : public BaseInfo {
 public:
    explicit CONSTANT_Integer_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_Integer_info() = default;

    types::u4 bytes;
};

class CONSTANT_Float_info : public BaseInfo {
 public:
    explicit CONSTANT_Float_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_Float_info() = default;

    types::u4 bytes;
};

class CONSTANT_Long_info : public BaseInfo {
 public:
    explicit CONSTANT_Long_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_Long_info() = default;

    types::u4 high_bytes;
    types::u4 low_bytes;
};

class CONSTANT_Double_info : public BaseInfo {
 public:
    explicit CONSTANT_Double_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_Double_info() = default;

    types::u4 high_bytes;
    types::u4 low_bytes;
};

class CONSTANT_NameAndType_info : public BaseInfo {
 public:
    explicit CONSTANT_NameAndType_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_NameAndType_info() = default;

    types::u2 name_index;
    types::u2 descriptor_index;
};

class CONSTANT_Utf8_info : public BaseInfo {
 public:
    explicit CONSTANT_Utf8_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_Utf8_info() = default;

    types::u2 length;
    std::vector<types::u1> bytes;
};

class CONSTANT_MethodHandle_info : public BaseInfo {
 public:
    explicit CONSTANT_MethodHandle_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_MethodHandle_info() = default;

    types::u1 reference_kind;
    types::u2 reference_index;
};

class CONSTANT_MethodType_info : public BaseInfo {
 public:
    explicit CONSTANT_MethodType_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_MethodType_info() = default;

    types::u2 descriptor_index;
};

class CONSTANT_InvokeDynamic_info : public BaseInfo {
 public:
     explicit CONSTANT_InvokeDynamic_info(const types::u1 &tag) : BaseInfo(tag) {}

    ~CONSTANT_InvokeDynamic_info() = default;

    types::u2 bootstrap_method_attr_index;
    types::u2 name_and_type_index;
};
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_UTILS_INFOS_H_
