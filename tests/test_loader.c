#include <stdio.h>
#include <stdlib.h>
#include "../include/data_loader.h"

int main() {
    int count = 0;
    DataPoint* data = load_spectrum("spectrum.txt", &count);

    if (!data) {
        printf("[FAIL] load_spectrum() returned NULL\n");
        return 1;
    }

    if (count <= 0) {
        printf("[FAIL] The file couldn't load valid points\n");
        free(data);
        return 1;
    }

    printf("[PASS] load_spectrum() loaded %d points correctly\n", count);

    free(data);
    return 0;
}