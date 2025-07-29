# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -g

# Source and object directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source and object files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# OS detection
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)  # macOS
	CFLAGS += -I/opt/homebrew/include
	LDFLAGS = -L/opt/homebrew/lib -lraylib \
	          -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio
	TARGET = $(BINDIR)/pong-mac
else  # Assume Windows (MinGW or similar)
	LDFLAGS = -lraylib -lwinmm -lgdi32 -luser32
	TARGET = $(BINDIR)/pong.exe
endif

# Ensure folders exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Default target
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean
