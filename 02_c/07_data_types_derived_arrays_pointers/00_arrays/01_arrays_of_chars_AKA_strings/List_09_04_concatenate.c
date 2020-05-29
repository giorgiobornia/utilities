/* Concatenazione di due stringhe
   Introduzione della seconda stringa con getchar */

#include <stdio.h>

char frase[160] = "Analisi, requisiti ";

main()
{
char dimmi[80];
int i, j;

printf("Inserisci una parola: ");
for(i=0; (dimmi[i]=getchar())!='\n'; i++)
  ;
dimmi[i]='\0';
for(i=0; frase[i]!='\0'; i++)
  ;
for(j=0; (frase[i]=dimmi[j])!='\0'; i++,j++)
  ;
printf(" frase: %s \n", frase);
}
