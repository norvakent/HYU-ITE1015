all: main

main: main.o
	g++ main.o -o main

main.o: main.cpp CPUCore.h IOFeeder.h
	g++ -c main.cpp

clean:
	rm -f main main.o