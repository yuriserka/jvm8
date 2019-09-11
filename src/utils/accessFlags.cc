#include "utils/accessFlags.h"

#include <map>

std::map<Utils::Types::u2, std::string> classAccessNames = {
    {Utils::Access::ClassAccess::ACC_PUBLIC, "public"},
    {Utils::Access::ClassAccess::ACC_FINAL, "final"},
    {Utils::Access::ClassAccess::ACC_SUPER, "super"},
    {Utils::Access::ClassAccess::ACC_INTERFACE, "interface"},
    {Utils::Access::ClassAccess::ACC_ABSTRACT, "abstract"},
    {Utils::Access::ClassAccess::ACC_SYNTHETIC, "synthetic"},
    {Utils::Access::ClassAccess::ACC_ANNOTATION, "annotation"},
    {Utils::Access::ClassAccess::ACC_ENUM, "enum"}
};

std::map<Utils::Types::u2, std::string> fieldAccessNames = {
    {Utils::Access::FieldAccess::ACC_PUBLIC, "public"},
    {Utils::Access::FieldAccess::ACC_PRIVATE, "private"},
    {Utils::Access::FieldAccess::ACC_PROTECTED, "protected"},
    {Utils::Access::FieldAccess::ACC_STATIC, "static"},
    {Utils::Access::FieldAccess::ACC_FINAL, "final"},
    {Utils::Access::FieldAccess::ACC_VOLATILE, "volatile"},
    {Utils::Access::FieldAccess::ACC_TRANSIENT, "transient"},
    {Utils::Access::FieldAccess::ACC_SYNTHETIC, "synthetic"},
    {Utils::Access::FieldAccess::ACC_ENUM, "enum"}
};

std::map<Utils::Types::u2, std::string> methodAccessNames = {
    {Utils::Access::MethodAccess::ACC_PUBLIC, "public"},
    {Utils::Access::MethodAccess::ACC_PRIVATE, "private"},
    {Utils::Access::MethodAccess::ACC_PROTECTED, "protected"},
    {Utils::Access::MethodAccess::ACC_STATIC, "static"},
    {Utils::Access::MethodAccess::ACC_FINAL, "final"},
    {Utils::Access::MethodAccess::ACC_SYNCHRONIZED, "syncronized"},
    {Utils::Access::MethodAccess::ACC_BRIDGE, "bridge"},
    {Utils::Access::MethodAccess::ACC_VARARGS, "varargs"},
    {Utils::Access::MethodAccess::ACC_NATIVE, "native"},
    {Utils::Access::MethodAccess::ACC_ABSTRACT, "abstract"},
    {Utils::Access::MethodAccess::ACC_STRICT, "strict"},
    {Utils::Access::MethodAccess::ACC_SYNTHETIC, "synthetic"}
};

namespace Utils {
namespace Access {
std::vector<std::string> getClassAccessType(const Utils::Types::u2 &accessType) {
    std::vector<Utils::Types::u2> keys;
    for(auto it = classAccessNames.begin(); it != classAccessNames.end(); ++it) {
        keys.push_back(it->first);
    }
    std::vector<std::string> flagsname;
    for (auto accessFlag : keys) {
        try {
            auto s = classAccessNames.at(accessType & accessFlag);
            flagsname.push_back(s);
        } catch(const std::exception &e) {
            continue;
        }
    }
    return flagsname;    
}

std::vector<std::string> getFieldAccessType(const Utils::Types::u2 &accessType) {
    std::vector<Utils::Types::u2> keys;
    for(auto it = fieldAccessNames.begin(); it != fieldAccessNames.end(); ++it) {
        keys.push_back(it->first);
    }
    std::vector<std::string> flagsname;
    for (auto accessFlag : keys) {
        try {
            auto s = fieldAccessNames.at(accessType & accessFlag);
            flagsname.push_back(s);
        } catch(const std::exception &e) {
            continue;
        }
    }
    return flagsname;    
}

std::vector<std::string> getMethodAccessType(const Utils::Types::u2 &accessType) {
    std::vector<Utils::Types::u2> keys;
    for(auto it = methodAccessNames.begin(); it != methodAccessNames.end(); ++it) {
        keys.push_back(it->first);
    }
    std::vector<std::string> flagsname;
    for (auto accessFlag : keys) {
        try {
            auto s = methodAccessNames.at(accessType & accessFlag);
            flagsname.push_back(s);
        } catch(const std::exception &e) {
            continue;
        }
    }
    return flagsname;    
}
}  // namespace Access
}  // namespace Utils