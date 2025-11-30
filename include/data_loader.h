#ifndef DATA_LOADER_H
#define DATA_LOADER_H

typedef struct {
    double wavelength; // longitud de onda en nm
    double intensity;  // intensidad normalizada
} DataPoint;

// Carga un archivo de espectro y devuelve un array dinámico.
DataPoint* load_spectrum(const char *filename, int *count);

#endif
