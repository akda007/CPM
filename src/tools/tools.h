#ifndef DIRTOOLS_H
#define DIRTOOLS_H

#include <stdbool.h>    

#pragma region Makefile_TEXT

#define MAKEFILE_TEXT "CC = gcc\n" \
                      "\n" \
                      "SRC_DIRS = ./src\n"\
                      "\n" \
                      "SRCS := $(shell find $(SRC_DIRS) -name *.c)\n"\
                      "OBJS := $(addsuffix .o,$(basename $(SRCS)))\n"\
                      "DEPS := $(OBJS:.o=.d)"\
                      "\n" \
                      "INC_DIRS := $(shell find $(SRC_DIRS) -type d)\n"\
                      "INC_FLAGS := $(addprefix -I,$(INC_DIRS))\n"\
                      "\n" \
                      "CFLAGS := -g3 -Wall $(INC_FLAGS) -MMD -MP\n"\
                      "\n" \
                      "\n" \
                      "$(TARGET): $(OBJS)\n"\
                      "	$(CC) $(CFLAGS) $(OBJS) -o $@\n"\
                      "\n" \
                      ".PHONY: clean\n"\
                      "\n" \
                      "clean:"\
                      "	find . -type f -name '*.o' -delete\n"\
                      "	find . -type f -name '*.d' -delete\n"\
                      "\n" \
                      "-include $(DEPS)"

#pragma endregion


bool containsFile(char * dir, const char * file);

#endif