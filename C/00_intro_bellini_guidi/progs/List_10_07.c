#include <stdio.h>
#define DIM_INT 16

void stampaBin ( int );

main()
{
  char resp[2];
  int  num;

  resp[0] = 's';

  while( resp[0] == 's' ) {
    printf("\nInserisci un intero positivo: ");
    scanf("%d", &num);
    printf("La sua rappresentazione binaria e': ");

    stampaBin( num );

    printf("\nVuoi continuare? (s/n): ");
    scanf("%s",resp);
  }
}

void stampaBin( int v )
{
  int i, j;
  char a[DIM_INT];

  if (v == 0)
    printf("%d", v);
  else  {
    for( i=0; v != 0; i++)   {
      a[i] = v % 2;
      v /= 2;
    }
    for(j = i-1 ; j >= 0; j--)
      printf("%d", a[j]);
  }
}
