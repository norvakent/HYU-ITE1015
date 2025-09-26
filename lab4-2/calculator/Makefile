main: main.o calc.o io.o
	g++ -o main main.o calc.o io.o

main.o: my_func.h main.cpp
	g++ -c main.cpp

calc.o: my_func.h calc.cpp
	g++ -c calc.cpp

io.o: my_func.h io.cpp
	g++ -c io.cpp
