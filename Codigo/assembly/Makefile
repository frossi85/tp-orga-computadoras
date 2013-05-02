CC=gcc
FLAGS=-std=gnu99
CLEAN=rm

all: main

main: compare.o shellsort.o swap.o suma.o
	$(CC) $(FLAGS) compare.o shellsort.o swap.o suma.o main.c -o main

compare.o: compare.S
	gcc -c compare.S -o compare.o

suma.o: suma.S
	gcc -c suma.S -o suma.o

swap.o: swap.S
	gcc -c swap.S -o swap.o

shellsort.o: shellsort.S
	gcc -c shellsort.S -o shellsort.o

clean: 
	$(CLEAN) *.o

