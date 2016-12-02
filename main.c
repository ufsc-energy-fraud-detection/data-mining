 /*
 * main.c
 *
 *  Created on: 14 de set de 2016
 *      Author: thiagordp
 */

#include <strings.h>
#include <stdio.h>
#include <time.h>
#include "data_base.h"
#include "arquivo.h"
#include "data_mining.h"
#include "util.h"

char data[4][50];
char numDays[4] = "365";

int main(int argc, char **argv)
{
	clock_t t1, t2;
	FILE *tmp;
	t1 = clock();

	int qtd = atoi(numDays);

	strcpy(data[0], "5/11/2007");

	for (int i = 0; i < 1; i++)
	{
		tmp = filterDataBase("household_power_consumption.txt", data[i], qtd);
		if (tmp == NULL)
		{
			printf("Data base not found\n");
			return 0;
		}

		char nomeArquivo[50];
		sprintf(nomeArquivo, "%s.%s.data", substituiChar(data[i]), numDays);
		//makgerarDAT(nomeArquivo, qtd, TESTE);
		createData(nomeArquivo, qtd, TRAINING);
		/*gerarDAT(nomeArquivo, qtd, FRAUDE_ZERO_PERIODICO);
		gerarDAT(nomeArquivo, qtd, FRAUDE_SOMA);
		gerarDAT(nomeArquivo, qtd, FRAUDE_SUB);
		gerarDAT(nomeArquivo, qtd, FRAUDE_ZERO);
		gerarDAT(nomeArquivo, qtd, FRAUDE_ESCALAR);*/
	}
	t2 = clock();
	float diff = ((float) (t2 - t1) / 1000000.0F) * 1000;
	printf("\n---------------- Time elapsed -> %.2f ms -------------- \n", diff);

	return 0;
}

