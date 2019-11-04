#include "utils/memory_areas/thread.h"

#include "instructions/execution_engine.h"
#include "utils/attributes.h"
#include "utils/errors.h"
#include "utils/helper_functions.h"
#include "utils/memory_areas/method_area.h"

#define MAX_STACK 40

namespace MemoryAreas {
// template <typename T>
void Thread::executeMethod(const std::string &method_name) {
  static int count = 0;
  static std::vector<std::string> metodos = {"BYTE", "GOTO", "FLOAT"};
  if (this->jvm_stack.size() > 2) return;

  if (this->jvm_stack.size() > MAX_STACK) {
    std::stringstream ss;
    ss << "Stack Overflow. This jvm supports only " << MAX_STACK
       << " methods calls at a time";

    throw Utils::Errors::Exception(Utils::Errors::kSTACK, ss.str());
  }

  auto method = this->method_area->getMethod(method_name);
  this->current_method = method_name;

  auto code_attr =
      Utils::getAttribute(this->current_class, &method.attributes, "Code")
          .getClass<Utils::Attributes::Code_attribute>();
  auto code_array = code_attr->code;

  this->jvm_stack.push(new Utils::Frame(
      code_attr->max_stack, code_attr->max_locals,
      this->method_area->runtime_constant_pool));
  this->current_frame = this->jvm_stack.top();

  // On instance method invocation, local variable 0 is always used to
  // pass a reference to the object on which the instance method is being invoked
  this->current_frame->pushLocalVar<int16_t>(this->current_class->this_class);
  
  for (auto it = code_array.begin(); it != code_array.end(); ++it) {
    // auto other_method = Instructions::runBytecode(&it, &this->current_frame->pc)
    //                     << "\n";
    if (!(++this->current_frame->pc % 6)) {
      // tem que executar com o arquivo instruções.class
      std::cout << method_name << ": " << this->current_frame->pc
                << " called " << metodos[count++ % 3] << "\n";
      this->executeMethod(metodos[(count-1) % 3]);
    }
    
    // if (other_method) {
    //   this->current_class = ?
    //   this->executeMethod()
    // }
  }

  this->jvm_stack.pop();

  // delete this->current_frame;
}
}  // namespace MemoryAreas