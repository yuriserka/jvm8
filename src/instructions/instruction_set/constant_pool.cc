#include "instructions/instruction_set/constant_pool.h"

#include "utils/flags.h"
#include "utils/memory.h"
#include "utils/memory_areas/heap.h"
#include "utils/memory_areas/method_area.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"
#include "utils/reference_kind.h"

namespace Instructions {
namespace ConstantPool {
<<<<<<< HEAD

=======
/**
 * @brief Push item from run-time constant pool (cat1)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> LoadCat1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  unsigned char kpool_index = *++*code_iterator;
  auto kpool_info = th->method_area->runtime_constant_pool[kpool_index - 1];
  switch (kpool_info.base->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = kpool_info.getClass<cp::CONSTANT_Integer_info>();
      th->current_frame->pushOperand<int>(kinteger_info->bytes);
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = kpool_info.getClass<cp::CONSTANT_Float_info>();
      th->current_frame->pushOperand<float>(
          Utils::castTo<float>(&kfloat_info->bytes));
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = kpool_info.getClass<cp::CONSTANT_String_info>();
      auto objectref = new Utils::Object(
          kstring_info->getValue(th->method_area->runtime_constant_pool),
          Utils::Reference::objectref_types::kREF_STRING,
          Utils::getClassName(th->current_class));
      auto stringref = th->heap->pushReference(objectref);
      th->current_frame->pushOperand(stringref);
      break;
    }
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = kpool_info.getClass<cp::CONSTANT_Class_info>();
      auto objectref = new Utils::Object(
          kclass_info->getValue(th->method_area->runtime_constant_pool),
          Utils::Reference::objectref_types::kREF_CLASS,
          Utils::getClassName(th->current_class));
      auto classref = th->heap->pushReference(objectref);
      th->current_frame->pushOperand(classref);
      break;
    }
  }
  *delta_code = 1;
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push item from run-time constant pool (wide)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> LoadCat1Wide::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  int16_t kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
  auto kpool_info = th->method_area->runtime_constant_pool[kpool_index - 1];
  switch (kpool_info.base->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = kpool_info.getClass<cp::CONSTANT_Integer_info>();
      th->current_frame->pushOperand<int>(kinteger_info->bytes);
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = kpool_info.getClass<cp::CONSTANT_Float_info>();
      th->current_frame->pushOperand<float>(
          Utils::castTo<float>(&kfloat_info->bytes));
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = kpool_info.getClass<cp::CONSTANT_String_info>();
      auto objectref = new Utils::Object(
          kstring_info->getValue(th->method_area->runtime_constant_pool),
          Utils::Reference::objectref_types::kREF_STRING,
          Utils::getClassName(th->current_class));
      auto stringref = th->heap->pushReference(objectref);
      th->current_frame->pushOperand(stringref);
      break;
    }
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = kpool_info.getClass<cp::CONSTANT_Class_info>();
      auto objectref = new Utils::Object(
          kclass_info->getValue(th->method_area->runtime_constant_pool),
          Utils::Reference::objectref_types::kREF_CLASS,
          Utils::getClassName(th->current_class));
      auto classref = th->heap->pushReference(objectref);
      th->current_frame->pushOperand(classref);
      break;
    }
  }
  *delta_code = 2;
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push item from run-time constant pool (cat2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> LoadCat2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }

  int16_t kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
  auto kpool_info = th->method_area->runtime_constant_pool[kpool_index - 1];
  switch (kpool_info.base->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_LONG: {
      auto klong_info = kpool_info.getClass<cp::CONSTANT_Long_info>();
      auto u8val =
          (static_cast<Utils::Types::u8>(klong_info->high_bytes) << 32 |
           klong_info->low_bytes);
      th->current_frame->pushOperand<long>(u8val);
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = kpool_info.getClass<cp::CONSTANT_Double_info>();
      auto u8val =
          (static_cast<Utils::Types::u8>(kdouble_info->high_bytes) << 32 |
           kdouble_info->low_bytes);
      th->current_frame->pushOperand<double>(Utils::castTo<double>(&u8val));
      break;
    }
  }
  *delta_code = 2;
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace ConstantPool
}  // namespace Instructions
