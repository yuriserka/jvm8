#ifndef INCLUDE_UTILS_CONSTANTPOOL_H_
#define INCLUDE_UTILS_CONSTANTPOOL_H_

#include <string>
#include <vector>

#include "utils/attributes.h"
#include "utils/types.h"

namespace Utils {
namespace ConstantPool {
enum ConstantTypes {
  kCONSTANT_CLASS = 7,
  kCONSTANT_FIELDREF = 9,
  kCONSTANT_METHODREF = 10,
  kCONSTANT_INTERFACEMETHODREF = 11,
  kCONSTANT_STRING = 8,
  kCONSTANT_INTEGER = 3,
  kCONSTANT_FLOAT = 4,
  kCONSTANT_LONG = 5,
  kCONSTANT_DOUBLE = 6,
  kCONSTANT_NAMEANDTYPE = 12,
  kCONSTANT_UTF8 = 1,
  kCONSTANT_METHODHANDLE = 15,
  kCONSTANT_METHODTYPE = 16,
  kCONSTANT_INVOKEDYNAMIC = 18
};

std::string getConstantTypename(const Types::u1 &ct);

// forward declaration
class cp_info;
class CONSTANT_Class_info;
class BaseReference;
class CONSTANT_FieldRef_info;
class CONSTANT_Methodref_info;
class CONSTANT_InterfaceMethodref_info;
class CONSTANT_String_info;
class CONSTANT_Integer_info;
class CONSTANT_Float_info;
class CONSTANT_Long_info;
class CONSTANT_Double_info;
class CONSTANT_NameAndType_info;
class CONSTANT_Utf8_info;
class CONSTANT_MethodHandle_info;
class CONSTANT_MethodType_info;
class CONSTANT_InvokeDynamic_info;

class BaseConstantInfo {
 public:
  BaseConstantInfo() = default;

  explicit BaseConstantInfo(const Types::u1 &tag) { this->tag = tag; }

  virtual ~BaseConstantInfo() = default;

  Types::u1 tag;
};

class cp_info {
 public:
  cp_info() = default;

  ~cp_info() = default;

  template <typename T>
  inline void deleteclass() {
    auto derivedptr = this->getClass<T>();
    derivedptr->~T();

    delete derivedptr;
  }

  template <typename T>
  inline T *setBase(const Types::u1 &tag) {
    this->base = new T(tag);
    return this->getClass<T>();
  }

  template <typename T>
  inline T *getClass() const {
    return dynamic_cast<T *>(this->base);
  }

  BaseConstantInfo *base;
};

class CONSTANT_Class_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Class_info(const Types::u1 &tag) : BaseConstantInfo(tag) {}

  ~CONSTANT_Class_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u2 name_index;
};

class BaseReference : public BaseConstantInfo {
 public:
  explicit BaseReference(const Types::u1 &tag) : BaseConstantInfo(tag) {}

  virtual std::string getValue(const std::vector<cp_info> &constpool,
                               const bool &dot) const = 0;
  virtual std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                                     const int &delta_tab) = 0;

  Types::u2 class_index;
  Types::u2 name_and_type_index;
};

class CONSTANT_FieldRef_info : public BaseReference {
 public:
  explicit CONSTANT_FieldRef_info(const Types::u1 &tag) : BaseReference(tag) {}

  ~CONSTANT_FieldRef_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool,
                       const bool &dot) const override;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab) override;
};

class CONSTANT_Methodref_info : public BaseReference {
 public:
  explicit CONSTANT_Methodref_info(const Types::u1 &tag) : BaseReference(tag) {}

  ~CONSTANT_Methodref_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool,
                       const bool &dot) const override;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab) override;
};

class CONSTANT_InterfaceMethodref_info : public BaseReference {
 public:
  explicit CONSTANT_InterfaceMethodref_info(const Types::u1 &tag)
      : BaseReference(tag) {}

  ~CONSTANT_InterfaceMethodref_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool,
                       const bool &dot) const override;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab) override;
};

class CONSTANT_String_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_String_info(const Types::u1 &tag) : BaseConstantInfo(tag) {}

  ~CONSTANT_String_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u2 string_index;
};

class CONSTANT_Integer_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Integer_info(const Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_Integer_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u4 bytes;
};

class CONSTANT_Float_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Float_info(const Types::u1 &tag) : BaseConstantInfo(tag) {}

  ~CONSTANT_Float_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u4 bytes;
};

class CONSTANT_Long_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Long_info(const Types::u1 &tag) : BaseConstantInfo(tag) {}

  ~CONSTANT_Long_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u4 high_bytes;
  Types::u4 low_bytes;
};

class CONSTANT_Double_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Double_info(const Types::u1 &tag) : BaseConstantInfo(tag) {}

  ~CONSTANT_Double_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;

  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u4 high_bytes;
  Types::u4 low_bytes;
};

class CONSTANT_NameAndType_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_NameAndType_info(const Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_NameAndType_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u2 name_index;
  Types::u2 descriptor_index;
};

class CONSTANT_Utf8_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Utf8_info(const Types::u1 &tag) : BaseConstantInfo(tag) {}

  ~CONSTANT_Utf8_info() = default;

  std::string getValue() const;
  std::string getGeneralInfo(const int &delta_tab);

  Types::u2 length;
  std::vector<Types::u1> bytes;
};

class CONSTANT_MethodHandle_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_MethodHandle_info(const Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_MethodHandle_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u1 reference_kind;
  Types::u2 reference_index;
};

class CONSTANT_MethodType_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_MethodType_info(const Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_MethodType_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u2 descriptor_index;
};

class CONSTANT_InvokeDynamic_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_InvokeDynamic_info(const Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_InvokeDynamic_info() = default;

  std::string getValue(const std::vector<cp_info> &constpool) const;
  std::string getGeneralInfo(const std::vector<cp_info> &constpool,
                             const int &delta_tab);

  Types::u2 bootstrap_method_attr_index;
  Types::u2 name_and_type_index;
};
}  // namespace ConstantPool
}  // namespace Utils

#endif  // INCLUDE_UTILS_CONSTANTPOOL_H_
