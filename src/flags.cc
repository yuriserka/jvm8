#include "../include/flags.h"

#include <string.h>
#include <iostream>

bool Utils::Flags::kVERBOSE;
bool Utils::Flags::kIGNORE;
std::string Utils::Flags::kFILE;

std::map<std::string, bool *> options = {
    {"-v", &Utils::Flags::kVERBOSE},
    {"-i", &Utils::Flags::kIGNORE}};

void Utils::Flags::toggleAll(const char **flags) {
    for (; *flags;) {
        if (!strcmp(*flags, "-f")) {
            kFILE = std::string(*++flags);
            flags++;
            continue;
        }
        toggle(*flags++);
    }
}

void Utils::Flags::toggle(const char *flag) {
    *options.at(flag) = !*options.at(flag);
}
