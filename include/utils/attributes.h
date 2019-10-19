#ifndef INCLUDE_UTILS_ATTRIBUTES_H_
#define INCLUDE_UTILS_ATTRIBUTES_H_

#include <string>
#include <vector>
#include "utils/types.h"

struct excption_info {
  Utils::Types::u2 start_pc;
  Utils::Types::u2 end_pc;
  Utils::Types::u2 handler_pc;
  Utils::Types::u2 catch_type;
};

struct innerClasses_info {
  Utils::Types::u2 inner_class_info_index;
  Utils::Types::u2 outer_class_info_index;
  Utils::Types::u2 inner_name_index;
  Utils::Types::u2 inner_class_access_flags;
};

struct lineNumberTable_info {
  Utils::Types::u2 start_pc;
  Utils::Types::u2 line_number;
};

struct localVariableTable_info {
  Utils::Types::u2 start_pc;
  Utils::Types::u2 length;
  Utils::Types::u2 name_index;
  Utils::Types::u2 descriptor_index;
  Utils::Types::u2 index;
};

struct localVariableTypetable_info {
  Utils::Types::u2 start_pc;
  Utils::Types::u2 length;
  Utils::Types::u2 name_index;
  Utils::Types::u2 signature_index;
  Utils::Types::u2 index;
};

struct element_value;

struct annotation {
  Utils::Types::u2 type_index;
  Utils::Types::u2 num_element_value_pairs;
  struct annotation_info {
    Utils::Types::u2 element_name_index;
    element_value *value;
  } info;
  std::vector<annotation_info> element_value_pairs;
};

struct element_value {
  Utils::Types::u1 tag;
  union {
    Utils::Types::u2 const_value_index;
    struct {
      Utils::Types::u2 type_name_index;
      Utils::Types::u2 const_name_index;
    } enum_const_value;
    Utils::Types::u2 class_info_index;
    annotation annotation_value;
    struct {
      Utils::Types::u2 num_values;
      std::vector<element_value> values;
    } array_value;
  } value;
};

struct runtimeVisibleParameterAnnotations_info {
  Utils::Types::u2 num_annotations;
  std::vector<annotation> annotations;
};

struct runtimeInvisibleParameterAnnotations_info {
  Utils::Types::u2 num_annotations;
  std::vector<annotation> annotations;
};

struct BootstrapMethods_info {
  Utils::Types::u2 bootstrap_method_ref;
  Utils::Types::u2 num_bootstrap_arguments;
  std::vector<Utils::Types::u2> bootstrap_arguments;
};

struct MethodParameters_info {
  Utils::Types::u2 name_index;
  Utils::Types::u2 access_flags;
};

// forward declaration
class Viewer;
class ClassFile;

namespace Utils {
namespace ConstantPool {
// forward declaration
class cp_info;
}  // namespace ConstantPool

namespace Attributes {
enum attr_types {
  kINVALID = -1,
  kCONSTANTVALUE,
  kCODE,
  kEXCEPTIONS,
  kINNERCLASS,
  kENCLOSINGMETHOD,
  kSYNTHETIC,
  kSIGNATURE,
  kSOURCEFILE,
  kLINENUMBERTABLE,
  kLOCALVARIABLETABLE,
  kDEPRECATED,
  kBOOTSTRAPMETHODS,
  kMETHODPARAMETERS
};

int getAttributeType(const std::wstring &attrname);

class BaseAttribute {
 public:
  BaseAttribute() = default;

  BaseAttribute(const Utils::Types::u2 &nameIdx,
                const Utils::Types::u4 &attrLen) {
    this->attribute_name_index = nameIdx;
    this->attribute_length = attrLen;
  }

  virtual ~BaseAttribute() = default;

  Utils::Types::u2 attribute_name_index;
  Utils::Types::u4 attribute_length;
};

class attribute_info {
 public:
  attribute_info() = default;

  ~attribute_info() = default;

  template <typename T>
  void deleteclass() {
    auto derivedptr = this->getClass<T>();
    derivedptr->~T();

    delete derivedptr;
  }

  template <typename T>
  T *setBase(const Utils::Types::u2 &nameIdx, const Utils::Types::u4 &attrLen) {
    this->base = new T(nameIdx, attrLen);
    return this->getClass<T>();
  }

  template <typename T>
  T *getClass() const {
    return dynamic_cast<T *>(this->base);
  }

