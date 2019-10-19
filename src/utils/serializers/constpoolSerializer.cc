#include "utils/serializers/constpoolSerializer.h"

#include <sstream>
#include "utils/constantPool.h"
#include "utils/memory.h"
#include "utils/utf8.h"

static std::string getHexByteString(types::u4 bytes, const int &size) {
  std::stringstream ss;
  ss << "0x" << std::setfill('0') << std::setw(size) << std::hex
     << std::uppercase << bytes;
  return ss.str();
}

namespace Utils {
namespace ConstantPool {
static void create_json_str(json *j, const CONSTANT_Class_info *kinfo,
                            const int &index) {
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"name", {}}
  };
  // clang-format on
}

static void create_json_str(json *j, const CONSTANT_FieldRef_info *kinfo,
                            const int &index) {
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"reference", {
        {"class", {}},
        {"name and type", {}}
      }
    }
  };
  // clang-format on
}

static void create_json_str(json *j, const CONSTANT_Methodref_info *kinfo,
                            const int &index) {
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"reference", {
        {"class", {}},
        {"name and type", {}}
      }
    }
  };
  // clang-format on
}

static void create_json_str(json *j,
                            const CONSTANT_InterfaceMethodref_info *kinfo,
                            const int &index) {
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"reference", {
        {"class", {}},
        {"name and type", {}}
      }
    }
  };
  // clang-format on
}

static void create_json_str(json *j, const CONSTANT_String_info *kinfo,
                            const int &index) {
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"string", {}}
  };
  // clang-format on
}

static void create_json_str(json *j, const CONSTANT_Integer_info *kinfo,
                            const int &index) {
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", getHexByteString(kinfo->bytes, 4)},
    {"value", kinfo->bytes}
  };
  // clang-format on
}

static void create_json_str(json *j, const CONSTANT_Float_info *kinfo,
                            const int &index) {
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", getHexByteString(kinfo->bytes, 4)},
    {"value", copyCast<float>(&kinfo->bytes)}
  };
  // clang-format on
}

static void create_json_str(json *j, const CONSTANT_Long_info *kinfo,
                            const int &index) {
  auto u8val = (static_cast<Utils::Types::u8>(kinfo->high_bytes) << 32 |
                kinfo->low_bytes);
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", {
        {"high", getHexByteString(kinfo->high_bytes, 8)},
        {"low", getHexByteString(kinfo->low_bytes, 8)}
      }
    },
    {"value", u8val}
  };
  // clang-format on
}

static void create_json_str(json *j, const CONSTANT_Double_info *kinfo,
                            const int &index) {
  auto u8val = (static_cast<Utils::Types::u8>(kinfo->high_bytes) << 32 |
                kinfo->low_bytes);
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", {
        {"high", getHexByteString(kinfo->high_bytes, 8)},
        {"low", getHexByteString(kinfo->low_bytes, 8)}
      }
    },
    {"value", copyCast<double>(&u8val)}
  };
  // clang-format on
}

static void create_json_str(json *j, const CONSTANT_NameAndType_info *kinfo,
                            const int &index) {
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"name", {}},
    {"descriptor", {}}
  };
  // clang-format on
}

static void create_json_str(json *j, const CONSTANT_Utf8_info *kinfo,
                            const int &index) {
  auto utf8_string = Utf8(kinfo).str;
  // clang-format off
  *j = {
    {"tag", kinfo->tag},
    {"cp_entry_index", index},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"string", std::string(utf8_string.begin(), utf8_string.end())},
    {"length", kinfo->length}
  };
  // clang-format on
}

template <typename T>
void ConstantPoolSerializer::writeReferences(json *j, const T *kinfo) {
  this->to_json(&(*j).at("/reference/class"_json_pointer),
                kinfo->class_index - 1);
  this->to_json(&(*j).at("/reference/name and type"_json_pointer),
                kinfo->name_and_type_index - 1);
}

bool ConstantPoolSerializer::to_json(json *j, const int &kpoolindex) {
  bool jmpNextIndex = false;
  if (kpoolindex < 0) {
    *j = {{"cp_entry_index", kpoolindex + 1},
          {"value", "invalid constant pool reference"}};
    return jmpNextIndex;
  }

  auto cpi = this->cf->constant_pool[kpoolindex];
  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<CONSTANT_Class_info>();
      create_json_str(j, kclass_info, kpoolindex + 1);
      this->to_json(&(*j).at("/name"_json_pointer),
                    kclass_info->name_index - 1);
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<CONSTANT_FieldRef_info>();
      create_json_str(j, kfieldref_info, kpoolindex + 1);
      this->writeReferences(j, kfieldref_info);
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<CONSTANT_Methodref_info>();
      create_json_str(j, kmethodref_info, kpoolindex + 1);
      this->writeReferences(j, kmethodref_info);
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info = cpi.getClass<CONSTANT_InterfaceMethodref_info>();
      create_json_str(j, kImethodref_info, kpoolindex + 1);
      this->writeReferences(j, kImethodref_info);
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<CONSTANT_String_info>();
      create_json_str(j, kstring_info, kpoolindex + 1);
      this->to_json(&(*j).at("/string"_json_pointer),
                    kstring_info->string_index - 1);
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<CONSTANT_Integer_info>();
      create_json_str(j, kinteger_info, kpoolindex + 1);
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<CONSTANT_Float_info>();
      create_json_str(j, kfloat_info, kpoolindex + 1);
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<CONSTANT_Long_info>();
      create_json_str(j, klong_info, kpoolindex + 1);
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<CONSTANT_Double_info>();
      create_json_str(j, kdouble_info, kpoolindex + 1);
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<CONSTANT_NameAndType_info>();
      create_json_str(j, knametype_info, kpoolindex + 1);
      this->to_json(&(*j).at("/name"_json_pointer),
                    knametype_info->name_index - 1);
      this->to_json(&(*j).at("/descriptor"_json_pointer),
                    knametype_info->descriptor_index - 1);
      break;
    }
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<CONSTANT_Utf8_info>();
      create_json_str(j, kutf8_info, kpoolindex + 1);
      break;
    }
  }
  return jmpNextIndex;
}
}  // namespace ConstantPool
}  // namespace Utils
