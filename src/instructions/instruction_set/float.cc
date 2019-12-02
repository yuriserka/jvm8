#include "instructions/instruction_set/float.h"

#include <cmath>
#include "utils/array_t.h"
#include "utils/flags.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
namespace Float {
/**
 * @brief Convert float to double
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> ToDouble::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<float>();
  th->current_frame->pushOperand(static_cast<double>(value));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Convert float to integer
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> ToInteger::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<float>();
  th->current_frame->pushOperand(static_cast<int>(value));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Convert float to long
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> ToLong::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<float>();
  th->current_frame->pushOperand(static_cast<long>(value));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Add float
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Add::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto soma = th->current_frame->popOperand<float>() +
              th->current_frame->popOperand<float>();
  th->current_frame->pushOperand(soma);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Load float from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> LoadFromArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  int index = th->current_frame->popOperand<int>();
  auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                      ->data.as<Utils::Array_t *>();
  th->current_frame->pushOperand(arrayref->get<float>(index));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Store float into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> StoreIntoArray::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto value = th->current_frame->popOperand<float>();
  auto index = th->current_frame->popOperand<int>();
  auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                      ->data.as<Utils::Array_t *>();
  arrayref->insert(value, index);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Compare float (val1 > val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> CompareGreater::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<float>();
  auto val1 = th->current_frame->popOperand<float>();
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
/**
 * @brief Compare float (val1 < val2)
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> CompareLess::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<float>();
  auto val1 = th->current_frame->popOperand<float>();
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
std::vector<int> Const_0::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<float>(0.0f);
  return {};
}
// ----------------------------------------------------------------------------
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
std::vector<int> Const_1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<float>(1.0f);
  return {};
}
// ----------------------------------------------------------------------------
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
std::vector<int> Const_2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand<float>(2.0f);
  return {};
}
// ----------------------------------------------------------------------------
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
std::vector<int> Div::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<float>();
  auto val1 = th->current_frame->popOperand<float>();
  th->current_frame->pushOperand(val1 / val2);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Load float from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
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
      th->current_frame->getLocalVarValue<float>(localvar_index));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Load float from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Load_0::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<float>(0));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Load float from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Load_1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<float>(1));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Load float from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Load_2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<float>(2));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Load float from local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Load_3::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->pushOperand(th->current_frame->getLocalVarValue<float>(3));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Multiply float
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Mul::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<float>();
  auto val1 = th->current_frame->popOperand<float>();
  th->current_frame->pushOperand<float>(val1 * val2);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Negate float
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Neg::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val = th->current_frame->popOperand<float>();
  th->current_frame->pushOperand<float>(-val);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Remainder float
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Rem::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<float>();
  auto val1 = th->current_frame->popOperand<float>();
  th->current_frame->pushOperand<float>(std::fmod(val1, val2));
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Return float from method
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Return::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto retval = th->current_frame->popOperand<float>();
  th->pushReturnValue(retval);
  th->current_frame->cleanOperands();
  return {1};
}
// ----------------------------------------------------------------------------
/**
 * @brief Store float into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
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
  auto floatref = th->current_frame->popOperand<float>();
  th->current_frame->pushLocalVar(floatref, localvar_index);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Store float into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Store_0::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto floatref = th->current_frame->popOperand<float>();
  th->current_frame->pushLocalVar(floatref, 0);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Store float into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Store_1::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto floatref = th->current_frame->popOperand<float>();
  th->current_frame->pushLocalVar(floatref, 1);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Store float into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Store_2::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto floatref = th->current_frame->popOperand<float>();
  th->current_frame->pushLocalVar(floatref, 2);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Store float into local variable
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Store_3::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto floatref = th->current_frame->popOperand<float>();
  th->current_frame->pushLocalVar(floatref, 3);
  return {};
}
// ----------------------------------------------------------------------------
/**
 * @brief Subtract float
 *
 * @param code_iterator
 * @param th
 * @param delta_code
 * @param wide
 * @param pc
 * @return std::vector<int>
 */
std::vector<int> Sub::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  auto val2 = th->current_frame->popOperand<float>();
  auto val1 = th->current_frame->popOperand<float>();
  th->current_frame->pushOperand<float>(val1 - val2);
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Float
}  // namespace Instructions
