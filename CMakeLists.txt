# CMakeLists.txt (raíz del proyecto)
# ----------------------------------------------------------
# Este archivo le dice a CMake cómo construir
# nuestro proyecto Comet Analyzer.
# ----------------------------------------------------------

cmake_minimum_required(VERSION 3.10)           # Versión mínima de CMake
project(comet_analyzer C)                      # Nombre del proyecto y lenguaje (C)

set(CMAKE_C_STANDARD 11)                       # Usamos C11 para el compilador

# Definimos el ejecutable "comet_analyzer" y le indicamos
# qué archivos .c forman parte de él.
add_executable(comet_analyzer
    src/main.c
    src/element_db.c
    src/data_loader.c
    src/spectrum_analyzer.c
)

# Le decimos al compilador dónde buscar nuestros headers (.h).
# ${PROJECT_SOURCE_DIR} es la carpeta raíz del proyecto.
target_include_directories(comet_analyzer PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# =======================
# Compilar tests
# =======================

add_executable(test_loader tests/test_loader.c
    src/data_loader.c
)

add_executable(test_peaks tests/test_peaks.c
    src/spectrum_analyzer.c
)

add_executable(test_match tests/test_match.c
    src/element_db.c
    src/spectrum_analyzer.c
)
