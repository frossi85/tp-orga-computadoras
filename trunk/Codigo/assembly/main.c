#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//extern int sumador(int *, size_t);

//extern void shellsort(char* [], int arraysize);

//extern void shellsort(char**, size_t arraysize);

extern void shellsort(char **, size_t);

extern char * swap(char **, int, int);

extern int compare(char *, char *);

int main (int argc, char** argv)
{
	char **words;
	int i;
	//int numeros[4] = {1, 5, 78, 8};

	
	
	words = malloc(4*sizeof(char*));

	for (i=0;i<4;i++) {
		words[i]=malloc(20*sizeof(char));
	}

	words[0]="hola\0";
	words[1]="que\0";
	words[2]="Como\0";
	words[3]="estas\0";

	shellsort(words,4);

	
	for (i=0;i<4;i++) {
		puts(words[i]);
	}

	/*
	printf("Size of size_t = %d\n", sizeof(size_t));

	printf("Size of int * = %d\n", sizeof(int *));

	printf("Size of int = %d\n", sizeof(int));

	printf("Size of char = %d\n", sizeof(char));

	printf("Size of char * = %d\n", sizeof(char*));

	printf("Size of char ** = %d\n", sizeof(char**));

	//printf("Suma del array = %d\n", sumador(numeros, 4));

	//printf("Resultado swap = %s\n",swap(words, 0, 3));

	printf("words[0] ahora es = %s\n", words[0]);
	printf("words[3] ahora es = %s\n", words[3]);


	printf(", : %d\n", compare("", ""));
	printf("hola, hola: %d\n", compare("hola", "hola"));
	printf("abcd, defg: %d\n", compare("abcd", "defg"));
	printf("defg, abcd: %d\n", compare("defg", "abcd"));
	printf("hola, holaa: %d\n", compare("hola", "holaa"));
	printf("aaa, aaa: %d\n", compare("aaa", "aaa")); 
	printf("aaa, aaaa: %d\n", compare("aaa", "aaaa"));
	printf("aaaa, aaa: %d\n", compare("aaaa", "aaa"));
	printf("caa, aaa: %d\n", compare("caa", "aaa"));
	printf("aaa, caa: %d\n", compare("aaa", "caa"));
	printf("caa, aaaa: %d\n", compare("caa", "aaaa"));
	printf("aaaa, caa: %d\n", compare("aaaa", "caa"));
	printf("zzz, zzzz: %d\n", compare("zzz", "zzzz"));
	printf("zzzz, zzz: %d\n", compare("zzzz", "zzz"));
	printf("bbb, bbbb: %d\n", compare("bbb", "bbbb"));
	printf("bbbb, bbb: %d\n", compare("bbbb", "bbb"));

	*/	

	return 0;

}
