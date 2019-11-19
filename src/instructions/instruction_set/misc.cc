#include "instructions/instruction_set/misc.h"

#include <memory>
#include "utils/array_t.h"
#include "utils/flags.h"
#include "utils/memory_areas/heap.h"
#include "utils/memory_areas/method_area.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
namespace Misc {
std::vector<int> Checkcast::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Dup::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto top = th->current_frame->popOperand<Any>();
  th->current_frame->pushOperand(top);
  th->current_frame->pushOperand(top);
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> DupX1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  // remove first two top operands
  auto top_first = th->current_frame->popOperand<Any>();
  auto top_second = th->current_frame->popOperand<Any>();

  // push duplicate object two positions down
  th->current_frame->pushOperand(top_first);

  // push former top operands back in order
  th->current_frame->pushOperand(top_second);
  th->current_frame->pushOperand(top_first);

  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> DupX2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  // NOTE(Claudio): Essa instrucao duplica o top e o insere dois OU tres
  // valores abaixo no operand stack. Como determinar qual das duas opcoes
  // usar?

  // Form 1:
  {
    // NOTE(Claudio): todos os tres valores sao cat1

    // remove first three top operands
    auto top_first = th->current_frame->popOperand<Any>();
    auto top_second = th->current_frame->popOperand<Any>();
    auto top_third = th->current_frame->popOperand<Any>();

    // push duplicate object three positions down
    th->current_frame->pushOperand(top_first);

    // push former top operands back in order
    th->current_frame->pushOperand(top_third);
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
  }

  // Form 2:
  {
    // NOTE(Claudio): top_first é cat1, top_second cat2

    // remove first two top operands
    auto top_first = th->current_frame->popOperand<Any>();
    auto top_second = th->current_frame->popOperand<Any>();

    // push duplicate object two positions down
    th->current_frame->pushOperand(top_first);

    // push former top operands back in order
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
  }

  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Dup2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  // NOTE(Claudio): Essa instrucao duplica o primeiro top ou o primeiro e
  // segundo top. Como determinar qual das duas opcoes usar?

  // Form 1:
  {
    auto top_first = th->current_frame->popOperand<Any>();

    th->current_frame->pushOperand(top_first);
    th->current_frame->pushOperand(top_first);
  }

  // Form 2:
  {
    auto top_first = th->current_frame->popOperand<Any>();
    auto top_second = th->current_frame->popOperand<Any>();

    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
  }

  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Dup2X1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  // NOTE(Claudio): Essa instrucao duplica o top ou os dois primeiros tops
  // e o(s) insere(m) dois OU tres valores abaixo no operand stack.
  // Como determinar qual das duas opcoes usar?

  // Form 1:
  {
    // NOTE(Claudio): nesse caso os tres valores sao de categoria 1

    // remove first three top operands
    auto top_first = th->current_frame->popOperand<Any>();
    auto top_second = th->current_frame->popOperand<Any>();
    auto top_third = th->current_frame->popOperand<Any>();

    // push duplicate object three positions down
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);

