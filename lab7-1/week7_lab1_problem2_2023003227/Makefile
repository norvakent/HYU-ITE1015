# Makefile for problem2

all: main

main: main.o Board.o ChessPiece.o
	g++ main.o Board.o ChessPiece.o -o main

main.o: main.cpp Board.h ChessPiece.h
	g++ -c main.cpp

Board.o: Board.cpp Board.h ChessPiece.h
	g++ -c Board.cpp

ChessPiece.o: ChessPiece.cpp ChessPiece.h Board.h
	g++ -c ChessPiece.cpp

clean:
	rm -f main main.o Board.o ChessPiece.o
