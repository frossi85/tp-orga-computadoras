/* ****************************************************************************
 * ****************************************************************************
 *
 * LIBRERÍA DE CARGA DE ARCHIVO DE PALABRAS
 *
 * ****************************************************************************
 * ***************************************************************************/


#include "fileloader.h"



// Función que carga un archivo de texto a memoria
// PRE: 'fileUrl' es la url completa al archivo a ordenar.
// POST: devuelve la lista de palabras cargadas en memoria
char * words file_loader(const char * fileUrl)
{
	FILE * file;
	long fileSize;
	char * buffer;
	size_t result;

	file = fopen (fileUrl, "r");

	if (file==NULL) 
	{
		//Fail to load file
		fputs ("The file can not be open or not exist", stderr); 
		exit (1);
	}

	//Get file size
	fseek (file , 0 , SEEK_END);
	fileSize = ftell (file);
	rewind (file);

	//Allocate memory for the whole file
	buffer = (char *) malloc (sizeof(char) * fileSize);
	
	if (buffer == NULL) 
	{
		fputs ("There is no enoght memory to allocate the file in memory", stderr); 
		exit (2);}

	//Copy the file to the buffer
	result = fread (buffer, 1, fileSize, file);
	
	if (result != fileSize) 
	{
		fputs ("Fail to read the whole file", stderr); 
		exit (3);
	}

	/* the whole file is now loaded in the memory buffer. */

	fclose (file);

	return buffer;
}

//	free (buffer);