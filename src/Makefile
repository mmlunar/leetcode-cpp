# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

# Default to main.cpp if no MAIN_FILE is provided
MAIN_FILE ?= main.cpp
TARGET = $(MAIN_FILE:.cpp=)  # Remove the .cpp extension for the target name

# Print debugging information
$(info Target: $(TARGET))
$(info Sources: $(MAIN_FILE) CustomAssert.cpp)

SRCS = $(MAIN_FILE) CustomAssert.cpp
HEADERS = CustomAssert.h
OBJ = $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to compile .cpp files to .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create the final executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Custom rule to build and run the program
run: $(TARGET)
	./$(TARGET)  # Replace with $(TARGET).exe on Windows if needed

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean run
