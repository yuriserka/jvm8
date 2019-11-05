#include "utils/helper_functions.h"

#include <algorithm>
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
}  // namespace Utils