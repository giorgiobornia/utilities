/* Esempio di utilizzo di abs() */
#include <stdio.h>
#include <math.h>

main()
{
  int a, b, segmento, lunghezza;

  printf("\n\nLUNGHEZZA SEGMENTO\n");
  printf("Primo estremo: ");
  scanf("%d", &a);
  printf("Secondo estremo: ");
  scanf("%d", &b);

  segmento = a-b;
  lunghezza = abs(segmento);

  printf("Lunghezza segmento: %d\n", lunghezza);
}
