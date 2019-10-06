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
  std::wstring getConstantPoolInfo(const int &index, const bool &dot = true);

 private:
  void printMagic();
  void printVersion();

  void printConstantPool();
  void printConstantPoolCount();
  bool printConstantPoolInfo(const int &index, const int &tab_shift,
                             const bool &inner,
                             const bool &innerNameAndType = false,
                             const int &utf8fmt = -1);

  void printAccessFlags();
  void printThisClass();
  void printSuperClass();

  void printInterfaces();
  void printInterfacesCount();
  void printInterfaceInfo(const int &index, const int &tab_shift);

  void printFields();
  void printFieldsCount();
  void printFieldInfo(const int &index, const int &tab_shift);

  void printMethods();
  void printMethodsCount();
  void printMethodInfo(const int &index, const int &tab_shift);

  void printAttributes(
      const std::vector<Utils::Attributes::attribute_info> &attributes,
      const int &attr_count, const int &tab_shift, const int &qtd_stars,
      const int &width_shift);
  void printAttributesCount(const int &tab_shift, const int &attr_count);
  void printAttributeInfo(Utils::Attributes::attribute_info *attribute,
                          const int &index, const int &tab_shift);

  template <typename T>
  void printReferences(const T *kinfo, const int &tab_shift);

  template <typename T>
  void print4bytesNumeral(const T *kinfo, const int &tab_shift,
                          const bool &inner);

  template <typename T>
  void print8bytesNumeral(const T *kinfo, const int &tab_shift,
                          const bool &inner);

  template <typename T>
  void printAccessFlags(const T *obj, const int &tab_shift, const int &width,
                        std::vector<std::string> (*getAccessTypeFunc)(
                            const Utils::Types::u2 &accessType));

  void printTable(const std::vector<std::string> vars,
                  Utils::Attributes::InnerClasses_attribute *innerclass_attr,
                  const int &tab_shift);

  void printTable(const std::vector<std::string> vars,
                  Utils::Attributes::LineNumberTable_attribute *lnt_attr,
                  const int &tab_shift);

  void printTable(const std::vector<std::string> vars,
                  Utils::Attributes::Code_attribute *code_attr,
                  const int &tab_shift);

  std::string classname;
  const ClassFile *classfile;
};

#endif  // INCLUDE_VIEWER_H_
