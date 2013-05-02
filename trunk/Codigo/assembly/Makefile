CC=gcc
FLAGS=-std=gnu99
CLEAN=rm

all: tp0

tp0: bubblesort.o shellsortasm.o fileloader.o tp0.c
	$(CC) $(FLAGS) bubblesort.o shellsort.o fileloader.o compare.o swap.o tp0.c -o tp0

bubblesort.o: bubblesort.h bubblesort.c
	$(CC) $(FLAGS) -c bubblesort.c -o bubblesort.o

shellsortc.o: shellsort.h shellsort.c
	$(CC) $(FLAGS) -c shellsort.c -o shellsort.o

fileloader.o: fileloader.h fileloader.c
	$(CC) $(FLAGS) -c fileloader.c -o fileloader.o

compare.o: compare.S
	$(CC) -c compare.S -o compare.o

swap.o: swap.S
	$(CC) -c swap.S -o swap.o

shellsortasm.o: compare.o swap.o shellsort.S
	$(CC) -c shellsort.S -o shellsort.o

clean:
	rm *.o
