#ifndef ELEMENT_DB_H
#define ELEMENT_DB_H

// We define a struck that sets the structure of the elements given:
typedef struct {
    char name[20];     // The name of the element
    double lines[10];  // The value of the lines(peaks)
    int line_count;    // The number of lines 
} Element;

Element* get_known_elements(int *count);
void print_known_elements(void);

#endif
