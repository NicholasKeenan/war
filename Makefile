#Makefile for card game

game: main.o stringManip.o cardManip.o
	gcc main.o stringManip.o cardManip.o -Wall -o game

main.o: stringManip.o cardManip.o main.c
	gcc main.c -c -Wall -o main.o

stringManip.o: stringManip.c stringManip.h
	gcc stringManip.c -c -Wall -o stringManip.o

cardManip.o: cardManip.c cardManip.h stringManip.h
	gcc cardManip.c -c -Wall -o cardManip.o

clean:
	rm *.o
	rm game