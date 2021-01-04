#include "utils/constantPool.h"

#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>

#include "utils/errors.h"
#include "utils/memory.h"
#include "utils/reference_kind.h"
#include "utils/string.h"

namespace Utils {
namespace ConstantPool {
std::string getConstantTypename(const Types::u1 &ct) {
  static std::map<Types::u1, std::string> names = {
      {kCONSTANT_CLASS, "Class"},
      {kCONSTANT_FIELDREF, "Fieldref"},
      {kCONSTANT_METHODREF, "Methodref"},
      {kCONSTANT_INTERFACEMETHODREF, "InterfaceMethodref"},
      {kCONSTANT_STRING, "String"},
      {kCONSTANT_INTEGER, "Integer"},
      {kCONSTANT_FLOAT, "Float"},
      {kCONSTANT_LONG, "Long"},
      {kCONSTANT_DOUBLE, "Double"},
      {kCONSTANT_NAMEANDTYPE, "NameAndType"},
      {kCONSTANT_UTF8, "Utf8"},
      {kCONSTANT_METHODHANDLE, "MethodHandle"},
      {kCONSTANT_METHODTYPE, "MethodType"},
      {kCONSTANT_INVOKEDYNAMIC, "InvokeDynamic"}};
  return names.at(ct);
}
// ----------------------------------------------------------------------------
std::string CONSTANT_Class_info::getValue(
    const std::vector<cp_info> &constpool) const {
  auto classname =
      constpool[this->name_index - 1].getClass<CONSTANT_Utf8_info>();
  return classname->getValue();
}

std::string CONSTANT_Class_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "Class Name: #" << this->name_index
     << " ";
  ss << "<" << this->getValue(constpool) << ">";

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_FieldRef_info::getValue(
    const std::vector<cp_info> &constpool, const bool &dot) const {
  auto classname =
      constpool[this->class_index - 1].getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool[this->name_and_type_index - 1]
                           .getClass<CONSTANT_NameAndType_info>();

  std::stringstream ss;
  auto n_and_t_str = name_and_type->getValue(constpool);
  ss << classname->getValue(constpool) << (dot ? "." : "");
  std::string field_name = "\0";
  for (auto it = n_and_t_str.begin(); *it != L':'; ++it) {
    field_name += *it;
  }
  ss << field_name;

  return ss.str();
}

std::string CONSTANT_FieldRef_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  auto classname =
      constpool[this->class_index - 1].getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool[this->name_and_type_index - 1]
                           .getClass<CONSTANT_NameAndType_info>();

  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "Class name: #" << this->class_index
     << " ";
  ss << "<" << classname->getValue(constpool) << ">";
  ss << "\n";
  ss << std::string(delta_tab, '\t') << "Name and type: #"
     << this->name_and_type_index << " ";
  ss << "<" << name_and_type->getValue(constpool) << ">";

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_Methodref_info::getValue(
    const std::vector<cp_info> &constpool, const bool &dot) const {
  auto classname =
      constpool[this->class_index - 1].getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool[this->name_and_type_index - 1]
                           .getClass<CONSTANT_NameAndType_info>();

  std::stringstream ss;
  auto n_and_t_str = name_and_type->getValue(constpool);
  ss << classname->getValue(constpool) << (dot ? "." : "");
  std::string method_name = "\0";
  for (auto it = n_and_t_str.begin(); *it != L':'; ++it) {
    method_name += *it;
  }
  ss << method_name;

  return ss.str();
}

std::string CONSTANT_Methodref_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  auto classname =
      constpool[this->class_index - 1].getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool[this->name_and_type_index - 1]
                           .getClass<CONSTANT_NameAndType_info>();

  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "Class name: #" << this->class_index
     << " ";
  ss << "<" << classname->getValue(constpool) << ">";
  ss << "\n";
  ss << std::string(delta_tab, '\t') << "Name and type: #"
     << this->name_and_type_index << " ";
  ss << "<" << name_and_type->getValue(constpool) << ">";

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_InterfaceMethodref_info::getValue(
    const std::vector<cp_info> &constpool, const bool &dot) const {
  auto classname =
      constpool[this->class_index - 1].getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool[this->name_and_type_index - 1]
                           .getClass<CONSTANT_NameAndType_info>();

  std::stringstream ss;
  auto n_and_t_str = name_and_type->getValue(constpool);
  ss << classname->getValue(constpool) << (dot ? "." : "");
  std::string interfacemethod_name = "\0";
  for (auto it = n_and_t_str.begin(); *it != L':'; ++it) {
    interfacemethod_name += *it;
  }
  ss << interfacemethod_name;

  return ss.str();
}

std::string CONSTANT_InterfaceMethodref_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  auto classname =
      constpool[this->class_index - 1].getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool[this->name_and_type_index - 1]
                           .getClass<CONSTANT_NameAndType_info>();

  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "Class name: #" << this->class_index
     << " ";
  ss << "<" << classname->getValue(constpool) << ">";
  ss << "\n";
  ss << std::string(delta_tab, '\t') << "Name and type: #"
     << this->name_and_type_index << " ";
  ss << "<" << name_and_type->getValue(constpool) << ">";

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_NameAndType_info::getValue(
    const std::vector<cp_info> &constpool) const {
  auto name = constpool[this->name_index - 1].getClass<CONSTANT_Utf8_info>();
  auto descriptor =
      constpool[this->descriptor_index - 1].getClass<CONSTANT_Utf8_info>();

  std::stringstream ss;
  ss << name->getValue() << ":" << descriptor->getValue();

  return ss.str();
}

std::string CONSTANT_NameAndType_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  auto name = constpool[this->name_index - 1].getClass<CONSTANT_Utf8_info>();
  auto descriptor =
      constpool[this->descriptor_index - 1].getClass<CONSTANT_Utf8_info>();

  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "Name: #" << this->name_index << " ";
  ss << "<" << name->getValue() << ">";
  ss << "\n";
  ss << std::string(delta_tab, '\t') << "Descriptor: #"
     << this->descriptor_index << " ";
  ss << "<" << descriptor->getValue() << ">";

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_String_info::getValue(
    const std::vector<cp_info> &constpool) const {
  auto string =
      constpool[this->string_index - 1].getClass<CONSTANT_Utf8_info>();

  return string->getValue();
}

std::string CONSTANT_String_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "String: #" << this->string_index
     << " <" << this->getValue(constpool) << ">";

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_Integer_info::getValue(
    const std::vector<cp_info> &constpool) const {
  std::stringstream ss;
  ss << this->bytes;

  return ss.str();
}

std::string CONSTANT_Integer_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "Bytes: "
     << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase
     << this->bytes << "\n";

