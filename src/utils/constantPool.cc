#include "utils/constantPool.h"

#include <map>

namespace Utils {
namespace ConstantPool {
std::map<Utils::Types::u1, std::string> names = {
    {CONSTANT_Class, "Class"},
    {CONSTANT_Fieldref, "Fieldref"},
    {CONSTANT_Methodref, "Methodref"},
    {CONSTANT_InterfaceMethodref, "InterfaceMethodref"},
    {CONSTANT_String, "String"},
    {CONSTANT_Integer, "Integer"},
    {CONSTANT_Float, "Float"},
    {CONSTANT_Long, "Long"},
    {CONSTANT_Double, "Double"},
    {CONSTANT_NameAndType, "NameAndType"},
    {CONSTANT_Utf8, "Utf8"},
    {CONSTANT_MethodHandle, "MethodHandle"},
    {CONSTANT_MethodType, "MethodType"},
    {CONSTANT_InvokeDynamic, "InvokeDynamic"}};
std::string getConstantTypename(const Utils::Types::u1 &ct) {
  return names.at(ct);
}
}  // namespace ConstantPool
}  // namespace Utils
