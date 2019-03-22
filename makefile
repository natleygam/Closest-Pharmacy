ex1: main.o Pharmacies.o
	g++ -std=c++11 -g -Wall main.o -g Pharmacies.o -o ex1

main.o: main.cpp Pharmacies.h
	g++ -std=c++11 -g -Wall -c main.cpp

Pharmacies.o: Pharmacies.h Pharmacies.cpp
	g++ -std=c++11 -g -Wall -c Pharmacies.cpp

clean:
	rm *.o ex1
