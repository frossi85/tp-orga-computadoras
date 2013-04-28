#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern int sumador(int *, size_t);

//extern void shellsort(char* [], int arraysize);

//extern void shellsort(char**, size_t arraysize);

extern char * swap(char **, int, int);

extern void shellsort(char **, size_t);

int main (int argc, char** argv)
{
	char **words;
	int i;
	int numeros[4] = {1, 5, 78, 8};

	words = malloc(4*sizeof(char*));

	for (i=0;i<4;i++) {
		words[i]=malloc(20*sizeof(char));
	}

	words[0]="hola mundo\0";
	words[1]="que tal\0";
	words[2]="como\0";
	words[3]="estas\0";

	for (i=0;i<4;i++) {
		puts(words[i]);
	}

	printf("Size of size_t = %d\n", sizeof(size_t));

	printf("Size of int * = %d\n", sizeof(int *));

	printf("Size of int = %d\n", sizeof(int));

	printf("Size of char * = %d\n", sizeof(char*));

	printf("Size of char ** = %d\n", sizeof(char**));

	printf("Suma del array = %d\n", sumador(numeros, 4));

	printf("Resultado swap = %s\n",swap(words, 0, 3));

	printf("words[0] ahora es = %s\n", words[0]);
	printf("words[3] ahora es = %s\n", words[3]);

	return 0;

}
