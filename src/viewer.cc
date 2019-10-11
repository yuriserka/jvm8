#include "viewer.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "instructions/printer.h"
#include "utils/accessFlags.h"
#include "utils/constantPool.h"
#include "utils/memory.h"
#include "utils/reference_kind.h"
#include "utils/string.h"
#include "utils/table.h"
#include "utils/utf8.h"
#include "utils/versions.h"

static std::ios state(NULL);

static void makeTitle(const std::string &title, const int &size,
                      const int &width, const int &depht = 0) {
  state.copyfmt(std::cout);
  std::cout << std::string(depht, '\t') << std::setfill('*') << std::setw(size)
            << "\n";
  std::cout.copyfmt(state);
  std::cout << std::setw(width) << title << "\n";
  state.copyfmt(std::cout);
  std::cout << std::string(depht, '\t') << std::setfill('*') << std::setw(size)
            << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printClassFile() {
  std::cout << "\n\tVisualizing ClassFile structure for " << this->classname
            << "\n";
  makeTitle("General Information", 80, 50);
  // this->printMagic();
  this->printVersion();
  this->printConstantPoolCount();
  this->printAccessFlags();
  this->printThisClass();
  this->printSuperClass();
  this->printInterfacesCount();
  this->printFieldsCount();
  this->printMethodsCount();
  this->printAttributesCount(0, this->classfile->attributes_count);

  this->printConstantPool();
  this->printInterfaces();
  this->printFields();
  this->printMethods();
  this->printAttributes(this->classfile->attributes,
                        this->classfile->attributes_count, 0, 80, 45);
}

void Viewer::printMagic() {
  state.copyfmt(std::cout);
  std::cout << "Magic: " << std::setw(16) << ' ' << "0x" << std::setfill('0')
            << std::setw(4) << std::hex << std::uppercase
            << this->classfile->magic << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printVersion() {
  state.copyfmt(std::cout);
  std::cout << "Minor version: " << std::setw(8) << ' '
            << this->classfile->minor_version << "\n";
  std::cout << "Major version: " << std::setw(8) << ' '
            << this->classfile->major_version << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printConstantPool() {
  makeTitle("Constant Pool", 80, 45);
  for (int i = 1; i < this->classfile->constant_pool_count; ++i) {
    auto jmpNextIndex = this->printConstantPoolInfo(i, 0);
    if (jmpNextIndex) {
      std::cout << "[" << ++i << "]"
                << " (large numeric continued)\n\n";
    }
  }
}

void Viewer::printConstantPoolCount() {
  state.copyfmt(std::cout);
  std::cout << "Constant Pool Count: " << std::setw(2) << ' '
            << this->classfile->constant_pool_count << "\n";
  std::cout.copyfmt(state);
}

bool Viewer::printConstantPoolInfo(const int index, const int delta_tab) {
  bool jmpNextIndex = false;
  auto kpool = this->classfile->constant_pool;
  auto cpi = this->classfile->constant_pool[index - 1];

  std::cout << std::string(delta_tab, '\t') << "[" << index << "] ";
  auto name = Utils::ConstantPool::getConstantTypename(cpi.base->tag);
  std::cout << "CONSTANT_" << name << "_info\n";

  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<cp::CONSTANT_Class_info>();
      std::wcout << kclass_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<cp::CONSTANT_FieldRef_info>();
      std::wcout << kfieldref_info->getGeneralInfo(kpool, delta_tab + 1)
                 << "\n";
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<cp::CONSTANT_Methodref_info>();
      std::wcout << kmethodref_info->getGeneralInfo(kpool, delta_tab + 1)
                 << "\n";
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info =
          cpi.getClass<cp::CONSTANT_InterfaceMethodref_info>();
      std::wcout << kImethodref_info->getGeneralInfo(kpool, delta_tab + 1)
                 << "\n";
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<cp::CONSTANT_String_info>();
      std::wcout << kstring_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<cp::CONSTANT_Integer_info>();
      std::wcout << kinteger_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<cp::CONSTANT_Float_info>();
      std::wcout << kfloat_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<cp::CONSTANT_Long_info>();
      std::wcout << klong_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<cp::CONSTANT_Double_info>();
      std::wcout << kdouble_info->getGeneralInfo(kpool, delta_tab + 1) << "\n";
      jmpNextIndex = true;
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<cp::CONSTANT_NameAndType_info>();
      std::wcout << knametype_info->getGeneralInfo(kpool, delta_tab + 1)
                 << "\n";
      break;
    }
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<cp::CONSTANT_Utf8_info>();
      std::wcout << kutf8_info->getGeneralInfo(delta_tab + 1) << "\n";
      break;
    }
    case cp::kCONSTANT_METHODHANDLE: {
      auto kmethodhandle_info = cpi.getClass<cp::CONSTANT_MethodHandle_info>();
      std::wcout << kmethodhandle_info->getGeneralInfo(kpool, delta_tab + 1)
                 << "\n";
      break;
    }
    case cp::kCONSTANT_METHODTYPE: {
      auto methodtype_info = cpi.getClass<cp::CONSTANT_MethodType_info>();
      std::wcout << methodtype_info->getGeneralInfo(kpool, delta_tab + 1)
                 << "\n";
      break;
    }
    case cp::kCONSTANT_INVOKEDYNAMIC: {
      auto invokedynamic_info = cpi.getClass<cp::CONSTANT_InvokeDynamic_info>();
      std::wcout << invokedynamic_info->getGeneralInfo(kpool, delta_tab + 1)
                 << "\n";
      break;
    }
  }
  std::cout << "\n";
  return jmpNextIndex;
}

