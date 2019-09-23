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

auto getHexByteString = [](types::u4 bytes, const int &size) -> std::string {
  std::stringstream ss;
  ss << "0x" << std::setfill('0') << std::setw(size) << std::hex
     << std::uppercase << bytes;
  return ss.str();
};

namespace Utils {
namespace Infos {
// clang-format off
static void create_json_str(json &j, CONSTANT_Class_info *kinfo) {
  j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"name", {
        {"index", kinfo->name_index},
        {"info", {}}
      }
    }
  };
}

static void create_json_str(json &j, CONSTANT_FieldRef_info *kinfo) {
  j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"reference", {
        {"class", {
            {"index", kinfo->class_index},
            {"info", {}}
          }
        },
        {"name and type", {
            {"index", kinfo->name_and_type_index},
            {"info", {}}
          }
        }
      }
    }
  };
}

static void create_json_str(json &j, CONSTANT_Methodref_info *kinfo) {
  j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"reference", {
        {"class", {
            {"index", kinfo->class_index},
            {"info", {}}
          }
        },
        {"name and type", {
            {"index", kinfo->name_and_type_index},
            {"info", {}}
          }
        }
      }
    }
  };
}

static void create_json_str(json &j, CONSTANT_InterfaceMethodref_info *kinfo) {
  j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"reference", {
        {"class", {
            {"index", kinfo->class_index},
            {"info", {}}
          }
        },
        {"name and type", {
            {"index", kinfo->name_and_type_index},
            {"info", {}}
          }
        }
      }
    }
  };
}

static void create_json_str(json &j, CONSTANT_String_info *kinfo) {
  j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"utf8", {
        {"index", kinfo->string_index},
        {"info", {}}
      }
    }
  };
}

static void create_json_str(json &j, CONSTANT_Integer_info *kinfo) {
  j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", getHexByteString(kinfo->bytes, 4)},
    {"value", kinfo->bytes}
  };
}

static void create_json_str(json &j, CONSTANT_Float_info *kinfo) {
  j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"bytes", getHexByteString(kinfo->bytes, 4)},
    {"value", copyCast<float>(&kinfo->bytes)}
  };
}

static void create_json_str(json &j, CONSTANT_Long_info *kinfo) {
  auto u8val = (static_cast<Utils::Types::u8>(kinfo->high_bytes) << 32 |
                kinfo->low_bytes);
  j = {
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

static void create_json_str(json &j, CONSTANT_Double_info *kinfo) {
  auto u8val = (static_cast<Utils::Types::u8>(kinfo->high_bytes) << 32 |
                kinfo->low_bytes);
  j = {
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

static void create_json_str(json &j, CONSTANT_NameAndType_info *kinfo) {
  j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"name", {
        {"index", kinfo->name_index},
        {"info", {}}
      }
    },
    {"descriptor", {
        {"index", kinfo->descriptor_index},
        {"info", {}}
      }
    }
  };
}

static void create_json_str(json &j, CONSTANT_Utf8_info *kinfo) {
  auto utf8_string = Utf8(kinfo).str;
  j = {
    {"tag", kinfo->tag},
    {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)},
    {"string", std::string(utf8_string.begin(), utf8_string.end())},
    {"length", kinfo->length}
  };
}

// void create_json_str(json &j, CONSTANT_MethodHandle_info *kinfo) {
//   j = {
//     {"tag", kinfo->tag},
//     {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)}
//   };
// }

// void create_json_str(json &j, CONSTANT_MethodType_info *kinfo) {
//   j = {
//     {"tag", kinfo->tag},
//     {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)}
//   };
// }

// void create_json_str(json &j, CONSTANT_InvokeDynamic_info *kinfo) {
//   j = {
//     {"tag", kinfo->tag},
//     {"type", Utils::ConstantPool::getConstantTypename(kinfo->tag)}
//   };
// }
// clang-format on

/**
 * Interfaces para serializar os objetos em formato JSON
 * */
void to_json(json &j, CONSTANT_Class_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);
  auto nameidx_cpi = const_cast<cp_info *>(&kpool[kinfo->name_index - 1]);
  create_json_str((i >= 0 ? j[i] : j).at("/name/info"_json_pointer),
                  nameidx_cpi->getClass<CONSTANT_Utf8_info>());
}

