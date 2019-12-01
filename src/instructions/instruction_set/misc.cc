#include "instructions/instruction_set/misc.h"

#include <memory>
#include "utils/accessFlags.h"
#include "utils/array_t.h"
#include "utils/field_t.h"
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
  auto kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;

  auto objectref = th->current_frame->popOperand<Utils::Object *>();
  auto classname_and_field_str =
      th->current_class->constant_pool[kpool_index - 1]
          .getClass<Utils::ConstantPool::CONSTANT_FieldRef_info>()
          ->getValue(th->current_class->constant_pool, true);
  auto classname = classname_and_field_str.substr(
      0, classname_and_field_str.find_last_of('.'));
  auto field_name = classname_and_field_str.substr(
      classname_and_field_str.find_last_of('.') + 1);

  auto old_class = th->current_class;
  // muda o contexto para onde o field vai estar
  th->method_area->update(th->method_area->getClass(classname));
  auto field = th->method_area->getField(field_name);
  auto field_access = Utils::Access::getFieldAccessType(field.access_flags);

  if (std::find_if(field_access.begin(), field_access.end(),
                   [](const std::string &s) { return !s.compare("static"); }) !=
      field_access.end()) {
    throw Utils::Errors::JvmException(
        Utils::Errors::java_exceptions::kINCOMPATIBLECLASSCHANGE,
        "IncompatibleClassChangeError");
  }

  if (objectref == nullptr) {
    throw Utils::Errors::JvmException(
        Utils::Errors::java_exceptions::kNULLPOINTEREXCEPTION,
        "NullPointerException");
  }

  auto field_val = objectref->fields[field_name]->data;
  th->current_frame->pushOperand(field_val);

  // retorna o contexto para a classe antiga
  th->method_area->update(old_class);
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> GetStatic::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  auto index = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;

  std::string classname, field_name, descriptor;
  Utils::getReference(th->method_area->runtime_classfile, index, &classname,
                      &field_name, &descriptor);

  // se classname.field_name != java/lang/System.out ai carrega a classe, tem
  // que inicializar e os krl ainda
  if ((classname + "." + field_name)
          .compare(std::string("java/lang/System.out"))) {
    if (Utils::Flags::options.kDEBUG) {
      std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
    }
    auto old_class = th->current_class;
    // muda o contexto para onde o field vai estar
    if (!th->method_area->isLoaded(classname)) {
      th->method_area->update(th->method_area->getClass(classname));
    }

    auto field_val = th->heap->getClass(classname)->getField(field_name)->data;
    th->current_frame->pushOperand(field_val);

    th->method_area->update(old_class);
  } else if (Utils::Flags::options.kDEBUG) {
    std::cout << "Ignorando " << Opcodes::getMnemonic(this->opcode) << " "
              << (classname + "." + field_name) << "\n";
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

  // auto objectref = th->current_frame->popOperand<Utils::Object *>();
  // if (objectref->data.is_null()) {
  //   th->current_frame->pushOperand(1);
  // }

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
  // auto kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
  *code_iterator += 2;
  int dims = *++*code_iterator;
  *delta_code = 3;

  auto inner_to_outer_dimensions = new int[dims];
  for (int i = dims - 1; i >= 0; --i) {
    inner_to_outer_dimensions[i] = th->current_frame->popOperand<int>();
    if (!inner_to_outer_dimensions[i]) {
      break;
    }
  }

  auto multiarray = new Utils::MultiArray_t(dims, inner_to_outer_dimensions);
  auto objectref =
      new Utils::Object(multiarray->arrays, Utils::Reference::kREF_ARRAY);

  th->current_frame->pushOperand(th->heap->pushReference(objectref));

  delete[] inner_to_outer_dimensions;

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
  *delta_code = 2;
  auto kpool_info = th->current_class->constant_pool[kpool_index - 1];

  auto classname =
      kpool_info.getClass<Utils::ConstantPool::CONSTANT_Class_info>()->getValue(
          th->current_class->constant_pool);

  auto old_class = th->current_class;
  // classname != java/lang/StringBuilder e != java/lang/String
  if (classname.compare("java/lang/StringBuilder") &&
      classname.compare("java/lang/String")) {
    th->method_area->update(th->method_area->getClass(classname));
  }

  auto objectref = new Utils::Object();
  th->current_frame->pushOperand(th->heap->pushReference(objectref));
  th->heap->addClass(th, classname);

  th->method_area->update(old_class);
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
  th->current_frame->popOperand<Any>();
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Pop2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  // cat 1
  if (!th->current_frame->topOperand().is<long>() &&
      !th->current_frame->topOperand().is<double>()) {
    th->current_frame->popOperand<Any>();
    th->current_frame->popOperand<Any>();
  } else {
    th->current_frame->popOperand<Any>();
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
  auto kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;

  auto classname_and_field_str =
      th->current_class->constant_pool[kpool_index - 1]
          .getClass<Utils::ConstantPool::CONSTANT_FieldRef_info>()
          ->getValue(th->current_class->constant_pool, true);

  auto field_name = classname_and_field_str.substr(
      classname_and_field_str.find_last_of('.') + 1);
  auto field = th->method_area->getField(field_name);

  auto val = th->current_frame->popOperand<Any>();
  auto objectref = th->current_frame->popOperand<Utils::Object *>();

  auto field_access = Utils::Access::getFieldAccessType(field.access_flags);

  if (std::find_if(field_access.begin(), field_access.end(),
                   [](const std::string &s) { return !s.compare("static"); }) !=
      field_access.end()) {
    throw Utils::Errors::JvmException(
        Utils::Errors::java_exceptions::kINCOMPATIBLECLASSCHANGE,
        "IncompatibleClassChangeError");
  }

  if (objectref == nullptr) {
    throw Utils::Errors::JvmException(
        Utils::Errors::java_exceptions::kNULLPOINTEREXCEPTION,
        "NullPointerException");
  }

  objectref->addField(field_name, new Utils::Field_t(val));
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> PutStatic::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;

  auto kfieldref_info =
      th->current_class->constant_pool[kpool_index - 1]
          .getClass<Utils::ConstantPool::CONSTANT_FieldRef_info>();

  auto classname_and_field_str =
      kfieldref_info->getValue(th->current_class->constant_pool, true);

  auto descriptor =
      th->method_area
          ->runtime_constant_pool[kfieldref_info->name_and_type_index - 1]
          .getClass<Utils::ConstantPool::CONSTANT_NameAndType_info>()
          ->getValue(th->current_class->constant_pool);

  descriptor = descriptor.substr(descriptor.find_last_of(':'));

  auto classname = classname_and_field_str.substr(
      0, classname_and_field_str.find_last_of('.'));
  auto field_name = classname_and_field_str.substr(
      classname_and_field_str.find_last_of('.') + 1);

  auto old_class = th->current_class;
  // muda o contexto para onde o field vai estar
  th->method_area->update(th->method_area->getClass(classname));

  auto field = th->method_area->getField(field_name);
  auto val = th->current_frame->popOperand<Any>();
  auto field_access = Utils::Access::getFieldAccessType(field.access_flags);

  if (std::find_if(field_access.begin(), field_access.end(),
                   [](const std::string &s) { return !s.compare("static"); }) ==
      field_access.end()) {
    throw Utils::Errors::JvmException(
        Utils::Errors::java_exceptions::kINCOMPATIBLECLASSCHANGE,
        "IncompatibleClassChangeError");
  }

  th->heap->getClass(classname)->addField(val, field_name, descriptor);
  th->method_area->update(old_class);
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
  return {1};
}
// ----------------------------------------------------------------------------
std::vector<int> Swap::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val1 = th->current_frame->popOperand<Any>();
  auto val2 = th->current_frame->popOperand<Any>();

  th->current_frame->pushOperand(val2);
  th->current_frame->pushOperand(val1);
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
