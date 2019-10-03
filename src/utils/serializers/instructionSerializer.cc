#include "utils/serializers/instructionSerializer.h"

#include "instructions/instructions_set/base.h"
#include "instructions/instructions_set/branch.h"
#include "instructions/instructions_set/byte.h"
#include "instructions/instructions_set/char.h"
#include "instructions/instructions_set/constant_pool.h"
#include "instructions/instructions_set/double.h"
#include "instructions/instructions_set/float.h"
#include "instructions/instructions_set/integer.h"
#include "instructions/instructions_set/invokes.h"
#include "instructions/instructions_set/jump.h"
#include "instructions/instructions_set/long.h"
#include "instructions/instructions_set/misc.h"
#include "instructions/instructions_set/monitor.h"
#include "instructions/instructions_set/reference.h"
#include "instructions/instructions_set/short.h"
#include "instructions/opcodes.h"
#include "utils/nlohmann_json.hpp"
#include "utils/utf8.h"

namespace Instructions {
int InstructionSerializer::to_json(
    json *j, std::vector<Utils::Types::u1>::iterator *code_it,
    const bool &wide) {
  auto opcode = **code_it;
  auto delta_code = 0;
  auto kpool_index = -1;
  Instruction *i = nullptr;
  switch (opcode) {
    case Opcodes::kAALOAD: {
      i = new Reference::LoadFromArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kAASTORE: {
      i = new Reference::StoreIntoArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kACONST_NULL: {
      i = new Reference::ConstNull();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kALOAD: {
      i = new Reference::Load();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kALOAD_0: {
      i = new Reference::Load_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kALOAD_1: {
      i = new Reference::Load_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kALOAD_2: {
      i = new Reference::Load_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kALOAD_3: {
      i = new Reference::Load_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kANEWARRAY: {
      i = new Reference::NewArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kARETURN: {
      i = new Reference::Return();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kARRAYLENGTH: {
      i = new Reference::ArrayLength();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kASTORE: {
      i = new Reference::Store();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kASTORE_0: {
      i = new Reference::Store_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kASTORE_1: {
      i = new Reference::Store_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kASTORE_2: {
      i = new Reference::Store_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kASTORE_3: {
      i = new Reference::Store_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kATHROW: {
      i = new Reference::Throw();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kBALOAD: {
      i = new Byte::LoadFromArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kBASTORE: {
      i = new Byte::StoreIntoArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kBIPUSH: {
      i = new Byte::Push();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kBREAKPOINT: {
      i = new Misc::Breakpoint();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kCALOAD: {
      i = new Char::LoadFromArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kCASTORE: {
      i = new Char::StoreIntoArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kCHECKCAST: {
      i = new Misc::Checkcast();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kD2F: {
      i = new Double::ToFloat();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kD2I: {
      i = new Double::ToInteger();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kD2L: {
      i = new Double::ToLong();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDADD: {
      i = new Double::Add();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDALOAD: {
      i = new Double::LoadFromArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDASTORE: {
      i = new Double::StoreIntoArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDCMPG: {
      i = new Double::CompareGreater();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDCMPL: {
      i = new Double::CompareLess();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDCONST_0: {
      i = new Double::Const_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDCONST_1: {
      i = new Double::Const_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDDIV: {
      i = new Double::Div();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDLOAD: {
      i = new Double::Load();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDLOAD_0: {
      i = new Double::Load_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDLOAD_1: {
      i = new Double::Load_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDLOAD_2: {
      i = new Double::Load_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDLOAD_3: {
      i = new Double::Load_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDMUL: {
      i = new Double::Mul();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDNEG: {
      i = new Double::Neg();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDREM: {
      i = new Double::Rem();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDRETURN: {
      i = new Double::Return();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDSTORE: {
      i = new Double::Store();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDSTORE_0: {
      i = new Double::Store_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDSTORE_1: {
      i = new Double::Store_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDSTORE_2: {
      i = new Double::Store_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDSTORE_3: {
      i = new Double::Store_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDSUB: {
      i = new Double::Sub();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDUP: {
      i = new Misc::Dup();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDUP_X1: {
      i = new Misc::DupX1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDUP_X2: {
      i = new Misc::DupX2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDUP2: {
      i = new Misc::Dup2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDUP2_X1: {
      i = new Misc::Dup2X1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kDUP2_X2: {
      i = new Misc::Dup2X2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kF2D: {
      i = new Float::ToDouble();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kF2I: {
      i = new Float::ToInteger();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kF2L: {
      i = new Float::ToLong();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFADD: {
      i = new Float::Add();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFALOAD: {
      i = new Float::LoadFromArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFASTORE: {
      i = new Float::StoreIntoArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFCMPG: {
      i = new Float::CompareGreater();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFCMPL: {
      i = new Float::CompareLess();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFCONST_0: {
      i = new Float::Const_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFCONST_1: {
      i = new Float::Const_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFCONST_2: {
      i = new Float::Const_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFDIV: {
      i = new Float::Div();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFLOAD: {
      i = new Float::Load();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFLOAD_0: {
      i = new Float::Load_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFLOAD_1: {
      i = new Float::Load_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFLOAD_2: {
      i = new Float::Load_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFLOAD_3: {
      i = new Float::Load_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFMUL: {
      i = new Float::Mul();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFNEG: {
      i = new Float::Neg();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFREM: {
      i = new Float::Rem();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFRETURN: {
      i = new Float::Return();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFSTORE: {
      i = new Float::Store();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFSTORE_0: {
      i = new Float::Store_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFSTORE_1: {
      i = new Float::Store_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFSTORE_2: {
      i = new Float::Store_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFSTORE_3: {
      i = new Float::Store_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kFSUB: {
      i = new Float::Sub();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kGETFIELD: {
      i = new Misc::GetField();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kGETSTATIC: {
      i = new Misc::GetStatic();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kGOTO: {
      i = new Misc::Goto();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kGOTO_W: {
      i = new Misc::GotoWide();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kI2B: {
      i = new Integer::ToByte();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kI2C: {
      i = new Integer::ToChar();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kI2D: {
      i = new Integer::ToDouble();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kI2F: {
      i = new Integer::ToFloat();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kI2L: {
      i = new Integer::ToLong();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kI2S: {
      i = new Integer::ToShort();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIADD: {
      i = new Integer::Add();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIALOAD: {
      i = new Integer::LoadFromArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIAND: {
      i = new Integer::And();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIASTORE: {
      i = new Integer::StoreIntoArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    // case Opcodes::kICONST_M1: {
    //   i = new Reference::LoadFromArray();
    //   i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
    //   break;
    // }
    case Opcodes::kICONST_0: {
      i = new Integer::Const_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kICONST_1: {
      i = new Integer::Const_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kICONST_2: {
      i = new Integer::Const_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kICONST_3: {
      i = new Integer::Const_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kICONST_4: {
      i = new Integer::Const_4();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kICONST_5: {
      i = new Integer::Const_5();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIDIV: {
      i = new Integer::Div();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIF_ACMPEQ: {
      i = new Branch::RefCompareEqual();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIF_ACMPNE: {
      i = new Branch::RefCompareNotEqual();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIF_ICMPEQ: {
      i = new Branch::IntegerCompareEqual();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIF_ICMPGE: {
      i = new Branch::IntegerCompareGreaterEqual();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIF_ICMPGT: {
      i = new Branch::IntegerCompareGreaterThan();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIF_ICMPLE: {
      i = new Branch::IntegerCompareLessEqual();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIF_ICMPLT: {
      i = new Branch::IntegerCompareLessThan();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIF_ICMPNE: {
      i = new Branch::IntegerCompareNotEqual();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIFEQ: {
      i = new Branch::EqualZero();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIFGE: {
      i = new Branch::GreaterEqualZero();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIFGT: {
      i = new Branch::GreaterThanZero();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIFLE: {
      i = new Branch::LessEqualZero();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIFLT: {
      i = new Branch::LessThanZero();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIFNE: {
      i = new Branch::NotEqualZero();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIFNONNULL: {
      i = new Branch::NonNull();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIFNULL: {
      i = new Branch::RefNull();
      // auto offset =
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIINC: {
      i = new Integer::Inc();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kILOAD: {
      i = new Integer::Load();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kILOAD_0: {
      i = new Integer::Load_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kILOAD_1: {
      i = new Integer::Load_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kILOAD_2: {
      i = new Integer::Load_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kILOAD_3: {
      i = new Integer::Load_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    // case Opcodes::kIMPDEP1: {
    //   i = new Reference::LoadFromArray();
    //   i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
    //   break;
    // }
    // case Opcodes::kIMPDEP2: {
    //   i = new Reference::LoadFromArray();
    //   i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
    //   break;
    // }
    case Opcodes::kIMUL: {
      i = new Integer::Mul();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kINEG: {
      i = new Integer::Neg();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kINSTANCEOF: {
      i = new Misc::InstanceOf();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kINVOKEDYNAMIC: {
      i = new Invokes::Dynamic();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kINVOKEINTERFACE: {
      i = new Invokes::Interface();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kINVOKESPECIAL: {
      i = new Invokes::Especial();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kINVOKESTATIC: {
      i = new Invokes::Static();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kINVOKEVIRTUAL: {
      i = new Invokes::Virtual();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIOR: {
      i = new Integer::Or();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIREM: {
      i = new Integer::Rem();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIRETURN: {
      i = new Integer::Return();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kISHL: {
      i = new Integer::ShiftLeft();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kISHR: {
      i = new Integer::ArithmeticShiftRight();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kISTORE: {
      i = new Integer::Store();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kISTORE_0: {
      i = new Integer::Store_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kISTORE_1: {
      i = new Integer::Store_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kISTORE_2: {
      i = new Integer::Store_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kISTORE_3: {
      i = new Integer::Store_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kISUB: {
      i = new Integer::Sub();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIUSHR: {
      i = new Integer::LogicalShiftRight();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kIXOR: {
      i = new Integer::Xor();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kJSR: {
      i = new Jump::JumpSubRoutine();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kJSR_W: {
      i = new Jump::JumpSubRoutineWide();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kL2D: {
      i = new Long::ToDouble();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kL2F: {
      i = new Long::ToFloat();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kL2I: {
      i = new Long::ToInteger();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLADD: {
      i = new Long::Add();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLALOAD: {
      i = new Long::LoadFromArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLAND: {
      i = new Long::And();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLASTORE: {
      i = new Long::StoreIntoArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLCMP: {
      i = new Long::Compare();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLCONST_0: {
      i = new Long::Const_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLCONST_1: {
      i = new Long::Const_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLDC: {
      i = new ConstantPool::LoadCat1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLDC_W: {
      i = new ConstantPool::LoadCat1Wide();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLDC2_W: {
      i = new ConstantPool::LoadCat2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLDIV: {
      i = new Long::Div();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLLOAD: {
      i = new Long::Load();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLLOAD_0: {
      i = new Long::Load_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLLOAD_1: {
      i = new Long::Load_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLLOAD_2: {
      i = new Long::Load_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLLOAD_3: {
      i = new Long::Load_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLMUL: {
      i = new Long::Mul();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLNEG: {
      i = new Long::Neg();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLOOKUPSWITCH: {
      i = new Misc::LookupSwitch();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLOR: {
      i = new Long::Or();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLREM: {
      i = new Long::Rem();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLRETURN: {
      i = new Long::Return();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLSHL: {
      i = new Long::ShiftLeft();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLSHR: {
      i = new Long::ArithmeticShiftRight();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLSTORE: {
      i = new Long::Store();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLSTORE_0: {
      i = new Long::Store_0();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLSTORE_1: {
      i = new Long::Store_1();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLSTORE_2: {
      i = new Long::Store_2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLSTORE_3: {
      i = new Long::Store_3();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLSUB: {
      i = new Long::Sub();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLUSHR: {
      i = new Long::LogicalShiftRight();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kLXOR: {
      i = new Long::Xor();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kMONITORENTER: {
      i = new Monitor::Enter();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kMONITOREXIT: {
      i = new Monitor::Exit();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kMULTIANEWARRAY: {
      i = new Misc::MultiDimArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kNEW: {
      i = new Misc::New();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kNEWARRAY: {
      i = new Misc::NewArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kNOP: {
      i = new Misc::Nop();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kPOP: {
      i = new Misc::Pop();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kPOP2: {
      i = new Misc::Pop2();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kPUTFIELD: {
      i = new Misc::PutField();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kPUTSTATIC: {
      i = new Misc::PutStatic();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kRET: {
      i = new Misc::Ret();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kRETURN: {
      i = new Misc::Return();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kSALOAD: {
      i = new Short::LoadFromArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kSASTORE: {
      i = new Short::StoreIntoArray();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kSIPUSH: {
      i = new Short::Push();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kSWAP: {
      i = new Misc::Swap();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kTABLESWITCH: {
      i = new Misc::TableSwitch();
      i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      break;
    }
    case Opcodes::kWIDE: {
      // i = new Misc::Wide();
      // i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      this->to_json(j, code_it, true);
      break;
    }
  }
  if (i) delete i;
  return 1 + delta_code;
}
}  // namespace Instructions