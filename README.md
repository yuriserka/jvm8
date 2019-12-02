# sbzada

repositório com o fim de fazer a JVM 8.

## Oracle Documentation

Oracle documentation avaible at: [Java SE 8](https://docs.oracle.com/javase/specs/jvms/se8/html/index.html)

## Usage

#### Linux:
`make clean && make`

`make && ./jvm.out {viewer, interpreter} <PATH> <FILE> [options]* [--args] [arguments]*`

#### Windows:
`mingw32-make.exe clean`

`mingw32-make.exe`

`make && .\jvm.exe {viewer, interpreter} <PATH> <FILE> [options]* [--args] [arguments]*`

## Avaible Command Line Options

### PATH
path to the program search for class files

### FILE
the actual class file to be executed by jvm

### arguments
list of parameters to be passed to the interpreter, i.e. to the main method

### Options
 - **-d, -debug**: interpreter flag, shows what instruction is being executed and the actual PC

 - **-json**: viewer flag, generates a json file that represents the structure of .class file passed

 - **-v, -verbose**: both modes flag, shows what is executing during program

 - **-i, -ignore**: no use

## Debugging

Make sure you have GDB installed.

Compile the program normally according to your operating system.

`gdb --args make && ./jvm.out {viewer, interpreter} <PATH> <FILE> [options]* [--args] [arguments]*`

#### Basic commands
consult the commands: [GDB Command Line Arguments](http://www.yolinux.com/TUTORIALS/GDB-Commands.html)
 

## Running Dynamic Code Analysis (only on Linux)

Make sure you have valgrind installed.

Compile the program normally according to your operating system.

```make && valgrind -v --leak-check=full --track-origins=yes --show-leak-kinds=all make && ./jvm.out {viewer, interpreter} <PATH> <FILE> [options]* [--args] [arguments]*```

## Code style reference
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

#### Running Static Code Checker
Make sure that you have Python and pip installed.

- installing: `pip install cpplint`
- running: `cpplint --recursive ./[src|include]`

#### Running Code Formatter (only on Linux)
Make sure that you have clang and clang-format installed

- installing: `sudo apt install clang clang-format`
- running: `./formatter ./[src|include]`

## Generating Documentation
Make sure that you have Doxygen installed.

- installing:

   Linux: `sudo apt install doxygen`<br/>
   Windows: [Click here to download](http://doxygen.nl/files/doxygen-1.8.16-setup.exe)

- running: `doxygen .\Doxyfile`

## Generating test files
Make sure you have Java 8u231 installed.

Follow the steps to install [JDK 8](https://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)

Follow the steps to install [JRE 8](https://www.oracle.com/technetwork/pt/java/javase/downloads/jre8-downloads-2133155.html)

- generating:

   Linux: `make tests`<br/>
   Windows: `mingw32-make tests`

- running:

   `cd .\classes\`

   `java <nome da classe>`

## Authors

### Cláudio Roberto Barros - 19/0097591
### Gabriel Alves Castro - 17/0033813
### Matheus breder - 17/0018997
### Yuri Serka do Carmo Rodrigues - 17/0024385