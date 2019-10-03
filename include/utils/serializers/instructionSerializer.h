#ifndef INCLUDE_UTILS_SERIALIZERS_INSTRUCTIONSERIALIZER_H_
#define INCLUDE_UTILS_SERIALIZERS_INSTRUCTIONSERIALIZER_H_

#include "classfile.h"
#include "utils/serializers/infoSerializer.h"

using nlohmann::json;

namespace Instructions {
class InstructionSerializer {
 public:
  InstructionSerializer(const ClassFile *cf,
                        const std::vector<Utils::Types::u1> &code) {
    this->cf = cf;
    this->code_array = code;
    this->kpool_serializer = new Utils::Infos::ConstantPoolSerializer(cf);
  }

  ~InstructionSerializer() { delete this->kpool_serializer; }

  int to_json(json *j, std::vector<Utils::Types::u1>::iterator *code_it,
              const bool &wide = false);

 private:
  const ClassFile *cf;
  std::vector<Utils::Types::u1> code_array;
  const Utils::Infos::ConstantPoolSerializer *kpool_serializer;
};
}  // namespace Instructions

#endif  // INCLUDE_UTILS_SERIALIZERS_INSTRUCTIONSERIALIZER_H_
