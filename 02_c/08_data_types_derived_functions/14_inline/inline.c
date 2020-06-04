#include <stdio.h>


inline void f(double b) {        /* inline alone does not work in C, but it works in C++ ! */
// static inline void f(double b) { /* works */
// extern inline void f(double b) {    /* works */
 
    printf("%lf\n", b);
}

int main() {
 
    f(7);
    
  return 0;
}
