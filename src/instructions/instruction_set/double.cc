#include "instructions/instruction_set/double.h"

#include <cmath>
#include "utils/array_t.h"
#include "utils/flags.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
namespace Double {
<<<<<<< HEAD

=======
/**
 * @brief Convert double to float
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
  auto value = th->current_frame->popOperand<double>();
  th->current_frame->pushOperand(static_cast<float>(value));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Convert double to integer
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
  auto value = th->current_frame->popOperand<double>();
  th->current_frame->pushOperand(static_cast<int>(value));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Convert double to long
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
  auto value = th->current_frame->popOperand<double>();
  th->current_frame->pushOperand(static_cast<long>(value));
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Add::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto soma = th->current_frame->popOperand<double>() +
              th->current_frame->popOperand<double>();
  th->current_frame->pushOperand(soma);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load double from array
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
  th->current_frame->pushOperand(arrayref->get<double>(index));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store double into local variable
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
  auto value = th->current_frame->popOperand<double>();
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
 * @brief Compare double (val1 > val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> CompareGreater::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<double>();
  auto val1 = th->current_frame->popOperand<double>();
  if (val1 > val2) {
    th->current_frame->pushOperand<int>(1);
  } else if (val1 == val2) {
    th->current_frame->pushOperand<int>(0);
  } else if (val1 < val2) {
    th->current_frame->pushOperand<int>(-1);
  } else {
    th->current_frame->pushOperand<int>(1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Compare double (val1 < val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
>>>>>>> b4932eb9aa6dba2be0f886d377ced60ee4c2895c
std::vector<int> CompareLess::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<double>();
  auto val1 = th->current_frame->popOperand<double>();
  if (val1 > val2) {
    th->current_frame->pushOperand<int>(1);
  } else if (val1 == val2) {
    th->current_frame->pushOperand<int>(0);
  } else if (val1 < val2) {
    th->current_frame->pushOperand<int>(-1);
  } else {
    th->current_frame->pushOperand<int>(-1);
  }
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief
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
  th->current_frame->pushOperand<double>(0.0);
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Const_1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<double>(1.0);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Divide double
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
  auto val2 = th->current_frame->popOperand<double>();
  auto val1 = th->current_frame->popOperand<double>();
  th->current_frame->pushOperand(val1 / val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load double from local variable
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
      th->current_frame->getLocalVarValue<double>(localvar_index));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load double from local variable
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
  th->current_frame->pushOperand(
      th->current_frame->getLocalVarValue<double>(0));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load double from local variable
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
  th->current_frame->pushOperand(
      th->current_frame->getLocalVarValue<double>(1));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load double from local variable
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
  th->current_frame->pushOperand(
      th->current_frame->getLocalVarValue<double>(2));
  return {};
}
// ---------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Load double from local variable
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
  th->current_frame->pushOperand(
      th->current_frame->getLocalVarValue<double>(3));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Multiply double
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
  auto val2 = th->current_frame->popOperand<double>();
  auto val1 = th->current_frame->popOperand<double>();
  th->current_frame->pushOperand(val1 * val2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Negate double
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
  auto val = th->current_frame->popOperand<double>();
  th->current_frame->pushOperand(-val);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Remainder double
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
  auto val2 = th->current_frame->popOperand<double>();
  auto val1 = th->current_frame->popOperand<double>();
  th->current_frame->pushOperand(std::fmod(val1, val2));
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Return double from method
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
  auto retval = th->current_frame->popOperand<double>();
  th->pushReturnValue(retval);
  th->current_frame->cleanOperands();
  return {1};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store double into local variable
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
  auto doubleref = th->current_frame->popOperand<double>();
  th->current_frame->pushLocalVar(doubleref, localvar_index);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store double into local variable
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
  auto doubleref = th->current_frame->popOperand<double>();
  th->current_frame->pushLocalVar(doubleref, 0);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store double into local variable
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
  auto doubleref = th->current_frame->popOperand<double>();
  th->current_frame->pushLocalVar(doubleref, 1);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store double into local variable
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
  auto doubleref = th->current_frame->popOperand<double>();
  th->current_frame->pushLocalVar(doubleref, 2);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Store double into local variable
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
  auto doubleref = th->current_frame->popOperand<double>();
  th->current_frame->pushLocalVar(doubleref, 3);
  return {};
}
// ----------------------------------------------------------------------------
<<<<<<< HEAD

=======
/**
 * @brief Subtract double
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
  auto val2 = th->current_frame->popOperand<double>();
  auto val1 = th->current_frame->popOperand<double>();
  th->current_frame->pushOperand(val1 - val2);
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Double
}  // namespace Instructions
