#include "utils/flags.h"

#include <string.h>
#include <iostream>
#include <map>

Options Utils::Flags::options = Options();

std::map<std::string, bool *> optionsNames = {
    {"-v", &Utils::Flags::options.kVERBOSE},
    {"-i", &Utils::Flags::options.kIGNORE},
    {"-json", &Utils::Flags::options.kJSON}};

namespace Utils {
namespace Flags {
void toggleAll(const char **flags) {
  for (; *flags;) {
    if (!strcmp(*flags, "-f")) {
      options.kFILE = std::string(*++flags);
      flags++;
      continue;
    }
    toggle(*flags++);
  }
}

void toggle(const char *flag) {
  *optionsNames.at(flag) = !*optionsNames.at(flag);
}
}  // namespace Flags
}  // namespace Utils
