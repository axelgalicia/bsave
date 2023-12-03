#-----------------------------------------------------------------
# Names, Files
#-----------------------------------------------------------------
OUTPUT_DIRECTORY := bin
LIB_DIRECTORY := lib
BINARY := bsave

# Source Files
SRCS := main.c \
        $(LIB_DIRECTORY)/diary.c \
        $(LIB_DIRECTORY)/page.c \
        $(LIB_DIRECTORY)/user.c \
        $(LIB_DIRECTORY)/file.c \
        $(LIB_DIRECTORY)/colors.c

# Object Files
OBJS := $(SRCS:.c=.o)

# Compile-Time Flags
CFLAGS := -Wall -g -Wextra

#-----------------------------------------------------------------
# Executables
#-----------------------------------------------------------------
MD := mkdir
CC := clang
RM := rm -rf

.PHONY: all clean create_bin compile execute

all: clean create_bin compile execute

clean:
		$(RM) $(OUTPUT_DIRECTORY) $(OBJS)

create_bin:
		$(MD) -p $(OUTPUT_DIRECTORY)

compile: $(OBJS)
		$(CC) $(CFLAGS) -o $(OUTPUT_DIRECTORY)/$(BINARY) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

execute:
		./$(OUTPUT_DIRECTORY)/$(BINARY)
