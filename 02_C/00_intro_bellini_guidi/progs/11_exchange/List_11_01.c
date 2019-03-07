#include <stdio.h>

void scambia(int, int);

main()
{
  int x, y;

  x = 8;
  y = 16;
  printf("Prima dello scambio\n");
  printf("x = %d, y = %d\n", x, y);

  scambia(x, y);

  printf("Dopo lo scambio\n");
  printf("x = %d, y = %d\n", x, y);
}


/* Versione KO di scambia */
void scambia(int a, int b)
{
  int temp;

	 temp = a;

	 a = b;
	 b = temp;
}
