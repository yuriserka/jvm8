#ifndef INCLUDE_VIEWER_H_
#define INCLUDE_VIEWER_H_

#include <string>
#include <vector>
#include "classfile.h"
#include "utils/attributes.h"

class Viewer {
 public:
  explicit Viewer(const ClassFile *cf, const std::string &fname) {
    this->classfile = cf;
    this->classname = fname;
  }

  void printClassFile();

 private:
  void printMagic();
  void printVersion();
  void printConstantPool();
  bool printConstantPoolInfo(const int &index, const int &depth,
                             const bool &inner);
  void printAccessFlags();
  void printThisClass();
  void printSuperClass();

  void printInterfaces();
  void printInterfacesInfo(const int &index, const int &depth);

  void printFields();
  void printFieldsInfo(const int &index, const int &depth);

  void printMethods();
  void printMethodsInfo(const int &index, const int &depth);

  void printAttributes(
      const std::vector<Utils::Attributes::attribute_info> &attributes,
      const int &attr_count, const int &depth);
  void printAttributeInfo(Utils::Attributes::attribute_info *attribute,
                          const int &index, const int &depth);

  template <typename T>
  void printReferences(const T *kinfo, const int &depth, const bool &inner);

  template <typename T>
  void print4bytesNumeral(const T *kinfo, const int &depth, const bool &inner);

  template <typename T>
  void print8bytesNumeral(const T *kinfo, const int &depth, const bool &inner);

  template <typename T>
  void printAccessFlags(const T *obj, const int &depth,
                        std::vector<std::string> (*getAccessTypeFunc)(
                            const Utils::Types::u2 &accessType));

  std::string classname;
  const ClassFile *classfile;
};

#endif  // INCLUDE_VIEWER_H_
