#ifndef INCLUDE_CLASSFILE_H_
#define INCLUDE_CLASSFILE_H_

#include <vector>

#include "utils/constantPool.h"
#include "utils/external/nlohmann_json.hpp"
#include "utils/infos.h"
#include "utils/types.h"

using nlohmann::json;

class ClassFile {
 public:
  ClassFile() = default;

  ~ClassFile() {
    this->deleteFieldsAttributes();
    this->deleteMethodsAttributes();
    this->deleteAttributes(&this->attributes);
    this->deleteConstantPool();
  }

  Utils::Types::u4 magic;
  Utils::Types::u2 minor_version;
  Utils::Types::u2 major_version;

  Utils::Types::u2 constant_pool_count;
  std::vector<Utils::ConstantPool::cp_info> constant_pool;

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
  std::vector<Utils::Attributes::attribute_info> attributes;

 private:
  void deleteConstantPool();
  void deleteFieldsAttributes();
  void deleteMethodsAttributes();
  void deleteAttributes(
      std::vector<Utils::Attributes::attribute_info> *attributes);
};

#endif  // INCLUDE_CLASSFILE_H_
