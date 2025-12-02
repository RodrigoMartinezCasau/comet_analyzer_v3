#include <stdio.h>
#include <stdlib.h>
#include "data_loader.h"
#include "element_db.h"
#include "spectrum_analyzer.h"

// Time to call all the strucks for each match and develop the report!
int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Uso: %s <archivo-espectro>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    printf("[INFO] Analyzing spectrum: %s\n", filename);

    int count = 0;
    DataPoint* spectrum = load_spectrum(filename, &count);

    if (!spectrum || count == 0) {
        printf("[ERROR] Couldn't load spectrum.\n");
        return 1;
    }

    printf("[INFO] %d data points loaded succesfully.\n", count);

    int element_count = 0;
    Element* elements = get_known_elements(&element_count);

    printf("[INFO] %d chemical elements loaded.\n", element_count);

    double peaks[64];
    int peak_count = detect_peaks(spectrum, count, peaks, 64);

    printf("[INFO] %d peaks detected:\n", peak_count);
    for (int i = 0; i < peak_count; i++) {
        printf("  - Peak in %.2f nm\n", peaks[i]);
    }

    Match matches[64];
    double tolerance = 1.0;
    int match_count = match_elements(peaks, peak_count, elements, element_count, matches, tolerance);

    printf("\n===== ANALYSIS RESULT =====\n\n");

    if (match_count == 0) {
        printf("Couldn't detect element.\n");
    } else {
        for (int i = 0; i < match_count; i++) {
            printf("Element detected: %s\n", matches[i].element_name);
            printf("  Peak observed: %.2f nm\n", matches[i].wavelength);
            printf("  Difference:     %.2f nm\n", matches[i].difference);
            printf("  Probability:   %.2f %%\n\n", matches[i].probability * 100.0);
        }
    }

    free(spectrum);
    free(elements);

    printf("[INFO] Analysis completed.\n");

    return 0;
}
