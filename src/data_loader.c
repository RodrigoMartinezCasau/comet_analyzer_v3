// This file reads values from the .txt file and creates a dynamic array 

#include <stdio.h>
#include <stdlib.h>
#include "data_loader.h"

DataPoint* load_spectrum(const char *filename, int *count) {
    *count = 0;

    // First we check for possible bugs regarding to the File 
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file'%s'\n", filename); 
        return NULL;
    }

    // Then we scan the number of lines starting the count from 0 
    double w, i;
    int lines = 0;
    while (fscanf(file, "%lf%*[ ,\t]%lf", &w, &i) == 2) {
        lines++;
    }

    // File could be empty :(
    if (lines == 0) {
        printf("Error: The file '%s' is empty or wrongly formatted.\n", filename);
        fclose(file);
        return NULL;
    }

    rewind(file);
    // Allocate the values of the variables for all data points
    DataPoint *data = malloc(sizeof(DataPoint) * lines);
    if (!data) {
        printf("Error: Insufficient memory.\n");
        fclose(file);
        return NULL;
    }

    int index = 0;
    while (fscanf(file, "%lf%*[ ,\t]%lf", &w, &i) == 2) { // Cool trick to skip comas and spaces ;)
        data[index].wavelength = w;
        data[index].intensity = i;
        index++;
    }

    fclose(file);
    *count = lines;
    return data;
}
