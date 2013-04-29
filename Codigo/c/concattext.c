#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concattext.h"

char* concattext(char* text1, char* text2)
{
	char* textResult;
	size_t sizeTextResult;
	int i=0;
	int j;

	sizeTextResult=strlen(text1)+strlen(text2);
	textResult=(char*)malloc((sizeof(char)*sizeTextResult)+1);

	while (i < strlen(text1)) {

		textResult[i] = text1[i];
		i++;

	};
	
	j=i;
	i=0;

	while (i < strlen(text2)) {

		textResult[j] = text2[i];
		i++;
		j++;

	};

	return textResult;

}

