#ifndef INCLUDE_CLASSFILE_H_
#define INCLUDE_CLASSFILE_H_

#include <vector>
#include "utils/types.h"
#include "utils/infos.h"
#include "utils/constantPool.h"

template <typename T>
void deleteClass(T *objptr) {
    objptr->~T();
    free(objptr);
}

struct ClassFile {
    Utils::Types::u4 magic;
    Utils::Types::u2 minor_version;
    Utils::Types::u2 major_version;
    Utils::Types::u2 constant_pool_count;
    std::vector<Utils::Infos::cp_info> constant_pool;
    Utils::Types::u2 access_flags;
    Utils::Types::u2 this_class;
    Utils::Types::u2 super_class;
    Utils::Types::u2 interfaces_count;
    std::vector<Utils::Types::u2> interfaces;
    Utils::Types::u2 fields_count;
    std::vector<Utils::Infos::field_info> fields;
    Utils::Types::u2 methods_count;
    std::vector<Utils::Infos::method_info> methods;
    Utils::Types::u2 attributes_count;
    std::vector<Utils::Infos::attribute_info> attributes;

    ~ClassFile() {
        for (int i = 0; i < this->constant_pool_count-1; ++i) {
            auto cpi = this->constant_pool[i];
            switch (cpi.base->tag) {
                namespace cp = Utils::ConstantPool;
                namespace info = Utils::Infos;
            case cp::CONSTANT_Class:
                cpi.deleteclass<info::CONSTANT_Class_info>();
                break;
            case cp::CONSTANT_Double:
                cpi.deleteclass<info::CONSTANT_Double_info>();
                break;
            case cp::CONSTANT_Fieldref:
                cpi.deleteclass<info::CONSTANT_FieldRef_info>();
                break;
            case cp::CONSTANT_Float:
                cpi.deleteclass<info::CONSTANT_Float_info>();
                break;
            case cp::CONSTANT_Integer:
                cpi.deleteclass<info::CONSTANT_Integer_info>();
                break;
            case cp::CONSTANT_InterfaceMethodref:
                cpi.deleteclass<info::CONSTANT_InterfaceMethodref_info>();
                break;
            case cp::CONSTANT_Long:
                cpi.deleteclass<info::CONSTANT_Long_info>();
                break;
            case cp::CONSTANT_Methodref:
                cpi.deleteclass<info::CONSTANT_Methodref_info>();
                break;
            case cp::CONSTANT_NameAndType:
                cpi.deleteclass<info::CONSTANT_NameAndType_info>();
                break;
            case cp::CONSTANT_String:
                cpi.deleteclass<info::CONSTANT_String_info>();
                break;
            case cp::CONSTANT_Utf8:
                cpi.deleteclass<info::CONSTANT_Utf8_info>();
                break;
            }
        }
    }
};

#endif  // INCLUDE_CLASSFILE_H_
