#include "utils/memory_areas/thread.h"

#include "instructions/opcodes.h"
#include "instructions/printer.h"
#include "utils/attributes.h"
#include "utils/helper_functions.h"

namespace MemoryAreas {
void Thread::executeMethod(const std::string &method_name) {
  auto method = Utils::getMethod(this->current_class, method_name);
  auto code_attr =
      Utils::getAttribute(this->current_class, &method.attributes, "Code")
          .getClass<Utils::Attributes::Code_attribute>();
  auto code_array = code_attr->code;
  this->current_frame = new Utils::Frame(
      code_attr->max_stack, code_attr->max_locals, this->current_class);
  this->jvm_stack.push(this->current_frame);
  for (auto it = code_array.begin(); it != code_array.end(); ++it) {
    std::cout << Instructions::Opcodes::getMnemonic(*it) << "\n";
  }
}
}  // namespace MemoryAreas