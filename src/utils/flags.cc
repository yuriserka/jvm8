#include "utils/flags.h"

#include <string.h>
#include <iostream>
#include <map>

bool Utils::Flags::kVERBOSE;
bool Utils::Flags::kIGNORE;
std::string Utils::Flags::kFILE;

std::map<std::string, bool *> options = {{"-v", &Utils::Flags::kVERBOSE},
                                         {"-i", &Utils::Flags::kIGNORE}};

namespace Utils {
namespace Flags {
void toggleAll(const char **flags) {
  for (; *flags;) {
    if (!strcmp(*flags, "-f")) {
      kFILE = std::string(*++flags);
      flags++;
      continue;
    }
    toggle(*flags++);
  }
}

void toggle(const char *flag) { *options.at(flag) = !*options.at(flag); }
}  // namespace Flags
}  // namespace Utils
