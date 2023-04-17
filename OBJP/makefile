main : main.o funkcijos.o
	g++ -std=c++20 -o main main.o funkcijos.o
	del *.o
main.o: main.cpp
	g++ -std=c++20 -c main.cpp
funkcijos.o: funkcijos.cpp funkcijos.h
	g++ -std=c++20 -c funkcijos.cpp