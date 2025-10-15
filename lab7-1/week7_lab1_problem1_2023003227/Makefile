# Makefile for problem1

all: main

main: main.o Bank.o Account.o SavingsAccount.o PremiumAccount.o Employee.o Manager.o Staff.o
	g++ main.o Bank.o Account.o SavingsAccount.o PremiumAccount.o Employee.o Manager.o Staff.o -o main

main.o: main.cpp Employee.h Manager.h Staff.h Bank.h SavingsAccount.h PremiumAccount.h Account.h
	g++ -c main.cpp

Bank.o: Bank.cpp Bank.h Manager.h Staff.h SavingsAccount.h PremiumAccount.h Account.h
	g++ -c Bank.cpp

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

SavingsAccount.o: SavingsAccount.cpp SavingsAccount.h Account.h
	g++ -c SavingsAccount.cpp

PremiumAccount.o: PremiumAccount.cpp PremiumAccount.h Account.h
	g++ -c PremiumAccount.cpp

Employee.o: Employee.cpp Employee.h Bank.h
	g++ -c Employee.cpp

Manager.o: Manager.cpp Manager.h Employee.h Bank.h
	g++ -c Manager.cpp

Staff.o: Staff.cpp Staff.h Employee.h Bank.h
	g++ -c Staff.cpp

clean:
	rm -f main main.o Bank.o Account.o SavingsAccount.o PremiumAccount.o Employee.o Manager.o Staff.o
