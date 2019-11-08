#include "instructions/instruction_set/invokes.h"
#include "utils/memory_areas/thread.h"

namespace Instructions {
namespace Invokes {
std::vector<int> Dynamic::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Interface::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Especial::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Static::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
template <typename T>
static std::string getDescriptor(const MemoryAreas::Thread *th,
                                 const Utils::ConstantPool::cp_info &ref) {
  const Utils::ConstantPool::cp_info nametypeindex =
      th->method_area
          ->runtime_constant_pool[ref.getClass<T>()->name_and_type_index - 1];

  auto nametype =
      nametypeindex.getClass<Utils::ConstantPool::CONSTANT_NameAndType_info>();

  return th->method_area->runtime_constant_pool[nametype->descriptor_index - 1]
      .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
      ->getValue();
}

std::vector<int> Virtual::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  auto index = (*++*code_iterator << 8) | *++*code_iterator;
  std::stringstream ss;

  auto ref = th->method_area->runtime_constant_pool[index - 1];
  std::string descriptor;

  switch (ref.base->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_FIELDREF: {
      ss << ref.getClass<cp::CONSTANT_FieldRef_info>()->getValue(
          th->method_area->runtime_constant_pool, true);
      descriptor = getDescriptor<cp::CONSTANT_FieldRef_info>(th, ref);
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      ss << ref.getClass<cp::CONSTANT_Methodref_info>()->getValue(
          th->method_area->runtime_constant_pool, true);
      descriptor = getDescriptor<cp::CONSTANT_Methodref_info>(th, ref);
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      ss << ref.getClass<cp::CONSTANT_InterfaceMethodref_info>()->getValue(
          th->method_area->runtime_constant_pool, true);
      descriptor = getDescriptor<cp::CONSTANT_InterfaceMethodref_info>(th, ref);
      break;
    }
  }

  auto ref_val = ss.str();
  auto classname = ref_val.substr(0, ref_val.find_last_of('.'));
  auto methodname = ref_val.substr(ref_val.find_last_of('.') + 1);

  *delta_code = 2;

  if (!(classname + "." + methodname).compare("java/io/PrintStream.println")) {
    std::cout << "Interceptando " << Opcodes::getMnemonic(this->opcode)
              << " java/io/PrintStream.println\n";
    std::cout << th->current_frame->popOperand<int>() << "\n";
    return {};
  }

  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  th->changeContext(classname, methodname, descriptor);

  return {};
}
// ----------------------------------------------------------------------------

}  // namespace Invokes
}  // namespace Instructions
