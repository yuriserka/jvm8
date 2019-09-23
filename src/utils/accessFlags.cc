#include "utils/accessFlags.h"

#include <map>

namespace Utils {
namespace Access {
std::map<Utils::Types::u2, std::string> classAccessNames = {
    {ClassAccess::ACC_PUBLIC, "public"},
    {ClassAccess::ACC_FINAL, "final"},
    {ClassAccess::ACC_SUPER, "super"},
    {ClassAccess::ACC_INTERFACE, "interface"},
    {ClassAccess::ACC_ABSTRACT, "abstract"},
    {ClassAccess::ACC_SYNTHETIC, "synthetic"},
    {ClassAccess::ACC_ANNOTATION, "annotation"},
    {ClassAccess::ACC_ENUM, "enum"}};

std::map<Utils::Types::u2, std::string> fieldAccessNames = {
    {FieldAccess::ACC_PUBLIC, "public"},
    {FieldAccess::ACC_PRIVATE, "private"},
    {FieldAccess::ACC_PROTECTED, "protected"},
    {FieldAccess::ACC_STATIC, "static"},
    {FieldAccess::ACC_FINAL, "final"},
    {FieldAccess::ACC_VOLATILE, "volatile"},
    {FieldAccess::ACC_TRANSIENT, "transient"},
    {FieldAccess::ACC_SYNTHETIC, "synthetic"},
    {FieldAccess::ACC_ENUM, "enum"}};

std::map<Utils::Types::u2, std::string> methodAccessNames = {
    {MethodAccess::ACC_PUBLIC, "public"},
    {MethodAccess::ACC_PRIVATE, "private"},
    {MethodAccess::ACC_PROTECTED, "protected"},
    {MethodAccess::ACC_STATIC, "static"},
    {MethodAccess::ACC_FINAL, "final"},
    {MethodAccess::ACC_SYNCHRONIZED, "syncronized"},
    {MethodAccess::ACC_BRIDGE, "bridge"},
    {MethodAccess::ACC_VARARGS, "varargs"},
    {MethodAccess::ACC_NATIVE, "native"},
    {MethodAccess::ACC_ABSTRACT, "abstract"},
    {MethodAccess::ACC_STRICT, "strict"},
    {MethodAccess::ACC_SYNTHETIC, "synthetic"}};

std::vector<std::string> getClassAccessType(
    const Utils::Types::u2 &accessType) {
  std::vector<Utils::Types::u2> keys;
  for (auto it = classAccessNames.begin(); it != classAccessNames.end(); ++it) {
    keys.push_back(it->first);
  }
  std::vector<std::string> flagsname;
  for (auto accessFlag : keys) {
    try {
      auto s = classAccessNames.at(accessType & accessFlag);
      flagsname.push_back(s);
    } catch (const std::exception &e) {
      continue;
    }
  }
  return flagsname;
}

std::vector<std::string> getFieldAccessType(
    const Utils::Types::u2 &accessType) {
  std::vector<Utils::Types::u2> keys;
  for (auto it = fieldAccessNames.begin(); it != fieldAccessNames.end(); ++it) {
    keys.push_back(it->first);
  }
  std::vector<std::string> flagsname;
  for (auto accessFlag : keys) {
    try {
      auto s = fieldAccessNames.at(accessType & accessFlag);
      flagsname.push_back(s);
    } catch (const std::exception &e) {
      continue;
    }
  }
  return flagsname;
}

std::vector<std::string> getMethodAccessType(
    const Utils::Types::u2 &accessType) {
  std::vector<Utils::Types::u2> keys;
  for (auto it = methodAccessNames.begin(); it != methodAccessNames.end();
       ++it) {
    keys.push_back(it->first);
  }
  std::vector<std::string> flagsname;
  for (auto accessFlag : keys) {
    try {
      auto s = methodAccessNames.at(accessType & accessFlag);
      flagsname.push_back(s);
    } catch (const std::exception &e) {
      continue;
    }
  }
  return flagsname;
}
}  // namespace Access
}  // namespace Utils
