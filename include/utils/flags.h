#ifndef INCLUDE_UTILS_FLAGS_H_
#define INCLUDE_UTILS_FLAGS_H_

#include <string>

struct Options {
  bool kVERBOSE;
  bool kIGNORE;
  std::string kFILE;
};

namespace Utils {
namespace Flags {
void toggleAll(const char **flags);
void toggle(const char *flag);

extern Options options;

}  // namespace Flags
}  // namespace Utils

#endif  // INCLUDE_UTILS_FLAGS_H_
