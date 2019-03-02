/* Calcolo area rettangolo */
#include <stdio.h>

int base, altezza, area;

main()
{
  printf("AREA RETTANGOLO\n\n");

  printf("Valore base: ");
  scanf("%d", &base);
  printf("Valore altezza: ");
  scanf("%d", &altezza);

  area = base*altezza;

  printf("Base: %d\n", base);
  printf("Altezza: %d\n", altezza);
  printf("Area: %d\n", area);
}