void to_json(json &j, CONSTANT_FieldRef_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);

  auto classindex = const_cast<cp_info *>(&kpool[kinfo->class_index - 1]);
  auto kclass_info = classindex->getClass<CONSTANT_Class_info>();
  create_json_str((i >= 0 ? j[i] : j).at("/reference/class/info"_json_pointer),
                  kclass_info);

  auto classnameindex =
      const_cast<cp_info *>(&kpool[kclass_info->name_index - 1]);
  auto kutf8_info = classnameindex->getClass<CONSTANT_Utf8_info>();
  create_json_str(
      (i >= 0 ? j[i] : j).at("/reference/class/info/name/info"_json_pointer),
      kutf8_info);

  auto nametypeindex =
      const_cast<cp_info *>(&kpool[kinfo->name_and_type_index - 1]);
  auto knametype_info = nametypeindex->getClass<CONSTANT_NameAndType_info>();
  create_json_str(
      (i >= 0 ? j[i] : j).at("/reference/name and type/info"_json_pointer),
      knametype_info);

  auto descriptorindex =
      const_cast<cp_info *>(&kpool[knametype_info->descriptor_index - 1]);
  kutf8_info = descriptorindex->getClass<CONSTANT_Utf8_info>();
  create_json_str(
      (i >= 0 ? j[i] : j)
          .at("/reference/name and type/info/descriptor/info"_json_pointer),
      kutf8_info);

  auto nameindex =
      const_cast<cp_info *>(&kpool[knametype_info->name_index - 1]);
  kutf8_info = nameindex->getClass<CONSTANT_Utf8_info>();
  create_json_str(
      (i >= 0 ? j[i] : j)
          .at("/reference/name and type/info/name/info"_json_pointer),
      kutf8_info);
}

void to_json(json &j, CONSTANT_Methodref_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);

  auto classindex = const_cast<cp_info *>(&kpool[kinfo->class_index - 1]);
  auto kclass_info = classindex->getClass<CONSTANT_Class_info>();
  create_json_str((i >= 0 ? j[i] : j).at("/reference/class/info"_json_pointer),
                  kclass_info);

  auto classnameindex =
      const_cast<cp_info *>(&kpool[kclass_info->name_index - 1]);
  auto kutf8_info = classnameindex->getClass<CONSTANT_Utf8_info>();
  create_json_str(
      (i >= 0 ? j[i] : j).at("/reference/class/info/name/info"_json_pointer),
      kutf8_info);

  auto nametypeindex =
      const_cast<cp_info *>(&kpool[kinfo->name_and_type_index - 1]);
  auto knametype_info = nametypeindex->getClass<CONSTANT_NameAndType_info>();
  create_json_str(
      (i >= 0 ? j[i] : j).at("/reference/name and type/info"_json_pointer),
      knametype_info);

  auto descriptorindex =
      const_cast<cp_info *>(&kpool[knametype_info->descriptor_index - 1]);
  kutf8_info = descriptorindex->getClass<CONSTANT_Utf8_info>();
  create_json_str(
      (i >= 0 ? j[i] : j)
          .at("/reference/name and type/info/descriptor/info"_json_pointer),
      kutf8_info);

  auto nameindex =
      const_cast<cp_info *>(&kpool[knametype_info->name_index - 1]);
  kutf8_info = nameindex->getClass<CONSTANT_Utf8_info>();
  create_json_str(
      (i >= 0 ? j[i] : j)
          .at("/reference/name and type/info/name/info"_json_pointer),
      kutf8_info);
}

void to_json(json &j, CONSTANT_InterfaceMethodref_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);

  auto classindex = const_cast<cp_info *>(&kpool[kinfo->class_index - 1]);
  auto kclass_info = classindex->getClass<CONSTANT_Class_info>();
  create_json_str((i >= 0 ? j[i] : j).at("/reference/class/info"_json_pointer),
                  kclass_info);

  auto classnameindex =
      const_cast<cp_info *>(&kpool[kclass_info->name_index - 1]);
  auto kutf8_info = classnameindex->getClass<CONSTANT_Utf8_info>();
  create_json_str(
      (i >= 0 ? j[i] : j).at("/reference/class/info/name/info"_json_pointer),
      kutf8_info);

  auto nametypeindex =
      const_cast<cp_info *>(&kpool[kinfo->name_and_type_index - 1]);
  auto knametype_info = nametypeindex->getClass<CONSTANT_NameAndType_info>();
  create_json_str(
      (i >= 0 ? j[i] : j).at("/reference/name and type/info"_json_pointer),
      knametype_info);

  auto descriptorindex =
      const_cast<cp_info *>(&kpool[knametype_info->descriptor_index - 1]);
  kutf8_info = descriptorindex->getClass<CONSTANT_Utf8_info>();
  create_json_str(
      (i >= 0 ? j[i] : j)
          .at("/reference/name and type/info/descriptor/info"_json_pointer),
      kutf8_info);

  auto nameindex =
      const_cast<cp_info *>(&kpool[knametype_info->name_index - 1]);
  kutf8_info = nameindex->getClass<CONSTANT_Utf8_info>();
  create_json_str(
      (i >= 0 ? j[i] : j)
          .at("/reference/name and type/info/name/info"_json_pointer),
      kutf8_info);
}

