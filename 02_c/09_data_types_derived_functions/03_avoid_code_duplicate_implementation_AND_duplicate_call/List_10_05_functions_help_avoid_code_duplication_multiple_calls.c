#include <stdio.h>

double area(float, float, char);

main()
{
  float b, h;
  double tri, ret;

  printf("Inserire base: ");
  scanf("%f", &b);
  printf("Inserire altezza: ");
  scanf("%f", &h);

  tri = area(b, h, 'T');
   
  ret = area(b, h, 'R');

  printf("Il triangolo (b = %f, h = %f) ha area %f\n", b, h, tri);
  printf("Il rettangolo (b = %f, h = %f) ha area %f\n", b, h, ret);
}

double area(float base, float altezza, char poligono)
{
  switch (poligono) {
    case 'T':     return (base * altezza/2.0);
    case 'R':     return (base * altezza);
    default :     return -1; 
  }
}
