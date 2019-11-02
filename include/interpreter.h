#ifndef INCLUDE_INTERPRETER_H_
#define INCLUDE_INTERPRETER_H_

#include "utils/frame.h"

class Interpreter {
 public:
  Interpreter(const ClassFile *cf, const std::string &fname) {
    this->classname = fname;
    this->entry_class = cf;
    this->init();
  }

  void run();

 private:
  std::string classname;
  void init() { std::cout << "criando as coisas pra thread...\n"; }
  const ClassFile *entry_class;
};

#endif  // INCLUDE_INTERPRETER_H_
