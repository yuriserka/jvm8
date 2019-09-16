#include <locale.h>
#include <iostream>
#include "include/classfile.h"
#include "include/reader.h"
#include "include/viewer.h"
#include "utils/errors.h"
#include "utils/flags.h"

int main(const int argc, const char **argv) {
  setlocale(LC_ALL, "");
  // argv[0] = ./jvm
  Utils::Flags::toggleAll(++argv);

  auto cf = new ClassFile();
  auto r = new Reader(cf, Utils::Flags::kFILE);
  auto v = new Viewer(cf, r->fname);

  try {
    r->readClassFile();
    v->printClassFile();
  } catch (const std::exception &e) {
    delete cf;
    delete r;
    delete v;
    if (Utils::Flags::kVERBOSE) {
      std::cout << "\tA exception happened\n";
    }
    std::cerr << e.what() << "\n";
    return EXIT_FAILURE;
  }

  delete cf;
  delete r;
  delete v;

  return 0;
}
