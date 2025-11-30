#include <stdio.h>
#include <math.h>
#include "../include/element_db.h"
#include "../include/spectrum_analyzer.h"

int main() {
    int elem_count = 0;
    Element* elements = get_known_elements(&elem_count);

    double peaks[] = {656.0};  // Pico exacto de hidrógeno
    Match matches[10];

    int found = match_elements(peaks, 1, elements, elem_count, matches, 1.0);

    if (found == 0) {
        printf("[FAIL] match_elements() no detectó Hidrogeno\n");
        free(elements);
        return 1;
    }

    if (strcmp(matches[0].element_name, "Hydrogen") != 0) {
        printf("[FAIL] match_elements() detectó otro elemento: %s\n", matches[0].element_name);
        free(elements);
        return 1;
    }

    printf("[PASS] match_elements() detectó correctamente Hidrogeno\n");

    free(elements);
    return 0;
}
