#ifndef DATA_LOADER_H
#define DATA_LOADER_H

// We define a struck to determine each of the DataPoints based on:
typedef struct {
    double wavelength; // The value of its wavelength 
    double intensity;  // The value of its intensity
} DataPoint;

DataPoint* load_spectrum(const char *filename, int *count);
#endif
