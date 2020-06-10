all: DoubleLETT.o test.o exe



exe: DoubleLETT.o test.o
	g++ DoubleLETT.o test.o -o exe


DoubleLETT.o: DoubleLETT.cpp DoubleLETT.hpp
	g++ -c DoubleLETT.cpp



test.o: DoubleLETT.hpp test.cpp
	g++ -c test.cpp