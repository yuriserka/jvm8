#pragma once

#include <cstdint>

namespace Utils {

namespace Types {

typedef std::uint8_t u1;
typedef std::uint16_t u2;
typedef std::uint32_t u4;
typedef std::uint64_t u8;
typedef std::int32_t integer;
typedef std::uint8_t byte;
typedef std::uint8_t boolean;
typedef std::uint8_t character;
} // namespace Types

enum Constants {
    CONSTANT_Class = 7,
    CONSTANT_Fieldref = 9,
    CONSTANT_Methodref = 10,
    CONSTANT_InterfaceMethodref = 11,
    CONSTANT_String = 8,
    CONSTANT_Integer = 3,
    CONSTANT_Float = 4,
    CONSTANT_Long = 5,
    CONSTANT_Double = 6,
    CONSTANT_NameAndType = 12,
    CONSTANT_Utf8 = 1
};
} // namespace Utils