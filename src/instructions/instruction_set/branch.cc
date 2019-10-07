#include "instructions/instruction_set/branch.h"

namespace Instructions {
namespace Branch {
void RefCompareEqual::toBytecode(
    std::vector<Utils::Types::u1>::iterator *code_it, const int &code_pos,
    int *delta_code, const bool &wide) {
  auto offset = (*++*code_it << 8) | *++*code_it;
  std::cout << Opcodes::getMnemonic(this->opcode) << " "
            << static_cast<int>(char(offset + offset)) << " (" << std::showpos
            << static_cast<int>(char(offset)) << ")\n";
  *delta_code = 2;
}

std::vector<std::string> RefCompareEqual::toBytecode_json(
    std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code, int *ret,
    const bool &wide) {
  auto offset = (*++*code_it << 8) | *++*code_it;
  *delta_code = 2;
  return {Utils::String::to_string(static_cast<int>(char(offset)))};
}

}  // namespace Branch
}  // namespace Instructions