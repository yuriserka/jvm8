#include "utils/memory_areas/thread.h"

#include <algorithm>
#include "instructions/execution_engine.h"
#include "instructions/opcodes.h"
#include "reader.h"
#include "utils/attributes.h"
#include "utils/errors.h"
#include "utils/flags.h"
#include "utils/helper_functions.h"
#include "utils/memory_areas/heap.h"
#include "utils/memory_areas/method_area.h"
#include "utils/string.h"

#define MAX_STACK 40

namespace MemoryAreas {
void Thread::executeMethod(const std::string &method_name,
                           const std::string &descriptor,
                           const bool &popObjectRef) {
  if (this->jvm_stack.size() > MAX_STACK) {
    std::stringstream ss;
    ss << "Stack Overflow. This jvm supports only " << MAX_STACK
       << " methods calls at a time";

    throw Utils::Errors::Exception(Utils::Errors::kSTACK, ss.str());
  }

  auto method = this->method_area->getMethod(method_name, descriptor);
  this->current_method = method_name;

  Utils::Attributes::Code_attribute *code_attr;

  try {
    code_attr =
        Utils::getAttribute(this->current_class, &method.attributes, "Code")
            .getClass<Utils::Attributes::Code_attribute>();
  } catch (const Utils::Errors::Exception &e) {
    std::cout << e.what() << "\n";
    return;
  }
  auto code_array = code_attr->code;

  if (Utils::Flags::options.kDEBUG) {
    std::cout << "\tExecuting method " << method_name << "\n";
  }

  auto newf = new Utils::Frame(code_attr->max_stack, code_attr->max_locals,
                               this->method_area->runtime_constant_pool);
  // se ja tem um current frame, significa que teve troca de contexto
  if (this->current_frame) {
    this->storeArguments(descriptor.substr(descriptor.find_first_of('(') + 1,
                                           descriptor.find_last_of(')') - 1),
                         newf, popObjectRef);
  } else {
    auto args = Utils::String::split(Utils::Flags::options.kJVM_ARGS, ' ');
    auto main_args =
        new Utils::Array_t(args.size(), Utils::Reference::kREF_STRING);
    auto this_obj =
        new Utils::Object(main_args, Utils::getClassName(this->current_class));
    for (size_t i = 0; i < args.size(); ++i) {
      main_args->insert(new Utils::Object(args[i], "java/lang/String"), i);
    }
    newf->pushLocalVar(this->heap->pushReference(this_obj), 0);
  }
  this->current_frame = newf;
  this->jvm_stack.push(this->current_frame);

  for (auto it = code_array.begin(); it != code_array.end(); ++it) {
    if (Utils::Flags::options.kDEBUG) {
      std::cout << this->current_frame->pc << ": ";
    }
    // tirei o try pra ficar mais fácil de debugar... mas ainda acho que vai
    // precisar dps
    try {
      auto finish_method =
          Instructions::runBytecode(&it, this, &this->current_frame->pc);
      if (finish_method) {
        break;
      }
    } catch (Utils::Object *obj) {
      if (Utils::Flags::options.kDEBUG) {
        std::cout << "Exception throwed by " << obj->class_name << "\n";
      }
      // acho que aqui seria onde teria o tratamento das excecoes da jvm????

      auto attributes = this->current_class->attributes;
      auto exception_table = code_attr->exception_table;

      auto jumpto = 0;
      for (auto it = exception_table.begin(); it != exception_table.end();
           ++it) {
        try {
          auto exceptions = Utils::getAttribute(
              this->current_class, &code_attr->attributes, "Exceptions");
        } catch (const Utils::Errors::Exception &e) {
        }
        auto elem_class_name =
            this->current_class->constant_pool[it->catch_type - 1]
                .getClass<Utils::ConstantPool::CONSTANT_Class_info>()
                ->getValue(this->method_area->runtime_constant_pool);
        if (elem_class_name == obj->class_name) {
          jumpto = it->handler_pc;
          goto handle;
        }
      }
      this->pushReturnValue(obj);
      this->current_frame->cleanOperands();
      throw obj;
handle:
      it += (jumpto - this->current_frame->pc - 1);
        this->current_frame->cleanOperands();
        this->current_frame->pushOperand(obj);
    }
  }

  this->jvm_stack.pop();
  delete newf;
}  // namespace MemoryAreas

void Thread::changeContext(const std::string &classname,
                           const std::string &method_name,
                           const std::string &descriptor,
                           const bool &popObjectRef) {
  auto const actual_classname = Utils::getClassName(this->current_class);
  auto old_class = this->current_class;
  if (classname.compare(actual_classname)) {
    if (Utils::Flags::options.kDEBUG) {
      std::cout << "\tchanging context to " << classname << "." << method_name
                << ":" << descriptor << "\n";
    }
    auto new_class = this->method_area->loadClass(classname);
    this->current_class = new_class;
    this->method_area->update(this->current_class);
  }
  auto old_method = this->current_method;
  auto old_frame = this->current_frame;

  this->executeMethod(method_name, descriptor, popObjectRef);

  this->current_class = old_class;
  this->current_frame = old_frame;
  this->current_method = old_method;

  if (Utils::Flags::options.kDEBUG) {
    std::cout << "\treturning context to " << actual_classname << "."
              << this->current_method << "\n";
  }
  this->method_area->update(this->current_class);
}

void Thread::storeArguments(const std::string &args, Utils::Frame *new_frame,
                            const bool &popObjectRef) {
  auto qtd_arguments_passados =
      [&popObjectRef](const std::string &args) -> int {
    std::string args_copy = args;
    int qtd_args = 0;
    for (auto it = args_copy.begin(); it != args_copy.end(); it++, ++qtd_args) {
      switch (*it) {
        case 'D':
        case 'J':
          ++qtd_args;
          break;
        case 'L':
          while (*it != ';') {
            ++it;
          }
          break;
        case '[':
          ++it;
          if (*it == 'L') {
            while (*it != ';') {
              ++it;
            }
          }
          break;
      }
    }
    return qtd_args;
  }(args);

  // isso faz com que qnd eu precisar popar o objectref a posição 0 fique vazia
  auto start_index =
      popObjectRef ? qtd_arguments_passados : qtd_arguments_passados - 1;

  // o ultimo argumento da nova função ta no topo da pilha, entao a gente
  // precisa inverter pra pegar os valores corretos
  for (auto it = args.rbegin(); it != args.rend(); ++it, --start_index) {
    // On instance method invocation, local variable 0 is always used to
    // pass a reference to the object on which the instance method is being
    // invoked
    // ainda nao sei se isso ta 100% certo, mas deu certo nos meus pequenos
    // testes
    switch (*it) {
      case 'D': {
        if ((it + 1) != args.rend() && *(it + 1) == '[') {
          ++it;
          new_frame->pushLocalVar(
              this->current_frame->popOperand<Utils::Object *>(), start_index);
        } else {
          new_frame->pushLocalVar(this->current_frame->popOperand<double>(),
                                  start_index-- - 1);
        }
        break;
      }
      case 'F': {
        if ((it + 1) != args.rend() && *(it + 1) == '[') {
          ++it;
          new_frame->pushLocalVar(
              this->current_frame->popOperand<Utils::Object *>(), start_index);
        } else {
          new_frame->pushLocalVar(this->current_frame->popOperand<float>(),
                                  start_index);
        }
        break;
      }
      case 'J': {
        if ((it + 1) != args.rend() && *(it + 1) == '[') {
          ++it;
          new_frame->pushLocalVar(
              this->current_frame->popOperand<Utils::Object *>(), start_index);
        } else {
          new_frame->pushLocalVar(this->current_frame->popOperand<long>(),
                                  start_index-- - 1);
        }
        break;
      }
      case 'B':
      case 'C':
      case 'I':
      case 'S':
      case 'Z':
        if ((it + 1) != args.rend() && *(it + 1) == '[') {
          ++it;
          new_frame->pushLocalVar(
              this->current_frame->popOperand<Utils::Object *>(), start_index);
        } else {
          new_frame->pushLocalVar(this->current_frame->popOperand<int>(),
                                  start_index);
        }
        break;
      case ';': {
        new_frame->pushLocalVar(
            this->current_frame->popOperand<Utils::Object *>(), start_index);
        while (*it != 'L') {
          ++it;
        }
        if ((it + 1) != args.rend() && *(it + 1) == '[') {
          ++it;
        }
        break;
      }
    }
  };
  if (popObjectRef) {
    auto objectref = this->current_frame->popOperand<Utils::Object *>();
    // if (!objectref->class_name.empty() && objectref->class_name.compare(
    //         Utils::getClassName(this->current_class))) {
    //   throw std::invalid_argument(
    //       "nao é aqui q tem que executar esse metodo, tem outra classe que "
    //       "implementa");
    // }
    new_frame->pushLocalVar(objectref, start_index);
  }
}
}  // namespace MemoryAreas