#include "utils/serializers/attributeSerializer.h"

#include "instructions/opcodes.h"
#include "utils/serializers/constpoolSerializer.h"
#include "utils/serializers/instructionSerializer.h"
#include "utils/utf8.h"

namespace Utils {
namespace Attributes {
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

// static void create_json_str(json *j, const Deprecated_attribute *depr_attr)
// {}

// static void create_json_str(json *j, const Exceptions_attribute *excpt_attr)
// {}

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

// static void create_json_str(
//     json *j, const LocalVariableTable_attribute *localvartb_attr) {}

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
  auto is = Utils::ConstantPool::ConstantPoolSerializer(this->cf);
  auto attr = this->attrs[attrindex];

  auto utf8nameindex =
      this->cf->constant_pool[attr.base->attribute_name_index - 1];
  auto kutf8 =
      utf8nameindex.getClass<Utils::ConstantPool::CONSTANT_Utf8_info>();
  auto attrName = Utf8(kutf8);
  auto attrtype = getAttributeType(attrName.str);

  switch (attrtype) {
    case kCODE: {
      auto code_attr = attr.getClass<Code_attribute>();
      create_json_str(j, code_attr);
      is.to_json(&(*j).at("/generic info/name"_json_pointer),
                 code_attr->attribute_name_index - 1);

      int i = 0, count = 0;
      auto codeArr = code_attr->code;
      auto is = Instructions::InstructionSerializer(this->cf, codeArr);
      for (auto it = codeArr.begin(); it != codeArr.end(); ++it, ++count) {
        // clang-format off
        (*j).at("/specific info/bytecode"_json_pointer)[count] = {
          {"code position", i},
          {"mnemonic", Instructions::Opcodes::getMnemonic(*it)},
          {"arguments", json::array()}
        };
        // clang-format on

        auto delta_code = is.to_json(
            &(*j).at("/specific info/bytecode"_json_pointer)[count].at(
                "/arguments"_json_pointer),
            &it);
        i += delta_code;
      }

      auto kpool_serializer =
          Utils::ConstantPool::ConstantPoolSerializer(this->cf);
      for (auto i = 0; i < code_attr->exception_table_length; ++i) {
        auto except = code_attr->exception_table[i];
        // clang-format off
        (*j).at("/specific info/exception table"_json_pointer)[i] = {
          {"nr.", i},
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
    case kCONSTANTVALUE: {
      auto kval_attr = attr.getClass<ConstantValue_attribute>();
      create_json_str(j, kval_attr);
      is.to_json(&(*j).at("/generic info/name"_json_pointer),
                 kval_attr->attribute_name_index - 1);
      is.to_json(&(*j).at("/specific info/constant value"_json_pointer),
                 kval_attr->constantvalue_index - 1);
      break;
    }
    case kDEPRECATED: {
      break;
    }
    case kEXCEPTIONS: {
      break;
    }
    case kLINENUMBERTABLE: {
      auto lnt_attr = attr.getClass<LineNumberTable_attribute>();
      create_json_str(j, lnt_attr);
      is.to_json(&(*j).at("/generic info/name"_json_pointer),
                 lnt_attr->attribute_name_index - 1);
      for (auto i = 0; i < lnt_attr->line_number_table_length; ++i) {
        auto lnt_info = lnt_attr->line_number_table[i];
        // clang-format off
        (*j).at("/specific info"_json_pointer)[i] = {
          {"nr.", i},
          {"start pc", lnt_info.start_pc},
          {"line number", lnt_info.line_number}
        };
        // clang-format on
      }
      break;
    }
    case kLOCALVARIABLETABLE: {
      break;
    }
    case kSOURCEFILE: {
      auto sourcefile_attr = attr.getClass<SourceFile_attribute>();
      create_json_str(j, sourcefile_attr);
      is.to_json(&(*j).at("/generic info/name"_json_pointer),
                 sourcefile_attr->attribute_name_index - 1);
      is.to_json(&(*j).at("/specific info/source file"_json_pointer),
                 sourcefile_attr->sourcefile_index - 1);
      break;
    }
    case kINVALID: {
      auto not_implemented_attr = attr.getClass<NotImplemented>();
      create_json_str(j, not_implemented_attr);
      is.to_json(&(*j).at("/generic info/name"_json_pointer),
                 not_implemented_attr->attribute_name_index - 1);
      break;
    }
  }
}
}  // namespace Attributes
}  // namespace Utils
