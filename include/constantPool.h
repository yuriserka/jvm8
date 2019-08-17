#pragma once

#include "types.h"
#include <vector>

struct ConstantPool {
    Utils::Types::u1 tag;
    std::vector<Utils::Types::u1> info;
};