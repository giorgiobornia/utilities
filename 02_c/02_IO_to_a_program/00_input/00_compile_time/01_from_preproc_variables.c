/* Compute area of a rectangle, use preprocessor constants */

/*
 * This method is worse, because there is no type checking on BASE and HEIGHT
 */

#include <stdio.h>

#define BASE 3
#define HEIGHT 7


int main() {
    
  double area;

  area = BASE * HEIGHT;
  printf("Base: %f\n", BASE);
  printf("Height: %f\n", HEIGHT);
  printf("Area: %f\n", area);
  
}
