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
#include "utils/nlohmann_json.hpp"
#include "utils/utf8.h"

namespace Instructions {
int InstructionSerializer::to_json(
    json *j, std::vector<Utils::Types::u1>::iterator *code_it,
    const bool &wide) {
  return 0;
  // auto opcode = **code_it;
  // auto delta_code = 0;
  // auto kpool_index = -1;
  // Instruction *i = nullptr;
  // switch (opcode) {
  //   case Opcodes::kAALOAD: {
  //     i = new Reference::LoadFromArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kAASTORE: {
  //     i = new Reference::StoreIntoArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kACONST_NULL: {
  //     i = new Reference::ConstNull(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kALOAD: {
  //     i = new Reference::Load(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kALOAD_0: {
  //     i = new Reference::Load_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kALOAD_1: {
  //     i = new Reference::Load_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kALOAD_2: {
  //     i = new Reference::Load_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kALOAD_3: {
  //     i = new Reference::Load_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kANEWARRAY: {
  //     i = new Reference::NewArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kARETURN: {
  //     i = new Reference::Return(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kARRAYLENGTH: {
  //     i = new Reference::ArrayLength(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kASTORE: {
  //     i = new Reference::Store(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kASTORE_0: {
  //     i = new Reference::Store_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kASTORE_1: {
  //     i = new Reference::Store_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kASTORE_2: {
  //     i = new Reference::Store_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kASTORE_3: {
  //     i = new Reference::Store_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kATHROW: {
  //     i = new Reference::Throw(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kBALOAD: {
  //     i = new Byte::LoadFromArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kBASTORE: {
  //     i = new Byte::StoreIntoArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kBIPUSH: {
  //     i = new Byte::Push(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kBREAKPOINT: {
  //     i = new Misc::Breakpoint(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kCALOAD: {
  //     i = new Char::LoadFromArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kCASTORE: {
  //     i = new Char::StoreIntoArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kCHECKCAST: {
  //     i = new Misc::Checkcast(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kD2F: {
  //     i = new Double::ToFloat(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kD2I: {
  //     i = new Double::ToInteger(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kD2L: {
  //     i = new Double::ToLong(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDADD: {
  //     i = new Double::Add(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDALOAD: {
  //     i = new Double::LoadFromArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDASTORE: {
  //     i = new Double::StoreIntoArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDCMPG: {
  //     i = new Double::CompareGreater(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDCMPL: {
  //     i = new Double::CompareLess(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDCONST_0: {
  //     i = new Double::Const_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDCONST_1: {
  //     i = new Double::Const_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDDIV: {
  //     i = new Double::Div(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDLOAD: {
  //     i = new Double::Load(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDLOAD_0: {
  //     i = new Double::Load_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDLOAD_1: {
  //     i = new Double::Load_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDLOAD_2: {
  //     i = new Double::Load_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDLOAD_3: {
  //     i = new Double::Load_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDMUL: {
  //     i = new Double::Mul(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDNEG: {
  //     i = new Double::Neg(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDREM: {
  //     i = new Double::Rem(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDRETURN: {
  //     i = new Double::Return(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDSTORE: {
  //     i = new Double::Store(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDSTORE_0: {
  //     i = new Double::Store_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDSTORE_1: {
  //     i = new Double::Store_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDSTORE_2: {
  //     i = new Double::Store_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDSTORE_3: {
  //     i = new Double::Store_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDSUB: {
  //     i = new Double::Sub(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDUP: {
  //     i = new Misc::Dup(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDUP_X1: {
  //     i = new Misc::DupX1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDUP_X2: {
  //     i = new Misc::DupX2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDUP2: {
  //     i = new Misc::Dup2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDUP2_X1: {
  //     i = new Misc::Dup2X1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kDUP2_X2: {
  //     i = new Misc::Dup2X2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kF2D: {
  //     i = new Float::ToDouble(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kF2I: {
  //     i = new Float::ToInteger(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kF2L: {
  //     i = new Float::ToLong(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFADD: {
  //     i = new Float::Add(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFALOAD: {
  //     i = new Float::LoadFromArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFASTORE: {
  //     i = new Float::StoreIntoArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFCMPG: {
  //     i = new Float::CompareGreater(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFCMPL: {
  //     i = new Float::CompareLess(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFCONST_0: {
  //     i = new Float::Const_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFCONST_1: {
  //     i = new Float::Const_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFCONST_2: {
  //     i = new Float::Const_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFDIV: {
  //     i = new Float::Div(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFLOAD: {
  //     i = new Float::Load(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFLOAD_0: {
  //     i = new Float::Load_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFLOAD_1: {
  //     i = new Float::Load_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFLOAD_2: {
  //     i = new Float::Load_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFLOAD_3: {
  //     i = new Float::Load_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFMUL: {
  //     i = new Float::Mul(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFNEG: {
  //     i = new Float::Neg(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFREM: {
  //     i = new Float::Rem(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFRETURN: {
  //     i = new Float::Return(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFSTORE: {
  //     i = new Float::Store(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFSTORE_0: {
  //     i = new Float::Store_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFSTORE_1: {
  //     i = new Float::Store_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFSTORE_2: {
  //     i = new Float::Store_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFSTORE_3: {
  //     i = new Float::Store_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kFSUB: {
  //     i = new Float::Sub(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kGETFIELD: {
  //     i = new Misc::GetField(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kGETSTATIC: {
  //     i = new Misc::GetStatic(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kGOTO: {
  //     i = new Misc::Goto(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kGOTO_W: {
  //     i = new Misc::GotoWide(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kI2B: {
  //     i = new Integer::ToByte(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kI2C: {
  //     i = new Integer::ToChar(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kI2D: {
  //     i = new Integer::ToDouble(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kI2F: {
  //     i = new Integer::ToFloat(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kI2L: {
  //     i = new Integer::ToLong(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kI2S: {
  //     i = new Integer::ToShort(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIADD: {
  //     i = new Integer::Add(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIALOAD: {
  //     i = new Integer::LoadFromArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIAND: {
  //     i = new Integer::And(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIASTORE: {
  //     i = new Integer::StoreIntoArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kICONST_M1: {
  //     i = new Integer::Const_m1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kICONST_0: {
  //     i = new Integer::Const_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kICONST_1: {
  //     i = new Integer::Const_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kICONST_2: {
  //     i = new Integer::Const_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kICONST_3: {
  //     i = new Integer::Const_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kICONST_4: {
  //     i = new Integer::Const_4(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kICONST_5: {
  //     i = new Integer::Const_5(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIDIV: {
  //     i = new Integer::Div(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIF_ACMPEQ: {
  //     i = new Branch::RefCompareEqual(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIF_ACMPNE: {
  //     i = new Branch::RefCompareNotEqual(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIF_ICMPEQ: {
  //     i = new Branch::IntegerCompareEqual(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIF_ICMPGE: {
  //     i = new Branch::IntegerCompareGreaterEqual(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIF_ICMPGT: {
  //     i = new Branch::IntegerCompareGreaterThan(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIF_ICMPLE: {
  //     i = new Branch::IntegerCompareLessEqual(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIF_ICMPLT: {
  //     i = new Branch::IntegerCompareLessThan(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIF_ICMPNE: {
  //     i = new Branch::IntegerCompareNotEqual(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIFEQ: {
  //     i = new Branch::EqualZero(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIFGE: {
  //     i = new Branch::GreaterEqualZero(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIFGT: {
  //     i = new Branch::GreaterThanZero(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIFLE: {
  //     i = new Branch::LessEqualZero(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIFLT: {
  //     i = new Branch::LessThanZero(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIFNE: {
  //     i = new Branch::NotEqualZero(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIFNONNULL: {
  //     i = new Branch::NonNull(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIFNULL: {
  //     i = new Branch::RefNull(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, nullptr, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIINC: {
  //     i = new Integer::Inc(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kILOAD: {
  //     i = new Integer::Load(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kILOAD_0: {
  //     i = new Integer::Load_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kILOAD_1: {
  //     i = new Integer::Load_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kILOAD_2: {
  //     i = new Integer::Load_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kILOAD_3: {
  //     i = new Integer::Load_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   // case Opcodes::kIMPDEP1: {
  //   //   i = new Reference::LoadFromArray(nullptr);
  //   //   auto intern_args = i->toBytecode_json(code_it, &delta_code,
  //   //   &kpool_index, wide);
  //   // *j = intern_args;
  //   //   break;
  //   // }
  //   // case Opcodes::kIMPDEP2: {
  //   //   i = new Reference::LoadFromArray(nullptr);
  //   //   auto intern_args = i->toBytecode_json(code_it, &delta_code,
  //   //   &kpool_index, wide);
  //   // *j = intern_args;
  //   //   break;
  //   // }
  //   case Opcodes::kIMUL: {
  //     i = new Integer::Mul(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kINEG: {
  //     i = new Integer::Neg(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kINSTANCEOF: {
  //     i = new Misc::InstanceOf(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kINVOKEDYNAMIC: {
  //     i = new Invokes::Dynamic(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kINVOKEINTERFACE: {
  //     i = new Invokes::Interface(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kINVOKESPECIAL: {
  //     i = new Invokes::Especial(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kINVOKESTATIC: {
  //     i = new Invokes::Static(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kINVOKEVIRTUAL: {
  //     i = new Invokes::Virtual(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kIOR: {
  //     i = new Integer::Or(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIREM: {
  //     i = new Integer::Rem(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIRETURN: {
  //     i = new Integer::Return(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kISHL: {
  //     i = new Integer::ShiftLeft(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kISHR: {
  //     i = new Integer::ArithmeticShiftRight(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kISTORE: {
  //     i = new Integer::Store(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kISTORE_0: {
  //     i = new Integer::Store_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kISTORE_1: {
  //     i = new Integer::Store_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kISTORE_2: {
  //     i = new Integer::Store_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kISTORE_3: {
  //     i = new Integer::Store_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kISUB: {
  //     i = new Integer::Sub(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIUSHR: {
  //     i = new Integer::LogicalShiftRight(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kIXOR: {
  //     i = new Integer::Xor(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kJSR: {
  //     i = new Jump::JumpSubRoutine(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kJSR_W: {
  //     i = new Jump::JumpSubRoutineWide(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kL2D: {
  //     i = new Long::ToDouble(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kL2F: {
  //     i = new Long::ToFloat(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kL2I: {
  //     i = new Long::ToInteger(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLADD: {
  //     i = new Long::Add(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLALOAD: {
  //     i = new Long::LoadFromArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLAND: {
  //     i = new Long::And(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLASTORE: {
  //     i = new Long::StoreIntoArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLCMP: {
  //     i = new Long::Compare(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLCONST_0: {
  //     i = new Long::Const_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLCONST_1: {
  //     i = new Long::Const_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLDC: {
  //     i = new ConstantPool::LoadCat1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kLDC_W: {
  //     i = new ConstantPool::LoadCat1Wide(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kLDC2_W: {
  //     i = new ConstantPool::LoadCat2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kLDIV: {
  //     i = new Long::Div(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLLOAD: {
  //     i = new Long::Load(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLLOAD_0: {
  //     i = new Long::Load_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLLOAD_1: {
  //     i = new Long::Load_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLLOAD_2: {
  //     i = new Long::Load_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLLOAD_3: {
  //     i = new Long::Load_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLMUL: {
  //     i = new Long::Mul(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLNEG: {
  //     i = new Long::Neg(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLOOKUPSWITCH: {
  //     i = new Misc::LookupSwitch(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLOR: {
  //     i = new Long::Or(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLREM: {
  //     i = new Long::Rem(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLRETURN: {
  //     i = new Long::Return(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLSHL: {
  //     i = new Long::ShiftLeft(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLSHR: {
  //     i = new Long::ArithmeticShiftRight(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLSTORE: {
  //     i = new Long::Store(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLSTORE_0: {
  //     i = new Long::Store_0(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLSTORE_1: {
  //     i = new Long::Store_1(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLSTORE_2: {
  //     i = new Long::Store_2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLSTORE_3: {
  //     i = new Long::Store_3(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLSUB: {
  //     i = new Long::Sub(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLUSHR: {
  //     i = new Long::LogicalShiftRight(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kLXOR: {
  //     i = new Long::Xor(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kMONITORENTER: {
  //     i = new Monitor::Enter(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kMONITOREXIT: {
  //     i = new Monitor::Exit(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kMULTIANEWARRAY: {
  //     i = new Misc::MultiDimArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kNEW: {
  //     i = new Misc::New(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kNEWARRAY: {
  //     i = new Misc::NewArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kNOP: {
  //     i = new Misc::Nop(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kPOP: {
  //     i = new Misc::Pop(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kPOP2: {
  //     i = new Misc::Pop2(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kPUTFIELD: {
  //     i = new Misc::PutField(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kPUTSTATIC: {
  //     i = new Misc::PutStatic(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     this->kpool_serializer->to_json(&(*j)[intern_args.size()],
  //                                     kpool_index - 1);
  //     break;
  //   }
  //   case Opcodes::kRET: {
  //     i = new Misc::Ret(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kRETURN: {
  //     i = new Misc::Return(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kSALOAD: {
  //     i = new Short::LoadFromArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kSASTORE: {
  //     i = new Short::StoreIntoArray(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kSIPUSH: {
  //     i = new Short::Push(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kSWAP: {
  //     i = new Misc::Swap(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kTABLESWITCH: {
  //     i = new Misc::TableSwitch(nullptr);
  //     auto intern_args =
  //         i->toBytecode_json(code_it, &delta_code, &kpool_index, wide);
  //     *j = intern_args;
  //     break;
  //   }
  //   case Opcodes::kWIDE: {
  //     // i = new Misc::Wide(nullptr);
  //     // auto intern_args = i->toBytecode_json(code_it, &delta_code,
  //     // &kpool_index, wide); *j = intern_args;
  //     this->to_json(j, code_it, true);
  //     break;
  //   }
  // }
  // if (i) delete i;
  // return 1 + delta_code;
}
}  // namespace Instructions
