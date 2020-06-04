
#include <stdio.h>

char frase[] = "Analisi, requisiti ";

main()
{
int i;
char discorso[80];
for(i=0; (discorso[i]=frase[i])!='\0'; i++)
  ;
printf(" originale: %s \n copia:     %s \n", frase, discorso);
}
