# Compiler and compiler flags
CXX := g++
CXXFLAGS := -Wall -Werror

# Source files
SRCS := diak.cpp main.cpp memtrace.cpp oktato.cpp szemely.cpp telefonkonyv.cpp
# Header files
HEADERS := diak.h gtest_lite.h memtrace.h oktato.h szemely.h telefonkonyv.h

# Object files
OBJS := $(SRCS:.cpp=.o)

# Target executable
TARGET := telefonkonyv

# Default target
all: $(TARGET)

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the directory
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
