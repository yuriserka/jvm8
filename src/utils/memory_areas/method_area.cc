#include "utils/memory_areas/method_area.h"

#include <algorithm>
#include "reader.h"
#include "utils/constantPool.h"
#include "utils/errors.h"
#include "utils/flags.h"
#include "utils/string.h"

namespace MemoryAreas {
Utils::Infos::method_info MethodArea::getMethod(const std::string &method_name,
                                                const std::string &descriptor) {
  auto method = std::find_if(
      this->methods.begin(), this->methods.end(),
      [&method_name, &descriptor,
       this](const Utils::Infos::method_info &method) {
        auto actual_method_name =
            this->runtime_constant_pool[method.name_index - 1]
                .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
                ->getValue();
        auto actual_method_ret =
            this->runtime_constant_pool[method.descriptor_index - 1]
                .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
                ->getValue();
        return !actual_method_name.compare(method_name) &&
               !actual_method_ret.compare(descriptor);
      });
  if (method == this->methods.end()) {
    auto classname = Utils::getClassName(this->runtime_classfile);
    std::stringstream ss;
    ss << "could not find method '" << method_name << ":" << descriptor
       << "' in class '" << classname << "'";
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
    auto classname = Utils::getClassName(this->runtime_classfile);

    std::stringstream ss;
    ss << "could not find field '" << field_name << "' in class '" << classname
       << "'";
    throw Utils::Errors::Exception(Utils::Errors::kFIELD, ss.str());
  }

  return *field;
}

const ClassFile *MethodArea::getClass(const std::string &classname) {
  if (!this->isLoaded(classname)) {
    return this->loadClass(classname);
  }

  auto classfile = std::find_if(this->loaded.begin(), this->loaded.end(),
                                [&classname](const ClassFile *classfile) {
                                  auto actual_name =
                                      Utils::getClassName(classfile);
                                  return !classname.compare(actual_name);
                                });

  return *classfile;
}

const ClassFile *MethodArea::loadClass(const std::string &classname) {
  if (this->isLoaded(classname)) {
    return this->getClass(classname);
  }
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Loading class " << classname << "\n";
  }
  std::stringstream ss;
  const ClassFile *new_class = new ClassFile();
  char delimiter = '/';
  auto splitted_path = Utils::String::split(classname, delimiter);
  if (splitted_path.size() == 1) {
    ss << Utils::Flags::options.kPATH << delimiter << classname << ".class";
  } else {
    ss << "." << delimiter << "classes" << delimiter << classname << ".class";
  }
  try {
    Reader(const_cast<ClassFile *>(new_class), ss.str()).readClassFile();
  } catch (const Utils::Errors::Exception &e) {
    // ss.str("");
    // ss << "Ignored <" << classname << "." << method_name << ">";
    delete new_class;
    throw Utils::Errors::Exception(Utils::Errors::kCLASSFILE, e.what());
  }

  this->loaded.push_back(new_class);

  return new_class;
}
}  // namespace MemoryAreas