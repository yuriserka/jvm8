#ifndef INCLUDE_VIEWER_H_
#define INCLUDE_VIEWER_H_

#include <string>
#include <vector>
#include "classfile.h"
#include "utils/attributes.h"

/**
 * @brief Class responsable for .class file visualization
 *
 */
class Viewer {
 public:
  /**
   * @brief Construct a new Viewer object
   *
   * @param cf the class file object which structure will be printed
   * @param fname the file name
   */
  explicit Viewer(const ClassFile *cf, const std::string &fname) {
    this->classfile = cf;
    this->classname = fname;
  }

  /**
   * @brief responsable for print each component of the ClassFile structure
   */
  void printClassFile();

  /**
   * @brief Get the Constant Pool Info object and return its string
   * representation
   *
   * @param index the constant pool index to look at
   * @param dot in most cases the print has the format: Class.method,
   * but not always
   * @return std::string the constructed string to be printed
   */
  std::string getConstantPoolInfo(const int &index, const bool &dot = true);

 private:
  void printMagic();
  void printVersion();

  void printConstantPool();
  void printConstantPoolCount();
  bool printConstantPoolInfo(const int index, const int delta_tab);

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
  void printAttributeInfo(const Utils::Attributes::attribute_info *attribute,
                          const int &index, const int &tab_shift);

  std::string getAttributeHeader(const Utils::Attributes::attribute_info *attr,
                                 const int &tab_shift);

  std::string classname;
  const ClassFile *classfile;
};

#endif  // INCLUDE_VIEWER_H_
