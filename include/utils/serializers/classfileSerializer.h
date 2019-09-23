#ifndef INCLUDE_UTILS_SERIALIZERS_CLASSFILESERIALIZER_H_
#define INCLUDE_UTILS_SERIALIZERS_CLASSFILESERIALIZER_H_

#include "classfile.h"

class ClassFileSerializer {
 public:
  explicit ClassFileSerializer(const ClassFile *cf) { this->cf = cf; }

  void to_json(json *j);

 private:
  void writeMagic(json *j);
  void writeVersion(json *j);
  void writeConstantPool(json *j);
  void writeAccessFlags(json *j);
  void writeThisClass(json *j);
  void writeSuperClass(json *j);
  void writeInterfaces(json *j);
  void writeFields(json *j);
  void writeMethods(json *j);
  void writeAttributes(json *j);

  const ClassFile *cf;
};

#endif  // INCLUDE_UTILS_SERIALIZERS_CLASSFILESERIALIZER_H_
