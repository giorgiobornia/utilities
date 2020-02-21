/* Calcolo del fattoriale con una funzione ricorsiva */

#include <stdio.h>

fat(int);

main()
{
int n;

printf("CALCOLO DI n!\n\n");
printf("Inser. n: \t");
scanf("%d", &n);
printf("Il fattoriale di: %d ha valore: %d\n", n, fat(n));
}

fat(int n)
{
if(n==0)
  return(1);
else
  return(n*fat(n-1));
}
