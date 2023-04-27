main : main.o funkcijos.o studentas.o
	g++ -std=c++20 -O3 -o main main.o funkcijos.o studentas.o
	del *.o
main.o: main.cpp
	g++ -std=c++20 -O3 -c main.cpp
funkcijos.o: funkcijos.cpp
	g++ -std=c++20 -O3 -c funkcijos.cpp
studentas.o: studentas.cpp
	g++ -std=c++20 -O3 -c studentas.cpp