#include "instructions/instruction_set/integer.h"

#include "utils/array_t.h"
#include "utils/flags.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
namespace Integer {
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
