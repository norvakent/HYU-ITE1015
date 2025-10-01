main: main.o omok.o map.o rules.o
	g++ -o main main.o omok.o map.o rules.o

main.o: func.h main.cpp
	g++ -c main.cpp

omok.o: func.h omok.cpp
	g++ -c omok.cpp

map.o: func.h map.cpp
	g++ -c map.cpp

rules.o: func.h rules.cpp
	g++ -c rules.cpp