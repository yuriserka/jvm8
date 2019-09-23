#ifndef INCLUDE_UTILS_SERIALIZERS_INFOSERIALIZER__H_
#define INCLUDE_UTILS_SERIALIZERS_INFOSERIALIZER__H_

#include <vector>
#include "utils/infos.h"
#include "utils/nlohmann_json.hpp"

using nlohmann::json;

namespace types = Utils::Types;

namespace Utils {
namespace Infos {
/**
 * Interfaces para serializar os objetos em formato JSON
 * */
void to_json(json &j, CONSTANT_Class_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_FieldRef_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_Methodref_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_InterfaceMethodref_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_String_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_Integer_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_Float_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_Long_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_Double_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_NameAndType_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
void to_json(json &j, CONSTANT_Utf8_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);

// não implementado ainda
void to_json(json &j, CONSTANT_MethodHandle_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
// não implementado ainda
void to_json(json &j, CONSTANT_MethodType_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);
// não implementado ainda
void to_json(json &j, CONSTANT_InvokeDynamic_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool,
             const int &i = -1);

class Serializer {
 public:
  explicit Serializer(const std::vector<Utils::Infos::cp_info> &constant_pool) {
    this->cpivec = constant_pool;
  }

  std::vector<Utils::Infos::cp_info> cpivec;
};

void to_json(json &j, Serializer &is);
}  // namespace Infos
}  // namespace Utils

#endif  // INCLUDE_UTILS_SERIALIZERS_INFOSERIALIZER__H_
