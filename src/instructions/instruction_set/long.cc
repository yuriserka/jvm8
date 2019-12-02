#include "instructions/instruction_set/long.h"

#include "utils/array_t.h"
#include "utils/flags.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
namespace Long {
<<<<<<< HEAD

=======
/**
 * @brief Convert long to double
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
  auto value = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<double>(value);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Convert long to float
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
  auto value = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<float>(value);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Convert long to integer
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> ToInteger::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<int>(value);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Add long
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
  auto soma = th->current_frame->popOperand<long>() +
              th->current_frame->popOperand<long>();
  th->current_frame->pushOperand(soma);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load long from local variable
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
  th->current_frame->pushOperand(arrayref->get<long>(index));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Boolean AND long
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
  auto val2 = th->current_frame->popOperand<long>();
  auto val1 = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>(val1 & val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store long into local variable
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
  auto value = th->current_frame->popOperand<long>();
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
 * @brief Compare long
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> Compare::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<long>();
  auto val1 = th->current_frame->popOperand<long>();
  if (val1 > val2) {
    th->current_frame->pushOperand<int>(1);
  } else if (val1 == val2) {
    th->current_frame->pushOperand<int>(0);
  } else if (val1 < val2) {
    th->current_frame->pushOperand<int>(-1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push float
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
  th->current_frame->pushOperand<long>(0L);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Push float
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
  th->current_frame->pushOperand<long>(1L);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Divide float
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

  auto val2 = th->current_frame->popOperand<long>();
  auto val1 = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>(val1 / val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load long from local variable
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
      th->current_frame->getLocalVarValue<long>(localvar_index));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load long from local variable
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
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<long>(0));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load long from local variable
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
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<long>(1));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load long from local variable
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
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<long>(2));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load long from local variable
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
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<long>(3));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Multiply long
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
  auto val2 = th->current_frame->popOperand<long>();
  auto val1 = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>(val1 * val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Negate long
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
  auto value = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>((~value) + 1);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Boolean OR long
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
  auto val2 = th->current_frame->popOperand<long>();
  auto val1 = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>(val1 | val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Remainder long
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
  auto val2 = th->current_frame->popOperand<long>();
  auto val1 = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>(val1 - (val1 / val2) * val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Return long from method
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
  auto retval = th->current_frame->popOperand<long>();
  th->pushReturnValue(retval);
  th->current_frame->cleanOperands();
  return {1};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Shift left long
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
  auto s = th->current_frame->popOperand<int>() & 0x3F;
  auto val1 = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>(val1 << s);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Arithmetic shift right long
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
  auto s = th->current_frame->popOperand<int>() & 0x3F;
  auto val1 = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>(val1 >> s);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store long into local variable
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
  auto objectref = th->current_frame->popOperand<long>();
  th->current_frame->pushLocalVar(objectref, localvar_index);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store long into local variable
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
  auto objectref = th->current_frame->popOperand<long>();
  th->current_frame->pushLocalVar(objectref, 0);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store long into local variable
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
  auto objectref = th->current_frame->popOperand<long>();
  th->current_frame->pushLocalVar(objectref, 1);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store long into local variable
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
  auto objectref = th->current_frame->popOperand<long>();
  th->current_frame->pushLocalVar(objectref, 2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store long into local variable
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
  auto objectref = th->current_frame->popOperand<long>();
  th->current_frame->pushLocalVar(objectref, 3);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Subtract long
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
  auto val2 = th->current_frame->popOperand<long>();
  auto val1 = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>(val1 - val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Logical shift right long
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
  auto s = th->current_frame->popOperand<int>() & 0x3F;
  auto val1 = th->current_frame->popOperand<long>();
  long result = 0L;
  if (val1 > 0L) {
    result = val1 >> s;
  } else {
    result = (val1 >> s) + (2L << ~s);
  }
  th->current_frame->pushOperand<long>(result);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Boolean XOR long
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
  auto val2 = th->current_frame->popOperand<long>();
  auto val1 = th->current_frame->popOperand<long>();
  th->current_frame->pushOperand<long>(val1 ^ val2);
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Long
}  // namespace Instructions
