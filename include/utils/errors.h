#ifndef INCLUDE_UTILS_ERRORS_H_
#define INCLUDE_UTILS_ERRORS_H_

#include <string>

namespace Utils {
namespace Errors {
class Exception : public std::exception {
 public:
  Exception(const int &c, const std::string &m) : code(c), message(m) {}

  const char *what() const noexcept { return this->message.c_str(); }

  const int errorCode() const { return this->code; }

 private:
  int code;
  std::string message;
};

enum errorTypes {
  kMEMCPY = -1,
  kCLASSFILE = 1,
  KMAGIC,
  kMINOR,
  kMAJOR,
  kCONSTANTPOOL,
  kBYTE,
  kUTF8,
  kREFKIND,
  kFIELD,
  kATTRIBUTE
};
}  // namespace Errors
}  // namespace Utils

#endif  // INCLUDE_UTILS_ERRORS_H_
