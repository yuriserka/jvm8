#ifndef INCLUDE_UTILS_SERIALIZERS_FIELDSERIALIZER_H_
#define INCLUDE_UTILS_SERIALIZERS_FIELDSERIALIZER_H_

#include <vector>
#include "classfile.h"
#include "utils/nlohmann_json.hpp"

using nlohmann::json;

namespace Utils {
namespace Infos {
class FieldSerializer {
 public:
  explicit FieldSerializer(const ClassFile *cf) { this->cf = cf; }

  void to_json(json *j, const int &fieldindex);

 private:
  const ClassFile *cf;
};
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_UTILS_SERIALIZERS_FIELDSERIALIZER_H_