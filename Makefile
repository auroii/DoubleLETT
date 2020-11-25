all: Node.o DoubleLETT.o test.o exe



exe: DoubleLETT.o Node.o test.o
	g++ -std=c++17 Node.o DoubleLETT.o test.o -o exe


DoubleLETT.o: DoubleLETT.cpp Node.hpp DoubleLETT.hpp
	g++ -std=c++17 -c DoubleLETT.cpp


Node.o: Node.cpp Node.hpp
	g++ -std=c++17 -c Node.cpp 

test.o: DoubleLETT.hpp Node.hpp test.cpp
	g++ -std=c++17 -c test.cpp





run:
	./exe <in