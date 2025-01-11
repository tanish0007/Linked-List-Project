# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Target Executable
TARGET = linked_list

# Source Files
SRC = main.c

# Build the Program
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean Build Files
clean:
	rm -f $(TARGET)

# phony targets
.PHONY: all clean