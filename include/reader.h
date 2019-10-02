#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include "classfile.h"
#include "utils/constantPool.h"
#include "utils/errors.h"

class Reader {
 public:
  explicit Reader(ClassFile *cf, const std::string &fpath);

  ~Reader() {
    if (this->file.is_open()) {
      this->file.close();
    }
  }

  void readClassFile();
  std::string fname;

 private:
  void readMagic();
  void readMinorVersion();
  void readMajorVersion();

  void readConstantPool();
  void readConstantPoolCount();
  void readConstantPoolInfo();

  void readAccessFlags();
  void readThisClass();
  void readSuperClass();

  void readInterfaces();
  void readInterfaceCount();
  void readInterfaceInfo();

  void readFields();
  void readFieldsCount();
  void readFieldsInfo();

  void readMethods();
  void readMethodsCount();
  void readMethodsInfo();

  void readAttributes();
  void readAttributesCount();
  void readAttributesInfo(
      std::vector<Utils::Attributes::attribute_info> *attributes);

  template <class T>
  inline void endianSwap(T *objp) {
    auto memp = reinterpret_cast<unsigned char *>(objp);
    std::reverse(memp, memp + sizeof(T));
  }

  template <typename T>
  inline void readBytes(T *objp) {
    this->file.read(reinterpret_cast<char *>(objp), sizeof(T));
    this->endianSwap(objp);
  }

  void kpoolValidEntry(const Utils::Types::u2 &index,
                       const std::string &indexname);

  template <typename T>
  T *kpoolValidInfo(const Utils::Types::u2 &index, const std::string &indexname,
                    const Utils::Types::u1 &tag) {
    this->kpoolValidEntry(index, indexname);
    auto kinfo = this->classfile->constant_pool[index - 1].getClass<T>();
    if (!kinfo) {
      throw Utils::Errors::Exception(
          Utils::Errors::kATTRIBUTE,
          "The constant_pool entry at " + indexname +
              " index must be a "
              "CONSTANT_" +
              Utils::ConstantPool::getConstantTypename(tag) +
              "_info structure");
    }
    return kinfo;
  }

  std::fstream file;
  ClassFile *classfile;
};

#endif  // INCLUDE_READER_H_
