// data_loader.c
// ------------------------------------------------------
// Implementa la función load_spectrum, que lee un archivo
// de texto con líneas del estilo:
//
//   400.5 0.12
//   401.1 0.09
//
// (dos números separados por espacio) y devuelve un array
// dinámico de DataPoint.
// ------------------------------------------------------

#include <stdio.h>      // fopen, fscanf, fclose
#include <stdlib.h>     // malloc, free
#include "data_loader.h"

// load_spectrum
// ------------------------------------------------------
// filename: path al archivo (ej: "spectrum.txt")
// count: salida -> número total de puntos leídos
//
// Devuelve:
//   - Un array dinámico de DataPoint si todo sale bien
//   - NULL si hubo un error
// ------------------------------------------------------
DataPoint* load_spectrum(const char *filename, int *count) {
    *count = 0;   // Inicializamos el contador a 0

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        // Archivo no encontrado o sin permisos
        printf("Error: No se pudo abrir el archivo '%s'\n", filename);
        return NULL;
    }

    double w, i;
    int lines = 0;

    // Paso 1: Contar cuántas líneas válidas tiene el archivo.
    // Formato flexible: acepta "400.5 0.12", "400.5, 0.12", "400.5 , 0.12", etc.
    while (fscanf(file, "%lf%*[ ,]%lf", &w, &i) == 2) {
        lines++;
    }

    if (lines == 0) {
        printf("Error: El archivo '%s' está vacío o mal formateado.\n", filename);
        fclose(file);
        return NULL;
    }

    // Volvemos al inicio del archivo para leer de verdad los datos
    rewind(file);

    // Paso 2: Reservamos memoria dinámica para TODOS los puntos
    DataPoint *data = malloc(sizeof(DataPoint) * lines);

    if (data == NULL) {
        printf("Error: No hay memoria suficiente.\n");
        fclose(file);
        return NULL;
    }

    // Paso 3: Leer de verdad los datos e introducirlos en el array
    int index = 0;

    while (fscanf(file, "%lf%*[ ,]%lf", &w, &i) == 2) {
        data[index].wavelength = w;  // Guardamos longitud de onda
        data[index].intensity  = i;  // Guardamos intensidad
        index++;
    }

    fclose(file);       // Cerramos archivo
    *count = lines;     // Guardamos el número total de puntos

    return data;        // Devolvemos el array dinámico
}
