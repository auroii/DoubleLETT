all: Node.o Edge.o DoubleLETT.o test.o exe



exe: DoubleLETT.o Edge.o Node.o test.o
	g++ -std=c++17 Node.o Edge.o DoubleLETT.o test.o -o exe


DoubleLETT.o: DoubleLETT.cpp Node.hpp Edge.hpp DoubleLETT.hpp
	g++ -std=c++17 -c DoubleLETT.cpp


Node.o: Node.cpp Node.hpp
	g++ -std=c++17 -c Node.cpp 

test.o: Edge.hpp DoubleLETT.hpp Node.hpp test.cpp
	g++ -std=c++17 -c test.cpp


Edge.o: Edge.hpp Node.hpp Edge.cpp
	g++ -std=c++17 -c Edge.cpp




run:
	./exe <in