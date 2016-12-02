/*
 * data_mining.c
 *
 *  Created on: 14 de set de 2016
 *      Author: thiagordp
 */

#include "data_mining.h"

long int fileToVector(char* fileName, float** fileValues)
{
	FILE* inputFIle = fileOpen(fileName);
	long int size = 0;
	float biggest = 0;

	*fileValues = calloc(1, sizeof(float));

	char* linhaArquivoBase = malloc(sizeof(char) * MAX_SIZE_LINE);

	do
	{
		if (readLine(inputFIle, linhaArquivoBase) == -1)
		{
			return size;
		}
		else
		{
			size++;
			*fileValues = realloc(*fileValues, size * sizeof(float));
			(*fileValues)[size - 1] = atof(linhaArquivoBase);
			if (biggest < (*fileValues)[size - 1])
				biggest = (*fileValues)[size - 1];
		}
	} while (1);
}

float createInput(float* samples, int numSamples)
{
	int i = 0, outAverageValues = 0, wrongSamples = 0;
	float samplesAverage = 0, meanDev = 0, sum = 0;

	samplesAverage = average(samples, numSamples);
	meanDev = meanDeviation(samplesAverage, samples, numSamples);
	for (i = 0; i < numSamples; i++)
	{
		if ((samples)[i] == -1)
		{
			wrongSamples++;
		}
		else if ((samples)[i] >= samplesAverage + NUM_MEAN_DEVIATION * meanDev || (samples)[i] <= samplesAverage - NUM_MEAN_DEVIATION * meanDev)
		{
			outAverageValues++;
		}
		else
		{
			sum = sum + (samples)[i];
		}
	}
	samplesAverage = sum / (numSamples - outAverageValues - wrongSamples);
	return (samplesAverage);
}

float *createInputSet(float* samples, long int size, int numDays)
{
	int i = 0;
	float *set = (float*) calloc(NUM_INPUTS * numDays, sizeof(float));
	
	for (i = 0; i < size / 30; i++)
	{
		set[i] = createInput(&samples[i * 30], 30);
	}
	return normalize(set, size / 30);
}

float *normalize(float *samples, int size)
{
	float *vet = (float*) calloc(size, sizeof(float));
	int i = 0;

	for (i = 0; i < size; i++)
	{
		vet[i] = samples[i] * ((MAX_NORM - MIN_NORM) / (MAX_VALUE_NORM - MIN_VALUE_NORM))
				+ (MIN_NORM - ((MAX_NORM - MIN_NORM) / (MAX_VALUE_NORM - MIN_VALUE_NORM)) * MIN_VALUE_NORM);
	}

	return vet;
}

void createData(char fileName[], int numDays, int use)
{
	float* values = NULL;
	int i, j, size = 0;
	char outputName[30], *aux;
	size = fileToVector(fileName, &values);
	printf("\n Sizes = %i\n", size);

	float* dadosIn = NULL;

	dadosIn = createInputSet(values, size, numDays);

	int numVal = size / SAMPLES_IN_INPUT;

	strcpy(outputName, fileName);
	aux = strchr(outputName, '.') + sizeof(char);
	aux = strchr(aux, '.');
	*aux = '\0';

	if (use == TRAINING)
	{
		strcat(outputName, ".TRAINING.data");
	}
	else
	{
		char temp[100];
		switch (use)
		{
		case TEST:
			strcat(outputName, ".TEST.data");
			break;
		case SUB_FRAUD:
			strcat(outputName, ".SUB_FRAUD.data");
			subFraud(dadosIn, numVal);
			break;
		case ZERO_FRAUD:
			strcat(outputName, ".ZERO_FRAUD.data");
			zeroFraud(dadosIn, numVal);
			break;
		case PERIODICAL_ZERO_FRAUD:
			strcat(outputName, ".PERIODICAL_ZERO_FRAUD.data");
			periodicalZeroFraud(dadosIn, numVal);
			break;
		case SUM_FRAUD:
			strcat(outputName, ".SUM_FRAUD.data");
			sumFraud(dadosIn, numVal);
			break;
		case ESCALAR_FRAUD:
			sprintf(temp, ".ESCALAR_FRAUD-%.1f.data", ESCALAR);
			strcat(outputName, temp);
			escalarFraud(dadosIn, numVal);
			break;
		}
	}
	FILE *arqSaida = fileCreate(outputName);

	if (use == TRAINING)
	{
		char buf[30];

		sprintf(buf, "%d %d 1\n", (numVal - SIZE_WINDOW - 2), NUM_INPUTS);
		fileWrite(arqSaida, buf);
	}

	for (i = 0; i < (numVal - SIZE_WINDOW - 2); i++)
	{

		for (j = i; j < i + SIZE_WINDOW - 1; j++)
		{
			char stringPotencia[QTD_DIGITOS_CHAR];

			snprintf(stringPotencia, QTD_DIGITOS_CHAR, "%f", dadosIn[j]);
			fileWrite(arqSaida, stringPotencia);
			fileWrite(arqSaida, " ");
		}

		if (use == TRAINING)
		{
			fileWrite(arqSaida, "\n");
		}

		floatToFile(dadosIn[j], arqSaida);
	}

	closeFIle(arqSaida);
}
