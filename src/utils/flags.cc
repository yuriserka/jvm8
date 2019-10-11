#include "utils/flags.h"

#include <string.h>
#include <iostream>
#include <map>
#include "utils/errors.h"

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
  bool *f = nullptr;
  try {
    f = optionsNames.at(flag);
  } catch (const std::exception &e) {
    throw Errors::Exception(Errors::kFLAG,
                            "invalid flag: " + std::string(flag));
  }
  *f = !*f;
}
}  // namespace Flags
}  // namespace Utils
