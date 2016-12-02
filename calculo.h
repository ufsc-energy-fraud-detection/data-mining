/*
 * calculo.h
 *
 *  Created on: 14 de set de 2016
 *      Author: thiagordp
 */

#ifndef CALCULO_H_
#define CALCULO_H_

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "types.h"

#define MAX_PROB_ZERO 80		// Maximum probability to zero a value in data vector
#define MIN_PROB_ZERO 20		// Minimum probability to zero a value in data vector
#define ESCALAR 2.0			// Value to multiply all the values in data vector

#define INITIAL_TIME 10			// Starting hour to initialize to zero values in data vector
#define FINAL_TIME 20			// Ending hour to initialize to zero values in data vector

/**
 * Average of the data subset from 'data[x]' to 'data[x+count]' 
 * @param data Pointer to the initial value of the calculation
 * @param count How many values should be in the average calculation
 * @return Average of the data set
 */
float average(float *data, int count);

/**
 * Mean Deviation of the data subset from 'data[x]' to 'data[x+count]'
 * @param average Average of this same data subset
 * @param data Pointer to the initial value of the calculation
 * @param count How many values should be in the average calculation
 * @return 
 */
float meanDeviation(float average, float *data, int count);

/**
 * Sums a small random value to all the values from the 'Fulldata' vector
 * @param fullData Pointer to the initial value of the data vector
 * @param size Size of the 'Fulldata' vector
 */
void sumFraud(float *fullData, int size);

/**
 * Generates random zeros all over the 'FullData' vector
 * @param fullData Pointer to the initial value of the data vector
 * @param size Size of the 'Fulldata' vector
 */
void zeroFraud(float *fullData, int size);

/**
 * Subtracts a small random value to all the values from the 'Fulldata' vector
 * @param fullData Pointer to the initial value of the data vector
 * @param size Size of the 'Fulldata' vector
 */
void subFraud(float *fullData, int size);

/**
 * Multiplies all the values from the fullData vector by the 'ESCALAR' define 
 * @param fullData Pointer to the initial value of the data vector
 * @param size Size of the 'Fulldata' vector
 */
void escalarFraud(float *fullData, int size);

/**
 * Generates zeros everyday from 'INITIAL_TIME' define to 'FINAL_TIME' define
 * @param fullData Pointer to the initial value of the data vector
 * @param size Size of the 'Fulldata' vector
 */
void periodicalZeroFraud(float *fullData, int size);

#endif /* CALCULO_H_ */
