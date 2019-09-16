#ifndef INCLUDE_UTILS_ATTRIBUTES_H_
#define INCLUDE_UTILS_ATTRIBUTES_H_

#include <vector>
#include "utils/types.h"

namespace types = Utils::Types;

struct excption_info {
  types::u2 start_pc;
  types::u2 end_pc;
  types::u2 handler_pc;
  types::u2 catch_type;
};

struct innerClasses_info {
  types::u2 inner_class_info_index;
  types::u2 outer_class_info_index;
  types::u2 inner_name_index;
  types::u2 inner_class_access_flags;
};

struct lineNumberTable_info {
  types::u2 start_pc;
  types::u2 line_number;
};

struct localVariableTable_info {
  types::u2 start_pc;
  types::u2 length;
  types::u2 name_index;
  types::u2 descriptor_index;
  types::u2 index;
};

struct localVariableTypetable_info {
  types::u2 start_pc;
  types::u2 length;
  types::u2 name_index;
  types::u2 signature_index;
  types::u2 index;
};

struct element_value;

struct annotation {
  types::u2 type_index;
  types::u2 num_element_value_pairs;
  struct annotation_info {
    types::u2 element_name_index;
    element_value *value;
  };
  std::vector<annotation_info> element_value_pairs;
};

struct element_value {
  types::u1 tag;
  union {
    types::u2 const_value_index;
    struct {
      types::u2 type_name_index;
      types::u2 const_name_index;
    } enum_const_value;
    types::u2 class_info_index;
    annotation annotation_value;
    struct {
      types::u2 num_values;
      std::vector<element_value> values;
    } array_value;
  } value;
};

struct runtimeVisibleParameterAnnotations_info {
  types::u2 num_annotations;
  std::vector<annotation> annotations;
};

struct runtimeInvisibleParameterAnnotations_info {
  types::u2 num_annotations;
  std::vector<annotation> annotations;
};

struct BootstrapMethods_info {
  types::u2 bootstrap_method_ref;
  types::u2 num_bootstrap_arguments;
  std::vector<types::u2> bootstrap_arguments;
};

struct MethodParameters_info {
  types::u2 name_index;
  types::u2 access_flags;
};

namespace Utils {
namespace Attributes {
class BaseAttribute {
 public:
  BaseAttribute() = default;

  explicit BaseAttribute(const types::u1 &nameIdx, const types::u4 &attrLen) {
    this->attribute_name_index = nameIdx;
    this->attribute_length = attrLen;
  }

  virtual ~BaseAttribute() = default;

  types::u2 attribute_name_index;
  types::u4 attribute_length;
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
  T *setBase(const types::u1 &tag) {
    this->base = new T(tag);
    return this->getClass<T>();
  }

  template <typename T>
  T *getClass() {
    return dynamic_cast<T *>(this->base);
  }

