/**
gcc -O0 -g -Wall 02_heap_memory_leak.c -o heap_ml
valgrind -v --log-file=valgrind.report  ./heap_ml
valgrind -v --leak-check=full --log-file=valgrind.report  ./heap_ml

*/
#include <stdlib.h>

  void f(void)
  {
     int* x = malloc(10 * sizeof(int));  // problem 2: memory leak -- x not freed
     x[9] = 0;                          // problem 1: heap block overrun
  }                    

  int main(void)
  {
     f();
     return 0;
  }
