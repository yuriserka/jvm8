#ifndef INCLUDE_INFOS_H_
#define INCLUDE_INFOS_H_

#include <vector>
#include "utils/types.h"

namespace types = Utils::Types;

namespace Utils {
namespace Infos {
class CONSTANT_Class_info;
class CONSTANT_FieldRef_info;
class CONSTANT_Methodref_info;
class CONSTANT_InterfaceMethodref_info;
class CONSTANT_String_info;
class CONSTANT_Integer_info;
class CONSTANT_Float_info;
class CONSTANT_Long_info;
class CONSTANT_Double_info;
class CONSTANT_NameAndType_info;
class CONSTANT_Utf8_info;
class CONSTANT_MethodHandle_info;

union info_t {
    CONSTANT_Class_info *classinfo_;
    CONSTANT_FieldRef_info *fieldref_;
    CONSTANT_Methodref_info *methodref_;
    CONSTANT_InterfaceMethodref_info *Imethodref_;
    CONSTANT_String_info *string_;
    CONSTANT_Integer_info *integer_;
    CONSTANT_Float_info *float_;
    CONSTANT_Long_info *long_;
    CONSTANT_Double_info *double_;
    CONSTANT_NameAndType_info *nameandtype_;
    CONSTANT_Utf8_info *utf8_;
};

class InfoBase {
 public:
    InfoBase() = default;

    explicit InfoBase(const types::u1 &tag) {
        this->tag = tag;
    }

    types::u1 tag;
};

class cp_info : public InfoBase {
 public:
    cp_info() = default;
    
    // basta deletar qualquer field, já que todos compartilham a mesma memória.
    ~cp_info() {
        std::free(this->info.classinfo_);
    }

    info_t info;
};

class CONSTANT_Class_info : public InfoBase {
 public:
    explicit CONSTANT_Class_info(const types::u1 &tag) : InfoBase(tag) {}
    types::u2 name_index;
};

class CONSTANT_FieldRef_info : public InfoBase {
 public:
    explicit CONSTANT_FieldRef_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u2 class_index;
    types::u2 name_and_type_index;
};

class CONSTANT_Methodref_info : public InfoBase {
 public:
    explicit CONSTANT_Methodref_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u2 class_index;
    types::u2 name_and_type_index;
};

class CONSTANT_InterfaceMethodref_info : public InfoBase {
 public:
    explicit CONSTANT_InterfaceMethodref_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u2 class_index;
    types::u2 name_and_type_index;
};

class CONSTANT_String_info : public InfoBase {
 public:
    explicit CONSTANT_String_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u2 string_index;
};

class CONSTANT_Integer_info : public InfoBase {
 public:
    explicit CONSTANT_Integer_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u4 bytes;
};

class CONSTANT_Float_info : public InfoBase {
 public:
    explicit CONSTANT_Float_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u4 bytes;
};

class CONSTANT_Long_info : public InfoBase {
 public:
    explicit CONSTANT_Long_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u4 high_bytes;
    types::u4 low_bytes;
};

class CONSTANT_Double_info : public InfoBase {
 public:
    explicit CONSTANT_Double_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u4 high_bytes;
    types::u4 low_bytes;
};

class CONSTANT_NameAndType_info : public InfoBase {
 public:
    explicit CONSTANT_NameAndType_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u2 name_index;
    types::u2 descriptor_index;
};

class CONSTANT_Utf8_info : public InfoBase {
 public:
    explicit CONSTANT_Utf8_info(const types::u1 &tag) : InfoBase(tag) {}    
    types::u2 length;
    std::vector<types::u1> bytes;
};
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_INFOS_H_
