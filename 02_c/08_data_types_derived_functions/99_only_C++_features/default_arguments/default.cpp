#include <stdio.h>


void f(double b = 1.) {
 
    printf("%lf\n", b);
}

int main() {
 
    f(7);
    f();
    
  return 0;
}
