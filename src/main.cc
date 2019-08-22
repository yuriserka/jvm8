#include "../include/classfile.h"
#include "../include/flags.h"
#include "../include/errors.h"
#include "../include/reader.h"

#include <iostream>

auto main(const int argc, const char **argv) -> int {
    Utils::Flags::toggleAll(++argv);

    auto cf = new ClassFile();
    auto r = new Reader(Utils::Flags::kFILE);

    try {
        r->readClassFile(cf);
    }
    catch(const Utils::Errors::Exception &err) {
        delete cf;
        delete r;
        std::cerr << err.what() << "\n";
        return EXIT_FAILURE;
    }
    
    delete cf;
    delete r;

    return 0;
}