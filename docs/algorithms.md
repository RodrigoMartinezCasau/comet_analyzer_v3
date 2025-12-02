Algorithms used:

1. Linear Search
Each peak is compared to every element wavelength.  
Time complexity: O(n × m).

2. Tolerance-based Matching
A match happens when:
difference = |peak - wavelength| <= tolerance

3. Probability Calculation
Simple confidence score:
prob = 1 - (difference / tolerance)

4. Memory Management**  
Dynamic allocation and freeing using `malloc()` and `free()`.

5. File Parsing 
Reading text files line-by-line and converting values into structured data.