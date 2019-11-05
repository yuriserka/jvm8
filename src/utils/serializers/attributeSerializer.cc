#include "utils/serializers/attributeSerializer.h"

#include "instructions/opcodes.h"
#include "utils/serializers/constpoolSerializer.h"
#include "utils/serializers/instructionSerializer.h"
#include "utils/string.h"

static std::string getHexByteString(Utils::Types::u4 bytes, const int &size) {
  std::stringstream ss;
  ss << "0x" << std::setfill('0') << std::setw(size) << std::hex
     << std::uppercase << bytes;
  return ss.str();
}

namespace Utils {
namespace Attributes {
static void create_json_str(json *j, const ConstantValue_attribute *kval_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", kval_attr->attribute_length}
      }
    },
    {"specific info", {
          {"constant value", {}}
      }
    },
  };
  // clang-format on
}

static void create_json_str(json *j, const Code_attribute *code_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", code_attr->attribute_length}
      }
    },
    {"specific info", {
        {"bytecode", json::array()},
        {"exception table", json::array()},
        {"misc", {
            {"maximum local variables", code_attr->max_locals},
            {"code length", code_attr->code_length}
          }
        }
      }
    },
    {"attributes", json::array()}
  };
  // clang-format on
}

static void create_json_str(json *j, const Exceptions_attribute *excpt_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", excpt_attr->attribute_length}
      }
    },
    {"specific info", json::array()}
  };
  // clang-format on
}

static void create_json_str(json *j, const InnerClasses_attribute *inner_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", inner_attr->attribute_length}
      }
    },
    {"specific info", json::array()}
  };
  // clang-format on
}

static void create_json_str(json *j,
                            const EnclosingMethod_attribute *enclosing_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", enclosing_attr->attribute_length}
      }
    },
    {"specific info", {
      {"class index", {}},
      {"method index", {}}
    }}
  };
  // clang-format on
}

static void create_json_str(json *j,
                            const Signature_attribute *signature_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", signature_attr->attribute_length}
      }
    },
    {"specific info", {
      {"signature index", {}}
    }}
  };
  // clang-format on
}

static void create_json_str(json *j,
                            const SourceFile_attribute *sourcefile_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", sourcefile_attr->attribute_length}
      }
    },
    {"specific info", {
        {"source file", {}}
      }
    },
  };
  // clang-format on
}

static void create_json_str(json *j,
                            const LineNumberTable_attribute *lnt_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", lnt_attr->attribute_length}
      }
    },
    {"specific info", json::array()},
  };
  // clang-format on
}

static void create_json_str(json *j,
                            const LocalVariableTable_attribute *lvt_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", lvt_attr->attribute_length}
      }
    },
    {"specific info", json::array()},
  };
  // clang-format on
}

static void create_json_str(json *j,
                            const BootstrapMethods_attribute *bootstrap_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", bootstrap_attr->attribute_length}
      }
    },
    {"specific info", json::array()},
  };
  // clang-format on
}

static void create_json_str(
    json *j, const MethodParameters_attribute *methodparams_attr) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", methodparams_attr->attribute_length}
      }
    },
    {"specific info", json::array()},
  };
  // clang-format on
}

static void create_json_str(json *j, const NotImplemented *not_implemented) {
  // clang-format off
  *j = {
    {"generic info", {
        {"name", {}},
        {"length", not_implemented->attribute_length}
      }
    },
    {"specific info", nullptr},
  };
  // clang-format on
}

