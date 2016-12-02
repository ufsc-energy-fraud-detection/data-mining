/*
 * types.h
 *
 *  Created on: 14 de set de 2016
 *      Author: thiagordp
 */

#ifndef TYPES_H_
#define TYPES_H_

#include "util.h"

// Quantidade de entradas na rede neural
#define NUM_INPUTS		48		    // Number of inputs in the neural network
#define SAMPLES_IN_INPUT	30		    // Number of samples in a single input of the artificial neural network
#define MIN_NORM		-1.0		    // Maximum value of normalization
#define MAX_NORM		1.0		    // Maximum value of normalization
#define MIN_VALUE_NORM		0.0		    // Minimum value of a sample
#define MAX_VALUE_NORM		9.0		    // Maximum value of a sample
#define SIZE_WINDOW		NUM_INPUTS + 1	    // Size of the window of the neural network
#define NUM_MEAN_DEVIATION	3		    // Number of mean deviation to exclude from average

enum uso_t
{
	TEST = 0, TRAINING, ZERO_FRAUD, PERIODICAL_ZERO_FRAUD, SUB_FRAUD, SUM_FRAUD,ESCALAR_FRAUD
};

#endif /* TYPES_H_ */
