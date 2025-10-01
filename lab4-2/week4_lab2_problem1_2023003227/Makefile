main: main.o map.o explode.o check.o
	g++ -o main main.o map.o explode.o check.o

main.o: func.h main.cpp
	g++ -c main.cpp

map.o: func.h map.cpp
	g++ -c map.cpp

explode.o: func.h explode.cpp
	g++ -c explode.cpp

check.o: func.h check.cpp
	g++ -c check.cpp