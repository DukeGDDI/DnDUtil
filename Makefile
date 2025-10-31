# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Ilib -Isource -Itests \
            -I/usr/src/googletest/googletest/include

# Directories
SRC_DIR := source
TEST_DIR := tests
BUILD_DIR := build
BIN := $(BUILD_DIR)/tests

# Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)
OBJS := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o) \
        $(TEST_FILES:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.test.o)

# GTest static library paths (change if you installed elsewhere)
GTEST_LIB_DIR := $(HOME)/.local/gtest-build/lib
LIBS := -L$(GTEST_LIB_DIR) -lgtest -lgtest_main -pthread

# Default target: build + run
all: run

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/%.test.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link everything into a single test binary
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

# Run tests
run: $(BIN)
	@echo "==============================="
	@echo " Running all GoogleTests..."
	@echo "==============================="
	@./$(BIN)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
