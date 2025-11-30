#ifndef ELEMENT_DB_H
#define ELEMENT_DB_H

// Definición de la estructura "Element".
typedef struct {
    char name[20];     // Nombre del elemento (ej: "Hydrogen")
    double lines[10];  // Longitudes de onda de sus líneas espectrales
    int line_count;    // Número de líneas espectrales registradas
} Element;

Element* get_known_elements(int *count);
void print_known_elements(void);

#endif
