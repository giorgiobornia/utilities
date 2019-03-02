/* Calcolo della potenza di base elevata a esponente
   dove esponente e' un numero maggiore uguale a zero */

#include <stdio.h>

double potenza(float, int);

main()
{
float b; int e;
printf("\n\n Calcolo della potenza \n\n");
printf("Inser. base: \t");
scanf("%f", &b);
printf("Inser. esponente: \t");
scanf("%d", &e);
printf("Potenza: %lf\n", potenza(b, e));
}

/* Funzione per il calcolo di base elevata a esp con esp>=0 */
double potenza(float base, int esp)
{
double pot = 1;
if(esp==0)  return(1);   /* caso esponente uguale a zero */
if(esp>0) {              /* calcolo della potenza */
  do
    pot = pot*base;      /* base*base*base.... esp volte */
  while(--esp>0);
}
return(pot);
}
