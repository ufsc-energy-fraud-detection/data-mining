/*
 * calculo.c
 *
 *  Created on: 16 de set de 2016
 *      Author: Allan
 */
#include "calculo.h"

float average(float *data, int count)
{
    float sum = 0.0;
    float average = 0.0;

    for (int i = 0; i < count; i++)
    {
        sum += data[i];
    }
    average = sum / count;

    return average;
}

float meanDeviation(float average, float *data, int count)
{
    float error = 0.0;
    float mean_dev = 0.0;

    for (int i = 0; i < count; i++)
    {
        error += pow(data[i] - average, 2);
    }

    mean_dev = sqrt(error / count);

    return mean_dev;
}

void sumFraud(float *fullData, int size)
{
    int i = 0;
    float error = 0;

    srand((unsigned) time(NULL));

    for (i = 0; i < size; i++)
    {
        error = rand() % 101;
        error = error / 100;

        fullData[i] = fullData[i] + (fullData[i] * error);

        if (fullData[i] > MAX_VALUE_NORM)
            fullData[i] = MAX_VALUE_NORM;
    }
}

void zeroFraud(float *fullData, int size)
{
    int i = 0;

    srand((unsigned) time(NULL));

    // Porcentagem de valores que serão anulados no vetor.
    int x = rand() % (MAX_PROB_ZERO + 1) + MIN_PROB_ZERO;
    printf("PROB: %d\n", x);

    for (i = 0; i < size; i++)
    {
        if (rand() % (MIN_PROB_ZERO + MAX_PROB_ZERO + 1) < x)
        {
            //printf("Zerado: %d:%.2f\n", i, vet[i]);
            fullData[i] = 0;
        }
    }
}

void subFraud(float *fullData, int size)
{
    int i = 0;
    float error = 0;
    // zera
    // soma
    srand((unsigned) time(NULL));

    for (i = 0; i < size; i++)
    {
        error = rand() % 101;
        error = error / 100;
        fullData[i] = fullData[i] - (fullData[i] * error);
    }
}

void periodicalZeroFraud(float *fullData, int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((i % 48) / 2 > INITIAL_TIME && (i % 48) / 2 < FINAL_TIME)
        {
            fullData[i] = 0;
        }
    }
}

void escalarFraud(float *fullData, int size)
{
    for (int i = 0; i < size; i++)
    {
        fullData[i] = fullData[i] * ESCALAR;
        if (fullData[i] > MAX_VALUE_NORM)
            fullData[i] = MAX_VALUE_NORM;
    }
}
