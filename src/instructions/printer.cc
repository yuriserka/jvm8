#include "instructions/printer.h"

#include <iostream>
#include <map>
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
#include "utils/utf8.h"
#include "viewer.h"

namespace Instructions {
static int printAALOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::LoadFromArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printAASTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::StoreIntoArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printACONST_NULLByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::ConstNull();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printALOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Load();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printALOAD_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Load_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printALOAD_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Load_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printALOAD_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Load_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printALOAD_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Load_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printANEWARRAYByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::NewArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printARETURNByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Return();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printARRAYLENGTHByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::ArrayLength();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printASTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Store();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printASTORE_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Store_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printASTORE_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Store_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printASTORE_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Store_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printASTORE_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Store_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printATHROWByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Reference::Throw();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printBALOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Byte::LoadFromArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printBASTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Byte::StoreIntoArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printBIPUSHByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Byte::Push();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printBREAKPOINTByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Breakpoint();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printCALOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Char::LoadFromArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printCASTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Char::StoreIntoArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printCHECKCASTByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new  Misc::Checkcast();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printD2FByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::ToFloat();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printD2IByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::ToInteger();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printD2LByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::ToLong();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDADDByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Add();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDALOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::LoadFromArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDASTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::StoreIntoArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDCMPGByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::CompareGreater();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDCMPLByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::CompareLess();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDCONST_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Const_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDCONST_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Const_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDDIVByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Div();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDLOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Load();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDLOAD_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new  Double::Load_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDLOAD_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new  Double::Load_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDLOAD_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new  Double::Load_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDLOAD_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new  Double::Load_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDMULByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Mul();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDNEGByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Neg();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDREMByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Rem();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDRETURNByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Return();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDSTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Store();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDSTORE_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Store_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDSTORE_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Store_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDSTORE_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Store_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDSTORE_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Store_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDSUBByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Double::Sub();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDUPByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Dup();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDUP_X1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::DupX1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDUP_X2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::DupX2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDUP2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Dup2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDUP2_X1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Dup2X1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printDUP2_X2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Dup2X2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printF2DByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::ToDouble();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printF2IByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::ToInteger();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printF2LByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::ToLong();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFADDByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Add();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFALOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::LoadFromArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFASTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::StoreIntoArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFCMPGByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::CompareGreater();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFCMPLByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::CompareLess();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFCONST_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Const_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFCONST_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Const_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFCONST_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Const_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFDIVByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Div();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFLOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Load();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFLOAD_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Load_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFLOAD_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Load_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFLOAD_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Load_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFLOAD_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Load_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFMULByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Mul();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFNEGByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Neg();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFREMByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Rem();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFRETURNByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Return();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFSTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Store();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFSTORE_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Store_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFSTORE_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Store_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFSTORE_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Store_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFSTORE_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Store_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printFSUBByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Float::Sub();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printGETFIELDByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::GetField();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printGETSTATICByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::GetStatic();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printGOTOByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Goto();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printGOTO_WByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::GotoWide();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printI2BByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::ToByte();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printI2CByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::ToChar();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printI2DByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::ToDouble();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printI2FByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::ToFloat();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printI2LByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::ToLong();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printI2SByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::ToShort();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIADDByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Add();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIALOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::LoadFromArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIANDByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::And();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIASTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::StoreIntoArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

/**
 * Essa daqui tá errada, pq ainda não fiz a classe pra essa instruçõa...
 * 
 * */
static int printICONST_M1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  // Instruction *i = new Reference::LoadFromArray();
  int delta_code = 0;
  // i->toBytecode(code_it, &delta_code);
  // delete i;
  return 1 + delta_code;
}

