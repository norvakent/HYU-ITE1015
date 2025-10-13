all: main

main: main.o GameManager.o Player.o Question.o
	g++ main.o GameManager.o Player.o Question.o -o main

main.o: main.cpp GameManager.h Player.h Question.h
	g++ -c main.cpp

GameManager.o: GameManager.cpp GameManager.h Player.h Question.h
	g++ -c GameManager.cpp

Player.o: Player.cpp Player.h Question.h
	g++ -c Player.cpp

Question.o: Question.cpp Question.h
	g++ -c Question.cpp

clean:
	rm -f main main.o GameManager.o Player.o Question.o