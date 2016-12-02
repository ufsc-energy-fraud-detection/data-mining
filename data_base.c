/*
 * data_mining_base.c
 *
 *  Created on: 14 de set de 2016
 *      Author: J�natas Negri Grandini
 */

#include "data_base.h"

#include <strings.h>
#include <string.h>
#include "types.h"

int collectTime(char* line);
float readPotency(char* line);
int writePotency(FILE* file, char* line);

long long int time = 0, timeBefore = -1;
long int numValues = 0, missingValues = 0;
int errorFlag = 0;

FILE* filterDataBase(char* fileName, char* initialDay, int numDays)
{

    FILE* dataBaseFile = fileOpen(fileName);
    // If something wrong happens, leave
    if (dataBaseFile == 0)
    {
        return dataBaseFile;
    }

    char outputName[30];
    char aux[30];

    // Creating the output file with the given name
    strcpy(outputName, substituiChar(initialDay));
    sprintf(aux, ".%d.data", numDays);
    strcat(outputName, aux);
    FILE* outputFile = fileCreate(outputName);

    char* lineDataBaseFile = malloc(sizeof (char) * MAX_SIZE_LINE);
    do
    {
        //If the day is not valid or doesn't exists, returns NULL
        if (readLine(dataBaseFile, lineDataBaseFile) == -1)
        {
            printf("\nDay not found, you must insert a valid day...\nLeaving\n");
            return NULL;
        }
    }
    while (strstr(lineDataBaseFile, initialDay) == NULL);
    printf("\nDay %s found!\n", initialDay);
    //While that searches for the given day "initialDay"
    
    int i;
    long int counts = numDays * 60 * 24;
    
    //For to read all the samples, which will be = 'one per minute'(60)*'number of hours in a day'(24)*'the number of days to sample'(numDays)
    for (i = 0; i < counts; i++)
    {
        //If the data for the given line is missing, jump to the next valid day, else write in the outputFile
        if (writePotency(outputFile, lineDataBaseFile) == -1)
        {
            printf("Day number %d has invalid data, skipping one day\n", (int) i / (60 * 24));
            // Skip a whole day of samples
            for (int j = 0; j < 60 * 24; j++)
                readLine(dataBaseFile, lineDataBaseFile);
                counts++;
        }
        readLine(dataBaseFile, lineDataBaseFile);
    }
    closeFIle(outputFile);
    closeFIle(dataBaseFile);
    printf("\nFile created with %ld samples and %ld missing values\n", numValues, missingValues);
    return dataBaseFile;
}

// Writes the potency of a given line in the output file
int writePotency(FILE* file, char* line)
{
    float potency = 0;
    time = collectTime(line);
    potency = readPotency(line);
    //If the data is incorrect or too small
    if (potency < 0.00005)
    {
        printf("Error at the given time %d:%d ", (int) (time / 60), (int) (time % 60));
        timeBefore = -1;
        return (-1);
    }
    // If it's the first value to be inserted or the last value was invalid, just write in the output
    if (timeBefore < 0)
    {
        floatToFile(potency, file);
        numValues++;
        timeBefore = time;
    }
    // If the last sample was from the minute before, write in the output file ( to make sure the samples are not skipping minutes)
    else if ((timeBefore + 1 == time) || (timeBefore == 23 * 60 + 59 && time == 0))
    {
        floatToFile(potency, file);
        numValues++;
        timeBefore = time;
    }
    return (0);
}

// Collects the time in minutes of the given line
int collectTime(char* line)
{
    int min = 0, hour = 0;
    line = strchr(line, ';') + sizeof (char);
    sscanf(line, "%d:%d", &hour, &min);
    return (hour * 60 + min);
}

// Reads the potency of the given line
float readPotency(char* line)
{
    line = strchr(line, ';') + sizeof (char);
    line = strchr(line, ';') + sizeof (char);
    float reactivePotency, activePotency;
    sscanf(line, "%f;%f", &activePotency, &reactivePotency);
    return (activePotency + reactivePotency);
}

