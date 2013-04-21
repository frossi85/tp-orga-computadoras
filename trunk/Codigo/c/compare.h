/* ****************************************************************************
 * ****************************************************************************
 *
 * LIBRERÍA SHELLSORT
 *
 * ****************************************************************************
 * ***************************************************************************/



#ifndef COMPARE_H
#define COMPARE_H



// Funcion que compara dos palabras y determina cual es menor alfanumericamente
// PRE: 'word1' y 'word2' son las palabras a comparar
// POST: devuelve un entero indicando el orden
// - < 0 word1 es menor a word2
// - > 0 word2 es menor a word1
// - = 0 word1 es igual a word2
int compare(const char* word1, const char* word2);


#endif