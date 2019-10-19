#include "utils/attributes.h"

#include <map>
#include <sstream>
#include "classfile.h"
#include "instructions/printer.h"
#include "utils/accessFlags.h"
#include "utils/constantPool.h"
#include "utils/external/tableformatter.h"
#include "utils/string.h"
#include "viewer.h"

namespace Utils {
namespace Attributes {
int getAttributeType(const std::wstring &attrname) {
  std::map<std::wstring, int> attrTypes = {
      {L"ConstantValue", kCONSTANTVALUE},
      {L"Code", kCODE},
      {L"Exceptions", kEXCEPTIONS},
      {L"InnerClasses", kINNERCLASS},
      {L"EnclosingMethod", kENCLOSINGMETHOD},
      {L"Synthetic", kSYNTHETIC},
      {L"Signature", kSIGNATURE},
      {L"SourceFile", kSOURCEFILE},
      {L"LineNumberTable", kLINENUMBERTABLE},
      {L"LocalVariableTable", kLOCALVARIABLETABLE},
      {L"Deprecated", kDEPRECATED},
      {L"BootstrapMethods", kBOOTSTRAPMETHODS},
      {L"MethodParameters", kMETHODPARAMETERS}};
  try {
    auto type = attrTypes.at(attrname);
    return type;
  } catch (const std::out_of_range &oor) {
    return Utils::Attributes::kINVALID;
  }
}
// ----------------------------------------------------------------------------
std::wstring NotImplemented::getSpecificInfo(const int &delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "NOT IMPLEMENTED\n";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring ConstantValue_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Constant value index: 'cp_info #"
      << this->constantvalue_index << "' ";
  auto constval = constpool[this->constantvalue_index - 1];
  wss << "<";
  switch (constval.base->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_LONG: {
      wss << constval.getClass<cp::CONSTANT_Long_info>()->getValue(constpool);
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      wss << constval.getClass<cp::CONSTANT_Float_info>()->getValue(constpool);
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      wss << constval.getClass<cp::CONSTANT_Double_info>()->getValue(constpool);
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      wss << constval.getClass<cp::CONSTANT_Integer_info>()->getValue(
          constpool);
      break;
    }
    case cp::kCONSTANT_STRING: {
      wss << constval.getClass<cp::CONSTANT_String_info>()->getValue(constpool);
      break;
    }
  }
  wss << ">\n";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring Code_attribute::getTable(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const std::vector<std::string> &header_vars, const int &delta_tab) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(10);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter endpc_col(8);
  endpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter handlerpc_col(12);
  handlerpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter catchtype_col(35);
  catchtype_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter(
      {nr_col, startpc_col, endpc_col, handlerpc_col, catchtype_col});

  // Table header
  for (auto v : header_vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < this->exception_table_length; ++i) {
    auto except = this->exception_table[i];
    std::wstringstream wss;
    wss << "'cp_info #" << except.catch_type << "'\n";
    if (except.catch_type) {
      auto classname = constpool[except.catch_type - 1]
                           .getClass<ConstantPool::CONSTANT_Class_info>();
      wss << classname->getValue(constpool);
    } else {
      wss << "any";
    }
    formatter << i << except.start_pc << except.end_pc << except.handler_pc
              << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  return String::to_wide(formatter.toString(delta_tab)) + L'\n';
}

std::wstring Code_attribute::getSpecificInfo(Viewer *v, const ClassFile *cf,
                                             const int &delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Bytecode: \n";
  int i = 0;
  auto codeArr = this->code;
  for (auto it = codeArr.begin(); it != codeArr.end(); ++it) {
    wss << Instructions::getBytecode(&it, v, &i, delta_tab + 2);
  }

  wss << std::wstring(delta_tab, '\t') << "Exception table: \n";
  std::vector<std::string> header_vars = {
      "Nr.", "Start PC", "End PC", "Handler PC", "Catch type",
  };
  wss << this->getTable(cf->constant_pool, header_vars, delta_tab + 1);

  wss << std::wstring(delta_tab, '\t') << "Misc: \n";
  wss << std::wstring(delta_tab + 1, '\t')
      << "Maximum local variables: " << this->max_locals << "\n";
  wss << std::wstring(delta_tab + 1, '\t')
      << "Code length: " << this->code_length << "\n";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring Exceptions_attribute::getTable(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const std::vector<std::string> &header_vars, const int &delta_tab) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(15);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter linenum_col(30);
  linenum_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, startpc_col, linenum_col});

