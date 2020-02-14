/* Esempio di utilizzo dell'istruzione for
Calcola la somma di cinque numeri interi immessi dall'utente */

#include <stdio.h>
int i, somma, numero;

main()
{
printf("SOMMA 5 NUMERI\n");
somma = 0;

for(i=1; i<=5; i=i+1) {
	printf("Inser. intero: ");
	scanf("%d", &numero);
	somma = somma + numero;
	}

printf("Somma: %d\n",somma);
}