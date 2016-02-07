# ==========================================
#   Continuous C Project
# ==========================================

# We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OSTYPE),cygwin)
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
else ifeq ($(OS),Windows_NT)
	CLEANUP = del /F /Q
	MKDIR = mkdir
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

# Path Definitions
PATHU = lib/unity/
PATHS = src/
PATHT = test/
PATHI = include/
PATHB = build/

# Determine our source files
SRCU = $(PATHU)unity.c
SRCS = $(wildcard $(PATHS)*.c)
SRCT = $(wildcard $(PATHT)*.c)
SRC = $(SRCU) $(SRCS) $(SRCT)

# Source files
OBJU = $(patsubst $(PATHU)%.c,$(PATHB)%.o,$(SRCU))
OBJS = $(patsubst $(PATHS)%.c,$(PATHB)%.o,$(SRCS))
OBJT = $(patsubst $(PATHT)%.c,$(PATHB)%.o,$(SRCT))
OBJ = $(OBJU) $(OBJS) $(OBJT)
#OBJ = $(OBJS)


# Other files we care about
DEPENDENCIES = $(PATHU)unity.h $(PATHU)unity_internals.h
TARGET = $(PATHB)test$(TARGET_EXTENSION)

# Tool Definitions
CC=gcc
CFLAGS=-I. -I$(PATHU) -I$(PATHI) -I$(PATHS) -DTEST
COPTIONS:=

.PHONY: all
all: clean coverage

help:
	@echo ""
	@echo "Continous C Build."
	@echo ""
	@echo "Common targets are:"
	@echo ""
	@echo "    all         - Builds the default target."
	@echo "    all         - Builds the default target."
	@echo "test - run tests quickly with the default Python"
	@echo "coverage - check code coverage quickly with the default Python"
	@echo "    clean       - Cleans all build products"


.PHONY: coverage
coverage: flag-coverage test

.PHONY: flag-coverage
flag-coverage:
	$(eval COPTIONS += -fprofile-arcs -ftest-coverage)


.PHONY: test
test: $(PATHB) $(TARGET)
	./$(TARGET)

$(PATHB)%.o:: $(PATHS)%.c $(DEPENDENCIES)
	$(CC) $(COPTIONS) -c $(CFLAGS) $< -o $@

$(PATHB)%.o:: $(PATHT)%.c $(DEPENDENCIES)
	$(CC) -c $(CFLAGS) $< -o $@

$(PATHB)%.o:: $(PATHU)%.c $(DEPENDENCIES)
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET): $(OBJ)
	gcc $(COPTIONS) -o $@ $^

.PHONY: clean
clean:
	$(CLEANUP) $(PATHB)*.o
	$(CLEANUP) $(PATHB)*.gcda
	$(CLEANUP) $(PATHB)*.gcno
	$(CLEANUP) $(TARGET)

$(PATHB):
	$(MKDIR) $(PATHB)