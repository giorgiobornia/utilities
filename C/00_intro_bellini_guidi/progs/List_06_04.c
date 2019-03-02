/* Calcola la somma dei valori interi passati dall'utente
   Termina quando viene immesso il valore 0 (zero)       */

#include <stdio.h>

main()
{
int somma, numero;
printf("SOMMA NUMERI\n");
printf("zero per terminare\n");
numero = 1;
somma  = 0;
while(numero!=0) {
	printf("Inser. intero: ");
	scanf("%d", &numero);
	somma = somma+numero;
}
printf("Somma: %d\n",somma);
}