    // push former top operands back in order
    th->current_frame->pushOperand(top_third);
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
  }

  // Form 2:
  {
    // NOTE(Claudio): nesse caso top_first é cat2, e top_second é cat1

    // remove first two top operands
    auto top_first = th->current_frame->popOperand<Any>();
    auto top_second = th->current_frame->popOperand<Any>();

    // push duplicate object two positions down
    th->current_frame->pushOperand(top_first);

    // push former top operands back in order
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
  }

  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Dup2X2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  // NOTE(Claudio): Essa instrucao duplica o top ou os dois primeiros tops
  // e o(s) insere(m) dois, tres ou quatro valores abaixo no operand stack.
  // Como determinar qual das tres opcoes usar?

  // Form 1:
  {
    // NOTE(Claudio): nesse caso os quatro valores sao de categoria 1

    // remove first four top operands
    auto top_first = th->current_frame->popOperand<Any>();
    auto top_second = th->current_frame->popOperand<Any>();
    auto top_third = th->current_frame->popOperand<Any>();
    auto top_fourth = th->current_frame->popOperand<Any>();

    // push duplicate object three positions down
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);

    // push former top operands back in order
    th->current_frame->pushOperand(top_fourth);
    th->current_frame->pushOperand(top_third);
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
  }

  // Form 2:
  {
    // NOTE(Claudio): nesse caso top_first é cat2, e top_second e top_third
    // sao cat1

    // remove first three top operands
    auto top_first = th->current_frame->popOperand<Any>();
    auto top_second = th->current_frame->popOperand<Any>();
    auto top_third = th->current_frame->popOperand<Any>();

    // push duplicate object two positions down
    th->current_frame->pushOperand(top_first);

    // push former top operands back in order
    th->current_frame->pushOperand(top_third);
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
  }

  // Form 3:
  {
    // NOTE(Claudio): nesse caso top_first e top_second sao cat1, e top_third
    // é cat2

    // remove first three top operands
    auto top_first = th->current_frame->popOperand<Any>();
    auto top_second = th->current_frame->popOperand<Any>();
    auto top_third = th->current_frame->popOperand<Any>();

    // push duplicate object two positions down
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);

    // push former top operands back in order
    th->current_frame->pushOperand(top_third);
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
  }

  // Form 4:
  {
    // NOTE(Claudio): nesse caso top_first e top_second sao cat2

    // remove first two top operands
    auto top_first = th->current_frame->popOperand<Any>();
    auto top_second = th->current_frame->popOperand<Any>();

    // push duplicate object two positions down
    th->current_frame->pushOperand(top_first);

    // push former top operands back in order
    th->current_frame->pushOperand(top_second);
    th->current_frame->pushOperand(top_first);
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> GetField::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> GetStatic::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  auto index = (*++*code_iterator << 8) | *++*code_iterator;

  std::string classname, methodname, reftype;
  Utils::getReference(th->method_area->runtime_classfile, index, &classname,
                      &methodname, &reftype);
  *delta_code = 2;

  // se classname.methodname != java/lang/System.out ai carrega a classe, tem
  // que inicializar e os krl ainda
  if ((classname + "." + methodname)
          .compare(std::string("java/lang/System.out"))) {
    if (Utils::Flags::options.kDEBUG) {
      std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    }
    th->method_area->loadClass(classname);
  } else if (Utils::Flags::options.kDEBUG) {
    std::cout << "Ignorando " << Opcodes::getMnemonic(this->opcode) << " "
              << (classname + "." + methodname) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Goto::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  th->current_frame->pc += (offset - *delta_code - 1);
  *code_iterator += (offset - *delta_code - 1);
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> GotoWide::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto offset = (*++*code_iterator << 24) | (*++*code_iterator << 16) |
                (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 4;
  th->current_frame->pc += (offset - *delta_code - 1);
  *code_iterator += (offset - *delta_code - 1);
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> InstanceOf::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  // auto kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
  // *delta_code = 2;

  auto objectref = th->current_frame->popOperand<Utils::Object *>();
  if (objectref->data.is_null()) {
    th->current_frame->pushOperand(1);
  }

  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> LookupSwitch::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> MultiDimArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> New::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
  auto kpool_info = th->method_area->runtime_constant_pool[kpool_index - 1];

  auto classname =
      kpool_info.getClass<Utils::ConstantPool::CONSTANT_Class_info>()->getValue(
          th->method_area->runtime_constant_pool);

  // classname != java/lang/StringBuilder e != java/lang/String
  if (classname.compare("java/lang/StringBuilder") &&
      classname.compare("java/lang/String")) {
    th->method_area->loadClass(classname);
  }

  auto objectref = new Utils::Object();
  th->current_frame->pushOperand(th->heap->pushReference(objectref));
  *delta_code = 2;
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> NewArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  unsigned char atype = *++*code_iterator;
  auto count = th->current_frame->popOperand<int>();

  if (!count) {
    throw Utils::Errors::JvmException(Utils::Errors::kNEGATIVEARRAYSIZE,
                                      "NegativeArraySizeException");
  }

  auto arr = new Utils::Array_t(count, atype);
  auto objectref = new Utils::Object(arr, Utils::Reference::kREF_ARRAY);
  th->current_frame->pushOperand(th->heap->pushReference(objectref));

  *delta_code = 1;
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Nop::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Pop::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Pop2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> PutField::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> PutStatic::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Ret::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Return::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->cleanOperands();
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Swap::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> TableSwitch::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Wide::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Misc
}  // namespace Instructions
