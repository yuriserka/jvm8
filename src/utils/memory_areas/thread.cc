#include "utils/memory_areas/thread.h"

#include "instructions/execution_engine.h"
#include "instructions/opcodes.h"
#include "reader.h"
#include "utils/attributes.h"
#include "utils/errors.h"
#include "utils/flags.h"
#include "utils/helper_functions.h"
#include "utils/memory_areas/method_area.h"
#include "utils/string.h"

#define MAX_STACK 40

namespace MemoryAreas {
// template <typename T>
void Thread::executeMethod(const std::string &method_name) {
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

  this->current_frame =
      new Utils::Frame(code_attr->max_stack, code_attr->max_locals,
                       this->method_area->runtime_constant_pool);
  this->jvm_stack.push(this->current_frame);

  // On instance method invocation, local variable 0 is always used to
  // pass a reference to the object on which the instance method is being
  // invoked
  this->current_frame->pushLocalVar(
      this->current_class->constant_pool[this->current_class->this_class - 1]
          .getClass<Utils::ConstantPool::CONSTANT_Class_info>());

  for (auto it = code_array.begin(); it != code_array.end(); ++it) {
    // Apenas para teste para ver se a troca de contexto em nível de função
    // funciona, ainda não passa argumentos e nem variaveis locais. invoke
    // [virtual | especial]
    if (*it == 0xb6 || *it == 0xb7) {
      std::cout << this->current_method << ": "
                << Instructions::Opcodes::getMnemonic(*it);
      uint16_t cp_arg = (((*++it) << 8) | *++it) - 1;
      std::cout << " -> args: cp[" << cp_arg << "]\n";

      // Generalizar para qualquer tipo de referencia...
      // std::string ref_class_name, ref_method_name;
      // switch (this->current_class->constant_pool[cp_arg].base->tag) {
      //   namespace cp = Utils::ConstantPool;
      //   case cp::kCONSTANT_FIELDREF: {
      //     Utils::getReference<cp::CONSTANT_FieldRef_info>(
      //         this->current_class, cp_arg, &ref_class_name,
      //         &ref_method_name);
      //     break;
      //   }
      //   case cp::kCONSTANT_METHODREF: {
      //     Utils::getReference<cp::CONSTANT_Methodref_info>(
      //         this->current_class, cp_arg, &ref_class_name,
      //         &ref_method_name);
      //     break;
      //   }
      //   case cp::kCONSTANT_INTERFACEMETHODREF: {
      //     Utils::getReference<cp::CONSTANT_InterfaceMethodref_info>(
      //         this->current_class, cp_arg, &ref_class_name,
      //         &ref_method_name);
      //     break;
      //   }
      // }

      auto methodref =
          this->method_area->runtime_constant_pool[cp_arg]
              .getClass<Utils::ConstantPool::CONSTANT_Methodref_info>();

      auto methodref_class_info =
          this->method_area->runtime_constant_pool[methodref->class_index - 1]
              .getClass<Utils::ConstantPool::CONSTANT_Class_info>();
      auto ref_class_name =
          this->method_area
              ->runtime_constant_pool[methodref_class_info->name_index - 1]
              .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
              ->getValue();

      auto methodref_nametype_info =
          this->method_area
              ->runtime_constant_pool[methodref->name_and_type_index - 1]
              .getClass<Utils::ConstantPool::CONSTANT_NameAndType_info>();
      auto ref_method_name =
          this->method_area
              ->runtime_constant_pool[methodref_nametype_info->name_index - 1]
              .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
              ->getValue();

      this->changeContext(ref_class_name, ref_method_name);
    }
  }

  this->jvm_stack.pop();
}

void Thread::changeContext(const std::string &classname,
                           const std::string &method_name) {
  std::cout << "\tchanging context to " << classname << "." << method_name
            << "\n";
  auto const classinfo =
      this->method_area
          ->runtime_constant_pool[this->current_class->this_class - 1]
          .getClass<Utils::ConstantPool::CONSTANT_Class_info>();

  auto const actual_classname =
      this->current_class->constant_pool[classinfo->name_index - 1]
          .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
          ->getValue();

  auto old_class = this->current_class;
  if (classname.compare(actual_classname)) {
    std::stringstream ss;
    ClassFile *new_class = new ClassFile();
    char delimiter = '/';
#if defined(_WIN32) || defined(WIN32)
    delimiter = '\\';
#endif
    auto splitted_path = Utils::String::split(classname, delimiter);
    if (splitted_path.empty()) {
      ss << Utils::Flags::options.kPATH << delimiter << classname << ".class";
    } else {
      ss << "." << delimiter << "classes" << delimiter << classname << ".class";
    }
    Reader(new_class, ss.str()).readClassFile();
    this->current_class = new_class;
  }

  auto old_method = this->current_method;
  auto old_frame = this->current_frame;

  if (this->current_class != old_class) {
    this->method_area->update(this->current_class);
  }

  this->executeMethod(method_name);

  if (this->current_class != old_class) {
    delete this->current_class;
  }

  this->current_class = old_class;
  this->current_frame = old_frame;
  this->current_method = old_method;

  this->method_area->update(this->current_class);
}
}  // namespace MemoryAreas
