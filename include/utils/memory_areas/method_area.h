#ifndef INCLUDE_UTILS_MEMORY_AREAS_METHOD_AREA_H_
#define INCLUDE_UTILS_MEMORY_AREAS_METHOD_AREA_H_

#include <vector>
#include "classfile.h"
#include "utils/infos.h"
#include "utils/types.h"

namespace MemoryAreas {
class MethodArea {
 public:
  MethodArea(const Utils::Types::u2 &num_methods,
             const Utils::Types::u2 &num_fields, const ClassFile *cf)
      : methods(num_methods), fields(num_fields) {
    this->runtime_constant_pool = cf->constant_pool;
  }

 private:
  std::vector<Utils::Infos::method_info> methods;
  std::vector<Utils::Infos::field_info> fields;
  std::vector<Utils::ConstantPool::cp_info> runtime_constant_pool;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_METHOD_AREA_H_
