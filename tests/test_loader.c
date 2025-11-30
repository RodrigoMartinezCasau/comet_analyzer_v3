#include <stdio.h>
#include "../include/data_loader.h"

int main() {
    int count = 0;
    DataPoint* data = load_spectrum("spectrum.txt", &count);

    if (!data) {
        printf("[FAIL] load_spectrum() devolvió NULL\n");
        return 1;
    }

    if (count <= 0) {
        printf("[FAIL] El archivo no cargó puntos válidos\n");
        free(data);
        return 1;
    }

    printf("[PASS] load_spectrum() cargó %d puntos correctamente\n", count);

    free(data);
    return 0;
}
