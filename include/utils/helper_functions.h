#ifndef INCLUDE_UTILS_HELPER_FUNCTIONS_H_
#define INCLUDE_UTILS_HELPER_FUNCTIONS_H_

#include <string>
#include "classfile.h"
#include "utils/constantPool.h"

namespace Utils {
Infos::method_info getMethod(const ClassFile *cf,
                             const std::string &method_name);

Attributes::attribute_info getAttribute(
    const ClassFile *cf, std::vector<Attributes::attribute_info> *attributes,
    const std::string &attr_name);

const std::string getClassName(const ClassFile *cf);

inline void getReference(const ClassFile *cf, const Types::u2 &ref_index,
                         std::string *ref_class_name,
                         std::string *ref_method_name,
                         std::string *ref_method_return = nullptr) {
  namespace cp = ConstantPool;

  cp::BaseReference *ref = nullptr;

  switch (cf->constant_pool[ref_index - 1].base->tag) {
    case ConstantPool::kCONSTANT_FIELDREF:
      ref = cf->constant_pool[ref_index - 1]
                .getClass<cp::CONSTANT_FieldRef_info>();
      break;
    case ConstantPool::kCONSTANT_INTERFACEMETHODREF:
      ref = cf->constant_pool[ref_index - 1]
                .getClass<cp::CONSTANT_InterfaceMethodref_info>();
      break;
    case ConstantPool::kCONSTANT_METHODREF:
      ref = cf->constant_pool[ref_index - 1]
                .getClass<cp::CONSTANT_Methodref_info>();
      break;
  }

  cp::cp_info class_info_entry = cf->constant_pool[ref->class_index - 1];
  cp::cp_info nametype_info_entry =
      cf->constant_pool[ref->name_and_type_index - 1];

  auto ref_class_info = class_info_entry.getClass<cp::CONSTANT_Class_info>();
  *ref_class_name = cf->constant_pool[ref_class_info->name_index - 1]
                        .getClass<cp::CONSTANT_Utf8_info>()
                        ->getValue();

  auto ref_nametype_info =
      nametype_info_entry.getClass<cp::CONSTANT_NameAndType_info>();
  *ref_method_name = cf->constant_pool[ref_nametype_info->name_index - 1]
                         .getClass<cp::CONSTANT_Utf8_info>()
                         ->getValue();
  if (ref_method_return) {
    *ref_method_return =
        cf->constant_pool[ref_nametype_info->descriptor_index - 1]
            .getClass<cp::CONSTANT_Utf8_info>()
            ->getValue();
  }
}
}  // namespace Utils

#endif  // INCLUDE_UTILS_HELPER_FUNCTIONS_H_
