
CC = gcc

TARGET = cpm.exe

SRC_DIRS = ./src

FIND = C:\msys64\usr\bin\find.exe

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := -I/mingw64/include/glib-2.0 -I/mingw64/lib/glib-2.0/include \
		  -I/mingw64/lib/glib-2.0/glib -I. -I./src/argsparser/argslib \
		  -Wall $(INC_FLAGS) -MMD -MP

LIBS := -lglib-2.0 -lintl

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.PHONY: clean shell

shell:
	@echo $(SHELL)

clean:
	rm -rf *.exe
	find . -type f -name '*.o' -delete
	find . -type f -name '*.d' -delete

-include $(DEPS)