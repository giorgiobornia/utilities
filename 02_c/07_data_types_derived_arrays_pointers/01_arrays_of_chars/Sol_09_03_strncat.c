/* Concatenazione di dei primi n caratteri di una stringa 
   su di un'altra con strcat */
#include <stdio.h>
#include <string.h>

char frase[160] = "Analisi, requisiti";

main()
{
char dimmi[80];
int i;

for(i=0; ((dimmi[i]=getchar())!='\n') && (i<80); i++)
  ;
dimmi[i] = '\0';
strncat(frase, dimmi, 5);
printf("%s \n", frase);
}
