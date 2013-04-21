/* ****************************************************************************
 * ****************************************************************************
 *
 * LIBRERIA PARA COMPARACION DE PALABRAS
 *
 * ****************************************************************************
 * ***************************************************************************/

#include "compare.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>




/* ****************************************************************************
 * FUNCIONES AUXILIARES
 * ***************************************************************************/

// Funcion que convierte una palabra a minusculas.
// PRE: 'palabra' es una cadena de caraceteres.
// POST: 'palabra' se convirtio en minusculas.
void palabraAMinuscula(char* palabra)
{
	int i;
	for (i = 0; palabra[i]; i++)
		palabra[i] = tolower(palabra[i]);
}




/* ****************************************************************************
 * FUNCIONES DE LA LIBRERIA
 * ***************************************************************************/


// Funcion que compara dos palabras y determina cual es menor alfanumericamente
// PRE: 'word1' y 'word2' son las palabras a comparar
// POST: devuelve un entero indicando el orden
// - < 0 word1 es menor a word2
// - > 0 word2 es menor a word1
// - = 0 word1 es igual a word2
int compare(const char* word1, const char* word2) 
{
	// Creamos una copia de las palabras
	char w1[strlen(word1)];
	char w2[strlen(word2)];
	strcpy(w1, word1);
	strcpy(w2, word2);

	// Convertimos en minusculas las palabras copiadas
	palabraAMinuscula(w1);
	palabraAMinuscula(w2);

	// Hacemos comparacion y devolvemos resultado
	return strcmp(w1, w2);
}