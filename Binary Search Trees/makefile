hw2: main.o BinarySearchTree.o BinaryNode.o
	g++ main.o BinarySearchTree.o BinaryNode.o  -o hw2

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -c BinarySearchTree.cpp

BinaryNode.o: BinaryNode.h BinaryNode.cpp
	g++ -std=c++11 -c BinaryNode.cpp

clean:
	rm *.o hw2