  ss << std::string(delta_tab, '\t') << "Value: " << std::dec << this->bytes;

  return ss.str();
}

// ----------------------------------------------------------------------------
std::string CONSTANT_Float_info::getValue(
    const std::vector<cp_info> &constpool) const {
  std::stringstream ss;
  ss << castTo<float>(&this->bytes);

  return ss.str();
}

std::string CONSTANT_Float_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "Bytes: "
     << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase
     << this->bytes << "\n";

  ss << std::string(delta_tab, '\t') << "Value: " << std::dec
     << castTo<float>(&this->bytes);

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_Long_info::getValue(
    const std::vector<cp_info> &constpool) const {
  std::stringstream ss;
  auto u8val =
      (static_cast<Types::u8>(this->high_bytes) << 32 | this->low_bytes);
  ss << u8val;

  return ss.str();
}

std::string CONSTANT_Long_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  auto u8val =
      (static_cast<Types::u8>(this->high_bytes) << 32 | this->low_bytes);

  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "High Bytes: ";
  ss << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase
     << this->high_bytes << "\n";

  ss << std::string(delta_tab, '\t') << "Low Bytes: ";
  ss << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase
     << this->low_bytes << "\n";

  ss << std::string(delta_tab, '\t') << "Long: " << std::dec << u8val;

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_Double_info::getValue(
    const std::vector<cp_info> &constpool) const {
  auto u8val =
      (static_cast<Types::u8>(this->high_bytes) << 32 | this->low_bytes);

  std::stringstream ss;
  ss << castTo<double>(&u8val);

  return ss.str();
}

std::string CONSTANT_Double_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  auto u8val =
      (static_cast<Types::u8>(this->high_bytes) << 32 | this->low_bytes);

  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "High Bytes: ";
  ss << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase
     << this->high_bytes << "\n";

  ss << std::string(delta_tab, '\t') << "Low Bytes: ";
  ss << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase
     << this->low_bytes << "\n";