void to_json(json &j, CONSTANT_String_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);
  auto stringindex = const_cast<cp_info *>(&kpool[kinfo->string_index - 1]);
  create_json_str((i >= 0 ? j[i] : j).at("/utf8/info"_json_pointer),
                  stringindex->getClass<CONSTANT_Utf8_info>());
}

void to_json(json &j, CONSTANT_Integer_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);
}

void to_json(json &j, CONSTANT_Float_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);
}

void to_json(json &j, CONSTANT_Long_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);
}

void to_json(json &j, CONSTANT_Double_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);
}

void to_json(json &j, CONSTANT_NameAndType_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);
  auto nameindex = const_cast<cp_info *>(&kpool[kinfo->name_index - 1]);
  create_json_str((i >= 0 ? j[i] : j).at("/name/info"_json_pointer),
                  nameindex->getClass<CONSTANT_Utf8_info>());
  auto descriptorindex =
      const_cast<cp_info *>(&kpool[kinfo->descriptor_index - 1]);
  create_json_str((i >= 0 ? j[i] : j).at("/descriptor/info"_json_pointer),
                  descriptorindex->getClass<CONSTANT_Utf8_info>());
}

void to_json(json &j, CONSTANT_Utf8_info *kinfo,
             const std::vector<Utils::Infos::cp_info> &kpool, const int &i) {
  create_json_str(i >= 0 ? j[i] : j, kinfo);
}

void to_json(json &j, Utils::Infos::Serializer &is) {
  for (size_t i = 0; i < is.cpivec.size(); ++i) {
    cp_info cpi = is.cpivec.at(i);
    switch (cpi.base->tag) {
      namespace cp = Utils::ConstantPool;
      case cp::CONSTANT_Class:
        to_json(j, cpi.getClass<CONSTANT_Class_info>(), is.cpivec, i);
        break;
      case cp::CONSTANT_Double:
        to_json(j, cpi.getClass<CONSTANT_Double_info>(), is.cpivec, i);
        ++i;
        break;
      case cp::CONSTANT_Fieldref:
        to_json(j, cpi.getClass<CONSTANT_FieldRef_info>(), is.cpivec, i);
        break;
      case cp::CONSTANT_Float:
        to_json(j, cpi.getClass<CONSTANT_Float_info>(), is.cpivec, i);
        break;
      case cp::CONSTANT_Integer:
        to_json(j, cpi.getClass<CONSTANT_Integer_info>(), is.cpivec, i);
        break;
      case cp::CONSTANT_InterfaceMethodref:
        to_json(j, cpi.getClass<CONSTANT_InterfaceMethodref_info>(), is.cpivec,
                i);
        break;
      case cp::CONSTANT_Long:
        to_json(j, cpi.getClass<CONSTANT_Long_info>(), is.cpivec, i);
        ++i;
        break;
      case cp::CONSTANT_Methodref:
        to_json(j, cpi.getClass<CONSTANT_Methodref_info>(), is.cpivec, i);
        break;
      case cp::CONSTANT_NameAndType:
        to_json(j, cpi.getClass<CONSTANT_NameAndType_info>(), is.cpivec, i);
        break;
      case cp::CONSTANT_String:
        to_json(j, cpi.getClass<CONSTANT_String_info>(), is.cpivec, i);
        break;
      case cp::CONSTANT_Utf8:
        to_json(j, cpi.getClass<CONSTANT_Utf8_info>(), is.cpivec, i);
        break;
    }
  }
}
}  // namespace Infos
}  // namespace Utils
