#include "utils/accessFlags.h"

#include <map>

std::map<Utils::Types::u2, std::string> classAccessNames = {
    {Utils::Access::ACC_PUBLIC, "public"},
    {Utils::Access::ACC_FINAL, "final"},
    {Utils::Access::ACC_SUPER, "super"},
    {Utils::Access::ACC_INTERFACE, "interface"},
    {Utils::Access::ACC_ABSTRACT, "abstract"},
    {Utils::Access::ACC_SYNTHETIC, "synthetic"},
    {Utils::Access::ACC_ANNOTATION, "annotation"},
    {Utils::Access::ACC_ENUM, "enum"}
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
}  // namespace Access
}  // namespace Utils