static int printICONST_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Const_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printICONST_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Const_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printICONST_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Const_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printICONST_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Const_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printICONST_4ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Const_4();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printICONST_5ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Const_5();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIDIVByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Div();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIF_ACMPEQByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::RefCompareEqual();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIF_ACMPNEByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::RefCompareNotEqual();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIF_ICMPEQByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::IntegerCompareEqual();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIF_ICMPGEByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::IntegerCompareGreaterEqual();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIF_ICMPGTByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::IntegerCompareGreaterThan();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIF_ICMPLEByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::IntegerCompareLessEqual();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIF_ICMPLTByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::IntegerCompareLessThan();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIF_ICMPNEByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::IntegerCompareNotEqual();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIFEQByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::EqualZero();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIFGEByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::GreaterEqualZero();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIFGTByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::GreaterThanZero();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIFLEByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::LessEqualZero();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIFLTByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::LessThanZero();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIFNEByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::NotEqualZero();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIFNONNULLByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::NonNull();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIFNULLByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Branch::RefNull();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIINCByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Inc();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printILOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Load();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printILOAD_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Load_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printILOAD_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Load_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printILOAD_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Load_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printILOAD_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Load_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

/**
 * Essa daqui tá errada, pq ainda não fiz a classe pra essa instruçõa...
 * 
 * */
static int printIMPDEP1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  // Instruction *i = new Reference::LoadFromArray();
  int delta_code = 0;
  // i->toBytecode(code_it, &delta_code);
  // delete i;
  return 1 + delta_code;
}

/**
 * Essa daqui tá errada, pq ainda não fiz a classe pra essa instruçõa...
 * 
 * */
static int printIMPDEP2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  // Instruction *i = new Reference::LoadFromArray();
  int delta_code = 0;
  // i->toBytecode(code_it, &delta_code);
  // delete i;
  return 1 + delta_code;
}

static int printIMULByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Mul();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printINEGByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Neg();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printINSTANCEOFByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::InstanceOf();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printINVOKEDYNAMICByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Invokes::Dynamic();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printINVOKEINTERFACEByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Invokes::Interface();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printINVOKESPECIALByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Invokes::Especial();
  int delta_code = 0;
  auto kpool_index = i->toBytecode(code_it, &delta_code) - 1;
  std::wcout << "<" << v->getBytecodeOperandString(kpool_index).c_str() << ">\n";
  delete i;
  return 1 + delta_code;
}

static int printINVOKESTATICByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Invokes::Static();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printINVOKEVIRTUALByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Invokes::Virtual();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIORByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Or();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIREMByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Rem();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIRETURNByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Return();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printISHLByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::ShiftLeft();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printISHRByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::ArithmeticShiftRight();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printISTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Store();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printISTORE_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Store_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printISTORE_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Store_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printISTORE_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Store_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printISTORE_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Store_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printISUBByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Sub();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIUSHRByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::LogicalShiftRight();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printIXORByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Integer::Xor();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printJSRByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Jump::JumpSubRoutine();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printJSR_WByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Jump::JumpSubRoutineWide();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printL2DByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::ToDouble();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printL2FByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::ToFloat();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printL2IByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::ToInteger();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLADDByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Add();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLALOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::LoadFromArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLANDByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::And();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLASTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::StoreIntoArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLCMPByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Compare();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLCONST_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Const_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLCONST_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Const_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLDCByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new ConstantPool::LoadCat1();
  int delta_code = 0;
  auto kpool_index = i->toBytecode(code_it, &delta_code) - 1;
  std::wcout << "<" << v->getBytecodeOperandString(kpool_index).c_str() << ">\n";
  delete i;
  return 1 + delta_code;
}

static int printLDC_WByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new ConstantPool::LoadCat1Wide();
  int delta_code = 0;
  auto kpool_index = i->toBytecode(code_it, &delta_code) - 1;
  std::wcout << "<" << v->getBytecodeOperandString(kpool_index).c_str() << ">\n";
  delete i;
  return 1 + delta_code;
}

static int printLDC2_WByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new ConstantPool::LoadCat2();
  int delta_code = 0;
  auto kpool_index = i->toBytecode(code_it, &delta_code) - 1;
  std::wcout << "<" << v->getBytecodeOperandString(kpool_index).c_str() << ">\n";
  delete i;
  return 1 + delta_code;
}

