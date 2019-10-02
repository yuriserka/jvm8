#include "utils/utf8.h"

#include <algorithm>
#include <codecvt>
#include <locale>
#include <string>

Utf8::Utf8(const Utils::Infos::CONSTANT_Utf8_info *kutf8Info) {
  std::vector<std::wstring> scapes = {L"\aa", L"\bb", L"\tt", L"\nn",
                                      L"\vv", L"\ff", L"\rr"};
  auto bytes = kutf8Info->bytes;
  Utils::Types::u2 byteRange[] = {0x0001, 0x0080, 0x8000, 0xFFFF};
  for (size_t i = 0; i < kutf8Info->length; ++i) {
    auto ubyte = +bytes[i];

    auto umByte = ubyte >= byteRange[0] && ubyte < byteRange[1];
    auto doisBytes = ubyte >= byteRange[1] && ubyte < byteRange[2];
    auto tresBytes = ubyte >= byteRange[0] && ubyte <= byteRange[3];

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
      auto b1 = (bytes[i] & 0x0F) << 12;
      auto b2 = (bytes[i + 1] & 0x3F) << 6;
      auto b3 = bytes[i + 2] & 0x3F;
      utf8c = static_cast<wchar_t>(b1 | b2 | b3);
      i += 2;
    } else if (ubyte > byteRange[3]) {
      auto b1 = (bytes[i] & 0x0F) << 16;
      auto b2 = (bytes[i + 1] & 0x3F) << 10;
      auto b3 = (bytes[i + 2] & 0x0F) << 6;
      auto b4 = bytes[i + 3] & 0x3F;
      utf8c = static_cast<wchar_t>(0x10000 | b1 | b2 | b3 | b4);
      i += 3;
    }
    this->str.push_back(utf8c);
  }
}
