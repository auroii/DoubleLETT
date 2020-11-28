all: Utils.o Node.o DoubleLETT.o driver.o exe



exe: DoubleLETT.o Utils.o Node.o driver.o
	g++ -O3 -std=c++17 Utils.o Node.o DoubleLETT.o driver.o -o exe


DoubleLETT.o: DoubleLETT.cpp Utils.hpp Node.hpp DoubleLETT.hpp
	g++ -O3 -std=c++17 -c DoubleLETT.cpp


Node.o: Node.cpp Node.hpp
	g++ -O3 -std=c++17 -c Node.cpp 

driver.o: Utils.hpp DoubleLETT.hpp Node.hpp driver.cpp
	g++ -O3 -std=c++17 -c driver.cpp

Utils.o: Utils.hpp Utils.cpp
	g++ -O3 -std=c++17 -c Utils.cpp


run:
	./exe <in