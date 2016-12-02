/*
 * data_mining.h
 *
 *  Created on: 14 de set de 2016
 *      Author: thiagordp
 */

#ifndef DATA_MINING_H_
#define DATA_MINING_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "arquivo.h"
#include "types.h"
#include "calculo.h"
#include "data_base.h"


/**
 * Runs through the "samples" vector and calculates the average of the next "numSamples" values, ignoring the samples that are NUM_MEAN_DEVIATION above or under the average. This will be one input of the neural network.
 * @param samples vector to the initial value to be mounted.
 * @param numSamples number of values to include in the calculation.
 * @return the average of the values that are NUM_MEAN_DEVIATION above or under the average.
 */
float createInput(float* samples, int numSamples);


/**
 * Runs through the whole "samples" vector of size "size" and creates the new vector with "size/samples" samples which are the average of 30 minutes made in the createInput function.
 * @param samples vector with all the samples collected.
 * @param size the size of "samples" vector.
 * @param numDays number of days to sample.
 * @return the new vector with the corrected sampled values to go as input in the neural network.
 */
float *createInputSet(float* samples, long int size, int numDays);

/**
 * Normalize the "samples" vector.
 * @param samples vector to be normalize.
 * @param size size of "samples" vector.
 * @return a new vector of the normalized values.
 */
float *normalize(float *samples, int size);

/**
 * Insert all the values in "fileName" file on the "fileValues" vector.
 * @param fileName the file to take the values from.
 * @param fileValues
 * @return the size of the fileValues vector
 */
long int fileToVector(char* fileName, float** fileValues);

/**
 * Creates a .data file which is an input file to the neural network, having many variations according to the "use" parameter.
 * @param fileName  name of the file having the samples of potency in the form of each line being a sample of the potency of a given minute.
 * @param numDays  number of days of the sampled file
 * @param use  what is the use of the file in the artificial neural network: TEST, TRAINING, ZERO_FRAUD, PERIODICAL_ZERO_FRAUD, SUB_FRAUD, SUM_FRAUD,ESCALAR_FRAUD
 */
void createData(char fileName[], int numDays, int use);

#endif /* DATA_MINING_H_ */