  // Table header
  for (auto v : header_vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < this->number_of_exceptions; ++i) {
    std::wstringstream wss;
    auto except = this->exception_index_table[i];
    wss << "'cp_info #" << except << "'\n";
    formatter << i << Utils::String::to_string(wss.str());
    wss.str(L"");

    auto classname =
        constpool[except - 1].getClass<ConstantPool::CONSTANT_Class_info>();
    wss << classname->getValue(constpool);

    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  return String::to_wide(formatter.toString(delta_tab)) + L'\n';
}

std::wstring Exceptions_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  std::vector<std::string> header_vars = {"Nr.", "Exception", "Verbose"};
  wss << this->getTable(constpool, header_vars, delta_tab);

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring InnerClasses_attribute::getTable(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const std::vector<std::string> &header_vars, const int &delta_tab) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter innerclass_col(20);
  innerclass_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter outerclass_col(20);
  outerclass_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter innername_col(20);
  innername_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter accessflags_col(25);
  accessflags_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter(
      {nr_col, innerclass_col, outerclass_col, innername_col, accessflags_col});

  // Table header
  for (auto v : header_vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < this->number_of_classes; ++i) {
    auto innerclass = this->classes[i];
    formatter << i;
    std::wstringstream wss;

    wss << "'cp_info #" << innerclass.inner_class_info_index << "'\n";
    auto inner_classname = constpool[innerclass.inner_class_info_index - 1]
                               .getClass<ConstantPool::CONSTANT_Class_info>();
    wss << inner_classname->getValue(constpool);
    formatter << String::to_string(wss.str());
    wss.str(L"");

    wss << "'cp_info #" << innerclass.outer_class_info_index << "'\n";
    if (innerclass.outer_class_info_index) {
      auto outer_classname = constpool[innerclass.outer_class_info_index - 1]
                                 .getClass<ConstantPool::CONSTANT_Class_info>();
      wss << outer_classname->getValue(constpool);
    } else {
      wss << L"invalid constant pool reference";
    }
    formatter << String::to_string(wss.str());
    wss.str(L"");

    wss << "'cp_info #" << innerclass.inner_name_index << "'\n";
    if (innerclass.inner_name_index) {
      auto innername = constpool[innerclass.inner_name_index - 1]
                           .getClass<ConstantPool::CONSTANT_Utf8_info>();
      wss << innername->getValue();
    } else {
      wss << L"invalid constant pool reference";
    }
    formatter << String::to_string(wss.str());
    wss.str(L"");

    wss << Utils::Access::getAccessFlags(
        innerclass.inner_class_access_flags,
        Utils::Access::getNestedClassAccessType);
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  return String::to_wide(formatter.toString(delta_tab)) + L'\n';
}

std::wstring InnerClasses_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  std::vector<std::string> header_vars = {
      "Nr.", "Inner Class", "Outer Class", "Inner Name", "Access Flags",
  };
  wss << this->getTable(constpool, header_vars, delta_tab);

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring EnclosingMethod_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Class index: 'cp_info #"
      << this->class_index << "' ";
  auto classname = constpool[this->class_index - 1]
                       .getClass<ConstantPool::CONSTANT_Class_info>();
  wss << "<" << classname->getValue(constpool) << ">\n";

