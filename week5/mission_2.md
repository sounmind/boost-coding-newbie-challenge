# Mission 2: Memory and Overflow

## 1. When Heap Overflow and Stack Overflow happen?

### Background: Memory Structure in C
1. Code Area
   -  Code of currently executing program is stored in this area.
   -  CPU read this code one line at a time by line.
2. Data Area
   -  Global and Static variables are allocated in this area as soon as the program starts and remains until the program is terminated.
3. Heap Area
   -  Memory which programmer dynamically allocated is stored in this area. 
4. Stack Area
   -  Local variables and parameters are allocated in this area and it disappears when the function ends.

### When it happens?
It happens when memory is allocated beyond the capacity of the buffer(a region of a physical memory storage).  
For example:
   1. When you call some function infinitely, the function's memory is allocated(stacked) forever in the stack until a stack overflow occurs.
   2. When you dynamically allocate memory on the heap and it overwrites your important data, a heap overflow happens.

## 2. What's difference with strcpy() and strncpy()? (+ what's your recommendation and why?)

1. strcpy() function copies whole content of one string into another string. Whereas, strncpy() function copies portion of contents of one string into another string.
2. If destination string length is less than source string, entire/specified source string value won¡¯t be copied into destination string in both cases
### Recomendation
It depends on your purpose. If you want to copy part of the string, you should use strncpy. If you need whole string you should use strcpy.

## 3. C libraries have functions such as memory initialization, copy, movement, comparision etc. Write codes to be accustomed yourself to that how to use it and check if it works well.
1. memory initialization `void *memset(void *s, int c, size_t n);`
   - Parameters or Arguments
     - s -> A pointer to a memory block that will be filled.
     - c -> The value to be stored.
     - n -> The number of characters(1 byte) to be stored.
  - returns
      - The memset function returns s.
  - required header
      - `#include <string.h>`

2. memory copy `void *memcpy(void *s1, const void *s2, size_t n);`
   - Parameters or Arguments
       - s1 -> An array where s2 will be copied to
       - s2 -> The string to be copied
       - n -> The number of characters to copy
   - returns
       - The memset function returns s.
   - required header
         - `#include <string.h>`
3. memory movement `void *memmove(void *s1, const void *s2, size_t n);`
   - Parameters or Arguments
       - s1 -> An array where s2 will be copied to.
       - s2 -> The string to be copied.
       - n -> The number of characters to copy. 
   - returns
       - The strcpy function returns s1.
   - required header
       - `#include <string.h>`
4. memory comparision `int memcmp(const void *s1, const void *s2, size_t n);`
- Parameters or Arguments
  - s1 -> An array to compare.
  - s2 -> An array to compare
  - n -> The number of characters to compare.
- returns
    - The memcmp function returns an integer. The return values are as follows:
        - 0 -> s1 and s2 are equal
        - Negative integer -> The stopping character in s1 was less than the stopping chracter in s2
        - Positive integer -> The stopping character in s1 was greater than the stopping chracter in s2
- required header
    - `#include <string.h>`

## References

1. [Buffer overflow](https://en.wikipedia.org/wiki/Buffer_overflow)
2. [What is the difference between strcpy() & strncpy() functions in C?](https://fresh2refresh.com/c-programming/c-interview-questions-answers/what-is-the-difference-between-strcpy-ampersand-strncpy-functions-in-c/)
3. [C Language: memset function(Initialize Memory Block)](https://www.techonthenet.com/c_language/standard_library_functions/string_h/memset.php)
4. [C Language: memcpy function(Copy Memory Block)](https://www.techonthenet.com/c_language/standard_library_functions/string_h/memcpy.php)
5. [C Language: memmove function(Copy Memory Block)](https://www.techonthenet.com/c_language/standard_library_functions/string_h/memmove.php)
6. [C Language: memcmp function(Compare Memory Blocks)](https://www.techonthenet.com/c_language/standard_library_functions/string_h/memcmp.php)

