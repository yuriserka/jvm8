#ifndef INCLUDE_UTILS_FRAME_H_
#define INCLUDE_UTILS_FRAME_H_

#include <vector>
#include "classfile.h"
#include "utils/external/any.h"
#include "utils/types.h"

namespace Utils {
class Frame {
 public:
  Frame(const Types::u2 &stack_size, const Types::u2 &localvar_size,
        const ClassFile *cf)
      : local_variables(localvar_size), operand_stack(stack_size) {
    this->runtime_constant_pool = cf->constant_pool;
  }

  void run();

 private:
  std::vector<Any> local_variables;
  std::vector<Any> operand_stack;
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
