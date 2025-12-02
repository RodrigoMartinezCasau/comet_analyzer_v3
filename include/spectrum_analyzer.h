#ifndef SPECTRUM_ANALYZER_H
#define SPECTRUM_ANALYZER_H
#include "data_loader.h"
#include "element_db.h"
#define MAX_MATCHES 32   

// We define a struck to determine the distribution of a matching element 
typedef struct {
    char element_name[32];
    double wavelength;      // Detected wavelength 
    double difference;      // Different between the detected wavelength and the element's exact wavelenght 
    double probability;     // Probability of the element given the difference 
} Match;

int detect_peaks(DataPoint* spec, int count, double* peaks_out, int max_peaks);

int match_elements(
    double* peaks,
    int peak_count,
    Element* elements,
    int elem_count,
    Match* matches_out,
    double tolerance
);

#endif
