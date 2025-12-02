Architecture and distribution used:

src/
├── main.c
├── data_loader.c
├── element_db.c
└── spectrum_analyzer.c
include/
├── data_loader.h
├── element_db.h
└── spectrum_analyzer.h

main.c – program entry, coordinates loading/matching/output  
data_loader.c – loads spectrum peaks  
element_db.c – loads element wavelengths  
spectrum_analyzer.c – compares peaks to elements and finds matches  
Headers expose structs and function declarations to keep the program modular.
