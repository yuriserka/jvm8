#ifndef ERRORS_H
#define ERRORS_H

#include <string>

namespace Utils {
    namespace Errors {
        
        class Exception : public std::exception {
          public:
            Exception(int c, std::string m) {
                this->code = c;
                this->message = m;
            }
            const char *what() const throw () {
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
            kMAJOR
        };
    }
}

#endif