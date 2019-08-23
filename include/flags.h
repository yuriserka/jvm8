#ifndef INCLUDE_FLAGS_H_
#define INCLUDE_FLAGS_H_

#include <string>
#include <map>
#include <vector>

namespace Utils {
namespace Flags {

void toggleAll(const char **flags);
void toggle(const char *flag);

extern bool kVERBOSE;
extern bool kIGNORE;
extern std::string kFILE;

}  // namespace Flags
}  // namespace Utils

#endif  // INCLUDE_FLAGS_H_
