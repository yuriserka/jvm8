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
  auto val = th->current_frame->popOperand<Any>();

  th->current_frame->pushOperand(val);
  th->current_frame->pushOperand(val);
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> DupX1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val1 = th->current_frame->popOperand<Any>();
  auto val2 = th->current_frame->popOperand<Any>();

  th->current_frame->pushOperand(val1);
  th->current_frame->pushOperand(val2);
  th->current_frame->pushOperand(val1);
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> DupX2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val1 = th->current_frame->popOperand<Any>();  // cat1
  // cat2
  if (th->current_frame->topOperand().is<long>() ||
      th->current_frame->topOperand().is<double>()) {
    auto val2 = th->current_frame->popOperand<Any>();

    th->current_frame->pushOperand(val1);
    th->current_frame->pushOperand(val2);
    th->current_frame->pushOperand(val1);
  } else {
    auto val2 = th->current_frame->popOperand<Any>();
    auto val3 = th->current_frame->popOperand<Any>();

    th->current_frame->pushOperand(val1);
    th->current_frame->pushOperand(val3);
    th->current_frame->pushOperand(val2);
    th->current_frame->pushOperand(val1);
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

  // se é cat2
  if (th->current_frame->topOperand().is<long>() ||
      th->current_frame->topOperand().is<double>()) {
    auto val = th->current_frame->popOperand<Any>();

    th->current_frame->pushOperand(val);
    th->current_frame->pushOperand(val);
  } else {
    auto val1 = th->current_frame->popOperand<Any>();
    auto val2 = th->current_frame->popOperand<Any>();

    th->current_frame->pushOperand(val2);
    th->current_frame->pushOperand(val1);
    th->current_frame->pushOperand(val2);
    th->current_frame->pushOperand(val1);
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

  // cat2
  if (th->current_frame->topOperand().is<long>() ||
      th->current_frame->topOperand().is<double>()) {
    auto val1 = th->current_frame->popOperand<Any>();
    auto val2 = th->current_frame->popOperand<Any>();

    th->current_frame->pushOperand(val1);
    th->current_frame->pushOperand(val2);
    th->current_frame->pushOperand(val1);
  } else {
    auto val1 = th->current_frame->popOperand<Any>();
    auto val2 = th->current_frame->popOperand<Any>();
    auto val3 = th->current_frame->popOperand<Any>();

    th->current_frame->pushOperand(val2);
    th->current_frame->pushOperand(val1);
    th->current_frame->pushOperand(val3);
    th->current_frame->pushOperand(val2);
    th->current_frame->pushOperand(val1);
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
  // cat2
  if (th->current_frame->topOperand().is<long>() ||
      th->current_frame->topOperand().is<double>()) {
    auto val1 = th->current_frame->popOperand<Any>();
    // se o proximo tbm for cat2
    if (th->current_frame->topOperand().is<long>() ||
        th->current_frame->topOperand().is<double>()) {
      auto val2 = th->current_frame->popOperand<Any>();

      th->current_frame->pushOperand(val1);
      th->current_frame->pushOperand(val2);
      th->current_frame->pushOperand(val1);
    } else {
      // val2 e 3 sao cat1
      auto val2 = th->current_frame->popOperand<Any>();
      auto val3 = th->current_frame->popOperand<Any>();

      th->current_frame->pushOperand(val1);
      th->current_frame->pushOperand(val3);
      th->current_frame->pushOperand(val2);
      th->current_frame->pushOperand(val1);
    }
  } else {
    // val1 é cat1
    auto val1 = th->current_frame->popOperand<Any>();
    auto val2 = th->current_frame->popOperand<Any>();
    // se val3 é cat2
    if (th->current_frame->topOperand().is<long>() ||
        th->current_frame->topOperand().is<double>()) {
      auto val3 = th->current_frame->popOperand<Any>();
      
      th->current_frame->pushOperand(val2);
      th->current_frame->pushOperand(val1);
      th->current_frame->pushOperand(val3);
      th->current_frame->pushOperand(val2);
      th->current_frame->pushOperand(val1);
    } else {
      auto val3 = th->current_frame->popOperand<Any>();
      auto val4 = th->current_frame->popOperand<Any>();

      th->current_frame->pushOperand(val2);
      th->current_frame->pushOperand(val1);
      th->current_frame->pushOperand(val4);
      th->current_frame->pushOperand(val3);
      th->current_frame->pushOperand(val2);
      th->current_frame->pushOperand(val1);
    }
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
