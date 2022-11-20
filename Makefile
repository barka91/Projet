CPP=g++ --std=c++11 -Wall

all : test

Tuile.o : Tuile.cpp Tuile.hpp
	$(CPP) -c Tuile.cpp

test.o : test.cpp Tuile.hpp
	$(CPP) -c test.cpp

test : Tuile.o test.o
	$(CPP) -o test test.o Tuile.o

clean :
	rm *.o *.exe