  BaseAttribute *base;
};

class ConstantValue_attribute : public BaseAttribute {
 public:
  explicit ConstantValue_attribute(const types::u1 &nameIdx,
                                   const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~ConstantValue_attribute() = default;

  types::u2 constantvalue_index;
};

class Code_attribute : public BaseAttribute {
 public:
  explicit Code_attribute(const types::u1 &nameIdx, const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Code_attribute() = default;

  types::u2 max_stack;
  types::u2 max_locals;
  types::u4 code_length;
  std::vector<types::u1> code;
  types::u2 exception_table_length;
  types::u2 attributes_count;
  std::vector<attribute_info> attributes;
  std::vector<excption_info> exception_table;
};

class Exceptions_attribute : public BaseAttribute {
 public:
  explicit Exceptions_attribute(const types::u1 &nameIdx,
                                const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Exceptions_attribute() = default;

  types::u2 number_of_exceptions;
  std::vector<types::u2> exception_index_table;
};

class InnerClasses_attribute : public BaseAttribute {
 public:
  explicit InnerClasses_attribute(const types::u1 &nameIdx,
                                  const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~InnerClasses_attribute() = default;

  types::u2 attribute_name_index;
  types::u4 attribute_length;
  types::u2 number_of_classes;
  std::vector<innerClasses_info> classes;
};

class EnclosingMethod_attribute : public BaseAttribute {
 public:
  explicit EnclosingMethod_attribute(const types::u1 &nameIdx,
                                     const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~EnclosingMethod_attribute() = default;

  types::u2 class_index;
  types::u2 method_index;
};

class Synthetic_attribute : public BaseAttribute {
 public:
  explicit Synthetic_attribute(const types::u1 &nameIdx,
                               const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Synthetic_attribute() = default;
};

class Signature_attribute : public BaseAttribute {
 public:
  explicit Signature_attribute(const types::u1 &nameIdx,
                               const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Signature_attribute() = default;

  types::u2 signature_index;
};

class SourceFile_attribute : public BaseAttribute {
  explicit SourceFile_attribute(const types::u1 &nameIdx,
                                const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~SourceFile_attribute() = default;

  types::u2 sourcefile_index;
};

class SourceDebugExtension_attribute : public BaseAttribute {
 public:
  explicit SourceDebugExtension_attribute(const types::u1 &nameIdx,
                                          const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~SourceDebugExtension_attribute() = default;

  std::vector<types::u1> debug_extension;
};

class LineNumberTable_attribute : public BaseAttribute {
 public:
  explicit LineNumberTable_attribute(const types::u1 &nameIdx,
                                     const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~LineNumberTable_attribute() = default;

  types::u2 line_number_table_length;
  std::vector<lineNumberTable_info> line_number_table;
};

class LocalVariableTable_attribute : public BaseAttribute {
 public:
  explicit LocalVariableTable_attribute(const types::u1 &nameIdx,
                                        const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~LocalVariableTable_attribute() = default;

  types::u2 local_variable_table_length;
  std::vector<localVariableTable_info> local_variable_table;
};

class LocalVariableTypeTable_attribute : public BaseAttribute {
 public:
  explicit LocalVariableTypeTable_attribute(const types::u1 &nameIdx,
                                            const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~LocalVariableTypeTable_attribute() = default;

  types::u2 local_variable_type_table_length;
  std::vector<localVariableTypetable_info> local_variable_type_table;
};

class Deprecated_attribute : public BaseAttribute {
 public:
  explicit Deprecated_attribute(const types::u1 &nameIdx,
                                const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~Deprecated_attribute() = default;
};

class RuntimeVisibleAnnotations_attribute : public BaseAttribute {
 public:
  explicit RuntimeVisibleAnnotations_attribute(const types::u1 &nameIdx,
                                               const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~RuntimeVisibleAnnotations_attribute() = default;

  types::u2 num_annotations;
  std::vector<annotation> annotations;
};

class RuntimeInvisibleAnnotations_attribute : public BaseAttribute {
 public:
  explicit RuntimeInvisibleAnnotations_attribute(const types::u1 &nameIdx,
                                                 const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~RuntimeInvisibleAnnotations_attribute() = default;

  types::u2 num_annotations;
  std::vector<annotation> annotations;
};

class RuntimeVisibleParameterAnnotations_attribute : public BaseAttribute {
 public:
  explicit RuntimeVisibleParameterAnnotations_attribute(
      const types::u1 &nameIdx, const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~RuntimeVisibleParameterAnnotations_attribute() = default;

  types::u1 num_parameters;
  std::vector<runtimeVisibleParameterAnnotations_info> parameter_annotations;
};

class RuntimeInvisibleParameterAnnotations_attribute : public BaseAttribute {
 public:
  explicit RuntimeInvisibleParameterAnnotations_attribute(
      const types::u1 &nameIdx, const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~RuntimeInvisibleParameterAnnotations_attribute() = default;

  types::u1 num_parameters;
  std::vector<runtimeInvisibleParameterAnnotations_info> parameter_annotations;
};

class BootstrapMethods_attribute : public BaseAttribute {
 public:
  explicit BootstrapMethods_attribute(const types::u1 &nameIdx,
                                      const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~BootstrapMethods_attribute() = default;

  types::u2 num_bootstrap_methods;
  std::vector<BootstrapMethods_info> bootstrap_methods;
};

class MethodParameters_attribute : public BaseAttribute {
 public:
  explicit MethodParameters_attribute(const types::u1 &nameIdx,
                                      const types::u4 &attrLen)
      : BaseAttribute(nameIdx, attrLen) {}

  ~MethodParameters_attribute() = default;

  types::u1 parameters_count;
  std::vector<MethodParameters_info> parameters;
};
}  // namespace Attributes
}  // namespace Utils

#endif  // INCLUDE_UTILS_ATTRIBUTES_H_
