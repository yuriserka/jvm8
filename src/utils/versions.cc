#include <map>
#include "utils/versions.h"

std::map<Utils::Types::u2, std::string> vs = {
    {0x3A, "Java SE 14"},
    {0x39, "Java SE 13"},
    {0x38, "Java SE 12"},
    {0x37, "Java SE 11"},
    {0x36, "Java SE 10"},
    {0x35, "Java SE 9"},
    {0x34, "Java SE 8"},
    {0x33, "Java SE 7"},
    {0x32, "Java SE 6.0"},
    {0x31, "Java SE 5.0"},
    {0x30, "JDK 1.4"},
    {0x2F, "JDK 1.3"},
    {0x2E, "JDK 1.2"},
    {0x2D, "JDK 1.1"}
};

namespace Utils {
namespace Versions {
std::string getVersion(const Utils::Types::u2 &major) {
    return vs.at(major);
}
}  // namespace Versions
}  // namespace Utils
