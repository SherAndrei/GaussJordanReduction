#Commands
MKDIR := mkdir
RMDIR := rm -rf

#Folders to make life easier
BIN 	:= ./bin
OBJ 	:= ./obj
INCLUDE := ./include
SRC 	:= ./src

#Compiler features
CC     := gcc
CFLAGS :=  -Wextra -Wpedantic -Wall -I$(INCLUDE)
 #-Werror
LIBS   := -lm

#Variables
EXE  := $(BIN)/main
SRCS := $(wildcard $(SRC)/*.c)
OBJS := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))	

# $@ - the left side of the :
# $^ - the right side of the :
# $< - the first item in the dependencies list
# -c flag says to generate the object file

$(EXE): $(OBJS) | $(BIN)
	$(CC) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) -c $< -o $@ $(CFLAGS) $(LIBS)

$(BIN) $(OBJ):
	$(MKDIR) $@

.PHONY: clean debug

clean:
	$(RMDIR) $(OBJ) $(BIN)

debug: CFLAGS += -g -O0
debug: $(EXE)