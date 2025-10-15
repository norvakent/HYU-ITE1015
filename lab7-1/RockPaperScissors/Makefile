main: main.o Person.o Player.o Enemy.o
	g++ main.o Person.o Player.o Enemy.o -o main

main.o: main.cpp Person.h Player.h Enemy.h
	g++ -c main.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

Player.o: Player.cpp Person.h Player.h
	g++ -c Player.cpp

Enemy.o: Enemy.cpp Person.h Enemy.h
	g++ -c Enemy.cpp

clean:
	rm -f main main.o Person.o Player.o Enemy.o