all: main

main: main.o
	g++ main.o -o main

main.o: main.cpp MediaLogger.h
	g++ -c main.cpp

clean:
	rm -f main main.o