Project Overview:

Comet Analyzer v3 is a C-based scientific tool designed to analyze the emission spectrum of a comet and identify potential chemical elements present in its composition.

The program performs the following tasks:

- Loads a spectrum file containing wavelength peaks.
- Loads an element database with known atomic emission wavelengths.
- Compares each observed peak to every element line using a tolerance threshold.
- Computes the difference between wavelengths and assigns probabilities.
- Generates a formatted report listing the detected elements.
- Frees all dynamically allocated memory to ensure safety and performance.

Input format:
- spectrum.txt — observed peaks (nm)

Output:
- A console report listing detected matches, differences, and probabilities.

