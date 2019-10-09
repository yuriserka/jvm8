#include "utils/accessFlags.h"

#include <map>

namespace Utils {
namespace Access {
std::map<Utils::Types::u2, std::string> classAccessNames = {
    {ClassAccess::kACC_PUBLIC, "public"},
    {ClassAccess::kACC_FINAL, "final"},
    {ClassAccess::kACC_SUPER, "super"},
    {ClassAccess::kACC_INTERFACE, "interface"},
    {ClassAccess::kACC_ABSTRACT, "abstract"},
    {ClassAccess::kACC_SYNTHETIC, "synthetic"},
    {ClassAccess::kACC_ANNOTATION, "annotation"},
    {ClassAccess::kACC_ENUM, "enum"}};

std::map<Utils::Types::u2, std::string> fieldAccessNames = {
    {FieldAccess::kACC_PUBLIC, "public"},
    {FieldAccess::kACC_PRIVATE, "private"},
    {FieldAccess::kACC_PROTECTED, "protected"},
    {FieldAccess::kACC_STATIC, "static"},
    {FieldAccess::kACC_FINAL, "final"},
    {FieldAccess::kACC_VOLATILE, "volatile"},
    {FieldAccess::kACC_TRANSIENT, "transient"},
    {FieldAccess::kACC_SYNTHETIC, "synthetic"},
    {FieldAccess::kACC_ENUM, "enum"}};

std::map<Utils::Types::u2, std::string> methodAccessNames = {
    {MethodAccess::kACC_PUBLIC, "public"},
    {MethodAccess::kACC_PRIVATE, "private"},
    {MethodAccess::kACC_PROTECTED, "protected"},
    {MethodAccess::kACC_STATIC, "static"},
    {MethodAccess::kACC_FINAL, "final"},
    {MethodAccess::kACC_SYNCHRONIZED, "syncronized"},
    {MethodAccess::kACC_BRIDGE, "bridge"},
    {MethodAccess::kACC_VARARGS, "varargs"},
    {MethodAccess::kACC_NATIVE, "native"},
    {MethodAccess::kACC_ABSTRACT, "abstract"},
    {MethodAccess::kACC_STRICT, "strict"},
    {MethodAccess::kACC_SYNTHETIC, "synthetic"}};

std::map<Utils::Types::u2, std::string> nestedAccessNames = {
    {NestedClassAccess::kACC_PUBLIC, "public"},
    {NestedClassAccess::kACC_PRIVATE, "private"},
    {NestedClassAccess::kACC_PROTECTED, "protected"},
    {NestedClassAccess::kACC_STATIC, "static"},
    {NestedClassAccess::kACC_FINAL, "final"},
    {NestedClassAccess::kACC_INTERFACE, "interface"},
    {NestedClassAccess::kACC_ABSTRACT, "abstract"},
    {NestedClassAccess::kACC_SYNTHETIC, "synthetic"},
    {NestedClassAccess::kACC_ANNOTATION, "annotation"},
    {NestedClassAccess::kACC_ENUM, "enum"}};

std::map<Utils::Types::u2, std::string> methodparamsNames = {
    {MethodParamsAccess::kACC_FINAL, "final"},
    {MethodParamsAccess::kACC_SYNTHETIC, "synthetic"},
    {MethodParamsAccess::kACC_MANDATED, "mandated"}};

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

std::vector<std::string> getNestedClassAccessType(
    const Utils::Types::u2 &accessType) {
  std::vector<Utils::Types::u2> keys;
  for (auto it = nestedAccessNames.begin(); it != nestedAccessNames.end();
       ++it) {
    keys.push_back(it->first);
  }
  std::vector<std::string> flagsname;
  for (auto accessFlag : keys) {
    try {
      auto s = nestedAccessNames.at(accessType & accessFlag);
      flagsname.push_back(s);
    } catch (const std::exception &e) {
      continue;
    }
  }
  return flagsname;
}

std::vector<std::string> getMethodParamsAccessType(
    const Utils::Types::u2 &accessType) {
  std::vector<Utils::Types::u2> keys;
  for (auto it = methodparamsNames.begin(); it != methodparamsNames.end();
       ++it) {
    keys.push_back(it->first);
  }
  std::vector<std::string> flagsname;
  for (auto accessFlag : keys) {
    try {
      auto s = methodparamsNames.at(accessType & accessFlag);
      flagsname.push_back(s);
    } catch (const std::exception &e) {
      continue;
    }
  }
  return flagsname;
}
}  // namespace Access
}  // namespace Utils
