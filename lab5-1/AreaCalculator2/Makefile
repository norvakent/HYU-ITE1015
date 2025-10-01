main : main.o Area.o
	g++ -o main main.o Area.o

main.o : Area.h main.cpp
	g++ -c main.cpp

Area.o : Area.h Area.cpp
	g++ -c Area.cpp