  wss << std::wstring(delta_tab, '\t') << "Method index: 'cp_info #"
      << this->method_index << "' ";
  if (this->method_index) {
    auto method = constpool[this->method_index - 1]
                      .getClass<ConstantPool::CONSTANT_NameAndType_info>();
    wss << "<" << method->getValue(constpool) << ">\n";
  } else {
    wss << L"invalid constant pool reference\n";
  }

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring Signature_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Signature index: 'cp_info #"
      << this->signature_index << "' ";
  auto signature = constpool[this->signature_index - 1]
                       .getClass<ConstantPool::CONSTANT_Utf8_info>();
  wss << "<" << signature->getValue() << ">\n";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring SourceFile_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  wss << std::wstring(delta_tab, '\t') << "Source file name index: 'cp_info #"
      << this->sourcefile_index << "' ";
  auto sourcefile = constpool[this->sourcefile_index - 1]
                        .getClass<ConstantPool::CONSTANT_Utf8_info>();
  wss << "<" << sourcefile->getValue() << ">\n";

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring LineNumberTable_attribute::getTable(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const std::vector<std::string> &header_vars, const int &delta_tab) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(10);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter linenum_col(15);
  linenum_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, startpc_col, linenum_col});

  // Table header
  for (auto v : header_vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < this->line_number_table_length; ++i) {
    auto lnt_info = this->line_number_table[i];
    formatter << i << lnt_info.start_pc << lnt_info.line_number;
    formatter.addHorizontalLine('_');
  }

  return String::to_wide(formatter.toString(delta_tab)) + L'\n';
}

std::wstring LineNumberTable_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  std::vector<std::string> header_vars = {"Nr.", "Start PC", "Line number"};
  wss << this->getTable(constpool, header_vars, delta_tab);

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring LocalVariableTable_attribute::getTable(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const std::vector<std::string> &header_vars, const int &delta_tab) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(10);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter len_col(8);
  len_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter index_col(8);
  index_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter name_col(20);
  name_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter descriptor_col(20);
  descriptor_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter(
      {nr_col, startpc_col, len_col, index_col, name_col, descriptor_col});

  // Table header
  for (auto v : header_vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < this->local_variable_table_length; ++i) {
    auto localvar_info = this->local_variable_table[i];
    formatter << i << localvar_info.start_pc << localvar_info.length
              << localvar_info.index;

    std::wstringstream wss;
    wss << "'cp_info #" << localvar_info.name_index << "'\n";
    auto name = constpool[localvar_info.name_index - 1]
                    .getClass<ConstantPool::CONSTANT_Utf8_info>();
    wss << name->getValue();
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << "'cp_info #" << localvar_info.descriptor_index << "'\n";
    auto descriptor = constpool[localvar_info.descriptor_index - 1]
                          .getClass<ConstantPool::CONSTANT_Utf8_info>();
    wss << descriptor->getValue();
    formatter << Utils::String::to_string(wss.str());

    formatter.addHorizontalLine('_');
  }

  return String::to_wide(formatter.toString(delta_tab)) + L'\n';
}

