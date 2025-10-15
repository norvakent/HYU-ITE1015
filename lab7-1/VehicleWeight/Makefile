all: main

main: main.o Vehicle.o Car.o Truck.o
	g++ main.o Vehicle.o Car.o Truck.o -o main

main.o: main.cpp Vehicle.h Car.h Truck.h
	g++ -c main.cpp

Vehicle.o: Vehicle.cpp Vehicle.h
	g++ -c Vehicle.cpp

Car.o: Car.cpp Car.h Vehicle.h
	g++ -c Car.cpp
	
Truck.o: Truck.cpp Truck.h Vehicle.h
	g++ -c Truck.cpp

clean:
	rm -f main main.o Vehicle.o Car.o Truck.o