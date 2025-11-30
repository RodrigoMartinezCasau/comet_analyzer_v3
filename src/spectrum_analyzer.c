#include <stdio.h>
#include <string.h>
#include <math.h>
#include "spectrum_analyzer.h"

// Función gaussiana para calcular probabilidad
static double gaussian_probability(double diff, double sigma) {
    return exp(-(diff * diff) / (2 * sigma * sigma));
}

// Detectar picos
int detect_peaks(DataPoint* spec, int count, double* peaks_out, int max_peaks) {
    int peak_count = 0;

    for (int i = 1; i < count - 1; i++) {
        if (spec[i].intensity > spec[i-1].intensity &&
            spec[i].intensity > spec[i+1].intensity) {

            if (peak_count < max_peaks) {
                peaks_out[peak_count] = spec[i].wavelength;
                peak_count++;
            }
        }
    }
    return peak_count;
}

// Matching
int match_elements(double* peaks, int peak_count,
                   Element* elements, int elem_count,
                   Match* matches_out, double tolerance) {

    int match_count = 0;

    for (int p = 0; p < peak_count; p++) {
        for (int e = 0; e < elem_count; e++) {
            for (int l = 0; l < elements[e].line_count; l++) {

                double diff = fabs(peaks[p] - elements[e].lines[l]);

                if (diff <= tolerance) {
                    double sigma = tolerance / 2.0;
                    double prob = gaussian_probability(diff, sigma);

                    if (match_count < MAX_MATCHES) {
                        strncpy(matches_out[match_count].element_name, elements[e].name, 31);
                        matches_out[match_count].element_name[31] = '\0';

                        matches_out[match_count].wavelength = peaks[p];
                        matches_out[match_count].difference = diff;
                        matches_out[match_count].probability = prob;

                        match_count++;
                    }
                }
            }
        }
    }
    return match_count;
}
