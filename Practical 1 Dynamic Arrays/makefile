ofiles = main.o testingFramework.o DynamicArrays.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp testingFramework.h DynamicArrays.h
	$(gpp_o) main.cpp

testingFramework.o: testingFramework.cpp testingFramework.h
	$(gpp_o) testingFramework.cpp

DynamicArrays.o: DynamicArrays.cpp DynamicArrays.h 
	$(gpp_o) DynamicArrays.cpp

run: main
	./main

clean:
	rm *.o main
