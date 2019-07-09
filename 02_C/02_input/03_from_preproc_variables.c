/* Compute area of a rectangle, use preprocessor constants */
#include <stdio.h>

#define BASE 3
#define HEIGHT 7

main()
{
  int area;

  area = BASE*HEIGHT;
  printf("Base: %d\n", BASE);
  printf("Height: %d\n", HEIGHT);
  printf("Area: %d\n", area);
}
