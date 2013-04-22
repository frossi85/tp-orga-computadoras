/* ****************************************************************************
 * ****************************************************************************
 *
 * LIBRERIA DE CARGA DE ARCHIVO DE PALABRAS
 *
 * ****************************************************************************
 * ***************************************************************************/



#ifndef FILELOADER_H
#define FILELOADER_H

#define INITIAL_BUFFER_SIZE 100

#include <stdbool.h>


// Funcion que carga un archivo de texto a memoria
// PRE: 'fileUrl' es la url completa al archivo a ordenar.
// POST: devuelve la lista de palabras cargadas en memoria
char* file_loader(const char * fileUrl);

int to_words(char * text, char *** result);

bool isEndOfWord(char letter);

#endif
