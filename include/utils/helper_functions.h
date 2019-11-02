#ifndef INCLUDE_UTILS_HELPER_FUNCTIONS_H_
#define INCLUDE_UTILS_HELPER_FUNCTIONS_H_

#include <string>
#include "classfile.h"

namespace Utils {
Infos::method_info getMethod(const ClassFile *cf,
                             const std::string &method_name);
Attributes::attribute_info getAttribute(
    const ClassFile *cf, std::vector<Attributes::attribute_info> *attributes,
    const std::string &attr_name);
}  // namespace Utils

#endif  // INCLUDE_UTILS_HELPER_FUNCTIONS_H_
