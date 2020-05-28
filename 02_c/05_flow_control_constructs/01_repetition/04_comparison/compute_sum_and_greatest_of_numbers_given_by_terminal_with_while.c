/* Determina somma e maggiore dei valori immessi */
#include <stdio.h>

main()
{
int somma,numero,max,i;

printf("SOMMA E MAGGIORE\n");
printf("zero per finire\n");
numero = 1;
somma = 0;
max = 0;
i = 1;
while(numero!=0 && i<=10)
{
	printf("Valore int.: ");
	scanf("%d", &numero);
	if(numero>max)
	   max = numero;
	somma = somma+numero;
	i++;
}
printf("Somma: %d\n", somma);
printf("Maggiore: %d\n", max);
}