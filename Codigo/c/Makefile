CC=gcc
FLAGS=-Wall -ansi
CLEAN=rm




all: tp0

tp0: bubblesort.o shellsort.o fileloader.o tp0.o
	gcc -std=gnu99 bubblesort.o shellsort.o fileloader.o tp0.o -o tp0

tp0.o: bubblesort.h shellsort.h fileloader.h tp0.c
	gcc -std=gnu99 -c tp0.c -o tp0.o

bubblesort.o: bubblesort.h bubblesort.c
	gcc -std=gnu99 -c bubblesort.c -o bubblesort.o

shellsort.o: shellsort.h shellsort.c
	gcc -std=gnu99 -c shellsort.c -o shellsort.o

fileloader.o: fileloader.h fileloader.c
	gcc -std=gnu99 -c fileloader.c -o fileloader.o

clean: 
	rm *.o
