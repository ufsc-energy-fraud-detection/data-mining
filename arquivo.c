/*
 * arquivo.c
 *
 *  Created on: 14 de set de 2016
 *      Author: thiagordp
 */

#include "arquivo.h"

FILE *fileOpen(char fileName[])
{
	FILE *arq = fopen(fileName, MODO_OP_BASE);

	if (arq == NULL)
	{
		printf("\n***arquivo.h - Arquivo especificado nao pode ser aberto***\n");
		return NULL;
	}
	printf("arquivo.h - Arquivo aberto : %s\n", fileName);
	return arq;
}

FILE *fileCreate(char fileName[])
{
	FILE *arq = fopen(fileName, MODO_OP_ENTR);

	if (arq == NULL)
	{
		printf("\n***arquivo.h - Arquivo especificado nao pode ser criado***\n");
		return NULL;
	}
	printf("arquivo.h - Arquivo criado : %s\n", fileName);
	return arq;
}

void fileWrite(FILE *file, char line[])
{
	if (file == NULL)
	{
		printf("arquivo.h - Escrita - Arquivo nao identificado.\n");
		return;
	}

	fprintf(file, "%s", line);

}

int readLine(FILE *file, char *line)
{
	if (fgets(line, MAX_SIZE_LINE, file) == NULL)
	{
		return (-1);
	}
	return (0);
}

int closeFIle(FILE *file)
{
	return fclose(file);
}

void floatToFile(float value, FILE* file)
{
	char stringPotencia[QTD_DIGITOS_CHAR];
	snprintf(stringPotencia, QTD_DIGITOS_CHAR, "%f", value);
	fileWrite(file, stringPotencia);
	fileWrite(file, "\n");
}