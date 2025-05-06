# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Isrc -Iinclude \
    -I/opt/homebrew/include/SDL3 -D_THREAD_SAFE

LDFLAGS = -L/opt/homebrew/lib -lSDL3 -lSDL3_image

# Directories
SRC_DIR = src
INC_DIR = include

# Source files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/setup.c $(SRC_DIR)/keyboard.c $(SRC_DIR)/mouse.c ${SRC_DIR}/window_resize.c ${SRC_DIR}/render.c

# Output binary
TARGET = main

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Clean target
clean:
	rm -f $(TARGET)
