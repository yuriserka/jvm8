#ifndef FLAGS_H
#define FLAGS_H

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
    }
}

#endif