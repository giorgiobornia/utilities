#include <stdio.h>

double area(float, float, char);

main()
{
  float b, h;
  double a;
  char p;

  printf("Inserire poligono (Triangolo/Rettangolo): ");
  scanf("%c", &p);
 
  printf("\nInserire base: ");
  scanf("%f", &b);
  printf("\nInserire altezza  : ");
  scanf("%f", &h);

  a = area(b, h, p);
  
  printf("Il poligono (b = %f, h = %f) ha area %f\n", b, h, a);
}

double area(float base, float altezza, char poligono)
{
  switch (poligono) {
    case 'T':     return (base * altezza/2.0);
    case 'R':     return (base * altezza);
    default :     return -1;
  }
}
