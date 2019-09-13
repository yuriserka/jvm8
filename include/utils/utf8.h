#ifndef UT8_STR
#define UTF8_STR

#include <codecvt>
#include <string>
#include <iostream>
#include <locale>
#include "utils/infos.h"

class Utf8 {
 public:
    explicit Utf8(const Utils::Infos::CONSTANT_Utf8_info *kutf8Info) {
        std::vector<std::string> scapes= {"\aa", "\bb", "\tt", "\nn", "\vv", "\ff", "\rr"};
        auto bytes = kutf8Info->bytes;
        Utils::Types::u2 byteRange[] = {
            0x0001, 0x0080, 0x8000, 0xFFFF
        };
        for (size_t i = 0; i < unsigned(kutf8Info->length); ++i) {
            auto ubyte = unsigned(bytes[i]);

            auto umByte = ubyte >= byteRange[0] && ubyte < byteRange[1];
            auto doisBytes = ubyte >= byteRange[1] && ubyte < byteRange[2];
            auto tresBytes = ubyte >= byteRange[0] && ubyte <= byteRange[3];
            auto seisBytes = ubyte > byteRange[3];

            wchar_t utf8c;
            if (umByte) {
                char s[] = {static_cast<char>(bytes[i]), '\0'};
                auto ok = std::find(scapes.begin(), scapes.end(), std::string(s));
                if (ok != scapes.end()) {
                    std::wstring_convert<std::codecvt_utf8<wchar_t> > converter;
                    auto unicodeChar = converter.from_bytes(((*++ok).insert((*++ok).front(), "\\")));
                    this->str.append(unicodeChar);
                    // std::cout << "\\" << *++ok;
                    utf8c = *static_cast<const wchar_t*>(
                        std::wstring(ok->begin(), ok->end()).c_str()
                    );
                } else {
                    utf8c = static_cast<wchar_t>(bytes[i]);
                }
            } else if (doisBytes) {
                auto b1 = (bytes[i] & 0x1F) << 6;
                auto b2 = bytes[i+1] & 0x3F;
                utf8c = static_cast<wchar_t>(b1 | b2);
                ++i;
            } else if (tresBytes) {
                auto b1 = (bytes[i] & 0x0F) << 12;
                auto b2 = (bytes[i+1] & 0x3F) << 6;
                auto b3 = bytes[i+2] & 0x3F;
                utf8c = static_cast<wchar_t>(b1 | b2 | b3);
                i += 2;
            } else if (seisBytes) {
                auto b1 = (bytes[i] & 0x0F) << 16;
                auto b2 = (bytes[i+1] & 0x3F) << 10;
                auto b3 = (bytes[i+2] & 0x0F) << 6;
                auto b4 = bytes[i+3] & 0x3F;
                utf8c = static_cast<wchar_t>(0x10000 | b1 | b2 | b3 | b4);
                i += 3;
            }
            str.append(&utf8c);
        }
    }

    friend std::wostream &operator<<(std::wostream &out, const Utf8 &str) {
        for (size_t i = 0; i < str.str.size(); ++i) {
            out << *(str.str.c_str() + i);
        }
        out << "\n";

        return out;
    }

    const wchar_t *toString() const {
        return str.c_str();
    }

 private:
    std::wstring str;
};

#endif