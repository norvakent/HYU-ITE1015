main: main.o
	g++ main.o -o main

main.o: main.cpp BasicCard.h MagStripeDevice.h RFIDDevice.h StudentID.h 
	g++ -c main.cpp

clean:
	rm -f main main.o