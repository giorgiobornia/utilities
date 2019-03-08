/* Visualizzazione caratteri di una stringa */

#include <stdio.h>

char frase[] = "Analisi, requisiti ";

main()
{
int i=0;
while(frase[i]!='\0') {
  printf("%c = %d = %o \n", frase[i], frase[i], frase[i]);
  i++;
}
}
