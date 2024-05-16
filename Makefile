# Compiler and compiler flags
CXX := g++
CXXFLAGS := -Wall -Werror -DMEMTRACE

# Source files
SRCS := diak.cpp main.cpp memtrace.cpp oktato.cpp szemely.cpp telefonkonyv.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Target executable
TARGET := telefonkonyv

# Default target
all: $(TARGET)

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rules to compile source files into object files with their dependencies
diak.o: diak.cpp diak.h szemely.h memtrace.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp telefonkonyv.h diak.h oktato.h memtrace.h szemely.h gtest_lite.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

memtrace.o: memtrace.cpp memtrace.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

oktato.o: oktato.cpp oktato.h szemely.h memtrace.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

szemely.o: szemely.cpp szemely.h memtrace.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

telefonkonyv.o: telefonkonyv.cpp telefonkonyv.h diak.h oktato.h szemely.h memtrace.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the directory
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
