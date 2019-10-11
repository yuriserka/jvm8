#include "utils/constantPool.h"

#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include "utils/errors.h"
#include "utils/memory.h"
#include "utils/reference_kind.h"
#include "utils/string.h"
#include "utils/utf8.h"

namespace Utils {
namespace ConstantPool {
std::map<Utils::Types::u1, std::string> names = {
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

std::string getConstantTypename(const Utils::Types::u1 &ct) {
  return names.at(ct);
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_Class_info::getValue(
    const std::vector<cp_info> *constpool) const {
  auto classname =
      constpool->at(this->name_index - 1).getClass<CONSTANT_Utf8_info>();
  return classname->getValue(constpool);
}

std::wstring CONSTANT_Class_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Class Name: 'cp_info #"
      << this->name_index << "' ";
  wss << "<" << this->getValue(constpool) << ">";
  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_FieldRef_info::getValue(const std::vector<cp_info> *constpool,
                                              const bool dot) const {
  auto classname =
      constpool->at(this->class_index - 1).getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool->at(this->name_and_type_index - 1)
                           .getClass<CONSTANT_NameAndType_info>();

  std::wstringstream wss;
  auto n_and_t_str = name_and_type->getValue(constpool);
  wss << classname->getValue(constpool) << (dot ? "." : "")
      << n_and_t_str.substr(0, n_and_t_str.find_last_of(':'));

  return wss.str();
}

std::wstring CONSTANT_FieldRef_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  auto classname =
      constpool->at(this->class_index - 1).getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool->at(this->name_and_type_index - 1)
                           .getClass<CONSTANT_NameAndType_info>();

  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Class name: 'cp_info #"
      << this->class_index << "' ";
  wss << "<" << classname->getValue(constpool) << ">";
  wss << "\n";
  wss << std::wstring(delta_tab, '\t') << "Name and type: 'cp_info #"
      << this->name_and_type_index << "' ";
  wss << "<" << name_and_type->getValue(constpool) << ">";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_Methodref_info::getValue(const std::vector<cp_info> *constpool,
                                               const bool dot) const {
  auto classname =
      constpool->at(this->class_index - 1).getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool->at(this->name_and_type_index - 1)
                           .getClass<CONSTANT_NameAndType_info>();

  std::wstringstream wss;
  auto n_and_t_str = name_and_type->getValue(constpool);
  wss << classname->getValue(constpool) << (dot ? "." : "")
      << n_and_t_str.substr(0, n_and_t_str.find_first_of(':'));

  return wss.str();
}

std::wstring CONSTANT_Methodref_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  auto classname =
      constpool->at(this->class_index - 1).getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool->at(this->name_and_type_index - 1)
                           .getClass<CONSTANT_NameAndType_info>();

  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Class name: 'cp_info #"
      << this->class_index << "' ";
  wss << "<" << classname->getValue(constpool) << ">";
  wss << "\n";
  wss << std::wstring(delta_tab, '\t') << "Name and type: 'cp_info #"
      << this->name_and_type_index << "' ";
  wss << "<" << name_and_type->getValue(constpool) << ">";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_InterfaceMethodref_info::getValue(
    const std::vector<cp_info> *constpool, const bool dot) const {
  auto classname =
      constpool->at(this->class_index - 1).getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool->at(this->name_and_type_index - 1)
                           .getClass<CONSTANT_NameAndType_info>();

  std::wstringstream wss;
  auto n_and_t_str = name_and_type->getValue(constpool);
  wss << classname->getValue(constpool) << (dot ? "." : "")
      << n_and_t_str.substr(0, n_and_t_str.find_last_of(':'));

  return wss.str();
}

std::wstring CONSTANT_InterfaceMethodref_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  auto classname =
      constpool->at(this->class_index - 1).getClass<CONSTANT_Class_info>();
  auto name_and_type = constpool->at(this->name_and_type_index - 1)
                           .getClass<CONSTANT_NameAndType_info>();

  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Class name: 'cp_info #"
      << this->class_index << "' ";
  wss << "<" << classname->getValue(constpool) << ">";
  wss << "\n";
  wss << std::wstring(delta_tab, '\t') << "Name and type: 'cp_info #"
      << this->name_and_type_index << "' ";
  wss << "<" << name_and_type->getValue(constpool) << ">";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_NameAndType_info::getValue(
    const std::vector<cp_info> *constpool) const {
  auto name =
      constpool->at(this->name_index - 1).getClass<CONSTANT_Utf8_info>();
  auto descriptor =
      constpool->at(this->descriptor_index - 1).getClass<CONSTANT_Utf8_info>();

  std::wstringstream wss;
  wss << name->getValue(constpool) << ":" << descriptor->getValue(constpool);

  return wss.str();
}

std::wstring CONSTANT_NameAndType_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  auto name =
      constpool->at(this->name_index - 1).getClass<CONSTANT_Utf8_info>();
  auto descriptor =
      constpool->at(this->descriptor_index - 1).getClass<CONSTANT_Utf8_info>();

  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Name: 'cp_info #" << this->name_index
      << "' ";
  wss << "<" << name->getValue(constpool) << ">";
  wss << "\n";
  wss << std::wstring(delta_tab, '\t') << "Descriptor: 'cp_info #"
      << this->descriptor_index << "' ";
  wss << "<" << descriptor->getValue(constpool) << ">";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_String_info::getValue(
    const std::vector<cp_info> *constpool) const {
  auto string =
      constpool->at(this->string_index - 1).getClass<CONSTANT_Utf8_info>();

  return string->getValue(constpool);
}

std::wstring CONSTANT_String_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "String: 'cp_info #"
      << this->string_index << "' <" << this->getValue(constpool) << ">";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_Integer_info::getValue(
    const std::vector<cp_info> *constpool) const {
  std::wstringstream wss;
  wss << this->bytes;

  return wss.str();
}

std::wstring CONSTANT_Integer_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Bytes: "
      << "0x" << std::setfill(L'0') << std::setw(8) << std::hex
      << std::uppercase << this->bytes << "\n";

  wss << std::wstring(delta_tab, '\t') << "Value: " << this->bytes << "\n";

  return wss.str();
}

// ----------------------------------------------------------------------------
std::wstring CONSTANT_Float_info::getValue(
    const std::vector<cp_info> *constpool) const {
  std::wstringstream wss;
  wss << copyCast<float>(&this->bytes);

  return wss.str();
}

std::wstring CONSTANT_Float_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Bytes: "
      << "0x" << std::setfill(L'0') << std::setw(8) << std::hex
      << std::uppercase << this->bytes << "\n";

  wss << std::wstring(delta_tab, '\t')
      << "Value: " << copyCast<float>(&this->bytes) << "\n";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_Long_info::getValue(
    const std::vector<cp_info> *constpool) const {
  std::wstringstream wss;
  auto u8val =
      (static_cast<Utils::Types::u8>(this->high_bytes) << 32 | this->low_bytes);
  wss << u8val;

  return wss.str();
}

std::wstring CONSTANT_Long_info::getGeneralInfo(const std::vector<cp_info> *constpool,
                                                const int delta_tab) {
  auto u8val =
      (static_cast<Utils::Types::u8>(this->high_bytes) << 32 | this->low_bytes);

  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "High Bytes: ";
  wss << "0x" << std::setfill(L'0') << std::setw(8) << std::hex
      << std::uppercase << this->high_bytes << "\n";

  wss << std::wstring(delta_tab, '\t') << "Low Bytes: ";
  wss << "0x" << std::setfill(L'0') << std::setw(8) << std::hex
      << std::uppercase << this->low_bytes << "\n";

  wss << std::wstring(delta_tab, '\t') << "Long: " << u8val << "\n";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_Double_info::getValue(
    const std::vector<cp_info> *constpool) const {
  auto u8val =
      (static_cast<Utils::Types::u8>(this->high_bytes) << 32 | this->low_bytes);

  std::wstringstream wss;
  wss << copyCast<double>(&u8val);

  return wss.str();
}

std::wstring CONSTANT_Double_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  auto u8val =
      (static_cast<Utils::Types::u8>(this->high_bytes) << 32 | this->low_bytes);

  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "High Bytes: ";
  wss << "0x" << std::setfill(L'0') << std::setw(8) << std::hex
      << std::uppercase << this->high_bytes << "\n";

  wss << std::wstring(delta_tab, '\t') << "Low Bytes: ";
  wss << "0x" << std::setfill(L'0') << std::setw(8) << std::hex
      << std::uppercase << this->low_bytes << "\n";

  wss << std::wstring(delta_tab, '\t') << "Double: " << copyCast<double>(&u8val)
      << "\n";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_Utf8_info::getValue(
    const std::vector<cp_info> *constpool) const {
  auto utf8_str = Utf8(this);
  return utf8_str.str;
}

std::wstring CONSTANT_Utf8_info::getGeneralInfo(const int delta_tab) {
  std::wstringstream wss;
  auto utf8_str = Utf8(this);
  wss << std::wstring(delta_tab, '\t')
      << "Length of byte array: " << this->length << "\n"
      << std::wstring(delta_tab, '\t')
      << "Length of string: " << utf8_str.str.size() << "\n"
      << std::wstring(delta_tab, '\t') << "String: " << utf8_str.str;
  return wss.str();
}
// ----------------------------------------------------------------------------

std::wstring CONSTANT_MethodHandle_info::getValue(
    const std::vector<cp_info> *constpool) const {
  std::wstringstream wss;
  wss << "Constant_"
      << String::to_wide(Utils::ConstantPool::getConstantTypename(this->tag))
      << "_info ";

  auto reference = constpool->at(this->reference_index - 1)
                       .getClass<CONSTANT_Methodref_info>();
  wss << reference->getValue(constpool, true);

  return wss.str();
}

std::wstring CONSTANT_MethodHandle_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Reference kind: "
      << String::to_wide(Reference::getReferenceType(this->reference_kind))
      << "\n";

  wss << std::wstring(delta_tab, '\t') << "Reference index: "
      << "'cp_info #" << this->reference_index << "' <";

  auto reference = constpool->at(this->reference_index - 1)
                       .getClass<CONSTANT_Methodref_info>();
  wss << reference->getValue(constpool, true) << ">";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_MethodType_info::getValue(
    const std::vector<cp_info> *constpool) const {
  std::wstringstream wss;
  auto type =
      constpool->at(this->descriptor_index - 1).getClass<CONSTANT_Utf8_info>();

  wss << type->getValue(constpool);

  return wss.str();
}

std::wstring CONSTANT_MethodType_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Type: "
      << "'cp_info #" << this->descriptor_index << "' ";

  auto type =
      constpool->at(this->descriptor_index - 1).getClass<CONSTANT_Utf8_info>();

  wss << type->getValue(constpool);

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring CONSTANT_InvokeDynamic_info::getValue(
    const std::vector<cp_info> *constpool) const {
  std::wstringstream wss;
  auto name_and_type = constpool->at(this->name_and_type_index - 1)
                           .getClass<CONSTANT_NameAndType_info>();
  auto nt_str = name_and_type->getValue(constpool);
  wss << nt_str.substr(0, nt_str.find_first_of(':')) << ", BootstrapMethods #"
      << this->bootstrap_method_attr_index;

  return wss.str();
}

std::wstring CONSTANT_InvokeDynamic_info::getGeneralInfo(
    const std::vector<cp_info> *constpool, const int delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Name and type: "
      << "'cp_info #" << this->name_and_type_index << "' ";

  auto name_and_type = constpool->at(this->name_and_type_index - 1)
                           .getClass<CONSTANT_NameAndType_info>();
  wss << "<" << name_and_type->getValue(constpool) << ">\n"
      << std::wstring(delta_tab, '\t') << "Bootstrap method: "
      << "'BootstrapMethods #" << this->bootstrap_method_attr_index << "'";

  return wss.str();
}
}  // namespace ConstantPool
}  // namespace Utils
