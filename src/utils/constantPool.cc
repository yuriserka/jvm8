#include "utils/constantPool.h"

#include <map>

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
}  // namespace ConstantPool
}  // namespace Utils
