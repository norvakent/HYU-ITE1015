main : main.o BankAccount.o
	g++ -o main main.o BankAccount.o

main.o : BankAccount.h main.cpp
	g++ -c main.cpp

BankAccount.o : BankAccount.h BankAccount.cpp
	g++ -c BankAccount.cpp
