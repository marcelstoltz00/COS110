CXX = g++
CXXFLAGS = -Wall -g -std=c++98 -fsanitize=address


SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)


TARGET = main


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


run: $(TARGET)
	./$(TARGET)
	make clean



leaks: $(TARGET)
	leaks --atExit -- ./$(TARGET)


clean:
	rm -f $(TARGET) $(OBJS)

