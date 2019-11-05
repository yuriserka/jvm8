#ifndef INCLUDE_UTILS_MEMORY_AREAS_METHOD_AREA_H_
#define INCLUDE_UTILS_MEMORY_AREAS_METHOD_AREA_H_

#include <vector>
#include "classfile.h"
#include "utils/infos.h"

namespace MemoryAreas {
class MethodArea {
 public:
  MethodArea(const ClassFile *cf) { this->update(cf); }

  void update(const ClassFile *cf) {
    this->cf = cf;
    this->runtime_constant_pool = cf->constant_pool;
    this->methods = cf->methods;
    this->fields = cf->fields;
  }

  Utils::Infos::method_info getMethod(const std::string &method_name);
  Utils::Infos::field_info getField(const std::string &field_name);

  std::vector<Utils::ConstantPool::cp_info> runtime_constant_pool;

 private:
  const ClassFile *cf;
  std::vector<Utils::Infos::method_info> methods;
  std::vector<Utils::Infos::field_info> fields;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_METHOD_AREA_H_
