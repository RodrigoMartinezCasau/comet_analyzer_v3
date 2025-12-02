// data_loader.c
// Lee archivo de espectro flexible y devuelve array dinámico

#include <stdio.h>
#include <stdlib.h>
#include "data_loader.h"

DataPoint* load_spectrum(const char *filename, int *count) {
    *count = 0;

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file'%s'\n", filename);
        return NULL;
    }

    double w, i;
    int lines = 0;

    // Contar líneas válidas
    while (fscanf(file, "%lf%*[ ,\t]%lf", &w, &i) == 2) {
        lines++;
    }

    if (lines == 0) {
        printf("Error: The file '%s' is empty or wrongly formatted.\n", filename);
        fclose(file);
        return NULL;
    }

    rewind(file);

    DataPoint *data = malloc(sizeof(DataPoint) * lines);
    if (!data) {
        printf("Error: Insufficient memory.\n");
        fclose(file);
        return NULL;
    }

    int index = 0;
    while (fscanf(file, "%lf%*[ ,\t]%lf", &w, &i) == 2) {
        data[index].wavelength = w;
        data[index].intensity = i;
        index++;
    }

    fclose(file);
    *count = lines;
    return data;
}
