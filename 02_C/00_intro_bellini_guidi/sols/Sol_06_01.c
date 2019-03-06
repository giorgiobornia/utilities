/* Determina il fattoriale dei numeri minori o uguali
   all'intero immesso dall'utente                    */

#include <stdio.h>
main()
{
int n, fat, aux;

printf("CALCOLO DEI FATTORIALI DEI NUMERI <= N\n\n");
printf("Inser. n: ");
scanf("%d", &n);

fat = 1;
printf("Il fattoriale di: 0 ha valore: %d\n", fat);

for(aux=1; aux<=n; aux++) {
  fat = fat*aux;
  printf("Il fattoriale di: %d ha valore: %d\n", aux, fat);
}
}