void AttributeSerializer::to_json(json *j, const int &attrindex) {
  auto kpool_serializer = ConstantPool::ConstantPoolSerializer(this->cf);
  auto attr = this->attrs[attrindex];

  auto utf8nameindex =
      this->cf->constant_pool[attr.base->attribute_name_index - 1];
  auto kutf8 = utf8nameindex.getClass<ConstantPool::CONSTANT_Utf8_info>();
  auto attrName = String::getUtf8Modified(kutf8);
  auto attrtype = getAttributeType(attrName);

  switch (attrtype) {
    case kCONSTANTVALUE: {
      auto kval_attr = attr.getClass<ConstantValue_attribute>();
      create_json_str(j, kval_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               kval_attr->attribute_name_index - 1);
      kpool_serializer.to_json(
          &(*j).at("/specific info/constant value"_json_pointer),
          kval_attr->constantvalue_index - 1);
      break;
    }
    case kCODE: {
      auto code_attr = attr.getClass<Code_attribute>();
      create_json_str(j, code_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               code_attr->attribute_name_index - 1);

      int i = 0, count = 0;
      auto codeArr = code_attr->code;
      auto instr_serializer =
          Instructions::InstructionSerializer(this->cf, codeArr);
      bool iswide = false;
      for (auto it = codeArr.begin(); it != codeArr.end(); ++it, ++count) {
        // clang-format off
        (*j).at("/specific info/bytecode"_json_pointer)[count] = {
          {"code position", i},
          {"mnemonic", Instructions::Opcodes::getMnemonic(*it)},
          {"arguments", json::array()}
        };
        // clang-format on

        auto delta_code = instr_serializer.to_json(
            &(*j).at("/specific info/bytecode"_json_pointer)[count].at(
                "/arguments"_json_pointer),
            &it, &i, &iswide);
        if (delta_code < 0) {
          iswide = true;
          delta_code = std::abs(delta_code);
        } else {
          iswide = false;
        }
        i += delta_code;
      }

      auto kpool_serializer =
          Utils::ConstantPool::ConstantPoolSerializer(this->cf);
      for (auto i = 0; i < code_attr->exception_table_length; ++i) {
        auto except = code_attr->exception_table[i];
        // clang-format off
        (*j).at("/specific info/exception table"_json_pointer)[i] = {
          {"start pc", except.start_pc},
          {"end pc", except.end_pc},
          {"handler pc", except.handler_pc},
          {"catch type", {}}
        };
        // clang-format on

        kpool_serializer.to_json(
            &(*j).at("/specific info/exception table"_json_pointer)[i].at(
                "/catch type"_json_pointer),
            except.catch_type - 1);
      }
      auto oldattrs = this->attrs;
      this->attrs = code_attr->attributes;
      for (auto i = 0; i < code_attr->attributes_count; ++i) {
        this->to_json(&(*j).at("/attributes"_json_pointer)[i], i);
      }
      this->attrs = oldattrs;
      break;
    }
    case kEXCEPTIONS: {
      auto except_attr = attr.getClass<Exceptions_attribute>();
      create_json_str(j, except_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               except_attr->attribute_name_index - 1);
      for (auto i = 0; i < except_attr->number_of_exceptions; ++i) {
        auto except_it = except_attr->exception_index_table[i];
        // clang-format off
        (*j).at("/specific info"_json_pointer)[i] = {
          {"exception", except_it},
          {"verbose", {}}
        };
        // clang-format on
        kpool_serializer.to_json(&(*j).at("/specific info"_json_pointer)[i].at(
                                     "/verbose"_json_pointer),
                                 except_it - 1);
      }
      break;
    }
    case kINNERCLASSES: {
      auto innerclasses_attr = attr.getClass<InnerClasses_attribute>();
      create_json_str(j, innerclasses_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               innerclasses_attr->attribute_name_index - 1);
      for (auto i = 0; i < innerclasses_attr->number_of_classes; ++i) {
        auto inner_info = innerclasses_attr->classes[i];
        // clang-format off
        (*j).at("/specific info"_json_pointer)[i] = {
          {"inner class", {}},
          {"outer class", {}},
          {"inner name", {}},
          {"access flags", getHexByteString(inner_info.inner_class_access_flags, 4)},
        };
        // clang-format on
        kpool_serializer.to_json(&(*j).at("/specific info"_json_pointer)[i].at(
                                     "/inner class"_json_pointer),
                                 inner_info.inner_class_info_index - 1);
        kpool_serializer.to_json(&(*j).at("/specific info"_json_pointer)[i].at(
                                     "/outer class"_json_pointer),
                                 inner_info.outer_class_info_index - 1);
        kpool_serializer.to_json(&(*j).at("/specific info"_json_pointer)[i].at(
                                     "/inner name"_json_pointer),
                                 inner_info.inner_name_index - 1);
      }
      break;
    }
    case kENCLOSINGMETHOD: {
      auto enclosingmethod_attr = attr.getClass<EnclosingMethod_attribute>();
      create_json_str(j, enclosingmethod_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               enclosingmethod_attr->attribute_name_index - 1);
      kpool_serializer.to_json(
          &(*j).at("/specific info/class index"_json_pointer),
          enclosingmethod_attr->class_index - 1);
      kpool_serializer.to_json(
          &(*j).at("/specific info/method index"_json_pointer),
          enclosingmethod_attr->method_index - 1);
      break;
    }
    case kSIGNATURE: {
      auto signature_attr = attr.getClass<Signature_attribute>();
      create_json_str(j, signature_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               signature_attr->attribute_name_index - 1);
      kpool_serializer.to_json(
          &(*j).at("/specific info/signature index"_json_pointer),
          signature_attr->signature_index - 1);
      break;
    }
    case kSOURCEFILE: {
      auto sourcefile_attr = attr.getClass<SourceFile_attribute>();
      create_json_str(j, sourcefile_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               sourcefile_attr->attribute_name_index - 1);
      kpool_serializer.to_json(
          &(*j).at("/specific info/source file"_json_pointer),
          sourcefile_attr->sourcefile_index - 1);
      break;
    }
    case kLINENUMBERTABLE: {
      auto lnt_attr = attr.getClass<LineNumberTable_attribute>();
      create_json_str(j, lnt_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               lnt_attr->attribute_name_index - 1);
      for (auto i = 0; i < lnt_attr->line_number_table_length; ++i) {
        auto lnt_info = lnt_attr->line_number_table[i];
        // clang-format off
        (*j).at("/specific info"_json_pointer)[i] = {
          {"start pc", lnt_info.start_pc},
          {"line number", lnt_info.line_number}
        };
        // clang-format on
      }
      break;
    }
    case kLOCALVARIABLETABLE: {
      auto lvt_attr = attr.getClass<LocalVariableTable_attribute>();
      create_json_str(j, lvt_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               lvt_attr->attribute_name_index - 1);
      for (auto i = 0; i < lvt_attr->local_variable_table_length; ++i) {
        auto lvt_info = lvt_attr->local_variable_table[i];
        // clang-format off
        (*j).at("/specific info"_json_pointer)[i] = {
          {"start pc", lvt_info.start_pc},
          {"length", lvt_info.length},
          {"index", lvt_info.index},
          {"name", {}},
          {"descriptor", {}}
        };
        // clang-format on
        kpool_serializer.to_json(
            &(*j).at("/specific info"_json_pointer)[i].at("/name"_json_pointer),
            lvt_info.name_index - 1);
        kpool_serializer.to_json(&(*j).at("/specific info"_json_pointer)[i].at(
                                     "/descriptor"_json_pointer),
                                 lvt_info.descriptor_index - 1);
      }
      break;
    }
    case kBOOTSTRAPMETHODS: {
      auto bootstrap_attr = attr.getClass<BootstrapMethods_attribute>();
      create_json_str(j, bootstrap_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               bootstrap_attr->attribute_name_index - 1);
      for (auto i = 0; i < bootstrap_attr->num_bootstrap_methods; ++i) {
        auto bootstrap_info = bootstrap_attr->bootstrap_methods[i];
        // clang-format off
        (*j).at("/specific info"_json_pointer)[i] = {
          {"bootstrap method", {}},
          {"arguments", json::array()}
        };
        // clang-format on
        kpool_serializer.to_json(&(*j).at("/specific info"_json_pointer)[i].at(
                                     "/bootstrap method"_json_pointer),
                                 bootstrap_info.bootstrap_method_ref - 1);
        for (int k = 0; k < bootstrap_info.num_bootstrap_arguments; ++k) {
          kpool_serializer.to_json(
              &(*j).at("/specific info"_json_pointer)[i].at(
                  "/arguments"_json_pointer)[k],
              bootstrap_info.bootstrap_arguments[k] - 1);
        }
      }
      break;
    }
    case kMETHODPARAMETERS: {
      auto methodparams_attr = attr.getClass<MethodParameters_attribute>();
      create_json_str(j, methodparams_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               methodparams_attr->attribute_name_index - 1);
      for (auto i = 0; i < methodparams_attr->parameters_count; ++i) {
        auto param_info = methodparams_attr->parameters[i];
        // clang-format off
        (*j).at("/specific info"_json_pointer)[i] = {
          {"parameter name", {}},
          {"access flags", getHexByteString(param_info.access_flags, 4)},
        };
        // clang-format on
        if (param_info.name_index) {
          kpool_serializer.to_json(
              &(*j).at("/specific info"_json_pointer)[i].at(
                  "/parameter name"_json_pointer),
              param_info.name_index - 1);
        } else if (!param_info.name_index) {
          (*j).at("/specific info"_json_pointer)[i].at(
              "/parameter name"_json_pointer) = "no formal parameter name";
        } else {
          (*j).at("/specific info"_json_pointer)[i].at(
              "/parameter name"_json_pointer) =
              "invalid constant pool reference";
        }
      }
      break;
    }
    case kINVALID: {
      auto not_implemented_attr = attr.getClass<NotImplemented>();
      create_json_str(j, not_implemented_attr);
      kpool_serializer.to_json(&(*j).at("/generic info/name"_json_pointer),
                               not_implemented_attr->attribute_name_index - 1);
      break;
    }
  }
}
}  // namespace Attributes
}  // namespace Utils
