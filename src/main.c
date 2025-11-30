#include <stdio.h>
#include <stdlib.h>
#include "data_loader.h"
#include "element_db.h"
#include "spectrum_analyzer.h"

int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Uso: %s <archivo-espectro>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    printf("[INFO] Analizando espectro: %s\n", filename);

    int count = 0;
    DataPoint* spectrum = load_spectrum(filename, &count);

    if (!spectrum || count == 0) {
        printf("[ERROR] No se pudo cargar el espectro.\n");
        return 1;
    }

    printf("[INFO] %d puntos de datos cargados correctamente.\n", count);

    int element_count = 0;
    Element* elements = get_known_elements(&element_count);

    printf("[INFO] %d elementos químicos cargados.\n", element_count);

    double peaks[64];
    int peak_count = detect_peaks(spectrum, count, peaks, 64);

    printf("[INFO] %d picos detectados:\n", peak_count);
    for (int i = 0; i < peak_count; i++) {
        printf("  - Pico en %.2f nm\n", peaks[i]);
    }

    Match matches[64];
    double tolerance = 1.0;
    int match_count = match_elements(peaks, peak_count, elements, element_count, matches, tolerance);

    printf("\n===== RESULTADOS DEL ANALISIS =====\n\n");

    if (match_count == 0) {
        printf("No se detectó ningún elemento.\n");
    } else {
        for (int i = 0; i < match_count; i++) {
            printf("Elemento detectado: %s\n", matches[i].element_name);
            printf("  Pico observado: %.2f nm\n", matches[i].wavelength);
            printf("  Diferencia:     %.2f nm\n", matches[i].difference);
            printf("  Probabilidad:   %.2f %%\n\n", matches[i].probability * 100.0);
        }
    }

    free(spectrum);
    free(elements);

    printf("[INFO] Análisis completado.\n");

    return 0;
}
