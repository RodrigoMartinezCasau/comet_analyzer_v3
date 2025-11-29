#ifndef SPECTRUM_ANALYZER_H
#define SPECTRUM_ANALYZER_H

#include "data_loader.h"
#include "element_db.h"

#define MAX_MATCHES 32   // Máximo de líneas detectadas

// Estructura para almacenar coincidencias elemento-pico
typedef struct {
    char element_name[32];  // "Hydrogen", "Sodium", etc.
    double wavelength;       // línea detectada
    double difference;       // diferencia respecto a la línea teórica
    double probability;
} Match;

/**
 * Detecta picos en el espectro.
 * Un pico es un punto cuya intensidad es mayor que sus vecinos.
 * 
 * spec     -> array con los datos
 * count    -> número de puntos
 * peaks    -> salida con las longitudes de onda detectadas como picos
 * 
 * return   -> número de picos encontrados
 */
int detect_peaks(DataPoint* spec, int count, double* peaks_out, int max_peaks);

/**
 * Compara los picos detectados con la base de datos de elementos.
 *
 * peaks        -> picos detectados
 * peak_count   -> número de picos
 * elements     -> base de datos de elementos
 * elem_count   -> número de elementos
 * matches_out  -> estructura con coincidencias
 *
 * return       -> número de coincidencias
 */
int match_elements(
    double* peaks,
    int peak_count,
    Element* elements,
    int elem_count,
    Match* matches_out,
    double tolerance
);

#endif
