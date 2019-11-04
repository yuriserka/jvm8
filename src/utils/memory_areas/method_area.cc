#include "utils/memory_areas/method_area.h"

#include <algorithm>
#include "utils/constantPool.h"
#include "utils/errors.h"

namespace MemoryAreas {
Utils::Infos::method_info MethodArea::getMethod(
    const std::string &method_name) {
  auto method = std::find_if(
      this->methods.begin(), this->methods.end(),
      [&method_name, this](const Utils::Infos::method_info &method) {
        auto actual_method_name =
            this->runtime_constant_pool[method.name_index - 1]
                .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
                ->getValue();
        return !actual_method_name.compare(method_name);
      });
  if (method == this->methods.end()) {
    auto classinfo = this->runtime_constant_pool[this->cf->this_class - 1]
                         .getClass<Utils::ConstantPool::CONSTANT_Class_info>();
    auto classname = this->runtime_constant_pool[classinfo->name_index - 1]
                         .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
                         ->getValue();
    std::stringstream ss;
    ss << "could not find method '" << method_name << "' in class '"
       << classname << "'";
    throw Utils::Errors::Exception(Utils::Errors::kMETHOD, ss.str());
  }

  return *method;
}

Utils::Infos::field_info MethodArea::getField(const std::string &field_name) {
  auto field = std::find_if(
      this->fields.begin(), this->fields.end(),
      [&field_name, this](const Utils::Infos::field_info &field) {
        auto actual_field_name =
            this->runtime_constant_pool[field.name_index - 1]
                .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
                ->getValue();
        return !actual_field_name.compare(field_name);
      });
  if (field == this->fields.end()) {
    auto classinfo = this->runtime_constant_pool[this->cf->this_class - 1]
                         .getClass<Utils::ConstantPool::CONSTANT_Class_info>();
    auto classname = this->runtime_constant_pool[classinfo->name_index - 1]
                         .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
                         ->getValue();
    std::stringstream ss;
    ss << "could not find field '" << field_name << "' in class '" << classname
       << "'";
    throw Utils::Errors::Exception(Utils::Errors::kFIELD, ss.str());
  }

  return *field;
}
}  // namespace MemoryAreas