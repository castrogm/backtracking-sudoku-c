# Compiler to use
CC = gcc

# Compiler flags (enable warnings and set include directory)
CFLAGS = -Wall -Iinclude

# Project directories
SRC_DIR = src
OBJ_DIR = obj

# Find all .c files in the src directory and define corresponding .o files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Name of the final executable
TARGET = sudoku_solver

# Default rule to build the project
all: $(TARGET)

# Rule to link the object files and build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files into .o object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to clean up compiled files and the executable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets to prevent conflicts with files named 'all' or 'clean'
.PHONY: all clean