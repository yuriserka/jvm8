#include <locale.h>
#include <iostream>
#include "classfile.h"
#include "reader.h"
#include "utils/errors.h"
#include "utils/flags.h"
#include "utils/serializers/classfileSerializer.h"
#include "viewer.h"

int main(const int argc, const char **argv) {
  setlocale(LC_ALL, "");
  // argv[0] = ./jvm
  Utils::Flags::toggleAll(++argv);

  auto cf = new ClassFile();
  auto r = new Reader(cf, Utils::Flags::options.kFILE);
  auto v = new Viewer(cf, r->fname);

  try {
    r->readClassFile();
    if (Utils::Flags::options.kJSON) {
      auto cfSerializer = ClassFileSerializer(cf);
      json j;
      cfSerializer.to_json(&j);
      std::ofstream o("classfile_structure.json");
      o << std::setw(2) << j << std::endl;
      if (Utils::Flags::options.kVERBOSE) {
        std::cout << "json file dump complete\n";
      }
    } else {
      v->printClassFile();
    }
  } catch (const Utils::Errors::Exception &e) {
    delete r;
    delete v;
    delete cf;
    if (Utils::Flags::options.kVERBOSE) {
      std::cout << "\tA exception happened\n";
    }
    std::cerr << "Error Code: " << e.errorCode() << "\nMessage: " << e.what()
              << "\n";
    return EXIT_FAILURE;
  }

  delete r;
  delete v;
  delete cf;

  return 0;
}
