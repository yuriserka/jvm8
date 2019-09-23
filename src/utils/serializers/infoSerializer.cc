#include "utils/serializers/infoSerializer.h"

#include <sstream>
#include "utils/constantPool.h"
#include "utils/utf8.h"

template <typename T, typename U>
static T copyCast(const U *in) {
  T dest;
  std::memcpy(&dest, in, sizeof(U));

  return dest;
}

static auto getHexByteString = [](types::u4 bytes,
                                  const int &size) -> std::string {
  std::stringstream ss;
  ss << "0x" << std::setfill('0') << std::setw(size) << std::hex
     << std::uppercase << bytes;
  return ss.str();
};

namespace Utils {
namespace Infos {
// clang-format off
static void create_json_str(json *j, CONSTANT_Class_info *kinfo) {
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"name", {
        {"cp_entry_index", kinfo->name_index},
        {"info", {}}
      }
    }
  };
}

static void create_json_str(json *j, CONSTANT_FieldRef_info *kinfo) {
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"reference", {
        {"class", {
            {"cp_entry_index", kinfo->class_index},
            {"info", {}}
          }
        },
        {"name and type", {
            {"cp_entry_index", kinfo->name_and_type_index},
            {"info", {}}
          }
        }
      }
    }
  };
}

static void create_json_str(json *j, CONSTANT_Methodref_info *kinfo) {
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"reference", {
        {"class", {
            {"cp_entry_index", kinfo->class_index},
            {"info", {}}
          }
        },
        {"name and type", {
            {"cp_entry_index", kinfo->name_and_type_index},
            {"info", {}}
          }
        }
      }
    }
  };
}

static void create_json_str(json *j, CONSTANT_InterfaceMethodref_info *kinfo) {
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"reference", {
        {"class", {
            {"cp_entry_index", kinfo->class_index},
            {"info", {}}
          }
        },
        {"name and type", {
            {"cp_entry_index", kinfo->name_and_type_index},
            {"info", {}}
          }
        }
      }
    }
  };
}

static void create_json_str(json *j, CONSTANT_String_info *kinfo) {
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"utf8", {
        {"cp_entry_index", kinfo->string_index},
        {"info", {}}
      }
    }
  };
}

static void create_json_str(json *j, CONSTANT_Integer_info *kinfo) {
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", getHexByteString(kinfo->bytes, 4)},
    {"value", kinfo->bytes}
  };
}

static void create_json_str(json *j, CONSTANT_Float_info *kinfo) {
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", getHexByteString(kinfo->bytes, 4)},
    {"value", copyCast<float>(&kinfo->bytes)}
  };
}

static void create_json_str(json *j, CONSTANT_Long_info *kinfo) {
  auto u8val = (static_cast<Utils::Types::u8>(kinfo->high_bytes) << 32 |
                kinfo->low_bytes);
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", {
        {"high", getHexByteString(kinfo->high_bytes, 8)},
        {"low", getHexByteString(kinfo->low_bytes, 8)}
      }
    },
    {"value", u8val}
  };
}

static void create_json_str(json *j, CONSTANT_Double_info *kinfo) {
  auto u8val = (static_cast<Utils::Types::u8>(kinfo->high_bytes) << 32 |
                kinfo->low_bytes);
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", {
        {"high", getHexByteString(kinfo->high_bytes, 8)},
        {"low", getHexByteString(kinfo->low_bytes, 8)}
      }
    },
    {"value", copyCast<double>(&u8val)}
  };
}

static void create_json_str(json *j, CONSTANT_NameAndType_info *kinfo) {
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"name", {
        {"cp_entry_index", kinfo->name_index},
        {"info", {}}
      }
    },
    {"descriptor", {
        {"cp_entry_index", kinfo->descriptor_index},
        {"info", {}}
      }
    }
  };
}

static void create_json_str(json *j, CONSTANT_Utf8_info *kinfo) {
  auto utf8_string = Utf8(kinfo).str;
  *j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"string", std::string(utf8_string.begin(), utf8_string.end())},
    {"length", kinfo->length}
  };
}
// clang-format on

template <typename T>
void Serializer::writeReferences(json *j, const T *kinfo) {
  this->kPoolInfo_to_JSON(&(*j).at("/reference/class/info"_json_pointer),
                          kinfo->class_index - 1);
  this->kPoolInfo_to_JSON(
      &(*j).at("/reference/name and type/info"_json_pointer),
      kinfo->name_and_type_index - 1);
}

bool Serializer::kPoolInfo_to_JSON(json *j, const int &kpoolindex) {
  bool jmpNextIndex = false;
  auto cpi = this->cf->constant_pool[kpoolindex];
  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::CONSTANT_Class: {
      auto kclass_info = cpi.getClass<CONSTANT_Class_info>();
      create_json_str(j, kclass_info);
      this->kPoolInfo_to_JSON(&(*j).at("/name/info"_json_pointer),
                              kclass_info->name_index - 1);
      break;
    }
    case cp::CONSTANT_Fieldref: {
      auto kfieldref_info = cpi.getClass<CONSTANT_FieldRef_info>();
      create_json_str(j, kfieldref_info);
      this->writeReferences(j, kfieldref_info);
      break;
    }
    case cp::CONSTANT_Methodref: {
      auto kmethodref_info = cpi.getClass<CONSTANT_Methodref_info>();
      create_json_str(j, kmethodref_info);
      this->writeReferences(j, kmethodref_info);
      break;
    }
    case cp::CONSTANT_InterfaceMethodref: {
      auto kImethodref_info = cpi.getClass<CONSTANT_InterfaceMethodref_info>();
      create_json_str(j, kImethodref_info);
      this->writeReferences(j, kImethodref_info);
      break;
    }
    case cp::CONSTANT_String: {
      auto kstring_info = cpi.getClass<CONSTANT_String_info>();
      create_json_str(j, kstring_info);
      this->kPoolInfo_to_JSON(&(*j).at("utf8/info"_json_pointer),
                              kstring_info->string_index - 1);
      break;
    }
    case cp::CONSTANT_Integer: {
      auto kinteger_info = cpi.getClass<CONSTANT_Integer_info>();
      create_json_str(j, kinteger_info);
      break;
    }
    case cp::CONSTANT_Float: {
      auto kfloat_info = cpi.getClass<CONSTANT_Float_info>();
      create_json_str(j, kfloat_info);
      break;
    }
    case cp::CONSTANT_Long: {
      auto klong_info = cpi.getClass<CONSTANT_Long_info>();
      create_json_str(j, klong_info);
      jmpNextIndex = true;
      break;
    }
    case cp::CONSTANT_Double: {
      auto kdouble_info = cpi.getClass<CONSTANT_Double_info>();
      create_json_str(j, kdouble_info);
      jmpNextIndex = true;
      break;
    }
    case cp::CONSTANT_NameAndType: {
      auto knametype_info = cpi.getClass<CONSTANT_NameAndType_info>();
      create_json_str(j, knametype_info);
      this->kPoolInfo_to_JSON(&(*j).at("/name/info"_json_pointer),
                              knametype_info->name_index - 1);
      this->kPoolInfo_to_JSON(&(*j).at("/descriptor/info"_json_pointer),
                              knametype_info->descriptor_index - 1);
      break;
    }
    case cp::CONSTANT_Utf8: {
      auto kutf8_info = cpi.getClass<CONSTANT_Utf8_info>();
      create_json_str(j, kutf8_info);
      break;
    }
  }
  return jmpNextIndex;
}
}  // namespace Infos
}  // namespace Utils
