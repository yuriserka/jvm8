#include "instructions/instruction_set/integer.h"

#include "utils/array_t.h"
#include "utils/flags.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
namespace Integer {
<<<<<<< HEAD

=======
/**
 * @brief Convert int to byte
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> ToByte::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(static_cast<int8_t>(value));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Convert int to char
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> ToChar::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(static_cast<char>(value));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Convert int to double
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> ToDouble::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand(static_cast<double>(value));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Convert int to float
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> ToFloat::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand(static_cast<float>(value));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Convert int to long
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> ToLong::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand(static_cast<long>(value));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Convert int to short
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> ToShort::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(static_cast<short>(value));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Add int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Add::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto soma = th->current_frame->popOperand<int>() +
              th->current_frame->popOperand<int>();
  th->current_frame->pushOperand(soma);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load int from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> LoadFromArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  int index = th->current_frame->popOperand<int>();
  auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                      ->data.as<Utils::Array_t *>();
  th->current_frame->pushOperand(arrayref->get<int>(index));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Boolean AND int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> And::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(val1 & val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store int into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> StoreIntoArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  auto index = th->current_frame->popOperand<int>();
  auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                      ->data.as<Utils::Array_t *>();
  arrayref->insert(value, index);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push int constant
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Const_m1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<int>(-1);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push int constant
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Const_0::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<int>(0);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push int constant
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Const_1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<int>(1);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push int constant
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Const_2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<int>(2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push int constant
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Const_3::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<int>(3);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push int constant
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Const_4::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<int>(4);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push int constant
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Const_5::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<int>(5);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Divide int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Div::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(val1 / val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Increment local variable by constant
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Inc::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  if (wide) {
    int16_t index = (*++*code_iterator << 8) | *++*code_iterator;
    int16_t k = (*++*code_iterator << 8) | *++*code_iterator;
    auto value = th->current_frame->getLocalVarReference<int>(index);
    *value += k;
    *delta_code = 4;
  } else {
    unsigned char index = *++*code_iterator;
    signed char k = *++*code_iterator;
    auto value = th->current_frame->getLocalVarReference<int>(index);
    *value += int{k};
    *delta_code = 2;
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load int from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Load::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  int localvar_index;
  if (wide) {
    localvar_index =
        static_cast<int16_t>((*++*code_iterator << 8) | *++*code_iterator);
    *delta_code = 2;
  } else {
    localvar_index = int{*++*code_iterator};
    *delta_code = 1;
  }
  th->current_frame->pushOperand(
      th->current_frame->getLocalVarValue<int>(localvar_index));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load int from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Load_0::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<int>(0));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load int from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Load_1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<int>(1));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load int from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Load_2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<int>(2));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load int from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Load_3::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<int>(3));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Multiply int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Mul::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(val1 * val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Negate int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Neg::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>((~value) + 1);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Boolean OR int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Or::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(val1 | val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Remaind int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Rem::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(val1 - (val1 / val2) * val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Return int from method
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Return::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto retval = th->current_frame->popOperand<int>();
  th->pushReturnValue(retval);
  th->current_frame->cleanOperands();
  return {1};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Shift left int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> ShiftLeft::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto s = th->current_frame->popOperand<int>() & 0x1F;
  auto val1 = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(val1 << s);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Arithmetic shift right int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> ArithmeticShiftRight::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto s = th->current_frame->popOperand<int>() & 0x1F;
  auto val1 = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(val1 >> s);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store int into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Store::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  int localvar_index;
  if (wide) {
    localvar_index =
        static_cast<int16_t>((*++*code_iterator << 8) | *++*code_iterator);
    *delta_code = 2;
  } else {
    localvar_index = int{*++*code_iterator};
    *delta_code = 1;
  }
  auto integerref = th->current_frame->popOperand<int>();
  th->current_frame->pushLocalVar(integerref, localvar_index);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store int into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Store_0::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto integerref = th->current_frame->popOperand<int>();
  th->current_frame->pushLocalVar(integerref, 0);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store int into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Store_1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto integerref = th->current_frame->popOperand<int>();
  th->current_frame->pushLocalVar(integerref, 1);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store int into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Store_2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto integerref = th->current_frame->popOperand<int>();
  th->current_frame->pushLocalVar(integerref, 2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store int into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Store_3::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto integerref = th->current_frame->popOperand<int>();
  th->current_frame->pushLocalVar(integerref, 3);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Subtract int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Sub::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(val1 - val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Logical shift right int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> LogicalShiftRight::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto s = th->current_frame->popOperand<int>() & 0x1F;
  auto val1 = th->current_frame->popOperand<int>();
  int result = 0;
  if (val1 > 0) {
    result = val1 >> s;
  } else {
    result = (val1 >> s) + (2 << ~s);
  }
  th->current_frame->pushOperand<int>(result);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Boolean XOR int
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Xor::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<int>();
  auto val1 = th->current_frame->popOperand<int>();
  th->current_frame->pushOperand<int>(val1 ^ val2);
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Integer
}  // namespace Instructions
