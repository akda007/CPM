

CC = gcc	
CFLAGS = -I/mingw64/include/glib-2.0 -I/mingw64/lib/glib-2.0/include -I. -I./src/argsparser/argslib
LIBS = -lglib-2.0 -lintl -dirent

BIN = bin
SRC = src
OBJ = obj

OBJS = $(wildcard $(OBJ)/*.o)

TARGET_NAME = cpm.exe

all: $(TARGET_NAME)

$(TARGET_NAME): $(OBJS) $(OBJ)/main.o $(OBJ)/argslib.o $(OBJ)/parser.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(LIBS) $(CFLAGS) -c $< -o $@

$(OBJ)/argslib.o: $(SRC)/argsparser/argslib/args.c $(SRC)/argsparser/argslib/args.h
	$(CC) $(LIBS) $(CFLAGS) -c $< -o $@

$(OBJ)/parser.o: $(SRC)/argsparser/parser.c $(SRC)/argsparser/parser.h
	$(CC) $(LIBS) $(CFLAGS) -c $< -o $@

.PHONY: all