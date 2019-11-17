#ifndef INCLUDE_UTILS_ERRORS_H_
#define INCLUDE_UTILS_ERRORS_H_

#include <stack>
#include <string>

namespace Utils {
namespace Errors {
class Exception : public std::exception {
 public:
  Exception(const int &c, const std::string &m) : code(c), message(m) {}

  const char *what() const noexcept override { return this->message.c_str(); }

  const int errorCode() const { return this->code; }

 private:
  int code;
  std::string message;
};

class JvmException : public std::exception {
 public:
  JvmException(const int &c, const std::string &m) : code(c), message(m) {}

  const char *what() const noexcept override { return this->message.c_str(); }

  const int errorCode() const { return this->code; }

  void printStrackTrace(std::stack<std::string> *call_stack);

 private:
  std::string getExceptionString();

  int code;
  std::string message;
};

enum errors {
  kCLASSFILE = 1,
  kMODE,
  KMAGIC,
  kMINOR,
  kMAJOR,
  kCONSTANTPOOL,
  kBYTE,
  kUTF8,
  kSOURCE,
  kMETHOD,
  kREFKIND,
  kFIELD,
  kATTRIBUTE,
  kINSTRUCTION,
  kMKDIR,
  kUTFDATAFORMATEXCEPTION,
  kSTACK,
  kNOTIMPLEMENTED,
  kLS,
  kMEMCPY,
  kVIEWER,
  kFLAG
};

enum vm_errors { kINTERNAL, kOUTOFMEMORY, kSTACKOVERFLOW, kUNKNOWN };

enum java_exceptions {
  kINDEXOUTOFBOUNDS,
  kNULLPOINTEREXCEPTION,
  kNEGATIVEARRAYSIZE,
  kARRAYSTORE,
  kCLASSCAST,
  kINCOMPATIBLECLASSCHANGE,
  kARITHMETIC,
  kILLEGALACCESS,

};
}  // namespace Errors
}  // namespace Utils

#endif  // INCLUDE_UTILS_ERRORS_H_
