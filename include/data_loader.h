// data_loader.h
// ------------------------------------------------------
// Este header declara la estructura DataPoint y las
// funciones necesarias para cargar un espectro desde un
// archivo de texto.
// ------------------------------------------------------

#ifndef DATA_LOADER_H
#define DATA_LOADER_H

// Un punto del espectro: una longitud de onda y su intensidad.
typedef struct {
    double wavelength;   // longitud de onda en nm
    double intensity;    // intensidad normalizada
} DataPoint;

// Carga un archivo de espectro y devuelve un array dinámico
// con todos los puntos leídos.
// "count" se usa para devolver cuántos puntos hay en total.
//x
// Devuelve NULL si hubo un error.
DataPoint* load_spectrum(const char *filename, int *count);

#endif // DATA_LOADER_H
