#include "instructions/instruction_set/branch.h"

#include "utils/flags.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
namespace Branch {
<<<<<<< HEAD
=======
/**
 * @brief Branch if reference comparison succeeds

 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> RefCompareEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<Utils::Object *>();
  auto val1 = th->current_frame->popOperand<Utils::Object *>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (val1 == val2) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if reference not null
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> RefCompareNotEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<Utils::Object *>();
  auto val1 = th->current_frame->popOperand<Utils::Object *>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (val1 != val2) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (val1 = val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> IntegerCompareEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (val1 == val2) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (val1 >= val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> IntegerCompareGreaterEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (val1 >= val2) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (val1 > val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> IntegerCompareGreaterThan::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (val1 > val2) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (val1 <= val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> IntegerCompareLessEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (val1 <= val2) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (val1 < val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> IntegerCompareLessThan::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (val1 < val2) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (val1 != val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> IntegerCompareNotEqual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (val1 != val2) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (value == 0)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> EqualZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (!value) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (value >= 0)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> GreaterEqualZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (value >= 0) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (value > 0)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> GreaterThanZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (value > 0) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (value <= 0)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> LessEqualZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (value <= 0) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (value < 0)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> LessThanZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (value < 0) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if int comparison succeeds (value != 0)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> NotEqualZero::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (value) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Branch if reference is not null
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> NonNull::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<Utils::Object *>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (value) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------

<<<<<<< HEAD
=======
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> RefNull::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<Utils::Object *>();
  int16_t offset = (*++*code_iterator << 8) | *++*code_iterator;
  *delta_code = 2;
  if (!value) {
    *code_iterator += (offset - *delta_code - 1);
    *pc += (offset - *delta_code - 1);
  }
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Branch
}  // namespace Instructions
