CC=g++ -c -g -Wall -ansi -pedantic

runMe: test.o MovieCollection.o Movie.o MovieNode.o
	g++ -o runMe test.o MovieCollection.o Movie.o MovieNode.o

test.o: test.cpp MovieCollection.hpp Movie.hpp MovieNode.hpp
	$(CC) test.cpp

MovieCollection.o: MovieCollection.cpp MovieCollection.hpp
	$(CC) MovieCollection.cpp

Movie.o: Movie.cpp Movie.hpp
	$(CC) Movie.cpp
	
MovieNode.o: MovieNode.cpp MovieNode.hpp
	$(CC) MovieNode.cpp
