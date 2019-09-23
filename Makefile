# https://pt.wikibooks.org/wiki/Programar_em_C/Makefiles
EXEC := jvm
BUILD_DIR := bin
SRC_DIR := src
DEP_DIR := $(BUILD_DIR)/.deps

# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

ifeq ($(OS), Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS), Windows)
	SRC := $(call rwildcard,src/,*.cc)
	# SRC := $(wildcard $(SRC_DIR)/*.cc) $(wildcard $(SRC_DIR)/**/*.cc $(wildcard $(SRC_DIR)/**/**/*.cc)
	MAKE_DIR = @cmd /C createBin.bat $(@D)
	DEL_FILES = @del /s /q bin $(EXEC).exe
else
	SRC := $(shell find src -name '*.cc')
	MAKE_DIR = @mkdir -p $(@D)
	DEL_FILES = $(RM) *~ $(OBJ) $(DEP) $(EXEC)
endif

OBJ := $(SRC:$(SRC_DIR)/%.cc=$(BUILD_DIR)/%.o)
DEP := $(SRC:$(SRC_DIR)/%.cc=$(DEP_DIR)/%.d)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
CC := g++
INCLUDES := -I"include/"
CXXFLAGS := $(INCLUDES) -std=c++11
CFLAGS := -g -Wall -pedantic -pthread -Wpedantic -Werror -lm

# $@  Nome da regra. 
# $<  Nome da primeira dependência 
# $^ Lista de dependências
# $? Lista de dependências mais recentes que a regra.
# $* Nome do arquivo sem sufixo

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ $(CXXFLAGS) $(CFLAGS) -o $@

$(DEP_DIR)/%.d: $(SRC_DIR)/%.cc
	$(MAKE_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc $(DEP_DIR)/%.d | $(DEP_DIR)
	$(MAKE_DIR)
	$(CC) -c $< $(DEPFLAGS) $(CXXFLAGS) $(CFLAGS) -o $@

$(DEP_DIR): ; $(MAKE_DIR)

$(DEP):
include $(wildcard $(DEP))
	
clean:
	$(DEL_FILES)