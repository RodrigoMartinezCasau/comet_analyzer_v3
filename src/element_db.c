#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element_db.h"

// A broad (and expandable) list of potential elements found in a comet 
// The values of the wavelebgts of each element correspond to the official digits 
Element* get_known_elements(int *count) {
    *count = 8; // For now we chose to use the most common ones --> 8
    Element *elements = malloc(sizeof(Element) * (*count));

    // Hydrogen 
    strcpy(elements[0].name, "Hydrogen");
    elements[0].lines[0] = 656.0;
    elements[0].lines[1] = 486.0;
    elements[0].lines[2] = 434.0;
    elements[0].line_count = 3;

    // Oxygen
    strcpy(elements[1].name, "Oxygen");
    elements[1].lines[0] = 777.0;
    elements[1].lines[1] = 844.0;
    elements[1].line_count = 2;

    // Sodium
    strcpy(elements[2].name, "Sodium");
    elements[2].lines[0] = 589.0;
    elements[2].line_count = 1;

    // Helium
    strcpy(elements[3].name, "Helium");
    elements[3].lines[0] = 587.6;
    elements[3].lines[1] = 447.1;
    elements[3].line_count = 2;

    // Carbon
    strcpy(elements[4].name, "Carbon");
    elements[4].lines[0] = 426.7;
    elements[4].lines[1] = 658.0;
    elements[4].line_count = 2;

    // Calcium
    strcpy(elements[5].name, "Calcium");
    elements[5].lines[0] = 422.7;
    elements[5].lines[1] = 393.4;
    elements[5].line_count = 2;

    // Magnesium
    strcpy(elements[6].name, "Magnesium");
    elements[6].lines[0] = 517.0;
    elements[6].line_count = 1;

    // Iron
    strcpy(elements[7].name, "Iron");
    elements[7].lines[0] = 438.4;
    elements[7].lines[1] = 526.0;
    elements[7].line_count = 2;

    return elements;
}
