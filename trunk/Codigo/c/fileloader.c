/* ****************************************************************************
 * ****************************************************************************
 *
 * LIBRERIA DE CARGA DE ARCHIVO DE PALABRAS
 *
 * ****************************************************************************
 * ***************************************************************************/


#include <stdio.h>
#include "fileloader.h"



// Funcion que carga un archivo de texto a memoria
// PRE: 'fileUrl' es la url completa al archivo a ordenar.
// POST: devuelve la lista de palabras cargadas en memoria
char * file_loader(const char * fileUrl)
{
	// FILE * file;
	// long fileSize;
	// char * buffer;
	// size_t result;

	// file = fopen (fileUrl, "r");

	// if (file==NULL) 
	// {
	// 	//Fail to load file
	// 	fputs ("The file can not be open or not exist", stderr); 
	// 	exit (1);
	// }

	// //Get file size
	// fseek (file , 0 , SEEK_END);
	// fileSize = ftell (file);
	// rewind (file);

	// //Allocate memory for the whole file
	// buffer = (char *) malloc (sizeof(char) * fileSize);
	
	// if (buffer == NULL) 
	// {
	// 	fputs ("There is no enoght memory to allocate the file in memory", stderr); 
	// 	exit (2);}

	// //Copy the file to the buffer
	// result = fread (buffer, 1, fileSize, file);
	
	// if (result != fileSize) 
	// {
	// 	fputs ("Fail to read the whole file", stderr); 
	// 	exit (3);
	// }

	// /* the whole file is now loaded in the memory buffer. */

	// fclose (file);

	// return buffer;

	// TEMP
	return NULL;
}


// [ Colocar documentacion ]
char ** to_words(char * text)
{
	// char ** words;
	// size_t textSize = sizeof (text) / sizeof (char);
	// size_t actualWordSize = 0; 
	// int wordsIndex = 0;
	// int letterIndex = 0;

	// //initialy allocate memory for 100 words

	// //words = malloc( MAXNUMBEROFWORDS * sizeof(char*) );
	// words = malloc( 100 * sizeof(char*) );

	// for (int i = 0; i < textSize; i++)
	// {
	// 	char letter = text[i];

	// 	if(letter != ' ')
	// 	{
	// 		words[wordsIndex][letterIndex] = letter;
	// 	}
	// 	else
	// 	{
	// 		letterIndex = 0;
	// 		wordsIndex++;

	// 	}
	// }

	// TEMP
	return NULL;

}


//	free (buffer);