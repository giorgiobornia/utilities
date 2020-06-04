/* Confronto tra due stringhe con strcmp */

#include <stdio.h>
#include <string.h>

char prima[160] = "mareggiata";

main()
{
char seconda[80];
int i, x;

printf("Inserisci una parola: ");
for(i=0; ((seconda[i]=getchar())!='\n') && (i<80); i++)
  ;
seconda[i] = '\0';

if( (x = (strcmp(prima, seconda))) == 0)
  printf("Sono uguali\n");
else
  if(x>0)
    printf("la prima e' maggiore della seconda\n");
  else
    printf("la seconda e' maggiore della prima\n");
}