std::wstring LocalVariableTable_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  std::vector<std::string> header_vars = {"Nr.",   "Start PC", "Length",
                                          "Index", "Name",     "Descriptor"};
  wss << this->getTable(constpool, header_vars, delta_tab);

  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring BootstrapMethods_attribute::getTable(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const std::vector<std::string> &header_vars, const int &delta_tab) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter bootstrap_col(30);
  bootstrap_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter args_col(55);
  args_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, bootstrap_col, args_col});

  // Table header
  for (auto v : header_vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < this->num_bootstrap_methods; ++i) {
    auto bootstrap_info = this->bootstrap_methods[i];
    formatter << i;

    std::wstringstream wss;
    wss << "'cp_info #" << bootstrap_info.bootstrap_method_ref << "'\n";
    auto methodhandle =
        constpool[bootstrap_info.bootstrap_method_ref - 1]
            .getClass<ConstantPool::CONSTANT_MethodHandle_info>();
    wss << methodhandle->getValue(constpool);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    for (auto j = 0; j < bootstrap_info.num_bootstrap_arguments; ++j) {
      wss << "'cp_info #" << bootstrap_info.bootstrap_arguments[j] << "' <";
      auto bootstrap_arg = constpool[bootstrap_info.bootstrap_arguments[j] - 1];
      switch (bootstrap_arg.base->tag) {
        namespace cp = ConstantPool;
        case cp::kCONSTANT_STRING: {
          auto i = bootstrap_arg.getClass<cp::CONSTANT_String_info>();
          wss << i->getValue(constpool);
          break;
        }
        case cp::kCONSTANT_CLASS: {
          auto i = bootstrap_arg.getClass<cp::CONSTANT_Class_info>();
          wss << i->getValue(constpool);
          break;
        }
        case cp::kCONSTANT_INTEGER: {
          auto i = bootstrap_arg.getClass<cp::CONSTANT_Integer_info>();
          wss << i->getValue(constpool);
          break;
        }
        case cp::kCONSTANT_LONG: {
          auto i = bootstrap_arg.getClass<cp::CONSTANT_Long_info>();
          wss << i->getValue(constpool);
          break;
        }
        case cp::kCONSTANT_FLOAT: {
          auto i = bootstrap_arg.getClass<cp::CONSTANT_Float_info>();
          wss << i->getValue(constpool);
          break;
        }
        case cp::kCONSTANT_DOUBLE: {
          auto i = bootstrap_arg.getClass<cp::CONSTANT_Double_info>();
          wss << i->getValue(constpool);
          break;
        }
        case cp::kCONSTANT_METHODHANDLE: {
          auto i = bootstrap_arg.getClass<cp::CONSTANT_MethodHandle_info>();
          wss << i->getValue(constpool);
          break;
        }
        case cp::kCONSTANT_METHODTYPE: {
          auto i = bootstrap_arg.getClass<cp::CONSTANT_MethodType_info>();
          wss << i->getValue(constpool);
          break;
        }
      }
      wss << ">\n";
    }
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  return String::to_wide(formatter.toString(delta_tab)) + L'\n';
}

std::wstring BootstrapMethods_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  std::vector<std::string> inner_vars = {"Nr.", "Bootstrap Method",
                                         "Arguments"};
  wss << this->getTable(constpool, inner_vars, delta_tab);
  return wss.str();
}
// ----------------------------------------------------------------------------
std::wstring MethodParameters_attribute::getTable(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const std::vector<std::string> &header_vars, const int &delta_tab) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter paramname_col(25);
  paramname_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter accessflags_col(35);
  accessflags_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, paramname_col, accessflags_col});

  // Table header
  for (auto v : header_vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < this->parameters_count; ++i) {
    auto param_info = this->parameters[i];
    formatter << i;
    std::wstringstream wss;

    wss << "'cp_info #" << param_info.name_index << "'\n";
    if (param_info.name_index) {
      auto name = constpool[param_info.name_index - 1]
                      .getClass<ConstantPool::CONSTANT_Utf8_info>();
      wss << name->getValue();
    } else if (!param_info.name_index) {
      wss << "no formal parameter name";
    } else {
      wss << "invalid constant pool reference";
    }
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << Utils::Access::getAccessFlags(
        param_info.access_flags, Utils::Access::getMethodParamsAccessType);
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  return String::to_wide(formatter.toString(delta_tab)) + L'\n';
}

std::wstring MethodParameters_attribute::getSpecificInfo(
    const std::vector<Utils::ConstantPool::cp_info> &constpool,
    const int &delta_tab) {
  std::wstringstream wss;
  std::vector<std::string> inner_vars = {"Nr.", "Parameter Name",
                                         "Access Flags"};
  wss << this->getTable(constpool, inner_vars, delta_tab);
  return wss.str();
}
}  // namespace Attributes
}  // namespace Utils
