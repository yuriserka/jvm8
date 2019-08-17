#pragma once

#include "./types.h"
#include <fstream>
#include <string>
#include <sstream>

struct ClassFile {
    ClassFile(std::string fpath) {
        this->file = std::fstream(fpath, std::ios::in);
    }
    std::fstream file;
    Utils::Types::u4 magic;
    Utils::Types::u2 minor_version;
    Utils::Types::u2 major_version;
    Utils::Types::u2 constant_pool_count;
    // ::::cp_info constant_pool[constant_pool_count - 1];
    // ::::u2 access_flags;
    // ::::u2 this_class;
    // ::::u2 super_class;
    // ::::u2 interfaces_count;
    // ::::u2 interfaces[interfaces_count];
    // ::::u2 fields_count;
    // ::::field_info fields[fields_count];
    // ::::u2 methods_count;
    // ::::method_info methods[methods_count];
    // ::::u2 attributes_count;
    // ::::attribute_info attributes[attributes_count];

    template <typename T>
    T readNBytes(int n) {
        std::stringstream ss;
        for (auto i = 0; i < n; ++i) {
            auto b = this->file.get();
            ss << std::hex << b;
        }
        T Nbytes;
        ss >> std::hex >> Nbytes;
        return Nbytes;
    }
};