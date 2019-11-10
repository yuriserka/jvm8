#include "instructions/instruction_set/constant_pool.h"

#include "utils/flags.h"
#include "utils/memory.h"
#include "utils/memory_areas/method_area.h"
#include "utils/memory_areas/thread.h"

namespace Instructions {
namespace ConstantPool {
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
      // referencia pra string, ou seja, apenas um "ponteiro" pra constant pool
      th->current_frame->pushOperand<Utils::Types::u2>(
          kstring_info->string_index);
      break;
    }
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = kpool_info.getClass<cp::CONSTANT_Class_info>();
      // referencia pro nome da classe, ou seja, apenas um "ponteiro" pra
      // constant pool
      th->current_frame->pushOperand<Utils::Types::u2>(kclass_info->name_index);
      break;
    }
  }
  *delta_code = 1;
  return {};
}
// ----------------------------------------------------------------------------
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
      // referencia pra string, ou seja, apenas um "ponteiro" pra constant pool
      th->current_frame->pushOperand<Utils::Types::u2>(
          kstring_info->string_index);
      break;
    }
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = kpool_info.getClass<cp::CONSTANT_Class_info>();
      // referencia pro nome da classe, ou seja, apenas um "ponteiro" pra
      // constant pool
      th->current_frame->pushOperand<Utils::Types::u2>(kclass_info->name_index);
      break;
    }
  }
  *delta_code = 2;
  return {};
}
// ----------------------------------------------------------------------------
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
