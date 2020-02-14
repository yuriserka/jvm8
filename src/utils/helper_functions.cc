#include "utils/helper_functions.h"

#include <algorithm>
#include "utils/access_flags.h"
#include "utils/errors.h"
#include "utils/infos.h"

namespace Utils {
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

const std::string getClassName(const ClassFile *cf) {
  auto const classinfo =
      cf->constant_pool[cf->this_class - 1]
          .getClass<Utils::ConstantPool::CONSTANT_Class_info>();

  auto actual_classname =
      cf->constant_pool[classinfo->name_index - 1]
          .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
          ->getValue();

  return actual_classname;
}

bool methodIs(const Utils::Infos::method_info &method,
              const std::string &access_type) {
  auto flags = Utils::Access::getMethodAccessType(method.access_flags);

  auto is = std::find_if(flags.begin(), flags.end(), [=](const std::string &f) {
              return !f.compare(access_type);
            }) != flags.end();

  return is;
}

bool fieldIs(const Utils::Infos::field_info &field,
             const std::string &access_type) {
  auto flags = Utils::Access::getFieldAccessType(field.access_flags);

  auto is = std::find_if(flags.begin(), flags.end(), [=](const std::string &f) {
              return !f.compare(access_type);
            }) != flags.end();

  return is;
}
}  // namespace Utils