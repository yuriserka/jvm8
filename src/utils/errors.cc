#include "utils/errors.h"

#include <iostream>
#include <sstream>

namespace Utils {
namespace Errors {
std::string JvmException::getExceptionString() {
  std::stringstream ss;
  switch (this->code) {
    case kNULLPOINTEREXCEPTION:
      ss << "java.lang.NullPointerException";
      break;
    case kINDEXOUTOFBOUNDS:
      ss << "java.lang.IndexOutOfBoundsException";
      break;
    case kNEGATIVEARRAYSIZE:
      ss << "java.lang.NegativeArraySizeException";
      break;
    case kARRAYSTORE:
      ss << "java.lang.ArrayStoreException";
      break;
    case kCLASSCAST:
      ss << "java.lang.ClassCastException";
      break;
    case kINCOMPATIBLECLASSCHANGE:
      ss << "java.lang.IncompatibleClassChangeError";
      break;
    case kARITHMETIC:
      ss << "java.lang.ArithmeticException";
      break;
    case kILLEGALACCESS:
      ss << "java.lang.IllegalAccessError";
      break;
  }
  return ss.str();
}

void JvmException::printStrackTrace(std::stack<std::string> *call_stack) {
  while (!call_stack->empty()) {
    auto m = call_stack->top();
    std::cout << this->getExceptionString() << "\n\tat " << m;
    call_stack->pop();
  }
}
}  // namespace Errors
}  // namespace Utils