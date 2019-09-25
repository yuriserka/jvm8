#include "utils/attributes.h"

#include <map>

namespace Utils {
namespace Attributes {
int getAttributeType(const std::wstring &attrname) {
  std::map<std::wstring, int> attrTypes = {
      {L"Code", kCODE},
      {L"ConstantValue", kCONSTANTVALUE},
      {L"Deprecated", kDEPRECATED},
      {L"Exceptions", kEXCEPTIONS},
      {L"LineNumberTable", kLINENUMBERTABLE},
      {L"LocalVariableTable", kLOCALVARIABLETABLE},
      {L"SourceFile", kSOURCEFILE}};
  try {
    auto type = attrTypes.at(attrname);
    return type;
  } catch (const std::exception &e) {
    //   std::stringstream err;
    // err << "Invalid Attribute";
    // throw Utils::Errors::Exception(Utils::Errors::kATTRIBUTE, err.str());
    return Utils::Attributes::kINVALID;
  }
}
}  // namespace Attributes
}  // namespace Utils