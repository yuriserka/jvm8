#ifndef INCLUDE_UTILS_SERIALIZERS_METHODSERIALIZER_H_
#define INCLUDE_UTILS_SERIALIZERS_METHODSERIALIZER_H_

#include "classfile.h"
#include "utils/nlohmann_json.hpp"

using nlohmann::json;

namespace Utils {
namespace Infos {
class MethodSerializer {
 public:
  explicit MethodSerializer(const ClassFile *cf) { this->cf = cf; }

  void to_json(json *j, const int &methodindex);

 private:
  const ClassFile *cf;
};
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_UTILS_SERIALIZERS_METHODSERIALIZER_H_
