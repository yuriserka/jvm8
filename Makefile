# https://pt.wikibooks.org/wiki/Programar_em_C/Makefiles
EXEC_NAME := jvm
BUILD_DIR := build
SRC_DIR := src
DEP_DIR := $(BUILD_DIR)/.deps
OBJ_DIR := $(BUILD_DIR)/.objs

# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

ifeq ($(OS), Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS), Windows)
	SRCS := $(call rwildcard,src/,*.cc)
	JAVA_SRC := $(call rwildcard,.javasrc/,*.java)
	MAKE_DIR = @cmd /C create_dir.bat $(@D)
	DEL_FILES = @del /s /q build $(EXEC).exe
	EXEC := $(EXEC_NAME)
else
	SRCS := $(shell find src -name '*.cc')
	JAVA_SRC := $(shell find .javasrc -name '*.java')
	MAKE_DIR = @mkdir -p $(@D)
	DEL_FILES = $(RM) *~ $(OBJS) $(DEPS) $(EXEC)
	EXEC := $(EXEC_NAME).out
endif

OBJS := $(SRCS:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
JAVA_OBJS := $(JAVA_SRC:.javasrc/%.java=classes/%.class)
DEPS := $(SRCS:$(SRC_DIR)/%.cc=$(DEP_DIR)/%.d)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
CXX := g++
INCLUDES := -I"include/"
CXXFLAGS := -std=c++11
CFLAGS := $(INCLUDES) -g -Wall -pedantic -Wpedantic -Werror -lm -pthread

# $@  Nome da regra. 
# $<  Nome da primeira dependência 
# $^ Lista de dependências
# $? Lista de dependências mais recentes que a regra.
# $* Nome do arquivo sem sufixo

.PHONY: all clean tests

all: $(EXEC)

tests: $(JAVA_OBJS)

classes/%.class: .javasrc/%.java
	@$(MAKE_DIR)
	@echo Compiling $<
	@javac -cp .javasrc $< -d classes -g -parameters

$(EXEC): $(OBJS)
	@echo Generating executable $@
	@$(CXX) $^ $(CXXFLAGS) $(CFLAGS) -o $@

$(DEP_DIR)/%.d: $(SRC_DIR)/%.cc
	@$(MAKE_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(DEP_DIR)/%.d
	@$(MAKE_DIR)
	@echo Compiling $<
	@$(CXX) -c $< $(DEPFLAGS) $(CXXFLAGS) $(CFLAGS) -o $@

$(DEPS):
include $(wildcard $(DEPS))

clean:
	@$(DEL_FILES)

-include $(wildcard $(DEPS))