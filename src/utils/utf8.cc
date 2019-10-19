#include "utils/utf8.h"

#include <algorithm>
#include <codecvt>
#include <locale>
#include <string>
#include "utils/errors.h"

Utf8::Utf8(const Utils::ConstantPool::CONSTANT_Utf8_info *kutf8Info) {
  std::vector<std::wstring> scapes = {L"\aa", L"\bb", L"\tt", L"\nn",
                                      L"\vv", L"\ff", L"\rr"};
  auto bytes = kutf8Info->bytes;
  for (size_t i = 0; i < kutf8Info->length; ++i) {
    auto umByte = (bytes[i] & 0x80) == 0;
    auto doisBytes = (bytes[i] & 0xE0) == 0xC0 && (bytes[i + 1] & 0xC0) == 0x80;
    auto tresBytes = (bytes[i] & 0xF0) == 0xE0 &&
                     (bytes[i + 1] & 0xC0) == 0x80 &&
                     (bytes[i + 2] & 0xC0) == 0x80;
    auto sixBytes = (bytes[i] == 0xED) && (bytes[i + 1] & 0xF0) == 0xA0 &&
                    (bytes[i + 2] & 0xC0) == 0x80 && (bytes[i + 3] == 0xED) &&
                    (bytes[i + 4] & 0xF0) == 0xB0 &&
                    (bytes[i + 5] & 0xC0) == 0x80;

    wchar_t utf8c = L'\0';
    if (umByte) {
      std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
      auto s = converter.from_bytes(bytes[i]);
      auto ok = std::find(scapes.begin(), scapes.end(), s);
      if (ok != scapes.end()) {
        auto unicodeScape = L"\\" + (*++ok);
        this->str.append(unicodeScape);
        utf8c = *static_cast<const wchar_t *>(
            std::wstring(ok->begin(), ok->end()).c_str());
      } else {
        utf8c = static_cast<wchar_t>(bytes[i]);
      }
    } else if (doisBytes) {
      auto b1 = (bytes[i] & 0x1F) << 6;
      auto b2 = bytes[i + 1] & 0x3F;
      utf8c = static_cast<wchar_t>(b1 | b2);
      ++i;
    } else if (tresBytes) {
      auto b1 = (bytes[i] & 0xF) << 12;
      auto b2 = (bytes[i + 1] & 0x3F) << 6;
      auto b3 = bytes[i + 2] & 0x3F;
      utf8c = static_cast<wchar_t>(b1 | b2 | b3);
      i += 2;
    } else if (sixBytes) {
      auto b1 = (bytes[i + 1] & 0x0F) << 16;
      auto b2 = (bytes[i + 2] & 0x3F) << 10;
      auto b3 = (bytes[i + 4] & 0x0F) << 6;
      auto b4 = bytes[i + 5] & 0x3F;
      utf8c = static_cast<wchar_t>(0x10000 | b1 | b2 | b3 | b4);
      i += 5;
    } else {
      std::wcout << "deu erro aaaaaaaaaaaa => utf8 char = "
                 << std::hex << static_cast<int>(utf8c) << "\n";
    }
    this->str.push_back(utf8c);
  }
}
