# Object files
ofiles = main.o Book.o Library.o

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++98 -Wall -g -fsanitize=address

# Target to create the main executable
main: $(ofiles)
	$(CXX) $(CXXFLAGS) $(ofiles) -o main

# Compile main.o
main.o: main.cpp Book.h Library.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Compile Book.o
Book.o: Book.cpp Book.h
	$(CXX) $(CXXFLAGS) -c Book.cpp -o Book.o

# Compile Library.o
Library.o: Library.cpp Library.h Book.h
	$(CXX) $(CXXFLAGS) -c Library.cpp -o Library.o

# Run the main executable
run: main
	./main

# Clean up object files and executable
clean:
	rm -f $(ofiles) main
