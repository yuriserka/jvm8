# sbzada

repositório com o fim de fazer a JVM 8.

## Oracle Documentation

Documentação da Oracle disponível em: [Java SE 8](https://docs.oracle.com/javase/specs/jvms/se8/html/index.html)

## Usage

#### Linux:
`make clean && make`

`./jvm.out interpreter ./classes/ anon.class`

#### Windows:
`mingw32-make.exe clean`

`mingw32-make.exe`

`.\jvm.exe viewer .\classes\ .\.classes\Anon.class -json`

## Debugging

Make sure you have GDB installed.

Compile the program normally according to your operating system.

`gdb --args ./jvm.out viewer ./classes/ ./classes/Caixa.class`

#### Basic commands
consult the commands: [GDB Command Line Arguments](http://www.yolinux.com/TUTORIALS/GDB-Commands.html)
 

## Running Dynamic Code Analysis (only on Linux)

Make sure you have valgrind installed.

Compile the program normally according to your operating system.

```make && valgrind -v --leak-check=full --track-origins=yes --show-leak-kinds=all ./jvm.out interpreter ./classes/ anon.class```

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