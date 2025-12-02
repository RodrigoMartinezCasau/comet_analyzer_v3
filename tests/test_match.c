#include <stdio.h>
#include <math.h>
#include "../include/element_db.h"
#include "../include/spectrum_analyzer.h"
#include <stdlib.h>
#include <string.h>

int main() {
    int elem_count = 0;
    Element* elements = get_known_elements(&elem_count);

    double peaks[] = {656.0};  
    Match matches[10];

    int found = match_elements(peaks, 1, elements, elem_count, matches, 1.0);

    if (found == 0) {
        printf("[FAIL] match_elements() couldn't detect Hidrogeno\n");
        free(elements);
        return 1;
    }

    if (strcmp(matches[0].element_name, "Hydrogen") != 0) {
        printf("[FAIL] match_elements() detected another element: %s\n", matches[0].element_name);
        free(elements);
        return 1;
    }

    printf("[PASS] match_elements() detected correctly: Hidrogeno\n");

    free(elements);
    return 0;
}
