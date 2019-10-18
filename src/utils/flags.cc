#include "utils/flags.h"

#include <string.h>
#include <iostream>
#include <map>
#include "utils/errors.h"

namespace Utils {
namespace Flags {
Options options = Options();

void toggleAll(const char **flags) {
  for (; *flags;) {
    if (!strcmp(*flags, "-f")) {
      options.kFILE = std::string(*++flags);
      flags++;
      continue;
    }
    if (!strcmp(*flags, "-p")) {
      options.kPATH = std::string(*++flags);
      flags++;
      continue;
    }
    toggle(*flags++);
  }
}

void toggle(const char *flag) {
  std::map<std::string, bool *> optionsNames = {{"-v", &options.kVERBOSE},
                                                {"-i", &options.kIGNORE},
                                                {"-json", &options.kJSON}};
  bool *f = nullptr;
  try {
    f = optionsNames.at(flag);
  } catch (const std::out_of_range &oor) {
    throw Errors::Exception(Errors::kFLAG,
                            "invalid flag: " + std::string(flag));
  }
  *f = !*f;
}
}  // namespace Flags
}  // namespace Utils
