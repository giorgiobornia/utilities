#include <stdio.h>
#include <math.h>

#define ZERO 0
#define TOP  1000

main()
{
  int a, b, c, x, y;

  printf("Valore di x: ");
  scanf("%d", &x);

  printf("Valore di y: ");
  scanf("%d", &y);

  a = ZERO-abs(x);
  b = TOP-abs(y);
  c = a*b;

  printf("Valore di a: %d\n", a);
  printf("Valore di b: %d\n", b);
  printf("Valore di c: %d\n", c);
}
