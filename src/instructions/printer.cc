#include "instructions/printer.h"

#include <iostream>
#include "instructions/instruction_set/base.h"
#include "instructions/instruction_set/branch.h"
#include "instructions/instruction_set/byte.h"
#include "instructions/instruction_set/char.h"
#include "instructions/instruction_set/constant_pool.h"
#include "instructions/instruction_set/double.h"
#include "instructions/instruction_set/float.h"
#include "instructions/instruction_set/integer.h"
#include "instructions/instruction_set/invokes.h"
#include "instructions/instruction_set/jump.h"
#include "instructions/instruction_set/long.h"
#include "instructions/instruction_set/misc.h"
#include "instructions/instruction_set/monitor.h"
#include "instructions/instruction_set/reference.h"
#include "instructions/instruction_set/short.h"
#include "instructions/opcodes.h"
#include "utils/utf8.h"
#include "viewer.h"

static std::ios state(NULL);

namespace Instructions {
void printBytecode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v,
                   int *code_index, const bool &wide) {
  auto opcode = **code_it;
  auto delta_code = 0;
  Instruction *i = nullptr;
  switch (opcode) {
    case Opcodes::kAALOAD: {
      i = new Reference::LoadFromArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kAASTORE: {
      i = new Reference::StoreIntoArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kACONST_NULL: {
      i = new Reference::ConstNull(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kALOAD: {
      i = new Reference::Load(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kALOAD_0: {
      i = new Reference::Load_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kALOAD_1: {
      i = new Reference::Load_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kALOAD_2: {
      i = new Reference::Load_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kALOAD_3: {
      i = new Reference::Load_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kANEWARRAY: {
      i = new Reference::NewArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx, false) << ">\n";
      break;
    }
    case Opcodes::kARETURN: {
      i = new Reference::Return(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kARRAYLENGTH: {
      i = new Reference::ArrayLength(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kASTORE: {
      i = new Reference::Store(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kASTORE_0: {
      i = new Reference::Store_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kASTORE_1: {
      i = new Reference::Store_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kASTORE_2: {
      i = new Reference::Store_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kASTORE_3: {
      i = new Reference::Store_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kATHROW: {
      i = new Reference::Throw(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kBALOAD: {
      i = new Byte::LoadFromArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kBASTORE: {
      i = new Byte::StoreIntoArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kBIPUSH: {
      i = new Byte::Push(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kBREAKPOINT: {
      i = new Misc::Breakpoint(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kCALOAD: {
      i = new Char::LoadFromArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kCASTORE: {
      i = new Char::StoreIntoArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kCHECKCAST: {
      i = new Misc::Checkcast(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kD2F: {
      i = new Double::ToFloat(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kD2I: {
      i = new Double::ToInteger(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kD2L: {
      i = new Double::ToLong(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDADD: {
      i = new Double::Add(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDALOAD: {
      i = new Double::LoadFromArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDASTORE: {
      i = new Double::StoreIntoArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDCMPG: {
      i = new Double::CompareGreater(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDCMPL: {
      i = new Double::CompareLess(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDCONST_0: {
      i = new Double::Const_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDCONST_1: {
      i = new Double::Const_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDDIV: {
      i = new Double::Div(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDLOAD: {
      i = new Double::Load(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDLOAD_0: {
      i = new Double::Load_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDLOAD_1: {
      i = new Double::Load_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDLOAD_2: {
      i = new Double::Load_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDLOAD_3: {
      i = new Double::Load_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDMUL: {
      i = new Double::Mul(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDNEG: {
      i = new Double::Neg(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDREM: {
      i = new Double::Rem(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDRETURN: {
      i = new Double::Return(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDSTORE: {
      i = new Double::Store(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDSTORE_0: {
      i = new Double::Store_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDSTORE_1: {
      i = new Double::Store_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDSTORE_2: {
      i = new Double::Store_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDSTORE_3: {
      i = new Double::Store_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDSUB: {
      i = new Double::Sub(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDUP: {
      i = new Misc::Dup(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDUP_X1: {
      i = new Misc::DupX1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDUP_X2: {
      i = new Misc::DupX2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDUP2: {
      i = new Misc::Dup2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDUP2_X1: {
      i = new Misc::Dup2X1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kDUP2_X2: {
      i = new Misc::Dup2X2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kF2D: {
      i = new Float::ToDouble(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kF2I: {
      i = new Float::ToInteger(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kF2L: {
      i = new Float::ToLong(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFADD: {
      i = new Float::Add(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFALOAD: {
      i = new Float::LoadFromArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFASTORE: {
      i = new Float::StoreIntoArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFCMPG: {
      i = new Float::CompareGreater(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFCMPL: {
      i = new Float::CompareLess(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFCONST_0: {
      i = new Float::Const_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFCONST_1: {
      i = new Float::Const_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFCONST_2: {
      i = new Float::Const_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFDIV: {
      i = new Float::Div(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFLOAD: {
      i = new Float::Load(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFLOAD_0: {
      i = new Float::Load_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFLOAD_1: {
      i = new Float::Load_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFLOAD_2: {
      i = new Float::Load_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFLOAD_3: {
      i = new Float::Load_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFMUL: {
      i = new Float::Mul(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFNEG: {
      i = new Float::Neg(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFREM: {
      i = new Float::Rem(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFRETURN: {
      i = new Float::Return(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFSTORE: {
      i = new Float::Store(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFSTORE_0: {
      i = new Float::Store_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFSTORE_1: {
      i = new Float::Store_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFSTORE_2: {
      i = new Float::Store_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFSTORE_3: {
      i = new Float::Store_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kFSUB: {
      i = new Float::Sub(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kGETFIELD: {
      i = new Misc::GetField(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kGETSTATIC: {
      i = new Misc::GetStatic(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kGOTO: {
      i = new Misc::Goto(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);

      break;
    }
    case Opcodes::kGOTO_W: {
      i = new Misc::GotoWide(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kI2B: {
      i = new Integer::ToByte(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kI2C: {
      i = new Integer::ToChar(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kI2D: {
      i = new Integer::ToDouble(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kI2F: {
      i = new Integer::ToFloat(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kI2L: {
      i = new Integer::ToLong(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kI2S: {
      i = new Integer::ToShort(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIADD: {
      i = new Integer::Add(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIALOAD: {
      i = new Integer::LoadFromArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIAND: {
      i = new Integer::And(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIASTORE: {
      i = new Integer::StoreIntoArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kICONST_M1: {
      i = new Integer::Const_m1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kICONST_0: {
      i = new Integer::Const_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kICONST_1: {
      i = new Integer::Const_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kICONST_2: {
      i = new Integer::Const_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kICONST_3: {
      i = new Integer::Const_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kICONST_4: {
      i = new Integer::Const_4(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kICONST_5: {
      i = new Integer::Const_5(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIDIV: {
      i = new Integer::Div(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIF_ACMPEQ: {
      i = new Branch::RefCompareEqual(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIF_ACMPNE: {
      i = new Branch::RefCompareNotEqual(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIF_ICMPEQ: {
      i = new Branch::IntegerCompareEqual(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIF_ICMPGE: {
      i = new Branch::IntegerCompareGreaterEqual(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIF_ICMPGT: {
      i = new Branch::IntegerCompareGreaterThan(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIF_ICMPLE: {
      i = new Branch::IntegerCompareLessEqual(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIF_ICMPLT: {
      i = new Branch::IntegerCompareLessThan(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIF_ICMPNE: {
      i = new Branch::IntegerCompareNotEqual(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIFEQ: {
      i = new Branch::EqualZero(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIFGE: {
      i = new Branch::GreaterEqualZero(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIFGT: {
      i = new Branch::GreaterThanZero(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIFLE: {
      i = new Branch::LessEqualZero(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIFLT: {
      i = new Branch::LessThanZero(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIFNE: {
      i = new Branch::NotEqualZero(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIFNONNULL: {
      i = new Branch::NonNull(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIFNULL: {
      i = new Branch::RefNull(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // state.copyfmt(std::cout);
      // std::cout << static_cast<int>(char(offset + *code_index)) << " ("
      //           << std::showpos << static_cast<int>(char(offset)) << ")\n";
      // std::cout.copyfmt(state);
      break;
    }
    case Opcodes::kIINC: {
      i = new Integer::Inc(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kILOAD: {
      i = new Integer::Load(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kILOAD_0: {
      i = new Integer::Load_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kILOAD_1: {
      i = new Integer::Load_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kILOAD_2: {
      i = new Integer::Load_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kILOAD_3: {
      i = new Integer::Load_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    // case Opcodes::kIMPDEP1: {
    //   i = new Reference::LoadFromArray(v);
    //   i->toBytecode(code_it, *code_index, &delta_code, wide);
    //   break;
    // }
    // case Opcodes::kIMPDEP2: {
    //   i = new Reference::LoadFromArray(v);
    //   i->toBytecode(code_it, *code_index, &delta_code, wide);
    //   break;
    // }
    case Opcodes::kIMUL: {
      i = new Integer::Mul(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kINEG: {
      i = new Integer::Neg(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kINSTANCEOF: {
      i = new Misc::InstanceOf(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kINVOKEDYNAMIC: {
      i = new Invokes::Dynamic(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kINVOKEINTERFACE: {
      i = new Invokes::Interface(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kINVOKESPECIAL: {
      i = new Invokes::Especial(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kINVOKESTATIC: {
      i = new Invokes::Static(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kINVOKEVIRTUAL: {
      i = new Invokes::Virtual(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kIOR: {
      i = new Integer::Or(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIREM: {
      i = new Integer::Rem(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIRETURN: {
      i = new Integer::Return(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kISHL: {
      i = new Integer::ShiftLeft(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kISHR: {
      i = new Integer::ArithmeticShiftRight(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kISTORE: {
      i = new Integer::Store(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kISTORE_0: {
      i = new Integer::Store_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kISTORE_1: {
      i = new Integer::Store_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kISTORE_2: {
      i = new Integer::Store_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kISTORE_3: {
      i = new Integer::Store_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kISUB: {
      i = new Integer::Sub(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIUSHR: {
      i = new Integer::LogicalShiftRight(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kIXOR: {
      i = new Integer::Xor(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kJSR: {
      i = new Jump::JumpSubRoutine(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kJSR_W: {
      i = new Jump::JumpSubRoutineWide(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kL2D: {
      i = new Long::ToDouble(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kL2F: {
      i = new Long::ToFloat(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kL2I: {
      i = new Long::ToInteger(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLADD: {
      i = new Long::Add(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLALOAD: {
      i = new Long::LoadFromArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLAND: {
      i = new Long::And(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLASTORE: {
      i = new Long::StoreIntoArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLCMP: {
      i = new Long::Compare(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLCONST_0: {
      i = new Long::Const_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLCONST_1: {
      i = new Long::Const_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLDC: {
      i = new ConstantPool::LoadCat1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kLDC_W: {
      i = new ConstantPool::LoadCat1Wide(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kLDC2_W: {
      i = new ConstantPool::LoadCat2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kLDIV: {
      i = new Long::Div(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLLOAD: {
      i = new Long::Load(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLLOAD_0: {
      i = new Long::Load_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLLOAD_1: {
      i = new Long::Load_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLLOAD_2: {
      i = new Long::Load_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLLOAD_3: {
      i = new Long::Load_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLMUL: {
      i = new Long::Mul(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLNEG: {
      i = new Long::Neg(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLOOKUPSWITCH: {
      i = new Misc::LookupSwitch(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLOR: {
      i = new Long::Or(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLREM: {
      i = new Long::Rem(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLRETURN: {
      i = new Long::Return(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLSHL: {
      i = new Long::ShiftLeft(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLSHR: {
      i = new Long::ArithmeticShiftRight(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLSTORE: {
      i = new Long::Store(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLSTORE_0: {
      i = new Long::Store_0(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLSTORE_1: {
      i = new Long::Store_1(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLSTORE_2: {
      i = new Long::Store_2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLSTORE_3: {
      i = new Long::Store_3(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLSUB: {
      i = new Long::Sub(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLUSHR: {
      i = new Long::LogicalShiftRight(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kLXOR: {
      i = new Long::Xor(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kMONITORENTER: {
      i = new Monitor::Enter(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kMONITOREXIT: {
      i = new Monitor::Exit(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kMULTIANEWARRAY: {
      i = new Misc::MultiDimArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kNEW: {
      i = new Misc::New(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx, false) << ">\n";
      break;
    }
    case Opcodes::kNEWARRAY: {
      i = new Misc::NewArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kNOP: {
      i = new Misc::Nop(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kPOP: {
      i = new Misc::Pop(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kPOP2: {
      i = new Misc::Pop2(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kPUTFIELD: {
      i = new Misc::PutField(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kPUTSTATIC: {
      i = new Misc::PutStatic(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      // std::wcout << "<" << v->getConstantPoolInfo(idx) << ">\n";
      break;
    }
    case Opcodes::kRET: {
      i = new Misc::Ret(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kRETURN: {
      i = new Misc::Return(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kSALOAD: {
      i = new Short::LoadFromArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kSASTORE: {
      i = new Short::StoreIntoArray(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kSIPUSH: {
      i = new Short::Push(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kSWAP: {
      i = new Misc::Swap(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kTABLESWITCH: {
      i = new Misc::TableSwitch(v);
      i->toBytecode(code_it, *code_index, &delta_code, wide);
      break;
    }
    case Opcodes::kWIDE: {
      // i = new Misc::Wide(v);
      // i->toBytecode(code_it, *code_index, &delta_code, wide);
      printBytecode(++code_it, v, &++*code_index, true);
      break;
    }
  }
  if (i) delete i;
  *code_index += 1 + delta_code;
}
}  // namespace Instructions
