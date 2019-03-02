/* Calcolo di n! (n fattoriale) */
#include <stdio.h>

main()       
{
int n, fat, m;

printf("CALCOLO DI N!\n\n");
printf("Inser. n: ");
scanf("%d", &n);

fat = n;
for(m=n; m>2; m--)
  fat = fat*(m-1);

printf("Il fattoriale di: %d ha valore: %d\n", n, fat);
}
