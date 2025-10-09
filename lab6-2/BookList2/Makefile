all: main

main: main.o Book.o Booklist.o
	g++ main.o Book.o Booklist.o -o main

main.o: main.cpp Book.h Booklist.h
	g++ -c main.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp

Booklist.o: Booklist.cpp Booklist.h Book.h
	g++ -c Booklist.cpp

clean:
	rm -f main main.o Book.o Booklist.o