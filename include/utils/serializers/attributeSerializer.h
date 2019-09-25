#ifndef INCLUDE_UTILS_SERIALIZERS_ATTRIBUTESERIALIZER_H_
#define INCLUDE_UTILS_SERIALIZERS_ATTRIBUTESERIALIZER_H_

#include <vector>
#include "classfile.h"
#include "utils/nlohmann_json.hpp"

using nlohmann::json;

namespace Utils {
namespace Attributes {
class AttributeSerializer {
 public:
  explicit AttributeSerializer(const ClassFile *cf,
                               const std::vector<attribute_info> &attrs) {
    this->attrs = attrs;
    this->cf = cf;
  }

  void to_json(json *j, const int &attrindex);

 private:
  const ClassFile *cf;
  std::vector<attribute_info> attrs;
};
}  // namespace Attributes
}  // namespace Utils

#endif  // INCLUDE_UTILS_SERIALIZERS_ATTRIBUTESERIALIZER_H_
