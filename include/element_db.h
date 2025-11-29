// element_db.h
// ------------------------------------------------------
// Este header define la estructura Element y declara las
// funciones para acceder a la base de datos de elementos
// espectrales conocidos.
// ------------------------------------------------------

#ifndef ELEMENT_DB_H
#define ELEMENT_DB_H

// Definición de la estructura "Element".
// Representa un elemento químico con sus longitudes
// de onda típicas observables en un espectro.
typedef struct {
    char name[20];      // Nombre del elemento (ej: "Hydrogen")
    double lines[10];   // Longitudes de onda de sus líneas espectrales
    int line_count;     // Número de líneas espectrales registradas
} Element;

// Devuelve un array dinámico de elementos conocidos.
// "count" sirve para decir cuántos elementos devuelve.
Element* get_known_elements(int *count);

// Función auxiliar para imprimirlos (solo para debug).
void print_known_elements(void);

#endif // ELEMENT_DB_H