static int printLDIVByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Div();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLLOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Load();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLLOAD_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Load_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLLOAD_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Load_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLLOAD_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Load_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLLOAD_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Load_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLMULByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Mul();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLNEGByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Neg();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLOOKUPSWITCHByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::LookupSwitch();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLORByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Or();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLREMByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Rem();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLRETURNByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Return();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLSHLByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::ShiftLeft();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLSHRByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::ArithmeticShiftRight();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLSTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::StoreIntoArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLSTORE_0ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Store_0();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLSTORE_1ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Store_1();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLSTORE_2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Store_2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLSTORE_3ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Store_3();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLSUBByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Sub();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLUSHRByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::LogicalShiftRight();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printLXORByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Long::Xor();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printMONITORENTERByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Monitor::Enter();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printMONITOREXITByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Monitor::Exit();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printMULTIANEWARRAYByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::MULTIANEWARRAY();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printNEWByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::New();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printNEWARRAYByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::NewArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printNOPByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Nop();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printPOPByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Pop();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printPOP2ByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Pop2();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printPUTFIELDByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::PutField();
  int delta_code = 0;
  auto kpool_index= i->toBytecode(code_it, &delta_code) - 1;
  std::wcout << "<" << v->getBytecodeOperandString(kpool_index).c_str() << ">\n";
  delete i;
  return 1 + delta_code;
}

static int printPUTSTATICByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::PutStatic();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printRETByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Ret();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printRETURNByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Return();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printSALOADByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Short::LoadFromArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printSASTOREByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Short::StoreIntoArray();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printSIPUSHByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Short::Push();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printSWAPByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Swap();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printTABLESWITCHByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::TableSwitch();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

static int printWIDEByteCode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  Instruction *i = new Misc::Wide();
  int delta_code = 0;
  i->toBytecode(code_it, &delta_code);
  delete i;
  return 1 + delta_code;
}

