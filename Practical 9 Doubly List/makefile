# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++98 -fsanitize=address

# Find all source files and generate corresponding object files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Define the target
TARGET = main

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compiling source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)
	rm -f $(TARGET) $(OBJS)


# Run memory leak detection using 'leaks'
leaks: $(TARGET)
	leaks --atExit -- ./$(TARGET)

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)
