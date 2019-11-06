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
#include "utils/errors.h"
#include "utils/memory_areas/thread.h"

namespace Instructions {
bool runBytecode(std::vector<Utils::Types::u1>::iterator *code_it,
                 MemoryAreas::Thread *th, int *pc, const bool &wide) {
  auto opcode = **code_it;
  auto pc_increment = 0;
  Instruction *i = nullptr;

  switch (opcode) {
    case Opcodes::kAALOAD: {
      i = new Reference::LoadFromArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kAASTORE: {
      i = new Reference::StoreIntoArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kACONST_NULL: {
      i = new Reference::ConstNull();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kALOAD: {
      i = new Reference::Load();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kALOAD_0: {
      i = new Reference::Load_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kALOAD_1: {
      i = new Reference::Load_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kALOAD_2: {
      i = new Reference::Load_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kALOAD_3: {
      i = new Reference::Load_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kANEWARRAY: {
      i = new Reference::NewArray();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0], false) << ">\n";
      break;
    }
    case Opcodes::kARETURN: {
      i = new Reference::Return();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kARRAYLENGTH: {
      i = new Reference::ArrayLength();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kASTORE: {
      i = new Reference::Store();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kASTORE_0: {
      i = new Reference::Store_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kASTORE_1: {
      i = new Reference::Store_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kASTORE_2: {
      i = new Reference::Store_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kASTORE_3: {
      i = new Reference::Store_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kATHROW: {
      i = new Reference::Throw();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kBALOAD: {
      i = new Byte::LoadFromArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kBASTORE: {
      i = new Byte::StoreIntoArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kBIPUSH: {
      i = new Byte::Push();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kBREAKPOINT: {
      throw Utils::Errors::Exception(
          Utils::Errors::kINSTRUCTION,
          Opcodes::getMnemonic(opcode) +
              " should not appear in any class file");
      break;
    }
    case Opcodes::kCALOAD: {
      i = new Char::LoadFromArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kCASTORE: {
      i = new Char::StoreIntoArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kCHECKCAST: {
      i = new Misc::Checkcast();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kD2F: {
      i = new Double::ToFloat();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kD2I: {
      i = new Double::ToInteger();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kD2L: {
      i = new Double::ToLong();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDADD: {
      i = new Double::Add();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDALOAD: {
      i = new Double::LoadFromArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDASTORE: {
      i = new Double::StoreIntoArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDCMPG: {
      i = new Double::CompareGreater();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDCMPL: {
      i = new Double::CompareLess();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDCONST_0: {
      i = new Double::Const_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDCONST_1: {
      i = new Double::Const_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDDIV: {
      i = new Double::Div();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDLOAD: {
      i = new Double::Load();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDLOAD_0: {
      i = new Double::Load_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDLOAD_1: {
      i = new Double::Load_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDLOAD_2: {
      i = new Double::Load_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDLOAD_3: {
      i = new Double::Load_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDMUL: {
      i = new Double::Mul();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDNEG: {
      i = new Double::Neg();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDREM: {
      i = new Double::Rem();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDRETURN: {
      i = new Double::Return();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDSTORE: {
      i = new Double::Store();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDSTORE_0: {
      i = new Double::Store_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDSTORE_1: {
      i = new Double::Store_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDSTORE_2: {
      i = new Double::Store_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDSTORE_3: {
      i = new Double::Store_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDSUB: {
      i = new Double::Sub();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDUP: {
      i = new Misc::Dup();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDUP_X1: {
      i = new Misc::DupX1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDUP_X2: {
      i = new Misc::DupX2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDUP2: {
      i = new Misc::Dup2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDUP2_X1: {
      i = new Misc::Dup2X1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kDUP2_X2: {
      i = new Misc::Dup2X2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kF2D: {
      i = new Float::ToDouble();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kF2I: {
      i = new Float::ToInteger();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kF2L: {
      i = new Float::ToLong();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFADD: {
      i = new Float::Add();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFALOAD: {
      i = new Float::LoadFromArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFASTORE: {
      i = new Float::StoreIntoArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFCMPG: {
      i = new Float::CompareGreater();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFCMPL: {
      i = new Float::CompareLess();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFCONST_0: {
      i = new Float::Const_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFCONST_1: {
      i = new Float::Const_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFCONST_2: {
      i = new Float::Const_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFDIV: {
      i = new Float::Div();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFLOAD: {
      i = new Float::Load();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFLOAD_0: {
      i = new Float::Load_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFLOAD_1: {
      i = new Float::Load_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFLOAD_2: {
      i = new Float::Load_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFLOAD_3: {
      i = new Float::Load_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFMUL: {
      i = new Float::Mul();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFNEG: {
      i = new Float::Neg();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFREM: {
      i = new Float::Rem();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFRETURN: {
      i = new Float::Return();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFSTORE: {
      i = new Float::Store();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFSTORE_0: {
      i = new Float::Store_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFSTORE_1: {
      i = new Float::Store_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFSTORE_2: {
      i = new Float::Store_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFSTORE_3: {
      i = new Float::Store_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kFSUB: {
      i = new Float::Sub();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kGETFIELD: {
      i = new Misc::GetField();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kGETSTATIC: {
      i = new Misc::GetStatic();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kGOTO: {
      i = new Misc::Goto();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kGOTO_W: {
      i = new Misc::GotoWide();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kI2B: {
      i = new Integer::ToByte();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kI2C: {
      i = new Integer::ToChar();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kI2D: {
      i = new Integer::ToDouble();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kI2F: {
      i = new Integer::ToFloat();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kI2L: {
      i = new Integer::ToLong();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kI2S: {
      i = new Integer::ToShort();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIADD: {
      i = new Integer::Add();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIALOAD: {
      i = new Integer::LoadFromArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIAND: {
      i = new Integer::And();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIASTORE: {
      i = new Integer::StoreIntoArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kICONST_M1: {
      i = new Integer::Const_m1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kICONST_0: {
      i = new Integer::Const_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kICONST_1: {
      i = new Integer::Const_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kICONST_2: {
      i = new Integer::Const_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kICONST_3: {
      i = new Integer::Const_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kICONST_4: {
      i = new Integer::Const_4();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kICONST_5: {
      i = new Integer::Const_5();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIDIV: {
      i = new Integer::Div();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIF_ACMPEQ: {
      i = new Branch::RefCompareEqual();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIF_ACMPNE: {
      i = new Branch::RefCompareNotEqual();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIF_ICMPEQ: {
      i = new Branch::IntegerCompareEqual();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIF_ICMPGE: {
      i = new Branch::IntegerCompareGreaterEqual();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIF_ICMPGT: {
      i = new Branch::IntegerCompareGreaterThan();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIF_ICMPLE: {
      i = new Branch::IntegerCompareLessEqual();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIF_ICMPLT: {
      i = new Branch::IntegerCompareLessThan();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIF_ICMPNE: {
      i = new Branch::IntegerCompareNotEqual();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIFEQ: {
      i = new Branch::EqualZero();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIFGE: {
      i = new Branch::GreaterEqualZero();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIFGT: {
      i = new Branch::GreaterThanZero();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIFLE: {
      i = new Branch::LessEqualZero();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIFLT: {
      i = new Branch::LessThanZero();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIFNE: {
      i = new Branch::NotEqualZero();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIFNONNULL: {
      i = new Branch::NonNull();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIFNULL: {
      i = new Branch::RefNull();
      auto args = i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kIINC: {
      i = new Integer::Inc();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kILOAD: {
      i = new Integer::Load();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kILOAD_0: {
      i = new Integer::Load_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kILOAD_1: {
      i = new Integer::Load_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kILOAD_2: {
      i = new Integer::Load_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kILOAD_3: {
      i = new Integer::Load_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIMPDEP1:
    case Opcodes::kIMPDEP2:
      throw Utils::Errors::Exception(
          Utils::Errors::kINSTRUCTION,
          Opcodes::getMnemonic(opcode) +
              " should not appear in any class file");
      break;
    case Opcodes::kIMUL: {
      i = new Integer::Mul();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kINEG: {
      i = new Integer::Neg();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kINSTANCEOF: {
      i = new Misc::InstanceOf();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kINVOKEDYNAMIC: {
      i = new Invokes::Dynamic();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kINVOKEINTERFACE: {
      i = new Invokes::Interface();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << "> count " << args[1]
      //  << "\n";
      break;
    }
    case Opcodes::kINVOKESPECIAL: {
      i = new Invokes::Especial();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kINVOKESTATIC: {
      i = new Invokes::Static();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kINVOKEVIRTUAL: {
      i = new Invokes::Virtual();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kIOR: {
      i = new Integer::Or();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIREM: {
      i = new Integer::Rem();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIRETURN: {
      i = new Integer::Return();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kISHL: {
      i = new Integer::ShiftLeft();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kISHR: {
      i = new Integer::ArithmeticShiftRight();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kISTORE: {
      i = new Integer::Store();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kISTORE_0: {
      i = new Integer::Store_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kISTORE_1: {
      i = new Integer::Store_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kISTORE_2: {
      i = new Integer::Store_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kISTORE_3: {
      i = new Integer::Store_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kISUB: {
      i = new Integer::Sub();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIUSHR: {
      i = new Integer::LogicalShiftRight();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kIXOR: {
      i = new Integer::Xor();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kJSR: {
      i = new Jump::JumpSubRoutine();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kJSR_W: {
      i = new Jump::JumpSubRoutineWide();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kL2D: {
      i = new Long::ToDouble();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kL2F: {
      i = new Long::ToFloat();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kL2I: {
      i = new Long::ToInteger();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLADD: {
      i = new Long::Add();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLALOAD: {
      i = new Long::LoadFromArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLAND: {
      i = new Long::And();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLASTORE: {
      i = new Long::StoreIntoArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLCMP: {
      i = new Long::Compare();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLCONST_0: {
      i = new Long::Const_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLCONST_1: {
      i = new Long::Const_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLDC: {
      i = new ConstantPool::LoadCat1();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kLDC_W: {
      i = new ConstantPool::LoadCat1Wide();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kLDC2_W: {
      i = new ConstantPool::LoadCat2();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kLDIV: {
      i = new Long::Div();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLLOAD: {
      i = new Long::Load();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLLOAD_0: {
      i = new Long::Load_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLLOAD_1: {
      i = new Long::Load_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLLOAD_2: {
      i = new Long::Load_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLLOAD_3: {
      i = new Long::Load_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLMUL: {
      i = new Long::Mul();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLNEG: {
      i = new Long::Neg();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLOOKUPSWITCH: {
      i = new Misc::LookupSwitch();
      i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kLOR: {
      i = new Long::Or();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLREM: {
      i = new Long::Rem();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLRETURN: {
      i = new Long::Return();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLSHL: {
      i = new Long::ShiftLeft();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLSHR: {
      i = new Long::ArithmeticShiftRight();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLSTORE: {
      i = new Long::Store();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLSTORE_0: {
      i = new Long::Store_0();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLSTORE_1: {
      i = new Long::Store_1();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLSTORE_2: {
      i = new Long::Store_2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLSTORE_3: {
      i = new Long::Store_3();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLSUB: {
      i = new Long::Sub();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLUSHR: {
      i = new Long::LogicalShiftRight();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kLXOR: {
      i = new Long::Xor();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kMONITORENTER: {
      i = new Monitor::Enter();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kMONITOREXIT: {
      i = new Monitor::Exit();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kMULTIANEWARRAY: {
      i = new Misc::MultiDimArray();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kNEW: {
      i = new Misc::New();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0], false) << ">\n";
      break;
    }
    case Opcodes::kNEWARRAY: {
      i = new Misc::NewArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kNOP: {
      i = new Misc::Nop();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kPOP: {
      i = new Misc::Pop();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kPOP2: {
      i = new Misc::Pop2();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kPUTFIELD: {
      i = new Misc::PutField();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kPUTSTATIC: {
      i = new Misc::PutStatic();
      auto args = i->execute(code_it, &pc_increment, wide);
      //   ss << "<" << v->getConstantPoolInfo(args[0]) << ">\n";
      break;
    }
    case Opcodes::kRET: {
      i = new Misc::Ret();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kRETURN: {
      i = new Misc::Return();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kSALOAD: {
      i = new Short::LoadFromArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kSASTORE: {
      i = new Short::StoreIntoArray();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kSIPUSH: {
      i = new Short::Push();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kSWAP: {
      i = new Misc::Swap();
      i->execute(code_it, &pc_increment, wide);
      break;
    }
    case Opcodes::kTABLESWITCH: {
      i = new Misc::TableSwitch();
      i->execute(code_it, &pc_increment, wide, pc);
      break;
    }
    case Opcodes::kWIDE: {
      i = new Misc::Wide();
      i->execute(code_it, &pc_increment, wide);
      runBytecode(&++*code_it, th, &++*pc, true);
      break;
    }
  }
  if (i) delete i;
  *pc += (wide ? 0 : 1) + pc_increment;

  return false;
}
}  // namespace Instructions