std::map<Utils::Types::u1, int (*)(std::vector<Utils::Types::u1>::iterator *, Viewer *)> op_func = {
  {Opcodes::kAALOAD, printAALOADByteCode},
  {Opcodes::kAASTORE, printAASTOREByteCode},
  {Opcodes::kACONST_NULL, printACONST_NULLByteCode},
  {Opcodes::kALOAD, printALOADByteCode},
  {Opcodes::kALOAD_0, printALOAD_0ByteCode},
  {Opcodes::kALOAD_1, printALOAD_1ByteCode},
  {Opcodes::kALOAD_2, printALOAD_2ByteCode},
  {Opcodes::kALOAD_3, printALOAD_3ByteCode},
  {Opcodes::kANEWARRAY, printANEWARRAYByteCode},
  {Opcodes::kARETURN, printARETURNByteCode},
  {Opcodes::kARRAYLENGTH, printARRAYLENGTHByteCode},
  {Opcodes::kASTORE, printASTOREByteCode},
  {Opcodes::kASTORE_0, printASTORE_0ByteCode},
  {Opcodes::kASTORE_1, printASTORE_1ByteCode},
  {Opcodes::kASTORE_2, printASTORE_2ByteCode},
  {Opcodes::kASTORE_3, printASTORE_3ByteCode},
  {Opcodes::kATHROW, printATHROWByteCode},
  {Opcodes::kBALOAD, printBALOADByteCode},
  {Opcodes::kBASTORE, printBASTOREByteCode},
  {Opcodes::kBIPUSH, printBIPUSHByteCode},
  {Opcodes::kBREAKPOINT, printBREAKPOINTByteCode},
  {Opcodes::kCALOAD, printCALOADByteCode},
  {Opcodes::kCASTORE, printCASTOREByteCode},
  {Opcodes::kCHECKCAST, printCHECKCASTByteCode},
  {Opcodes::kD2F, printD2FByteCode},
  {Opcodes::kD2I, printD2IByteCode},
  {Opcodes::kD2L, printD2LByteCode},
  {Opcodes::kDADD, printDADDByteCode},
  {Opcodes::kDALOAD, printDALOADByteCode},
  {Opcodes::kDASTORE, printDASTOREByteCode},
  {Opcodes::kDCMPG, printDCMPGByteCode},
  {Opcodes::kDCMPL, printDCMPLByteCode},
  {Opcodes::kDCONST_0, printDCONST_0ByteCode},
  {Opcodes::kDCONST_1, printDCONST_1ByteCode},
  {Opcodes::kDDIV, printDDIVByteCode},
  {Opcodes::kDLOAD, printDLOADByteCode},
  {Opcodes::kDLOAD_0, printDLOAD_0ByteCode},
  {Opcodes::kDLOAD_1, printDLOAD_1ByteCode},
  {Opcodes::kDLOAD_2, printDLOAD_2ByteCode},
  {Opcodes::kDLOAD_3, printDLOAD_3ByteCode},
  {Opcodes::kDMUL, printDMULByteCode},
  {Opcodes::kDNEG, printDNEGByteCode},
  {Opcodes::kDREM, printDREMByteCode},
  {Opcodes::kDRETURN, printDRETURNByteCode},
  {Opcodes::kDSTORE, printDSTOREByteCode},
  {Opcodes::kDSTORE_0, printDSTORE_0ByteCode},
  {Opcodes::kDSTORE_1, printDSTORE_1ByteCode},
  {Opcodes::kDSTORE_2, printDSTORE_2ByteCode},
  {Opcodes::kDSTORE_3, printDSTORE_3ByteCode},
  {Opcodes::kDSUB, printDSUBByteCode},
  {Opcodes::kDUP, printDUPByteCode},
  {Opcodes::kDUP_X1, printDUP_X1ByteCode},
  {Opcodes::kDUP_X2, printDUP_X2ByteCode},
  {Opcodes::kDUP2, printDUP2ByteCode},
  {Opcodes::kDUP2_X1, printDUP2_X1ByteCode},
  {Opcodes::kDUP2_X2, printDUP2_X2ByteCode},
  {Opcodes::kF2D, printF2DByteCode},
  {Opcodes::kF2I, printF2IByteCode},
  {Opcodes::kF2L, printF2LByteCode},
  {Opcodes::kFADD, printFADDByteCode},
  {Opcodes::kFALOAD, printFALOADByteCode},
  {Opcodes::kFASTORE, printFASTOREByteCode},
  {Opcodes::kFCMPG, printFCMPGByteCode},
  {Opcodes::kFCMPL, printFCMPLByteCode},
  {Opcodes::kFCONST_0, printFCONST_0ByteCode},
  {Opcodes::kFCONST_1, printFCONST_1ByteCode},
  {Opcodes::kFCONST_2, printFCONST_2ByteCode},
  {Opcodes::kFDIV, printFDIVByteCode},
  {Opcodes::kFLOAD, printFLOADByteCode},
  {Opcodes::kFLOAD_0, printFLOAD_0ByteCode},
  {Opcodes::kFLOAD_1, printFLOAD_1ByteCode},
  {Opcodes::kFLOAD_2, printFLOAD_2ByteCode},
  {Opcodes::kFLOAD_3, printFLOAD_3ByteCode},
  {Opcodes::kFMUL, printFMULByteCode},
  {Opcodes::kFNEG, printFNEGByteCode},
  {Opcodes::kFREM, printFREMByteCode},
  {Opcodes::kFRETURN, printFRETURNByteCode},
  {Opcodes::kFSTORE, printFSTOREByteCode},
  {Opcodes::kFSTORE_0, printFSTORE_0ByteCode},
  {Opcodes::kFSTORE_1, printFSTORE_1ByteCode},
  {Opcodes::kFSTORE_2, printFSTORE_2ByteCode},
  {Opcodes::kFSTORE_3, printFSTORE_3ByteCode},
  {Opcodes::kFSUB, printFSUBByteCode},
  {Opcodes::kGETFIELD, printGETFIELDByteCode},
  {Opcodes::kGETSTATIC, printGETSTATICByteCode},
  {Opcodes::kGOTO, printGOTOByteCode},
  {Opcodes::kGOTO_W, printGOTO_WByteCode},
  {Opcodes::kI2B, printI2BByteCode},
  {Opcodes::kI2C, printI2CByteCode},
  {Opcodes::kI2D, printI2DByteCode},
  {Opcodes::kI2F, printI2FByteCode},
  {Opcodes::kI2L, printI2LByteCode},
  {Opcodes::kI2S, printI2SByteCode},
  {Opcodes::kIADD, printIADDByteCode},
  {Opcodes::kIALOAD, printIALOADByteCode},
  {Opcodes::kIAND, printIANDByteCode},
  {Opcodes::kIASTORE, printIASTOREByteCode},
  {Opcodes::kICONST_M1, printICONST_M1ByteCode},
  {Opcodes::kICONST_0, printICONST_0ByteCode},
  {Opcodes::kICONST_1, printICONST_1ByteCode},
  {Opcodes::kICONST_2, printICONST_2ByteCode},
  {Opcodes::kICONST_3, printICONST_3ByteCode},
  {Opcodes::kICONST_4, printICONST_4ByteCode},
  {Opcodes::kICONST_5, printICONST_5ByteCode},
  {Opcodes::kIDIV, printIDIVByteCode},
  {Opcodes::kIF_ACMPEQ, printIF_ACMPEQByteCode},
  {Opcodes::kIF_ACMPNE, printIF_ACMPNEByteCode},
  {Opcodes::kIF_ICMPEQ, printIF_ICMPEQByteCode},
  {Opcodes::kIF_ICMPGE, printIF_ICMPGEByteCode},
  {Opcodes::kIF_ICMPGT, printIF_ICMPGTByteCode},
  {Opcodes::kIF_ICMPLE, printIF_ICMPLEByteCode},
  {Opcodes::kIF_ICMPLT, printIF_ICMPLTByteCode},
  {Opcodes::kIF_ICMPNE, printIF_ICMPNEByteCode},
  {Opcodes::kIFEQ, printIFEQByteCode},
  {Opcodes::kIFGE, printIFGEByteCode},
  {Opcodes::kIFGT, printIFGTByteCode},
  {Opcodes::kIFLE, printIFLEByteCode},
  {Opcodes::kIFLT, printIFLTByteCode},
  {Opcodes::kIFNE, printIFNEByteCode},
  {Opcodes::kIFNONNULL, printIFNONNULLByteCode},
  {Opcodes::kIFNULL, printIFNULLByteCode},
  {Opcodes::kIINC, printIINCByteCode},
  {Opcodes::kILOAD, printILOADByteCode},
  {Opcodes::kILOAD_0, printILOAD_0ByteCode},
  {Opcodes::kILOAD_1, printILOAD_1ByteCode},
  {Opcodes::kILOAD_2, printILOAD_2ByteCode},
  {Opcodes::kILOAD_3, printILOAD_3ByteCode},
  {Opcodes::kIMPDEP1, printIMPDEP1ByteCode},
  {Opcodes::kIMPDEP2, printIMPDEP2ByteCode},
  {Opcodes::kIMUL, printIMULByteCode},
  {Opcodes::kINEG, printINEGByteCode},
  {Opcodes::kINSTANCEOF, printINSTANCEOFByteCode},
  {Opcodes::kINVOKEDYNAMIC, printINVOKEDYNAMICByteCode},
  {Opcodes::kINVOKEINTERFACE, printINVOKEINTERFACEByteCode},
  {Opcodes::kINVOKESPECIAL, printINVOKESPECIALByteCode},
  {Opcodes::kINVOKESTATIC, printINVOKESTATICByteCode},
  {Opcodes::kINVOKEVIRTUAL, printINVOKEVIRTUALByteCode},
  {Opcodes::kIOR, printIORByteCode},
  {Opcodes::kIREM, printIREMByteCode},
  {Opcodes::kIRETURN, printIRETURNByteCode},
  {Opcodes::kISHL, printISHLByteCode},
  {Opcodes::kISHR, printISHRByteCode},
  {Opcodes::kISTORE, printISTOREByteCode},
  {Opcodes::kISTORE_0, printISTORE_0ByteCode},
  {Opcodes::kISTORE_1, printISTORE_1ByteCode},
  {Opcodes::kISTORE_2, printISTORE_2ByteCode},
  {Opcodes::kISTORE_3, printISTORE_3ByteCode},
  {Opcodes::kISUB, printISUBByteCode},
  {Opcodes::kIUSHR, printIUSHRByteCode},
  {Opcodes::kIXOR, printIXORByteCode},
  {Opcodes::kJSR, printJSRByteCode},
  {Opcodes::kJSR_W, printJSR_WByteCode},
  {Opcodes::kL2D, printL2DByteCode},
  {Opcodes::kL2F, printL2FByteCode},
  {Opcodes::kL2I, printL2IByteCode},
  {Opcodes::kLADD, printLADDByteCode},
  {Opcodes::kLALOAD, printLALOADByteCode},
  {Opcodes::kLAND, printLANDByteCode},
  {Opcodes::kLASTORE, printLASTOREByteCode},
  {Opcodes::kLCMP, printLCMPByteCode},
  {Opcodes::kLCONST_0, printLCONST_0ByteCode},
  {Opcodes::kLCONST_1, printLCONST_1ByteCode},
  {Opcodes::kLDC, printLDCByteCode},
  {Opcodes::kLDC_W, printLDC_WByteCode},
  {Opcodes::kLDC2_W, printLDC2_WByteCode},
  {Opcodes::kLDIV, printLDIVByteCode},
  {Opcodes::kLLOAD, printLLOADByteCode},
  {Opcodes::kLLOAD_0, printLLOAD_0ByteCode},
  {Opcodes::kLLOAD_1, printLLOAD_1ByteCode},
  {Opcodes::kLLOAD_2, printLLOAD_2ByteCode},
  {Opcodes::kLLOAD_3, printLLOAD_3ByteCode},
  {Opcodes::kLMUL, printLMULByteCode},
  {Opcodes::kLNEG, printLNEGByteCode},
  {Opcodes::kLOOKUPSWITCH, printLOOKUPSWITCHByteCode},
  {Opcodes::kLOR, printLORByteCode},
  {Opcodes::kLREM, printLREMByteCode},
  {Opcodes::kLRETURN, printLRETURNByteCode},
  {Opcodes::kLSHL, printLSHLByteCode},
  {Opcodes::kLSHR, printLSHRByteCode},
  {Opcodes::kLSTORE, printLSTOREByteCode},
  {Opcodes::kLSTORE_0, printLSTORE_0ByteCode},
  {Opcodes::kLSTORE_1, printLSTORE_1ByteCode},
  {Opcodes::kLSTORE_2, printLSTORE_2ByteCode},
  {Opcodes::kLSTORE_3, printLSTORE_3ByteCode},
  {Opcodes::kLSUB, printLSUBByteCode},
  {Opcodes::kLUSHR, printLUSHRByteCode},
  {Opcodes::kLXOR, printLXORByteCode},
  {Opcodes::kMONITORENTER, printMONITORENTERByteCode},
  {Opcodes::kMONITOREXIT, printMONITOREXITByteCode},
  {Opcodes::kMULTIANEWARRAY, printMULTIANEWARRAYByteCode},
  {Opcodes::kNEW, printNEWByteCode},
  {Opcodes::kNEWARRAY, printNEWARRAYByteCode},
  {Opcodes::kNOP, printNOPByteCode},
  {Opcodes::kPOP, printPOPByteCode},
  {Opcodes::kPOP2, printPOP2ByteCode},
  {Opcodes::kPUTFIELD, printPUTFIELDByteCode},
  {Opcodes::kPUTSTATIC, printPUTSTATICByteCode},
  {Opcodes::kRET, printRETByteCode},
  {Opcodes::kRETURN, printRETURNByteCode},
  {Opcodes::kSALOAD, printSALOADByteCode},
  {Opcodes::kSASTORE, printSASTOREByteCode},
  {Opcodes::kSIPUSH, printSIPUSHByteCode},
  {Opcodes::kSWAP, printSWAPByteCode},
  {Opcodes::kTABLESWITCH, printTABLESWITCHByteCode},
  {Opcodes::kWIDE, printWIDEByteCode},
};

int printBytecode(std::vector<Utils::Types::u1>::iterator *code_it, Viewer *v) {
  auto opcode = **code_it;
  return op_func.at(opcode)(code_it, v);
}
}  // namespace Instructions