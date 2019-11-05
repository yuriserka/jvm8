#ifndef INCLUDE_UTILS_FRAME_H_
#define INCLUDE_UTILS_FRAME_H_

#include <stack>
#include <vector>
#include "utils/constantPool.h"
#include "utils/errors.h"
#include "utils/external/any.h"
#include "utils/types.h"

namespace Utils {
class Frame {
 public:
  Frame(const Types::u2 &stack_size, const Types::u2 &localvar_size,
        const std::vector<ConstantPool::cp_info> &kpool) {
    this->max_operand_stack_size = stack_size;
    this->max_localvar_size = localvar_size;
    this->runtime_constant_pool = kpool;
    this->pc = 0;
  }

  template <typename T>
  void pushLocalVar(const T &localvar) {
    if (this->local_variables.size() > this->max_localvar_size) {
      throw Utils::Errors::Exception(Utils::Errors::kSTACK,
                                     "Loval Variable Overflow");
    }
    this->local_variables.emplace_back(localvar);
  }

  template <typename T>
  T &getLocalVar(const int &index) {
    return this->local_variables[index].as<T>();
  }

  template <typename T>
  void pushOperand(const T &operand) {
    if (this->operand_stack.size() > this->max_operand_stack_size) {
      throw Utils::Errors::Exception(Utils::Errors::kSTACK,
                                     "Stack Frame Overflow");
    }
    this->operand_stack.push(operand);
  }

  template <typename T>
  T &popOperand() {
    auto any = this->operand_stack.top();
    this->operand_stack.pop();

    return any.as<T>();
  }

  int pc;

 private:
  std::vector<Any> local_variables;
  std::stack<Any> operand_stack;
  uint16_t max_operand_stack_size;
  uint16_t max_localvar_size;
  std::vector<ConstantPool::cp_info> runtime_constant_pool;
};
}  // namespace Utils

// std::vector<Any> local_variables = {Any(115), Any("Hello mundo cruel"),
//                                     Any(651151613.144456), Any(3.14159f)};

// std::cout << local_variables[0].as<int>() << "\n";
// std::cout << local_variables[1].as<const char *>() << "\n";
// std::cout << local_variables[2].as<double>() << "\n";
// std::cout << local_variables[3].as<float>() << "\n";

#endif  // INCLUDE_UTILS_FRAME_H_
