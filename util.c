/*
 * util.c
 *
 *  Created on: 30 de set de 2016
 *      Author: Jonas
 */

#include "util.h"

char* substituiChar(char* data)
{
	char *str = (char*) calloc (30, sizeof(char));

	strcpy(str, data);
	//strcpy(nomeArq, data);

	// Substitui / por -
	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i] == '/')
		{
			str[i] = '-';
		}
	}

	return str;
	//strcat(nomeArq, ".dat");
}
