#include "../include/classFile.h"

#include <iostream>

auto main() -> int {
    auto classfile = new ClassFile("Caixa.class");
    classfile->magic =  classfile->readNBytes<Utils::Types::u4>(4);

    std::cout << "0x" << std::hex << std::uppercase << classfile->magic << "\n";
    
    delete classfile;

    return 0;
}