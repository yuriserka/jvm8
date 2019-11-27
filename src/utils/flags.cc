#include "utils/flags.h"

#include <string.h>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include "utils/errors.h"

namespace Utils {
namespace Flags {
Options options = Options();

static std::string getUsage() {
  std::stringstream ss;
  ss << "usage: ./jvm {mode} <path_to_class_file> <class_file> [options]\n"
     << "\tmode: viewer, interpreter\n"
     << "\toptions: -v, -json, -d";

  return ss.str();
}

static void setMode(const char *mode) {
  static std::map<std::string, bool *> modes = {
      {"viewer", &options.KMODE.kVIEWER},
      {"interpreter", &options.KMODE.kINTERPRETER}};
  bool *f = nullptr;
  try {
    f = modes.at(mode);
  } catch (const std::out_of_range &oor) {
    throw Errors::Exception(Errors::kMODE, getUsage());
  }
  *f = !*f;
}

void toggleAll(const char **flags) {
  setMode(*flags++);

  std::stringstream ss;
  try {
    options.kPATH = std::string(*flags++);
  } catch (const std::exception &e) {
    ss << "missing <PATH> argument\n" << getUsage();
    throw Errors::Exception(Errors::kMODE, ss.str());
  }

  try {
    options.kFILE = std::string(*flags++);
  } catch (const std::exception &e) {
    ss << "missing <FILE> argument\n" << getUsage();
    throw Errors::Exception(Errors::kMODE, ss.str());
  }

#if defined(_WIN32) || defined(WIN32)
  options.kPATH = std::regex_replace(options.kPATH, std::regex("\\\\"), "/");
  options.kFILE = std::regex_replace(options.kFILE, std::regex("\\\\"), "/");
#endif

  for (; *flags;) {
    toggle(*flags++);
  }
}

void toggle(const char *flag) {
  static std::map<std::string, bool *> optionsNames = {
      {"-v", &options.kVERBOSE}, {"-verbose", &options.kVERBOSE},
      {"-i", &options.kIGNORE},  {"-ignore", &options.kIGNORE},
      {"-d", &options.kDEBUG},   {"-debug", &options.kDEBUG},
      {"-json", &options.kJSON}};
  bool *f = nullptr;
  try {
    f = optionsNames.at(flag);
  } catch (const std::out_of_range &oor) {
    throw Errors::Exception(Errors::kFLAG,
                            "invalid option: " + std::string(flag));
  }
  *f = !*f;
}
}  // namespace Flags
}  // namespace Utils