std::wstring Viewer::getConstantPoolInfo(const int &index, const bool &dot) {
  std::wstringstream wss;
  if (!index) {
    wss << "invalid constant pool reference";
    return wss.str();
  }
  auto cpi = this->classfile->constant_pool[index - 1];
  auto kpool = this->classfile->constant_pool;

  switch (cpi.base->tag) {
    namespace cp = Utils::ConstantPool;
    namespace info = Utils::Infos;
    case cp::kCONSTANT_CLASS: {
      auto kclass_info = cpi.getClass<cp::CONSTANT_Class_info>();
      wss << kclass_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_FIELDREF: {
      auto kfieldref_info = cpi.getClass<cp::CONSTANT_FieldRef_info>();
      wss << kfieldref_info->getValue(kpool, dot);
      break;
    }
    case cp::kCONSTANT_METHODREF: {
      auto kmethodref_info = cpi.getClass<cp::CONSTANT_Methodref_info>();
      wss << kmethodref_info->getValue(kpool, dot);
      break;
    }
    case cp::kCONSTANT_INTERFACEMETHODREF: {
      auto kImethodref_info =
          cpi.getClass<cp::CONSTANT_InterfaceMethodref_info>();
      wss << kImethodref_info->getValue(kpool, dot);
      break;
    }
    case cp::kCONSTANT_STRING: {
      auto kstring_info = cpi.getClass<cp::CONSTANT_String_info>();
      wss << kstring_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_INTEGER: {
      auto kinteger_info = cpi.getClass<cp::CONSTANT_Integer_info>();
      wss << kinteger_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_FLOAT: {
      auto kfloat_info = cpi.getClass<cp::CONSTANT_Float_info>();
      wss << kfloat_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_LONG: {
      auto klong_info = cpi.getClass<cp::CONSTANT_Long_info>();
      wss << klong_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_DOUBLE: {
      auto kdouble_info = cpi.getClass<cp::CONSTANT_Double_info>();
      wss << kdouble_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_NAMEANDTYPE: {
      auto knametype_info = cpi.getClass<cp::CONSTANT_NameAndType_info>();
      wss << knametype_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_UTF8: {
      auto kutf8_info = cpi.getClass<cp::CONSTANT_Utf8_info>();
      wss << kutf8_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_METHODHANDLE: {
      auto kmethodhandle_info = cpi.getClass<cp::CONSTANT_MethodHandle_info>();
      wss << kmethodhandle_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_METHODTYPE: {
      auto kmethodtype_info = cpi.getClass<cp::CONSTANT_MethodType_info>();
      wss << kmethodtype_info->getValue(kpool);
      break;
    }
    case cp::kCONSTANT_INVOKEDYNAMIC: {
      auto kinvokedynamic_info =
          cpi.getClass<cp::CONSTANT_InvokeDynamic_info>();
      wss << kinvokedynamic_info->getValue(kpool);
      break;
    }
  }
  return wss.str();
}

void Viewer::printAccessFlags() {
  auto flags = Utils::Access::getClassAccessType(this->classfile->access_flags);
  state.copyfmt(std::cout);
  std::cout << "Access Flags: " << std::setw(11);
  std::cout << "0x" << std::setfill('0') << std::setw(4) << std::hex
            << std::uppercase << this->classfile->access_flags;
  std::cout.copyfmt(state);
  std::cout << " [";
  for (size_t i = 0; i < flags.size(); ++i) {
    std::cout << flags[i] << (i < flags.size() - 1 ? " " : "");
  }
  std::cout << "]\n";
}

void Viewer::printThisClass() {
  std::cout << "This class: " << std::setw(11) << ' ' << "'cp_info #"
            << this->classfile->this_class << "' ";
  std::wcout << "<"
             << this->getConstantPoolInfo(this->classfile->this_class, false)
             << ">\n";
}

void Viewer::printSuperClass() {
  std::cout << "Super class: " << std::setw(10) << ' ' << "'cp_info #"
            << this->classfile->super_class << "' ";
  std::wcout << "<"
             << this->getConstantPoolInfo(this->classfile->super_class, false)
             << ">\n";
}

void Viewer::printInterfaces() {
  makeTitle("Interfaces", 80, 40);
  for (auto i = 0; i < this->classfile->interfaces_count; ++i) {
    this->printInterfaceInfo(i, 1);
  }
}

void Viewer::printInterfacesCount() {
  state.copyfmt(std::cout);
  std::cout << "Interfaces Count: " << std::setw(6)
            << this->classfile->interfaces_count << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printInterfaceInfo(const int &index, const int &tab_shift) {
  auto interfaceidx = this->classfile->interfaces[index];
  std::cout << std::string(tab_shift, '\t') << "Interface " << index << "\n";
  std::cout << std::string(tab_shift + 1, '\t') << "Interface: 'cp_info #"
            << interfaceidx << "' ";
  std::wcout << "<" << this->getConstantPoolInfo(interfaceidx, false) << ">\n";
}

void Viewer::printFields() {
  makeTitle("Fields", 80, 35);
  for (auto i = 0; i < this->classfile->fields_count; ++i) {
    this->printFieldInfo(i, 1);
  }
}

void Viewer::printFieldsCount() {
  state.copyfmt(std::cout);
  std::cout << "Fields Count: " << std::setw(10)
            << this->classfile->fields_count << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printFieldInfo(const int &index, const int &tab_shift) {
  auto field = this->classfile->fields[index];
  std::cout << std::string(tab_shift, '\t') << "[" << index << "] ";
  std::wcout << this->getConstantPoolInfo(field.name_index, false) << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Name: 'cp_info #"
            << field.name_index << "' ";
  std::wcout << "<" << this->getConstantPoolInfo(field.name_index, false)
             << ">\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Descriptor: 'cp_info #"
            << field.descriptor_index << "' ";
  std::wcout << "<" << this->getConstantPoolInfo(field.descriptor_index, false)
             << ">\n";

  Utils::Access::getAccessFlags(field.access_flags,
                                Utils::Access::getFieldAccessType);
  this->printAttributes(field.attributes, field.attributes_count, tab_shift + 1,
                        20, 30);
}

void Viewer::printMethods() {
  makeTitle("Methods", 80, 45);
  for (auto i = 0; i < this->classfile->methods_count; ++i) {
    this->printMethodInfo(i, 1);
  }
}

void Viewer::printMethodsCount() {
  state.copyfmt(std::cout);
  std::cout << "Methods Count: " << std::setw(9)
            << this->classfile->methods_count << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printMethodInfo(const int &index, const int &tab_shift) {
  auto method = this->classfile->methods[index];
  std::cout << std::string(tab_shift, '\t') << "[" << index << "] ";
  std::wcout << this->getConstantPoolInfo(method.name_index, false) << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Name: 'cp_info #"
            << method.name_index << "' ";
  std::wcout << "<" << this->getConstantPoolInfo(method.name_index, false)
             << ">\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Descriptor: 'cp_info #"
            << method.descriptor_index << "' ";
  std::wcout << "<" << this->getConstantPoolInfo(method.descriptor_index, false)
             << ">\n";

  Utils::Access::getAccessFlags(method.access_flags,
                                Utils::Access::getMethodAccessType);
  this->printAttributes(method.attributes, method.attributes_count,
                        tab_shift + 1, 20, 30);
}

void Viewer::printAttributes(
    const std::vector<Utils::Attributes::attribute_info> &attributes,
    const int &attr_count, const int &tab_shift, const int &qtd_stars,
    const int &width_shift) {
  if (!attr_count) {
    return;
  }
  makeTitle("Attributes", qtd_stars, width_shift, tab_shift);
  for (auto i = 0; i < attr_count; ++i) {
    auto attr = attributes[i];
    this->printAttributeInfo(&attr, i, tab_shift + 1);
  }
}

void Viewer::printAttributesCount(const int &tab_shift, const int &attr_count) {
  state.copyfmt(std::cout);
  std::cout << std::string(tab_shift, '\t')
            << "Attributes Count: " << std::setw(6) << attr_count << "\n";
  std::cout.copyfmt(state);
}

void Viewer::printTable(const std::vector<std::string> vars,
                        Utils::Attributes::Code_attribute *code_attr,
                        const int &tab_shift) {
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
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < code_attr->exception_table_length; ++i) {
    auto except = code_attr->exception_table[i];
    std::wstringstream wss;
    wss << "'cp_info #" << except.catch_type << "'\n"
        << this->getConstantPoolInfo(except.catch_type, false);
    formatter << i << except.start_pc << except.end_pc << except.handler_pc
              << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(const std::vector<std::string> vars,
                        Utils::Attributes::LineNumberTable_attribute *lnt_attr,
                        const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(10);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter linenum_col(15);
  linenum_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, startpc_col, linenum_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < lnt_attr->line_number_table_length; ++i) {
    auto lnt_info = lnt_attr->line_number_table[i];
    formatter << i << lnt_info.start_pc << lnt_info.line_number;
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(const std::vector<std::string> vars,
                        Utils::Attributes::Exceptions_attribute *excpt_attr,
                        const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(15);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter linenum_col(30);
  linenum_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, startpc_col, linenum_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < excpt_attr->number_of_exceptions; ++i) {
    auto except = excpt_attr->exception_index_table[i];
    std::wstringstream wss;
    wss << "'cp_info #" << except << "'\n";
    formatter << i << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << this->getConstantPoolInfo(except, false);
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(
    const std::vector<std::string> vars,
    Utils::Attributes::InnerClasses_attribute *innerclass_attr,
    const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter innerclass_col(20);
  innerclass_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter outerclass_col(20);
  outerclass_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter innername_col(20);
  innername_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter accessflags_col(35);
  accessflags_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter(
      {nr_col, innerclass_col, outerclass_col, innername_col, accessflags_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < innerclass_attr->number_of_classes; ++i) {
    auto innerclass = innerclass_attr->classes[i];
    formatter << i;
    std::wstringstream wss;

    wss << "'cp_info #" << innerclass.inner_class_info_index << "'\n"
        << this->getConstantPoolInfo(innerclass.inner_class_info_index, false);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << "'cp_info #" << innerclass.outer_class_info_index << "'\n"
        << this->getConstantPoolInfo(innerclass.outer_class_info_index, false);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << "'cp_info #" << innerclass.inner_name_index << "'\n"
        << this->getConstantPoolInfo(innerclass.inner_name_index, false);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << Utils::Access::getAccessFlags(
        innerclass.inner_class_access_flags,
        Utils::Access::getNestedClassAccessType);
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(
    const std::vector<std::string> vars,
    Utils::Attributes::LocalVariableTable_attribute *localvar_attr,
    const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter startpc_col(10);
  startpc_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter len_col(8);
  len_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter index_col(8);
  index_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter name_col(15);
  name_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter(
      {nr_col, startpc_col, len_col, index_col, name_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < localvar_attr->local_variable_table_length; ++i) {
    auto localvar_info = localvar_attr->local_variable_table[i];
    formatter << i << localvar_info.start_pc << localvar_info.length
              << localvar_info.index;

    std::wstringstream wss;
    wss << "'cp_info #" << localvar_info.name_index << "'\n"
        << this->getConstantPoolInfo(localvar_info.name_index, false);

    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(
    const std::vector<std::string> vars,
    Utils::Attributes::BootstrapMethods_attribute *bootstrap_attr,
    const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter bootstrap_col(30);
  bootstrap_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter args_col(55);
  args_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, bootstrap_col, args_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < bootstrap_attr->num_bootstrap_methods; ++i) {
    auto bootstrap_info = bootstrap_attr->bootstrap_methods[i];
    formatter << i;

    std::wstringstream wss;
    wss << "'cp_info #" << bootstrap_info.bootstrap_method_ref << "'\n"
        << this->getConstantPoolInfo(bootstrap_info.bootstrap_method_ref,
                                     false);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    for (auto j = 0; j < bootstrap_info.num_bootstrap_arguments; ++j) {
      wss << "'cp_info #" << bootstrap_info.bootstrap_arguments[j] << "' <"
          << this->getConstantPoolInfo(bootstrap_info.bootstrap_arguments[j])
          << ">\n";
    }
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printTable(
    const std::vector<std::string> vars,
    Utils::Attributes::MethodParameters_attribute *methodparams_attr,
    const int &tab_shift) {
  namespace tf = tableformatter;

  tf::CellFormatter nr_col(5);
  nr_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter paramname_col(25);
  paramname_col.horizontalAlignment = tf::HORIZONTAL::LEFT;
  tf::CellFormatter accessflags_col(35);
  accessflags_col.horizontalAlignment = tf::HORIZONTAL::LEFT;

  tf::TableFormatter formatter({nr_col, paramname_col, accessflags_col});

  // Table header
  for (auto v : vars) {
    formatter << v;
  }
  formatter.addHorizontalLine('*');

  for (auto i = 0; i < methodparams_attr->parameters_count; ++i) {
    auto param_info = methodparams_attr->parameters[i];
    formatter << i;
    std::wstringstream wss;

    wss << "'cp_info #" << param_info.name_index << "'\n"
        << this->getConstantPoolInfo(param_info.name_index, false);
    formatter << Utils::String::to_string(wss.str());
    wss.str(L"");

    wss << Utils::Access::getAccessFlags(
        param_info.access_flags, Utils::Access::getMethodParamsAccessType);
    formatter << Utils::String::to_string(wss.str());
    formatter.addHorizontalLine('_');
  }

  std::cout << formatter.toString(tab_shift) << '\n';
}

void Viewer::printAttributeInfo(Utils::Attributes::attribute_info *attribute,
                                const int &index, const int &tab_shift) {
  auto utf8nameindex =
      this->classfile->constant_pool[attribute->base->attribute_name_index - 1];
  auto kutf8_info =
      utf8nameindex.getClass<Utils::ConstantPool::CONSTANT_Utf8_info>();
  auto attrName = Utf8(kutf8_info);
  auto attrtype = Utils::Attributes::getAttributeType(attrName.str);

  std::cout << std::string(tab_shift, '\t') << "[" << index << "] ";
  std::wcout << attrName << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Generic Info: \n";
  std::cout << std::string(tab_shift + 2, '\t')
            << "Attribute name index: 'cp_info #"
            << attribute->base->attribute_name_index << "' ";

  std::wcout << "<"
             << this->getConstantPoolInfo(attribute->base->attribute_name_index,
                                          false)
             << ">\n";

  std::cout << std::string(tab_shift + 2, '\t')
            << "Attribute length: " << attribute->base->attribute_length
            << "\n";

  std::cout << std::string(tab_shift + 1, '\t') << "Specific Info: \n";

  switch (attrtype) {
    namespace attrs = Utils::Attributes;
    case attrs::kCONSTANTVALUE: {
      auto kval_attr = attribute->getClass<attrs::ConstantValue_attribute>();
      std::cout << std::string(tab_shift + 2, '\t')
                << "Constant value index: 'cp_info #"
                << kval_attr->constantvalue_index << "' ";
      std::wcout << "<"
                 << this->getConstantPoolInfo(kval_attr->constantvalue_index,
                                              false)
                 << ">\n";
      break;
    }
    case attrs::kCODE: {
      auto code_attr = attribute->getClass<attrs::Code_attribute>();
      std::cout << std::string(tab_shift + 2, '\t') << "Bytecode: \n";
      int i = 0;
      auto codeArr = code_attr->code;
      for (auto it = codeArr.begin(); it != codeArr.end(); ++it) {
        std::cout << std::string(tab_shift + 3, '\t') << i << ": ";
        Instructions::printBytecode(&it, this, &i);
      }

      std::cout << std::string(tab_shift + 2, '\t') << "Exception table: \n";
      std::vector<std::string> except_vars = {
          "Nr.", "Start PC", "End PC", "Handler PC", "Catch type",
      };
      this->printTable(except_vars, code_attr, tab_shift + 3);

      std::cout << std::string(tab_shift + 2, '\t') << "Misc: \n";
      std::cout << std::string(tab_shift + 3, '\t')
                << "Maximum local variables: " << code_attr->max_locals << "\n";
      std::cout << std::string(tab_shift + 3, '\t')
                << "Code length: " << code_attr->code_length << "\n";
      this->printAttributes(code_attr->attributes, code_attr->attributes_count,
                            tab_shift + 1, 20, 47);
      break;
    }
    case attrs::kEXCEPTIONS: {
      auto exception_attr = attribute->getClass<attrs::Exceptions_attribute>();
      std::vector<std::string> except_vars = {
          "Nr.",
          "Exception",
          "Verbose",
      };
      this->printTable(except_vars, exception_attr, tab_shift + 2);
      break;
    }
    case attrs::kINNERCLASS: {
      auto innerclass_attr =
          attribute->getClass<attrs::InnerClasses_attribute>();

      std::vector<std::string> inner_vars = {
          "Nr.", "Inner Class", "Outer Class", "Inner Name", "Access Flags",
      };
      this->printTable(inner_vars, innerclass_attr, tab_shift + 2);
      break;
    }
    case attrs::kENCLOSINGMETHOD: {
      auto enclosing_attr =
          attribute->getClass<attrs::EnclosingMethod_attribute>();
      std::cout << std::string(tab_shift + 2, '\t') << "Class index: 'cp_info #"
                << enclosing_attr->class_index << "' ";
      std::wcout << "<"
                 << this->getConstantPoolInfo(enclosing_attr->class_index,
                                              false)
                 << ">\n";

      std::cout << std::string(tab_shift + 2, '\t')
                << "Method index: 'cp_info #" << enclosing_attr->method_index
                << "' ";
      std::wcout << "<"
                 << this->getConstantPoolInfo(enclosing_attr->method_index,
                                              false)
                 << ">\n";
      std::cout << ">\n";
      break;
    }
    case attrs::kSYNTHETIC: {
      break;
    }
    case attrs::kSIGNATURE: {
      auto signature_attr = attribute->getClass<attrs::Signature_attribute>();
      std::cout << std::string(tab_shift + 2, '\t')
                << "Signature index: 'cp_info #"
                << signature_attr->signature_index << "' ";
      std::wcout << "<"
                 << this->getConstantPoolInfo(signature_attr->signature_index,
                                              false)
                 << ">\n";
      break;
    }
    case attrs::kSOURCEFILE: {
      auto sourcefile_attr = attribute->getClass<attrs::SourceFile_attribute>();
      std::cout << std::string(tab_shift + 2, '\t')
                << "Source file name index: 'cp_info #"
                << sourcefile_attr->sourcefile_index << "' ";
      std::wcout << "<"
                 << this->getConstantPoolInfo(sourcefile_attr->sourcefile_index,
                                              false)
                 << ">\n";
      break;
    }
    case attrs::kLINENUMBERTABLE: {
      auto lnt_attr = attribute->getClass<attrs::LineNumberTable_attribute>();
      std::vector<std::string> vars = {"Nr.", "Start PC", "Line number"};
      this->printTable(vars, lnt_attr, tab_shift + 2);
      break;
    }
    case attrs::kLOCALVARIABLETABLE: {
      auto localvar_attr =
          attribute->getClass<attrs::LocalVariableTable_attribute>();
      std::vector<std::string> vars = {"Nr.", "Start PC", "Length", "Index",
                                       "Name"};
      this->printTable(vars, localvar_attr, tab_shift + 2);
      break;
    }
    case attrs::kDEPRECATED: {
      break;
    }
    case attrs::kBOOTSTRAPMETHODS: {
      auto bootstrap_attr =
          attribute->getClass<attrs::BootstrapMethods_attribute>();

      std::vector<std::string> inner_vars = {"Nr.", "Bootstrap Method",
                                             "Arguments"};
      this->printTable(inner_vars, bootstrap_attr, tab_shift + 2);
      break;
    }
    case attrs::kMETHODPARAMETERS: {
      auto methodparams_attr =
          attribute->getClass<attrs::MethodParameters_attribute>();
      std::vector<std::string> inner_vars = {"Nr.", "Parameter Name",
                                             "Access Flags"};
      this->printTable(inner_vars, methodparams_attr, tab_shift + 2);
      break;
    }
    case attrs::kINVALID: {
      std::cout << std::string(tab_shift + 2, '\t') << "NOT IMPLEMENTED\n";
      break;
    }
  }
}
