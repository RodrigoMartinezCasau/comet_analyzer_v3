#include <stdio.h>
#include "../include/spectrum_analyzer.h"

int main() {
    DataPoint fake[] = {
        {400, 0.1},
        {401, 0.5}, // pico
        {402, 0.2},
        {500, 0.2},
        {501, 0.8}, // pico
        {502, 0.1}
    };

    double peaks[10];
    int found = detect_peaks(fake, 6, peaks, 10);

    if (found != 2) {
        printf("[FAIL] detect_peaks() should detect 2 peaks, detected %d\n", found);
        return 1;
    }

    if (peaks[0] != 401 || peaks[1] != 501) {
        printf("[FAIL] Incorrect lengths detected\n");
        return 1;
    }

    printf("[PASS] detect_peaks() detected 2 peaks correctly\n");
    return 0;
}
