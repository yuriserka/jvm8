#include "utils/flags.h"

#include <string.h>
#include <iostream>
#include <map>

Options Utils::Flags::options = Options();

namespace Utils {
namespace Flags {
std::map<std::string, bool *> optionsNames = {{"-v", &options.kVERBOSE},
                                              {"-i", &options.kIGNORE},
                                              {"-json", &options.kJSON}};

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
