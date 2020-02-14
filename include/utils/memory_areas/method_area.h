#ifndef INCLUDE_UTILS_MEMORY_AREAS_METHOD_AREA_H_
#define INCLUDE_UTILS_MEMORY_AREAS_METHOD_AREA_H_

#include <list>
#include <string>
#include <vector>
#include "classfile.h"
#include "utils/helper_functions.h"
#include "utils/infos.h"

namespace MemoryAreas {
class MethodArea {
 public:
  MethodArea(const ClassFile *cf) { this->update(cf); }

  ~MethodArea() {
    this->loaded.remove_if([](const ClassFile *cf) {
      delete cf;
      return true;
    });
  }

  void update(const ClassFile *cf) {
    this->runtime_classfile = cf;
    this->runtime_constant_pool = cf->constant_pool;
    this->methods = cf->methods;
    this->fields = cf->fields;
  }

  bool isLoaded(const std::string &classname) {
    auto already_pushed =
        std::find_if(this->loaded.begin(), this->loaded.end(),
                     [&classname](const ClassFile *classfile) {
                       auto actual_name = Utils::getClassName(classfile);
                       return !classname.compare(actual_name);
                     });
    return already_pushed != this->loaded.end();
  }

  const ClassFile *getClass(const std::string &classname);

  // std::string getClassThatImplementsMethod(const std::string &classname,
  //                                          const std::string &method_name,
  //                                          const std::string &descriptor);

  const ClassFile *loadClass(const std::string &classname);

  Utils::Infos::method_info getMethod(const std::string &method_name,
                                      const std::string &descriptor);

  Utils::Infos::field_info getField(const std::string &field_name);

  std::vector<Utils::ConstantPool::cp_info> runtime_constant_pool;
  const ClassFile *runtime_classfile;
  std::vector<Utils::Infos::field_info> fields;

 private:
  const ClassFile *loadClass(const ClassFile *cf) {
    this->loaded.push_back(cf);
    return cf;
  }
  std::list<const ClassFile *> loaded;
  std::vector<Utils::Infos::method_info> methods;
};
}  // namespace MemoryAreas

#endif  // INCLUDE_UTILS_MEMORY_AREAS_METHOD_AREA_H_
