#ifndef SPECTRUM_ANALYZER_H
#define SPECTRUM_ANALYZER_H

#include "data_loader.h"
#include "element_db.h"

#define MAX_MATCHES 32   


typedef struct {
    char element_name[32];
    double wavelength;      // línea detectada
    double difference;      // diferencia respecto a la línea teórica
    double probability;     // probabilidad estimada
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
