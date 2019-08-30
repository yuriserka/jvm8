EXE := jvm
OBJ_DIR := bin
SRC_DIR := src

ifeq ($(OS), Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS), Windows)
	SRC := $(wildcard $(SRC_DIR)/*.cc) $(wildcard $(SRC_DIR)/**/*.cc)
	MAKE_DIR = @cmd /C createBin.bat $(@D)
	DEL_FILES = @del /s /q bin $(EXE).exe
else
	SRC := $(shell find src -name '*.cc')
	MAKE_DIR = @mkdir -p $(@D)
	DEL_FILES = $(RM) *~ $(OBJ) $(EXE)
endif

OBJ := $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
CXX := g++
INCLUDES := -I"include/"
CPPFLAGS := $(INCLUDES) -std=c++11
CFLAGS := -g -Wall -pedantic -pthread -Wpedantic -Werror -lm

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $^ $(CPPFLAGS) $(CFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(MAKE_DIR)
	$(CXX) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

clean:
	$(DEL_FILES)