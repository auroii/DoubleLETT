all: DoubleLETT.o test.o exe



exe: DoubleLETT.o test.o
	g++ -std=c++17 DoubleLETT.o test.o -o exe


DoubleLETT.o: DoubleLETT.cpp DoubleLETT.hpp
	g++ -std=c++17 -c DoubleLETT.cpp



test.o: DoubleLETT.hpp test.cpp
	g++ -std=c++17 -c test.cpp


run:
	./exe <in