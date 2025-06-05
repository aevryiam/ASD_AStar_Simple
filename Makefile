# Makefile for Graph A* Program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Target executable
TARGET = graph_astar

# Source files
SOURCES = graph_astar.cpp

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Clean build files
clean:
	del $(TARGET).exe 2>nul || echo "No executable to clean"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help
help:
	@echo Available targets:
	@echo   all     - Build the program
	@echo   clean   - Remove built files
	@echo   run     - Build and run the program
	@echo   help    - Show this help message

.PHONY: all clean run help
