#include "utils/string.h"

#include "utils/constantPool.h"
#include "utils/errors.h"

namespace Utils {
namespace String {
std::string getUtf8Modified(
    const ConstantPool::CONSTANT_Utf8_info *kutf8Info) {
  int c, char2, char3;
  int count = 0;
  int chararr_count = 0;

  uint16_t utflen = kutf8Info->length;
  auto chararr = new char[utflen];
  auto bytes = kutf8Info->bytes;

  while (count < utflen) {
    c = (int)bytes[count] & 0xff;
    if (c > 127) break;
    count++;
    chararr[chararr_count++] = (char)c;
  }

  while (count < utflen) {
    c = (int)bytes[count] & 0xff;

    switch (c >> 4) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
        /* 0xxxxxxx*/
        count++;
        chararr[chararr_count++] = (char)c;
        break;
      case 12:
      case 13:
        /* 110x xxxx   10xx xxxx*/
        count += 2;
        if (count > utflen) {
          throw Utils::Errors::Exception(
              Utils::Errors::kUTFDATAFORMATEXCEPTION,
              "malformed input: partial character at end");
        }
        char2 = (int)bytes[count - 1];
        if ((char2 & 0xC0) != 0x80) {
          throw Utils::Errors::Exception(
              Utils::Errors::kUTFDATAFORMATEXCEPTION,
              "malformed input around byte " + count);
        }
        chararr[chararr_count++] = (char)(((c & 0x1F) << 6) | (char2 & 0x3F));
        break;
      case 14:
        /* 1110 xxxx  10xx xxxx  10xx xxxx */
        count += 3;
        if (count > utflen) {
          throw Utils::Errors::Exception(
              Utils::Errors::kUTFDATAFORMATEXCEPTION,
              "malformed input: partial character at end");
        }
        char2 = (int)bytes[count - 2];
        char3 = (int)bytes[count - 1];
        if (((char2 & 0xC0) != 0x80) || ((char3 & 0xC0) != 0x80)) {
          throw Utils::Errors::Exception(
              Utils::Errors::kUTFDATAFORMATEXCEPTION,
              "malformed input around byte " + (count - 1));
        }
        chararr[chararr_count++] =
            (char)(((c & 0x0F) << 12) | ((char2 & 0x3F) << 6) | (char3 & 0x3F));
        break;
      default:
        /* 10xx xxxx,  1111 xxxx */
        throw Utils::Errors::Exception(Utils::Errors::kUTFDATAFORMATEXCEPTION,
                                       "malformed input around byte " + count);
    }
  }

  return std::string(chararr, chararr_count);
}
}  // namespace String
}  // namespace Utils
