# Makefile for SDL3 Game Project with modular directories

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Isrc -Iinclude $(shell pkg-config --cflags sdl3)
LDFLAGS = $(shell pkg-config --libs sdl3)

# Directories
SRC_DIR = src
INC_DIR = include

# Source files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/setup.c $(SRC_DIR)/keyboard.c

# Output binary
TARGET = main

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Clean target
clean:
	rm -f $(TARGET)
