# Makefile for problem1
all: main

main: main.o calculator.o complex_number.o
	g++ main.o calculator.o complex_number.o -o main
main.o: main.cpp calculator.h complex_number.h
	g++ -c main.cpp
calculator.o: calculator.cpp calculator.h complex_number.h
	g++ -c calculator.cpp
complex_number.o: complex_number.cpp complex_number.h
	g++ -c complex_number.cpp
clean:
	rm -f main main.o calculator.o complex_number.o