/* Compute area of a rectangle, using scanf to input the data */

#include <stdio.h>

int main() {

    double base, height, area;
    
  printf("Area of the rectangle \n\n");

  printf("Value of base: ");
  scanf("%lf", &base);
  printf("Value of height: ");
  scanf("%lf", &height);

  area = base*height;

  printf("Base: %lf\n", base);
  printf("Height: %lf\n", height);
  printf("Area: %lf\n", area);
}
