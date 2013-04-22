/* ****************************************************************************
 * PROGRAMA DE ORDENAMIENTO DE PALABRAS
 * ****************************************************************************
 * 
 * Facultad de Ingenieria - UBA
 * 66.20 Organizacion de computadoras
 * Trabajo Practico N°0: Conjunto de instrucciones MIPS
 * 
 * ALUMNOS: 
 * 
 * Facundo Rossi (86707) - frossi85@gmail.com
 * Federico Colangelo () - 
 * Federico Martin Rossi (92086) - federicomrossi@gmail.com
 *
 * ****************************************************************************
 *
 * Programa que... [ Colocar texto aqui ]
 *
 *
 *
 * FORMA DE USO
 * ============
 * 
 *  [ Colocar texto aqui ]
 *
 */


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "bubblesort.h"
#include "shellsort.h"
#include "fileloader.h"

void testFileLoader(const char * url)
{
	char * text;
	char ** words = NULL;
	int wordsSize = 0;

	text = file_loader(url);
	
	if (text != NULL)
	{
		//fputs(text, stdout);
	}

	wordsSize = to_words(text, &words);

	for(int i = 0; i < wordsSize; i++)
	{
		fputs("\n", stdout);
		fputs(words[i], stdout);
		fputs("\n", stdout);
	}	
}



/* ****************************************************************************
 * FUNCIONES AUXILIARES
 * ***************************************************************************/


// Funcion que imprime por pantalla el mensaje de ayuda del programa.
void ayudaImprimirSalidaEstandar()
{
	printf("tp0 [OPTIONS] [files...]\n");
	printf("-h, --help\t\t\t display this help and exit.\n");
	printf("-V, --version\t\t\t display version information and exit.\n");
	printf("-m, --bubble\t\t\t use the bubblesort algorithm.\n");
	printf("-s, --sel\t\t\t use the shellsort algorithm.\n\n");
	printf("$echo -n echo 'El tractorcito rojo que silbo y bufo' > entrada.txt\n");
	printf("$tp0 -b entrada.txt\n");
	printf("bufo El que rojo silbo tractorcito y\n\n");
	printf("cat letters.txt\n");
	printf("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ$\n\n");
	printf("$tp0 letters.txt\n");
	printf("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ\n$\n\n");
	printf("$tp0 letters.txt entrada.txt\n");
	printf("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ bufo El que rojo silbo tractorcito y\n$\n");
}


// Funcion que imprime por pantalla la version del programa.
void versionImprimirSalidaEstandar()
{
	printf("Programa de ordenamiento de palabras\nVersión: v0.1\n");
}


// Funcion que imprime los resultados del ordenamiento a traves de la salida
// estandar.
void ordenamientoImprimirSalidaEstandar(char* palabras[], int arraysize)
{
	int i;
	for(i = 0; i < arraysize; printf("%s ", palabras[i++]));
	printf("\n");
}





/* ****************************************************************************
 * PROGRAMA PRINCIPAL
 * ***************************************************************************/


int main(int argc, char **argv) 
{
	//testFileLoader("/home/facundo/c/prueba");

	
	char *cvalue = NULL;
	int c;

	//File loader variables
	char * text;
	char ** words = NULL;
	int wordsSize = 0;

	opterr = 0;

	while ((c = getopt(argc, argv, "hVb:s:")) != -1)
	{
		switch (c)
		{
			// Ayuda
			case 'h':
				ayudaImprimirSalidaEstandar();
				break;

			// Version
			case 'V':
				versionImprimirSalidaEstandar();
				break;

			// Ejecucion de bubblesort
			case 'b':
				cvalue = optarg;
				printf("TEMP: %s\n", cvalue);

				text = file_loader(cvalue);

				if (text == NULL)
					break;
	
				wordsSize = to_words(text, &words);

				if (wordsSize == -1)
					break;
				
				bubblesort(words, wordsSize);
				ordenamientoImprimirSalidaEstandar(words, wordsSize);
				break;

			// Ejecucion de shellsort
			case 's':
				cvalue = optarg;
				printf("TEMP: %s\n", cvalue);

				text = file_loader(cvalue);
				
				if (text == NULL)
					break;

				wordsSize = to_words(text, &words);

				if (wordsSize == -1)
					break;

				shellsort(words, wordsSize);
				ordenamientoImprimirSalidaEstandar(words, wordsSize);
				break;
			
			// No se especifica nombre de archivo
			case '?':
				// Ejecutar bubblesort con texto desde entrada 
				// estandar
				if(optopt == 'b')
				{
					// Ingresar texto por entrada estandar y parsearlo
					// bubblesort(words, arraysize);
					// ordenamientoImprimirSalidaEstandar(words, arraysize);
					
					// DEBUG
					char* s[7] = {"El", "tractorcito", "rojo", "que", "silbo", "y", "bufo"};
					bubblesort(s, 7);
					ordenamientoImprimirSalidaEstandar(s, 7);
					// END-DEBUG

					break;
				}
				// Ejecutar shellsort con texto desde entrada
				// estandar
				else if(optopt == 's')
				{
					// Ingresar texto por entrada estandar y parsearlo
					// shellsort(words, arraysize);
					// ordenamientoImprimirSalidaEstandar(words, size);

					// DEBUG
					char* s[7] = {"El", "tractorcito", "rojo", "que", "silbo", "y", "bufo"};
					shellsort(s, 7);
					ordenamientoImprimirSalidaEstandar(s, 7);
					// END-DEBUG

					break;
				}

			default:
				opterr = 1;
				break;
		}
	}


/*
	printf ("aflag = %d, bflag = %d, cvalue = %s\n", aflag, bflag, cvalue);
     
	for (index = optind; index < argc; index++)
		printf ("Non-option argument %s\n", argv[index]);
*/

	if(opterr || argc <= 1)
	{
		fprintf (stderr, "Los argumentos no son válidos.\n");
		printf("Tipee 'tp0 -h' para ver el modo de uso.\n");
	}


	return 0;
}

