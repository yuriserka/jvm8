#ifndef INCLUDE_UTILS_FLAGS_H_
#define INCLUDE_UTILS_FLAGS_H_

#include <string>

struct Options {
  bool kVERBOSE;
  bool kDEBUG;
  bool kIGNORE;
  bool kJSON;
  struct {
    bool kVIEWER;
    bool kINTERPRETER;
  } KMODE;
  std::string kFILE;
  std::string kPATH;
  std::string kJVM_ARGS;
};

namespace Utils {
namespace Flags {
void toggleAll(const char **flags);
void toggle(const char *flag);

extern Options options;

}  // namespace Flags
}  // namespace Utils

#endif  // INCLUDE_UTILS_FLAGS_H_
