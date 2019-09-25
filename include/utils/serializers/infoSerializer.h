#ifndef INCLUDE_UTILS_SERIALIZERS_INFOSERIALIZER_H_
#define INCLUDE_UTILS_SERIALIZERS_INFOSERIALIZER_H_

#include "classfile.h"
#include "utils/nlohmann_json.hpp"

using nlohmann::json;

namespace Utils {
namespace Infos {
class Serializer {
 public:
  explicit Serializer(const ClassFile *cf) { this->cf = cf; }

  bool kPoolInfo_to_JSON(json *j, const int &kpoolindex);

 private:
  template <typename T>
  void writeReferences(json *j, const T *kinfo);

  const ClassFile *cf;
};
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_UTILS_SERIALIZERS_INFOSERIALIZER_H_
