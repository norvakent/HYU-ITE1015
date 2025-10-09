main : main.o Date.o DateCalculator.o
	g++ -o main main.o Date.o DateCalculator.o

main.o : Date.h DateCalculator.h main.cpp
	g++ -c main.cpp

Date.o : Date.h Date.cpp
	g++ -c Date.cpp

DateCalculator.o : DateCalculator.h DateCalculator.cpp
	g++ -c DateCalculator.cpp
