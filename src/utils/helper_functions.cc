#include "utils/helper_functions.h"

#include <algorithm>
#include "utils/errors.h"
#include "utils/infos.h"

namespace Utils {
// Infos::method_info getMethod(const ClassFile *cf,
//                              const std::string &method_name) {
//   auto method_to_exec =
//       std::find_if(cf->methods.begin(), cf->methods.end(),
//                    [&method_name, &cf](const Infos::method_info &method) {
//                      auto actual_method_name =
//                          cf->constant_pool[method.name_index - 1]
//                              .getClass<ConstantPool::CONSTANT_Utf8_info>()
//                              ->getValue();
//                      return !actual_method_name.compare(method_name);
//                    });
//   if (method_to_exec == cf->methods.end()) {
//     auto classinfo = cf->constant_pool[cf->this_class - 1]
//                          .getClass<ConstantPool::CONSTANT_Class_info>();
//     auto classname = cf->constant_pool[classinfo->name_index - 1]
//                          .getClass<ConstantPool::CONSTANT_Utf8_info>()
//                          ->getValue();
//     std::stringstream ss;
//     ss << "could not find method '" << method_name << "' in class '"
//        << classname << "'";
//     throw Errors::Exception(Errors::kMETHOD, ss.str());
//   }

//   return *method_to_exec;
// }

Attributes::attribute_info getAttribute(
    const ClassFile *cf, std::vector<Attributes::attribute_info> *attributes,
    const std::string &attr_name) {
  auto attr =
      std::find_if(attributes->begin(), attributes->end(),
                   [&attr_name, &cf](const Attributes::attribute_info &attr) {
                     auto actual_attr_name =
                         cf->constant_pool[attr.base->attribute_name_index - 1]
                             .getClass<ConstantPool::CONSTANT_Utf8_info>()
                             ->getValue();
                     return !actual_attr_name.compare(attr_name);
                   });
  if (attr == attributes->end()) {
    std::stringstream ss;
    ss << "could not find attribute " << attr_name;
    throw Errors::Exception(Errors::kMETHOD, ss.str());
  }

  return *attr;
}
}  // namespace Utils