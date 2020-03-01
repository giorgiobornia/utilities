/* Compute area of a rectangle, use scanf */
#include <stdio.h>

int main()
{

    int base, height, area;
    
  printf("Area of the rectangle \n\n");

  printf("Value of base: ");
  scanf("%d", &base);
  printf("Value of height: ");
  scanf("%d", &height);

  area = base*height;

  printf("Base: %d\n", base);
  printf("Height: %d\n", height);
  printf("Area: %d\n", area);
}
