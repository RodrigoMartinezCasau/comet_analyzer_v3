#ifndef ELEMENT_DB_H
#define ELEMENT_DB_H


typedef struct {
    char name[20];     
    double lines[10]; 
    int line_count;    
} Element;

Element* get_known_elements(int *count);
void print_known_elements(void);

#endif
