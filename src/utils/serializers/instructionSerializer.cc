#include "utils/serializers/instructionSerializer.h"

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
#include "utils/external/nlohmann_json.hpp"
#include "utils/utf8.h"

namespace Instructions {
int InstructionSerializer::to_json(
    json *j, std::vector<Utils::Types::u1>::iterator *code_it, int *code_index,
    const bool &wide) {
  auto opcode = **code_it;
  auto delta_code = 0;
  auto kpool_index = -1;
  Instruction *i = nullptr;
  switch (opcode) {
    case Opcodes::kAALOAD: {
      i = new Reference::LoadFromArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kAASTORE: {
      i = new Reference::StoreIntoArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kACONST_NULL: {
      i = new Reference::ConstNull();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kALOAD: {
      i = new Reference::Load();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kALOAD_0: {
      i = new Reference::Load_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kALOAD_1: {
      i = new Reference::Load_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kALOAD_2: {
      i = new Reference::Load_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kALOAD_3: {
      i = new Reference::Load_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kANEWARRAY: {
      i = new Reference::NewArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kARETURN: {
      i = new Reference::Return();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kARRAYLENGTH: {
      i = new Reference::ArrayLength();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kASTORE: {
      i = new Reference::Store();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kASTORE_0: {
      i = new Reference::Store_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kASTORE_1: {
      i = new Reference::Store_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kASTORE_2: {
      i = new Reference::Store_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kASTORE_3: {
      i = new Reference::Store_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kATHROW: {
      i = new Reference::Throw();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kBALOAD: {
      i = new Byte::LoadFromArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kBASTORE: {
      i = new Byte::StoreIntoArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kBIPUSH: {
      i = new Byte::Push();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
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
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kCASTORE: {
      i = new Char::StoreIntoArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kCHECKCAST: {
      i = new Misc::Checkcast();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kD2F: {
      i = new Double::ToFloat();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kD2I: {
      i = new Double::ToInteger();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kD2L: {
      i = new Double::ToLong();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDADD: {
      i = new Double::Add();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDALOAD: {
      i = new Double::LoadFromArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDASTORE: {
      i = new Double::StoreIntoArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDCMPG: {
      i = new Double::CompareGreater();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDCMPL: {
      i = new Double::CompareLess();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDCONST_0: {
      i = new Double::Const_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDCONST_1: {
      i = new Double::Const_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDDIV: {
      i = new Double::Div();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDLOAD: {
      i = new Double::Load();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDLOAD_0: {
      i = new Double::Load_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDLOAD_1: {
      i = new Double::Load_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDLOAD_2: {
      i = new Double::Load_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDLOAD_3: {
      i = new Double::Load_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDMUL: {
      i = new Double::Mul();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDNEG: {
      i = new Double::Neg();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDREM: {
      i = new Double::Rem();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDRETURN: {
      i = new Double::Return();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDSTORE: {
      i = new Double::Store();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDSTORE_0: {
      i = new Double::Store_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDSTORE_1: {
      i = new Double::Store_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDSTORE_2: {
      i = new Double::Store_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDSTORE_3: {
      i = new Double::Store_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDSUB: {
      i = new Double::Sub();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDUP: {
      i = new Misc::Dup();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDUP_X1: {
      i = new Misc::DupX1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDUP_X2: {
      i = new Misc::DupX2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDUP2: {
      i = new Misc::Dup2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDUP2_X1: {
      i = new Misc::Dup2X1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kDUP2_X2: {
      i = new Misc::Dup2X2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kF2D: {
      i = new Float::ToDouble();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kF2I: {
      i = new Float::ToInteger();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kF2L: {
      i = new Float::ToLong();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFADD: {
      i = new Float::Add();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFALOAD: {
      i = new Float::LoadFromArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFASTORE: {
      i = new Float::StoreIntoArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFCMPG: {
      i = new Float::CompareGreater();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFCMPL: {
      i = new Float::CompareLess();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFCONST_0: {
      i = new Float::Const_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFCONST_1: {
      i = new Float::Const_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFCONST_2: {
      i = new Float::Const_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFDIV: {
      i = new Float::Div();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFLOAD: {
      i = new Float::Load();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFLOAD_0: {
      i = new Float::Load_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFLOAD_1: {
      i = new Float::Load_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFLOAD_2: {
      i = new Float::Load_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFLOAD_3: {
      i = new Float::Load_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFMUL: {
      i = new Float::Mul();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFNEG: {
      i = new Float::Neg();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFREM: {
      i = new Float::Rem();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFRETURN: {
      i = new Float::Return();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFSTORE: {
      i = new Float::Store();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFSTORE_0: {
      i = new Float::Store_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFSTORE_1: {
      i = new Float::Store_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFSTORE_2: {
      i = new Float::Store_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFSTORE_3: {
      i = new Float::Store_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kFSUB: {
      i = new Float::Sub();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kGETFIELD: {
      i = new Misc::GetField();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kGETSTATIC: {
      i = new Misc::GetStatic();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kGOTO: {
      i = new Misc::Goto();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kGOTO_W: {
      i = new Misc::GotoWide();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kI2B: {
      i = new Integer::ToByte();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kI2C: {
      i = new Integer::ToChar();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kI2D: {
      i = new Integer::ToDouble();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kI2F: {
      i = new Integer::ToFloat();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kI2L: {
      i = new Integer::ToLong();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kI2S: {
      i = new Integer::ToShort();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIADD: {
      i = new Integer::Add();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIALOAD: {
      i = new Integer::LoadFromArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIAND: {
      i = new Integer::And();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIASTORE: {
      i = new Integer::StoreIntoArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kICONST_M1: {
      i = new Integer::Const_m1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kICONST_0: {
      i = new Integer::Const_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kICONST_1: {
      i = new Integer::Const_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kICONST_2: {
      i = new Integer::Const_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kICONST_3: {
      i = new Integer::Const_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kICONST_4: {
      i = new Integer::Const_4();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kICONST_5: {
      i = new Integer::Const_5();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIDIV: {
      i = new Integer::Div();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIF_ACMPEQ: {
      i = new Branch::RefCompareEqual();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIF_ACMPNE: {
      i = new Branch::RefCompareNotEqual();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIF_ICMPEQ: {
      i = new Branch::IntegerCompareEqual();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIF_ICMPGE: {
      i = new Branch::IntegerCompareGreaterEqual();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIF_ICMPGT: {
      i = new Branch::IntegerCompareGreaterThan();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIF_ICMPLE: {
      i = new Branch::IntegerCompareLessEqual();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIF_ICMPLT: {
      i = new Branch::IntegerCompareLessThan();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIF_ICMPNE: {
      i = new Branch::IntegerCompareNotEqual();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIFEQ: {
      i = new Branch::EqualZero();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIFGE: {
      i = new Branch::GreaterEqualZero();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIFGT: {
      i = new Branch::GreaterThanZero();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIFLE: {
      i = new Branch::LessEqualZero();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIFLT: {
      i = new Branch::LessThanZero();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIFNE: {
      i = new Branch::NotEqualZero();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIFNONNULL: {
      i = new Branch::NonNull();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIFNULL: {
      i = new Branch::RefNull();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, nullptr, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIINC: {
      i = new Integer::Inc();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kILOAD: {
      i = new Integer::Load();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kILOAD_0: {
      i = new Integer::Load_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kILOAD_1: {
      i = new Integer::Load_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kILOAD_2: {
      i = new Integer::Load_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kILOAD_3: {
      i = new Integer::Load_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
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
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kINEG: {
      i = new Integer::Neg();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kINSTANCEOF: {
      i = new Misc::InstanceOf();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kINVOKEDYNAMIC: {
      i = new Invokes::Dynamic();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kINVOKEINTERFACE: {
      i = new Invokes::Interface();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kINVOKESPECIAL: {
      i = new Invokes::Especial();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kINVOKESTATIC: {
      i = new Invokes::Static();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kINVOKEVIRTUAL: {
      i = new Invokes::Virtual();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kIOR: {
      i = new Integer::Or();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIREM: {
      i = new Integer::Rem();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIRETURN: {
      i = new Integer::Return();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kISHL: {
      i = new Integer::ShiftLeft();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kISHR: {
      i = new Integer::ArithmeticShiftRight();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kISTORE: {
      i = new Integer::Store();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kISTORE_0: {
      i = new Integer::Store_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kISTORE_1: {
      i = new Integer::Store_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kISTORE_2: {
      i = new Integer::Store_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kISTORE_3: {
      i = new Integer::Store_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kISUB: {
      i = new Integer::Sub();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIUSHR: {
      i = new Integer::LogicalShiftRight();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kIXOR: {
      i = new Integer::Xor();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kJSR: {
      i = new Jump::JumpSubRoutine();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kJSR_W: {
      i = new Jump::JumpSubRoutineWide();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kL2D: {
      i = new Long::ToDouble();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kL2F: {
      i = new Long::ToFloat();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kL2I: {
      i = new Long::ToInteger();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLADD: {
      i = new Long::Add();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLALOAD: {
      i = new Long::LoadFromArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLAND: {
      i = new Long::And();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLASTORE: {
      i = new Long::StoreIntoArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLCMP: {
      i = new Long::Compare();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLCONST_0: {
      i = new Long::Const_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLCONST_1: {
      i = new Long::Const_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLDC: {
      i = new ConstantPool::LoadCat1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kLDC_W: {
      i = new ConstantPool::LoadCat1Wide();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kLDC2_W: {
      i = new ConstantPool::LoadCat2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kLDIV: {
      i = new Long::Div();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLLOAD: {
      i = new Long::Load();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLLOAD_0: {
      i = new Long::Load_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLLOAD_1: {
      i = new Long::Load_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLLOAD_2: {
      i = new Long::Load_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLLOAD_3: {
      i = new Long::Load_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLMUL: {
      i = new Long::Mul();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLNEG: {
      i = new Long::Neg();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLOOKUPSWITCH: {
      i = new Misc::LookupSwitch();
      auto intern_args = i->toBytecode_json(code_it, &delta_code, &kpool_index,
                                            wide, code_index);
      *j = intern_args;
      break;
    }
    case Opcodes::kLOR: {
      i = new Long::Or();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLREM: {
      i = new Long::Rem();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLRETURN: {
      i = new Long::Return();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLSHL: {
      i = new Long::ShiftLeft();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLSHR: {
      i = new Long::ArithmeticShiftRight();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLSTORE: {
      i = new Long::Store();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLSTORE_0: {
      i = new Long::Store_0();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLSTORE_1: {
      i = new Long::Store_1();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLSTORE_2: {
      i = new Long::Store_2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLSTORE_3: {
      i = new Long::Store_3();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLSUB: {
      i = new Long::Sub();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLUSHR: {
      i = new Long::LogicalShiftRight();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kLXOR: {
      i = new Long::Xor();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kMONITORENTER: {
      i = new Monitor::Enter();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kMONITOREXIT: {
      i = new Monitor::Exit();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kMULTIANEWARRAY: {
      i = new Misc::MultiDimArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kNEW: {
      i = new Misc::New();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kNEWARRAY: {
      i = new Misc::NewArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kNOP: {
      i = new Misc::Nop();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kPOP: {
      i = new Misc::Pop();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kPOP2: {
      i = new Misc::Pop2();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kPUTFIELD: {
      i = new Misc::PutField();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kPUTSTATIC: {
      i = new Misc::PutStatic();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      this->kpool_serializer->to_json(&(*j)[intern_args.size()],
                                      kpool_index - 1);
      break;
    }
    case Opcodes::kRET: {
      i = new Misc::Ret();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kRETURN: {
      i = new Misc::Return();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kSALOAD: {
      i = new Short::LoadFromArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kSASTORE: {
      i = new Short::StoreIntoArray();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kSIPUSH: {
      i = new Short::Push();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kSWAP: {
      i = new Misc::Swap();
      auto intern_args =
          i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
      *j = intern_args;
      break;
    }
    case Opcodes::kTABLESWITCH: {
      i = new Misc::TableSwitch();
      auto intern_args = i->toBytecode_json(code_it, &delta_code, &kpool_index,
                                            wide, code_index);
      *j = intern_args;
      break;
    }
    case Opcodes::kWIDE: {
      // i = new Misc::Wide();
      // auto intern_args = i->toBytecode_json(code_it, &delta_code,
      // &kpool_index, wide); *j = intern_args;
      this->to_json(j, code_it, &++*code_index, true);
      break;
    }
  }
  if (i) delete i;
  return 1 + delta_code;
}
}  // namespace Instructions
