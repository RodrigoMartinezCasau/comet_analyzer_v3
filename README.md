# 📘 Comet Analyzer — Instrucciones de Uso

Este proyecto analiza un espectro de un cometa a partir de un archivo de texto y detecta los elementos químicos presentes según sus líneas espectrales.

---

## ✅ 1. Requisitos

Asegúrate de tener instalado:

- **CMake (≥ 3.10)**
- **Compilador C (clang o gcc)**

Puedes comprobarlo con:

```bash
cmake --version
gcc --version
✅ 2. Construir el proyecto
Desde la carpeta raíz del proyecto (comet_analyzer_v3/):
cmake --build build
Esto:
Genera los archivos necesarios
Compila el código en build/
Crea el ejecutable comet_analyzer
✅ 3. Ejecutar el programa
El programa necesita un archivo de espectro en texto plano.
📄 Ejemplo de spectrum.txt:
400.1, 0.12
434.0, 0.87
486.0, 0.90
589.2, 1.00
656.0, 0.75
777.0, 0.95
▶️ Ejecutar el analizador:
./build/comet_analyzer spectrum.txt
🔬 ¿Qué hace el programa?
El programa:
Carga los valores del espectro
Detecta automáticamente los picos
Compara con la base de datos de elementos
Calcula diferencias y probabilidades
El resultado muestra:
Elemento detectado
Pico observado
Diferencia con la línea teórica
Probabilidad estimada
🛠 Problemas comunes
❗ “Uso: ./build/comet_analyzer”
No pasaste el nombre del archivo.
Ejemplo correcto:

./build/comet_analyzer spectrum.txt
❗ “No se pudo abrir archivo”
Verifica:
Que spectrum.txt exista
Que esté en la misma carpeta desde donde ejecutas
Que tenga el formato correcto
🎯 Proyecto completado
Si ves elementos detectados y sus probabilidades, el programa funciona correctamente.

---

