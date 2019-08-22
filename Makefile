EXE = jvm
OBJ_DIR = bin
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.cc)
OBJ = $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
CXX = g++
CPPFLAGS = -std=c++11
CFLAGS = -g -Wall -pedantic -pthread -Wpedantic -Werror -lm

.PHONY: all clean

all: createBinFolder $(EXE)

createBinFolder:
ifeq ($(OS), Windows_NT)
	cmd /C createBin.bat
else
	@mkdir -p $(@D)
endif

$(EXE): $(OBJ)
	$(CXX) $^ $(CPPFLAGS) $(CFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

clean:
ifeq ($(OS), Windows_NT)
	del /S /Q bin $(EXE).exe
else
	$(RM) *~ $(OBJ) $(EXE)
endif