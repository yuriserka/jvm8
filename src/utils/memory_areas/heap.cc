#include "utils/memory_areas/heap.h"

#include "utils/access_flags.h"
#include "utils/class_t.h"
#include "utils/helper_functions.h"
#include "utils/memory_areas/method_area.h"

namespace MemoryAreas {
void Heap::addClass(Thread *th, const std::string &classname) {
  if (this->isInitialized(classname)) {
    return;
  }
  this->initialized_classes.push_back(new Utils::Class_t(classname));
  try {
    th->method_area->getMethod("<clinit>", "()V");
    th->changeContext(classname, "<clinit>", "()V", false);
  } catch (const Utils::Errors::Exception &e) {
    for (auto &field : th->method_area->fields) {
      if (Utils::fieldIs(field, "static")) {
        Any default_val;
        auto descriptor =
            th->method_area->runtime_constant_pool[field.descriptor_index - 1]
                .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
                ->getValue();
        auto fname =
            th->method_area->runtime_constant_pool[field.name_index - 1]
                .getClass<Utils::ConstantPool::CONSTANT_Utf8_info>()
                ->getValue();
        auto classref = this->getClass(classname);
        switch (descriptor[0]) {
          case 'B':
          case 'C':
          case 'I':
          case 'S':
          case 'Z':
            default_val = 0;
            break;
          case 'J':
            default_val = 0L;
            break;
          case 'D':
            default_val = 0.0;
            break;
          case 'F':
            default_val = 0.0f;
            break;
          case 'L':
            default_val = new Utils::Object(classname);
            break;
        }
        classref->addField(default_val, fname, descriptor);
      }
    }
    return;
  }
}
}  // namespace MemoryAreas