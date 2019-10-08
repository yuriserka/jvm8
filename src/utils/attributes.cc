#include "utils/attributes.h"

#include <map>

namespace Utils {
namespace Attributes {
int getAttributeType(const std::wstring &attrname) {
  std::map<std::wstring, int> attrTypes = {
      {L"ConstantValue", kCONSTANTVALUE},
      {L"Code", kCODE},
      {L"Exceptions", kEXCEPTIONS},
      {L"InnerClasses", kINNERCLASS},
      {L"EnclosingMethod", kENCLOSINGMETHOD},
      {L"Synthetic", kSYNTHETIC},
      {L"Signature", kSIGNATURE},
      {L"SourceFile", kSOURCEFILE},
      {L"LineNumberTable", kLINENUMBERTABLE},
      {L"LocalVariableTable", kLOCALVARIABLETABLE},
      {L"Deprecated", kDEPRECATED},
      {L"BootstrapMethods", kBOOTSTRAPMETHODS},
      {L"MethodParameters", kMETHODPARAMETERS}};
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