  BaseAttribute *base;
};

class NotImplemented : public BaseAttribute {
 public:
  NotImplemented(const Utils::Types::u2 &nameIdx,
                 const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~NotImplemented() = default;

  std::wstring getSpecificInfo(const int &delta_tab);
};

class ConstantValue_attribute : public BaseAttribute {
 public:
  ConstantValue_attribute(const Utils::Types::u2 &nameIdx,
                          const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~ConstantValue_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 constantvalue_index;
};

class Code_attribute : public BaseAttribute {
 public:
  Code_attribute(const Utils::Types::u2 &nameIdx,
                 const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Code_attribute() = default;

  std::wstring getSpecificInfo(Viewer *v, const ClassFile *cf,
                               const int &delta_tab);

  Utils::Types::u2 max_stack;
  Utils::Types::u2 max_locals;
  Utils::Types::u4 code_length;
  std::vector<Utils::Types::u1> code;
  Utils::Types::u2 exception_table_length;
  Utils::Types::u2 attributes_count;
  std::vector<attribute_info> attributes;
  std::vector<excption_info> exception_table;

 private:
  std::wstring getTable(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const std::vector<std::string> &header_vars, const int &delta_tab);
};

class Exceptions_attribute : public BaseAttribute {
 public:
  Exceptions_attribute(const Utils::Types::u2 &nameIdx,
                       const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Exceptions_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 number_of_exceptions;
  std::vector<Utils::Types::u2> exception_index_table;

 private:
  std::wstring getTable(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const std::vector<std::string> &header_vars, const int &delta_tab);
};

class InnerClasses_attribute : public BaseAttribute {
 public:
  InnerClasses_attribute(const Utils::Types::u2 &nameIdx,
                         const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~InnerClasses_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 number_of_classes;
  std::vector<innerClasses_info> classes;

 private:
  std::wstring getTable(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const std::vector<std::string> &header_vars, const int &delta_tab);
};

class EnclosingMethod_attribute : public BaseAttribute {
 public:
  EnclosingMethod_attribute(const Utils::Types::u2 &nameIdx,
                            const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~EnclosingMethod_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 class_index;
  Utils::Types::u2 method_index;
};

class Synthetic_attribute : public BaseAttribute {
 public:
  Synthetic_attribute(const Utils::Types::u2 &nameIdx,
                      const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Synthetic_attribute() = default;
};

class Signature_attribute : public BaseAttribute {
 public:
  Signature_attribute(const Utils::Types::u2 &nameIdx,
                      const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Signature_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 signature_index;
};

class SourceFile_attribute : public BaseAttribute {
 public:
  SourceFile_attribute(const Utils::Types::u2 &nameIdx,
                       const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~SourceFile_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 sourcefile_index;
};

class SourceDebugExtension_attribute : public BaseAttribute {
 public:
  SourceDebugExtension_attribute(const Utils::Types::u2 &nameIdx,
                                 const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~SourceDebugExtension_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  std::vector<Utils::Types::u1> debug_extension;
};

class LineNumberTable_attribute : public BaseAttribute {
 public:
  LineNumberTable_attribute(const Utils::Types::u2 &nameIdx,
                            const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~LineNumberTable_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 line_number_table_length;
  std::vector<lineNumberTable_info> line_number_table;

 private:
  std::wstring getTable(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const std::vector<std::string> &header_vars, const int &delta_tab);
};

class LocalVariableTable_attribute : public BaseAttribute {
 public:
  LocalVariableTable_attribute(const Utils::Types::u2 &nameIdx,
                               const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~LocalVariableTable_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 local_variable_table_length;
  std::vector<localVariableTable_info> local_variable_table;

 private:
  std::wstring getTable(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const std::vector<std::string> &header_vars, const int &delta_tab);
};

class LocalVariableTypeTable_attribute : public BaseAttribute {
 public:
  LocalVariableTypeTable_attribute(const Utils::Types::u2 &nameIdx,
                                   const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~LocalVariableTypeTable_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 local_variable_type_table_length;
  std::vector<localVariableTypetable_info> local_variable_type_table;
};

class Deprecated_attribute : public BaseAttribute {
 public:
  Deprecated_attribute(const Utils::Types::u2 &nameIdx,
                       const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Deprecated_attribute() = default;
};

class RuntimeVisibleAnnotations_attribute : public BaseAttribute {
 public:
  RuntimeVisibleAnnotations_attribute(const Utils::Types::u2 &nameIdx,
                                      const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~RuntimeVisibleAnnotations_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 num_annotations;
  std::vector<annotation> annotations;
};

class RuntimeInvisibleAnnotations_attribute : public BaseAttribute {
 public:
  RuntimeInvisibleAnnotations_attribute(const Utils::Types::u2 &nameIdx,
                                        const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~RuntimeInvisibleAnnotations_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 num_annotations;
  std::vector<annotation> annotations;
};

class RuntimeVisibleParameterAnnotations_attribute : public BaseAttribute {
 public:
  RuntimeVisibleParameterAnnotations_attribute(const Utils::Types::u2 &nameIdx,
                                               const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~RuntimeVisibleParameterAnnotations_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u1 num_parameters;
  std::vector<runtimeVisibleParameterAnnotations_info> parameter_annotations;
};

class RuntimeInvisibleParameterAnnotations_attribute : public BaseAttribute {
 public:
  RuntimeInvisibleParameterAnnotations_attribute(
      const Utils::Types::u2 &nameIdx, const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~RuntimeInvisibleParameterAnnotations_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u1 num_parameters;
  std::vector<runtimeInvisibleParameterAnnotations_info> parameter_annotations;
};

class BootstrapMethods_attribute : public BaseAttribute {
 public:
  BootstrapMethods_attribute(const Utils::Types::u2 &nameIdx,
                             const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~BootstrapMethods_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u2 num_bootstrap_methods;
  std::vector<BootstrapMethods_info> bootstrap_methods;

 private:
  std::wstring getTable(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const std::vector<std::string> &header_vars, const int &delta_tab);
};

class MethodParameters_attribute : public BaseAttribute {
 public:
  MethodParameters_attribute(const Utils::Types::u2 &nameIdx,
                             const Utils::Types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~MethodParameters_attribute() = default;

  std::wstring getSpecificInfo(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const int &delta_tab);

  Utils::Types::u1 parameters_count;
  std::vector<MethodParameters_info> parameters;

 private:
  std::wstring getTable(
      const std::vector<Utils::ConstantPool::cp_info> &constpool,
      const std::vector<std::string> &header_vars, const int &delta_tab);
};
}  // namespace Attributes
}  // namespace Utils

#endif  // INCLUDE_UTILS_ATTRIBUTES_H_
