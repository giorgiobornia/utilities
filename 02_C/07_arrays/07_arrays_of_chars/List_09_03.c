/* Concatenazione di due stringhe */

#include <stdio.h>

char frase[160] = "Analisi, requisiti ";

main()
{
char dimmi[80];
int i, j;

printf("Inserisci una parola: ");
scanf("%s", dimmi);
for(i=0; (frase[i])!='\0'; i++)
  ;
for(j=0; (frase[i]=dimmi[j])!='\0'; i++,j++)
  ;
printf("frase: %s \n", frase);
}
