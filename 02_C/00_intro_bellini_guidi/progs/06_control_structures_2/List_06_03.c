/* Calcolo n! (n fattoriale) */
#include <stdio.h>

main()       
{
int n, fat, aux;

printf("CALCOLO DI N!\n\n");
printf("Inser. n: ");
scanf("%d", &n);

fat = 1;
for(aux=2; aux<=n; aux++) fat = fat*aux;

printf("Il fattoriale di: %d ha valore: %d\n", n, fat);
}
