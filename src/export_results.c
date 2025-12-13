#include <stdio.h>

void export_results() {
    FILE *f = fopen("frontend/results.txt", "w");
    if (!f) {
        perror("Error creating results.txt");
        return;
    }

    // FORMATO:
    // Element,Observed_nm,Reference_nm,Difference_nm,Probability

    fprintf(f, "Hydrogen,486.00,486.00,0.00,100.00\n");
    fprintf(f, "Sodium,589.20,589.00,0.20,92.31\n");
    fprintf(f, "Oxygen,777.00,777.00,0.00,100.00\n");

    fclose(f);
}
