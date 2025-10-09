main : main.o VendingMachine.o
	g++ -o main main.o VendingMachine.o

main.o : VendingMachine.h main.cpp
	g++ -c main.cpp

VendingMachine.o : VendingMachine.h VendingMachine.cpp
	g++ -c VendingMachine.cpp
