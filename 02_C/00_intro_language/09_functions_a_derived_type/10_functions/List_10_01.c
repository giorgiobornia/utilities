#include <stdio.h>

double cubo(float);

main()
{
  float  a;
  double b;

  printf("Inserisci un numero: ");
  scanf("%f", &a);

  b = cubo(a);
  printf("%f elevato al cubo e' uguale a %f", a, b);
}


double cubo(float c)
{
  return (c*c*c);
}