  ss << std::string(delta_tab, '\t') << "Double: " << std::dec
     << castTo<double>(&u8val);

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_Utf8_info::getValue() const {
  auto utf8_str = String::getUtf8Modified(this);
  return utf8_str;
}

std::string CONSTANT_Utf8_info::getGeneralInfo(const int &delta_tab) {
  std::stringstream ss;
  auto utf8_str = this->getValue();
  ss << std::string(delta_tab, '\t') << "Length of byte array: " << this->length
     << "\n"
     << std::string(delta_tab, '\t') << "Length of string: " << utf8_str.size()
     << "\n"
     << std::string(delta_tab, '\t') << "String: " << utf8_str;
  return ss.str();
}
// ----------------------------------------------------------------------------

std::string CONSTANT_MethodHandle_info::getValue(
    const std::vector<cp_info> &constpool) const {
  std::stringstream ss;
  ss << "Constant_" << ConstantPool::getConstantTypename(this->tag) << "_info ";

  auto cpi = constpool[this->reference_index - 1];
  switch (cpi.base->tag) {
    case kCONSTANT_FIELDREF: {
      auto referece = cpi.getClass<CONSTANT_FieldRef_info>();
      ss << referece->getValue(constpool, true);
      break;
    }
    case kCONSTANT_METHODREF: {
      auto referece = cpi.getClass<CONSTANT_Methodref_info>();
      ss << referece->getValue(constpool, true);
      break;
    }
    case kCONSTANT_INTERFACEMETHODREF: {
      auto referece = cpi.getClass<CONSTANT_InterfaceMethodref_info>();
      ss << referece->getValue(constpool, true);
      break;
    }
  }

  return ss.str();
}

std::string CONSTANT_MethodHandle_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  std::stringstream ss;
  ss << std::string(delta_tab, '\t')
     << "Reference kind: " << Reference::getReferenceType(this->reference_kind)
     << "\n";

  ss << std::string(delta_tab, '\t') << "Reference index: "
     << "#" << this->reference_index << " <";

  auto cpi = constpool[this->reference_index - 1];
  switch (cpi.base->tag) {
    case kCONSTANT_FIELDREF: {
      auto referece = cpi.getClass<CONSTANT_FieldRef_info>();
      ss << referece->getValue(constpool, true);
      break;
    }
    case kCONSTANT_METHODREF: {
      auto referece = cpi.getClass<CONSTANT_Methodref_info>();
      ss << referece->getValue(constpool, true);
      break;
    }
    case kCONSTANT_INTERFACEMETHODREF: {
      auto referece = cpi.getClass<CONSTANT_InterfaceMethodref_info>();
      ss << referece->getValue(constpool, true);
      break;
    }
  }
  ss << ">";

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_MethodType_info::getValue(
    const std::vector<cp_info> &constpool) const {
  std::stringstream ss;
  auto type =
      constpool[this->descriptor_index - 1].getClass<CONSTANT_Utf8_info>();

  ss << type->getValue();

  return ss.str();
}

std::string CONSTANT_MethodType_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "Type: "
     << "#" << this->descriptor_index << " ";

  auto type =
      constpool[this->descriptor_index - 1].getClass<CONSTANT_Utf8_info>();

  ss << type->getValue();

  return ss.str();
}
// ----------------------------------------------------------------------------
std::string CONSTANT_InvokeDynamic_info::getValue(
    const std::vector<cp_info> &constpool) const {
  std::stringstream ss;
  auto name_and_type = constpool[this->name_and_type_index - 1]
                           .getClass<CONSTANT_NameAndType_info>();
  auto nt_str = name_and_type->getValue(constpool);
  ss << nt_str.substr(0, nt_str.find_first_of(':')) << ", BootstrapMethods #"
     << this->bootstrap_method_attr_index;

  return ss.str();
}

std::string CONSTANT_InvokeDynamic_info::getGeneralInfo(
    const std::vector<cp_info> &constpool, const int &delta_tab) {
  std::stringstream ss;
  ss << std::string(delta_tab, '\t') << "Name and type: "
     << "#" << this->name_and_type_index << " ";

  auto name_and_type = constpool[this->name_and_type_index - 1]
                           .getClass<CONSTANT_NameAndType_info>();
  ss << "<" << name_and_type->getValue(constpool) << ">\n"
     << std::string(delta_tab, '\t') << "Bootstrap method: "
     << "BootstrapMethods #" << this->bootstrap_method_attr_index << "";

  return ss.str();
}
}  // namespace ConstantPool
}  // namespace Utils
