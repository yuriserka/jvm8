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

std::string getConstantTypename(const Utils::Types::u1 &ct);

// forward declaration
class cp_info;
class CONSTANT_Class_info;
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

  explicit BaseConstantInfo(const Utils::Types::u1 &tag) { this->tag = tag; }

  virtual ~BaseConstantInfo() = default;

  Utils::Types::u1 tag;
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
  inline T *setBase(const Utils::Types::u1 &tag) {
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
  explicit CONSTANT_Class_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_Class_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u2 name_index;
};

class CONSTANT_FieldRef_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_FieldRef_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_FieldRef_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool,
                        const bool dot) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u2 class_index;
  Utils::Types::u2 name_and_type_index;
};

class CONSTANT_Methodref_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Methodref_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_Methodref_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool,
                        const bool dot) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u2 class_index;
  Utils::Types::u2 name_and_type_index;
};

class CONSTANT_InterfaceMethodref_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_InterfaceMethodref_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_InterfaceMethodref_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool,
                        const bool dot) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u2 class_index;
  Utils::Types::u2 name_and_type_index;
};

class CONSTANT_String_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_String_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_String_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u2 string_index;
};

class CONSTANT_Integer_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Integer_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_Integer_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u4 bytes;
};

class CONSTANT_Float_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Float_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_Float_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u4 bytes;
};

class CONSTANT_Long_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Long_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_Long_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u4 high_bytes;
  Utils::Types::u4 low_bytes;
};

class CONSTANT_Double_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Double_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_Double_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;

  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u4 high_bytes;
  Utils::Types::u4 low_bytes;
};

class CONSTANT_NameAndType_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_NameAndType_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_NameAndType_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u2 name_index;
  Utils::Types::u2 descriptor_index;
};

class CONSTANT_Utf8_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_Utf8_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_Utf8_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const int delta_tab);

  Utils::Types::u2 length;
  std::vector<Utils::Types::u1> bytes;
};

class CONSTANT_MethodHandle_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_MethodHandle_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_MethodHandle_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u1 reference_kind;
  Utils::Types::u2 reference_index;
};

class CONSTANT_MethodType_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_MethodType_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_MethodType_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u2 descriptor_index;
};

class CONSTANT_InvokeDynamic_info : public BaseConstantInfo {
 public:
  explicit CONSTANT_InvokeDynamic_info(const Utils::Types::u1 &tag)
      : BaseConstantInfo(tag) {}

  ~CONSTANT_InvokeDynamic_info() = default;

  std::wstring getValue(const std::vector<cp_info> *constpool) const;
  std::wstring getGeneralInfo(const std::vector<cp_info> *constpool,
                              const int delta_tab);

  Utils::Types::u2 bootstrap_method_attr_index;
  Utils::Types::u2 name_and_type_index;
};
}  // namespace ConstantPool
}  // namespace Utils

#endif  // INCLUDE_UTILS_CONSTANTPOOL_H_
