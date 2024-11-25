# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++98 -fsanitize=address

# Targets and dependencies
TARGET = main
OBJECTS = main.o testingFramework.o inventory.o item.o

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Compiling source files
main.o: main.cpp testingFramework.h inventory.h item.h
	$(CXX) $(CXXFLAGS) -c main.cpp

testingFramework.o: testingFramework.cpp testingFramework.h
	$(CXX) $(CXXFLAGS) -c testingFramework.cpp

inventory.o: inventory.cpp inventory.h item.h
	$(CXX) $(CXXFLAGS) -c inventory.cpp

item.o: item.cpp item.h
	$(CXX) $(CXXFLAGS) -c item.cpp

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run the program with leaks for leak detection
leaks: $(TARGET)
	leaks -atExit -- ./$(TARGET)

# Clean up generated files
clean:
	rm -f *.o $(TARGET)
