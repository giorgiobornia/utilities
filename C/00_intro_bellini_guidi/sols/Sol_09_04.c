/* Confronto dei primi n caratteri di due stringhe con strncmp */

#include <stdio.h>
#include <string.h>

char prima[160] = "Analisi, requisiti";

main()
{
char seconda[80];
int i, x;

for(i=0; ((seconda[i]=getchar())!='\n') && (i<80); i++)
  ;
seconda[i]='\0';
if((x=(strncmp(prima, seconda, 5)))==0)
  printf("Sono uguali\n");
else
  if(x>0)
    printf("La prima e' maggiore della seconda\n");
  else
    printf("La seconda e' maggiore della prima\n");
}
