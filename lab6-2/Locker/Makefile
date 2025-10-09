all: main

main: main.o locker.o
	g++ main.o locker.o -o main

main.o: main.cpp Locker.h
	g++ -c main.cpp

locker.o: Locker.cpp Locker.h
	g++ -c Locker.cpp

clean:
	rm -f main main.o locker.o