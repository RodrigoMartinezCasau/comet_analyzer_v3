// element_db.c
// ------------------------------------------------------
// Implementación de la base de datos de elementos.
// Aquí creamos un array dinámico con elementos químicos
// y sus líneas espectrales características.
// ------------------------------------------------------

#include <stdio.h>          // Para printf
#include <stdlib.h>         // Para malloc
#include <string.h>         // Para strcpy
#include "element_db.h"     // Nuestro header


// ------------------------------------------------------
// get_known_elements
// Devuelve un array dinámico con los elementos conocidos.
// ------------------------------------------------------
Element* get_known_elements(int *count) {
    *count = 8;   // Solo 8 elementos por ahora (iremos ampliando)

    // Reservamos memoria para 3 elementos
    Element *elements = malloc(sizeof(Element) * (*count));

    // ====== ELEMENTO 1: HIDRÓGENO ======
    strcpy(elements[0].name, "Hydrogen");
    elements[0].lines[0] = 656.0;
    elements[0].lines[1] = 486.0;
    elements[0].lines[2] = 434.0;
    elements[0].line_count = 3;

    // ====== ELEMENTO 2: OXÍGENO ======
    strcpy(elements[1].name, "Oxygen");
    elements[1].lines[0] = 777.0;
    elements[1].lines[1] = 844.0;
    elements[1].line_count = 2;

    // ====== ELEMENTO 3: SODIO ======
    strcpy(elements[2].name, "Sodium");
    elements[2].lines[0] = 589.0;
    elements[2].line_count = 1;

    // ===== ELEMENTO 4: HELIO =====
    strcpy(elements[3].name, "Helium");
    elements[3].lines[0] = 587.6;  // línea amarilla típica
    elements[3].lines[1] = 447.1;
    elements[3].line_count = 2;

    // ===== ELEMENTO 5: CARBONO =====
    strcpy(elements[4].name, "Carbon");
    elements[4].lines[0] = 426.7;
    elements[4].lines[1] = 658.0;
    elements[4].line_count = 2;

    // ===== ELEMENTO 6: CALCIO =====
   strcpy(elements[5].name, "Calcium");
   elements[5].lines[0] = 422.7;
   elements[5].lines[1] = 393.4;
   elements[5].line_count = 2;

   // ===== ELEMENTO 7: MAGNESIUM =====
   strcpy(elements[6].name, "Magnesium");
   elements[6].lines[0] = 517.0;
   elements[6].line_count = 1;

   // ===== ELEMENTO 8: IRON =====
   strcpy(elements[7].name, "Iron");
   elements[7].lines[0] = 438.4;
   elements[7].lines[1] = 526.0;
   elements[7].line_count = 2;

    return elements;
}

// ------------------------------------------------------
// print_known_elements
// Muestra los elementos almacenados (debug).
// ------------------------------------------------------
void print_known_elements(void) {
    int count = 0;
    Element *elements = get_known_elements(&count);

    printf("Elements known by Comet Analyzer:\n");
    printf("---------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%s: ", elements[i].name);

        for (int j = 0; j < elements[i].line_count; j++) {
            printf("%.1f nm", elements[i].lines[j]);
            if (j < elements[i].line_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    free(elements); // Liberamos memoria dinámica
}
