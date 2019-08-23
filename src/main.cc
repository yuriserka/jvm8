#include <iostream>
#include "../include/classfile.h"
#include "../include/flags.h"
#include "../include/errors.h"
#include "../include/reader.h"

int main(const int argc, const char **argv) {
    Utils::Flags::toggleAll(++argv);

    auto cf = new ClassFile();
    auto r = new Reader(Utils::Flags::kFILE);

    try {
        r->readClassFile(cf);
    }
    catch (const std::exception &e) {
        delete cf;
        delete r;
        if (Utils::Flags::kVERBOSE) {
            std::cout << "\tA exception happened\n";
        }
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    delete cf;
    delete r;

    return 0;
}
