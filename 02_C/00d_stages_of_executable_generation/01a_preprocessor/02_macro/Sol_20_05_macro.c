/* Esempio di macro che concatena i primi n caratteri
   di una stringa su di un'altra                      */

#include <stdio.h>

#define CONCATENA(uno,due,n) {\
  for(i=0; uno[i]!='\0'; i++);\
  for(j=0; (uno[i]=due[j])!='\0'  && j<(n)-1; i++,j++);\
}

char stringa1[100] = "Prima stringa ";

main()
{
char stringa2[100];
int i, j, n;
printf("Inserire una parola: ");
for(i=0; (stringa2[i]=getchar())!='\n'; i++)
  ;
stringa2[i]='\0';

printf("Caratteri da concatenare: ");
scanf("%d", &n);

CONCATENA(stringa1, stringa2, n);

printf(" Stringa concatenata: %s \n", stringa1);
}
