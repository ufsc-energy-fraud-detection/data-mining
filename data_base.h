/*
 * data_mining_base.h
 *
 *  Created on: 14 de set de 2016
 *      Author: thiagordp
 */

#ifndef DATA_BASE_H_
#define DATA_BASE_H_

#include "types.h"
#include "arquivo.h"
#include <stdio.h>


/**
 * Generates a file named "initialDay.numDays" which will be the data base filtered.
 * @param fileName Name of the data base file to be filtered.
 * @param initialDay Day to begin collecting data. From 17/12/2006 to 25/11/2010. 
 ** Days and moths must not include zero. Ex: 1/1/2008 **
 * @param numDays Number days to collect data.
 * @return returns a pointer to the generated file
 */
FILE* filterDataBase(char* fileName, char* initialDay, int numDays);

#endif /* DATA_BASE_H_ */
