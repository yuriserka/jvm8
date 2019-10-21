#include "utils/flags.h"

#include <string.h>
#include <iostream>
#include <map>
#include <sstream>
#include "utils/errors.h"

namespace Utils {
namespace Flags {
Options options = Options();

static void setMode(const char *mode) {
  std::map<std::string, bool *> modes = {
      {"viewer", &options.KMODE.kVIEWER},
      {"interpreter", &options.KMODE.kINTERPRETER}};
  bool *f = nullptr;
  try {
    f = modes.at(mode);
  } catch (const std::out_of_range &oor) {
    std::stringstream ss;
    ss << "usage: ./jvm {mode} <path_to_class_file> <class_file> [options]\n"
       << "\tmode: viewer, interpreter\n"
       << "\toptions: -v, -json";
    throw Errors::Exception(Errors::kMODE, ss.str());
  }
  *f = !*f;
}

void toggleAll(const char **flags) {
  setMode(*flags++);
  options.kPATH = std::string(*flags++);
  options.kFILE = std::string(*flags++);

  for (; *flags;) {
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
