# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -g

# Libraries to link (adjust for your OS and raylib install)
LIBS = -lraylib -lwinmm -lgdi32 -luser32

# Source and object files
SRCDIR = src
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Output executable
TARGET = pong.exe

# Create object directory if not exist
$(shell mkdir -p $(OBJDIR))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean
