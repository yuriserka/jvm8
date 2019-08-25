#ifndef INCLUDE_ERRORS_H_
#define INCLUDE_ERRORS_H_

#include <string>

namespace Utils {
namespace Errors {
class Exception : public std::exception {
 public:
    Exception(const int &c, const std::string &m) : code(c), message(m) {}
    const char *what() const throw() {
        return this->message.c_str();
    }

 private:
    int code;
    std::string message;
};

enum {
    kCLASSFILE = 1,
    KMAGIC,
    kMINOR,
    kMAJOR,
    kCONSTANTPOOL
};
}  // namespace Errors
}  // namespace Utils

#endif  // INCLUDE_ERRORS_H_
