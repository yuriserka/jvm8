#include "viewer.h"

#include <iostream>
#include <algorithm>
#include <map>
#include "utils/constantPool.h"
#include "utils/versions.h"

static std::ios state(NULL);

void Viewer::printClassFile() {
    std::cout << "Visualizing ClassFile structure for "
              << this->classname << "\n";
    this->printMagic();
    this->printVersion();
    this->printConstantPool();
}

void Viewer::printMagic() {
    state.copyfmt(std::cout);
    std::cout << "Magic: '" << "0x" << std::hex << std::uppercase
              << this->classfile->magic << "'\n";
    std::cout.copyfmt(state);
}

void Viewer::printVersion() {
    std::cout << "Version: '"
              << Utils::Versions::getVersion(this->classfile->major_version)
              << ", " << this->classfile->major_version << "."
              << this->classfile->minor_version << "'\n";
}

void Viewer::printConstantPool() {
    std::cout << "Constant Pool Count: "
              << this->classfile->constant_pool_count << "\n";
    std::cout << "Constant Pool:\n";
    for (auto i = 0; i < this->classfile->constant_pool_count-1; ++i) {
        this->printConstantPoolInfo(i, 2, false);
    }
}

void Viewer::printConstantPoolInfo(int index, int depth, bool inner) {
    auto constpool = this->classfile->constant_pool[index];
    if (!inner) {
        std::cout << "\tTAG '" << index + 1 << "': ";
        auto name = Utils::ConstantPool::getConstantTypename(constpool.base->tag);
        std::cout << "(" << unsigned(constpool.base->tag) << ", " << name << ")\n";
    }
    switch (constpool.base->tag) {
        namespace cp = Utils::ConstantPool;
        namespace info = Utils::Infos;
    case cp::CONSTANT_Class: {
        auto kclassinfo = constpool.getClass<info::CONSTANT_Class_info>();
        std::cout << std::string(depth, '\t') << "Name Index: " << kclassinfo->name_index << "\n";
        this->printConstantPoolInfo(kclassinfo->name_index - 1, depth + 1, true);
        break;
    }
    case cp::CONSTANT_Utf8: {
        auto kclassinfo = constpool.getClass<info::CONSTANT_Utf8_info>();
        if (!inner) {
            std::cout << std::string(depth, '\t') << "Length: " << kclassinfo->length << "\n";
            std::cout << std::string(depth, '\t') << "Bytes: ";
        }
        std::cout << (inner ? std::string(depth, '\t') : "") << "\"";
        std::vector<std::string> scapes= {"\aa", "\bb", "\tt", "\nn", "\vv", "\ff", "\rr"};
        auto bytes = kclassinfo->bytes;
        /*
         * @brief representa o array de ranges para mapear a quantidade de bytes
         * 
         * String content is encoded in modified UTF-8. Modified UTF-8 strings
         * are encoded so that code point sequences that contain only non-null
         * ASCII characters can be represented using only 1 byte per code point,
         * but all code points in the Unicode codespace can be represented.
         * Modified UTF-8 strings are not null-terminated.
         * 
         * The encoding is as follows:
         * 
         * - range 0x0001 to 0x007F are represented by a single byte.
         * - range 0x0080 to 0x07FF are represented by a pair of bytes x and y
         * - range 0x0800 to 0xFFFF are represented by 3 bytes x, y, and z
         * - higher than 0xFFFF are represented by 6 bytes, u, v, w, x, y, and z;
         */ 
        const std::map<int, const unsigned> byteRange = {
            {1, 0x0001},
            {2, 0x0080},
            {3, 0x8000},
            {4, 0xFFFF}
        };
        for (size_t i = 0; i < unsigned(kclassinfo->length); ++i) {
            auto ubyte = unsigned(bytes[i]);

            auto umByte = ubyte >= byteRange.at(1) && ubyte < byteRange.at(2);
            auto doisBytes = ubyte >= byteRange.at(2) && ubyte < byteRange.at(3);
            auto tresBytes = ubyte >= byteRange.at(1) && ubyte <= byteRange.at(4);
            auto seisBytes = ubyte > byteRange.at(4);

            wchar_t utf8c;
            if (umByte) {
                char s[] = {static_cast<char>(bytes[i]), '\0'};
                auto ok = std::find(scapes.begin(), scapes.end(), std::string(s));
                if (ok != scapes.end()) {
                    std::cout << "\\" << *++ok;
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
            } else {
                state.copyfmt(std::cout);
                std::cout << "0x" << std::hex << std::uppercase << ubyte;
                std::cout.copyfmt(state);
            }
            std::wcout << utf8c;
        }
        std::cout << "\"\n";
        break;
    }
    default:
        break;
    }
}