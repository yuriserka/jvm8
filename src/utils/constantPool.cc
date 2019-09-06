#include "utils/constantPool.h"

#include <map>

std::map<Utils::Types::u1, std::string> names = {
    {Utils::ConstantPool::CONSTANT_Class, "Class"},
    {Utils::ConstantPool::CONSTANT_Fieldref, "Fieldref"},
    {Utils::ConstantPool::CONSTANT_Methodref, "Methodref"},
    {Utils::ConstantPool::CONSTANT_InterfaceMethodref, "InterfaceMethodref"},
    {Utils::ConstantPool::CONSTANT_String, "String"},
    {Utils::ConstantPool::CONSTANT_Integer, "Integer"},
    {Utils::ConstantPool::CONSTANT_Float, "Float"},
    {Utils::ConstantPool::CONSTANT_Long, "Long"},
    {Utils::ConstantPool::CONSTANT_Double, "Double"},
    {Utils::ConstantPool::CONSTANT_NameAndType, "NameAndType"},
    {Utils::ConstantPool::CONSTANT_Utf8, "Utf8"},
    {Utils::ConstantPool::CONSTANT_MethodHandle, "MethodHandle"},
    {Utils::ConstantPool::CONSTANT_MethodType, "MethodType"},
    {Utils::ConstantPool::CONSTANT_InvokeDynamic, "InvokeDynamic"}
};

namespace Utils {
namespace ConstantPool {
std::string getConstantTypename(const Utils::Types::u1 &ct) {
    return names.at(ct);
}
}  // namespace ConstantPool
}  // namespace Utils
