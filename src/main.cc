#include <locale.h>
#include <iostream>
#include "classfile.h"
#include "interpreter.h"
#include "reader.h"
#include "utils/errors.h"
#include "utils/fileSystem.h"
#include "utils/flags.h"
#include "utils/serializers/classfileSerializer.h"
#include "viewer.h"

void dumpJsonFile(const ClassFile *cf, const std::string &filename);

int main(const int argc, const char **argv) {
  setlocale(LC_ALL, "");

  ClassFile *entry_classfile = new ClassFile();
  Reader *r = nullptr;
  Viewer *v = nullptr;
  Interpreter *i = nullptr;

  try {
    // argv[0] = ./jvm
    Utils::Flags::toggleAll(++argv);

    std::string comando;
#if defined(_WIN32) || defined(WIN32)
    comando = "cmd /C chcp 65001";
#endif
    auto ret = system(comando.c_str());
    if (ret == -1) {
      namespace err = Utils::Errors;
      throw err::Exception(err::kUTF8,
                           "Error Setting UTF-8 enconding to terminal");
    }

    r = new Reader(entry_classfile, Utils::Flags::options.kFILE);

    r->readClassFile();
    if (Utils::Flags::options.KMODE.kVIEWER) {
      v = new Viewer(entry_classfile, r->fname);
      v->printClassFile();

      if (Utils::Flags::options.kJSON) {
        dumpJsonFile(entry_classfile, r->fname);
        if (Utils::Flags::options.kVERBOSE) {
          std::cout << "json file dump complete\n";
        }
      }
    } else {
      i = new Interpreter(entry_classfile, r->fname);
      i->run();
    }
  } catch (const Utils::Errors::Exception &e) {
    delete i;
    delete v;
    delete r;
    delete entry_classfile;
    if (Utils::Flags::options.kVERBOSE) {
      std::cout << "\tA exception happened\n";
    }
    std::cout << "Error Code: " << e.errorCode() << "\nMessage: " << e.what()
              << "\n";
    return EXIT_FAILURE;
  }

  delete i;
  delete v;
  delete r;
  delete entry_classfile;

  return 0;
}

void dumpJsonFile(const ClassFile *cf, const std::string &filename) {
  auto cfSerializer = ClassFileSerializer(cf);
  json j;
  cfSerializer.to_json(&j);
  const std::string outdir = "./.out/";
  Utils::FileSystem::makeDirectory(outdir.c_str());
  const std::string classname = filename.substr(0, filename.find_last_of('.'));
  const std::string path = outdir + '/' + classname + "_structure.json";
  std::ofstream o(path);
  o << std::setw(2) << j << std::endl;
}
