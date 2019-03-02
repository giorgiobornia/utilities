/* Esempio di istruzioni composte */
#include <stdio.h>

int i;
int mag_100;
int min_100;

main ()
{
mag_100 = 0;
min_100 = 0;

printf("Dammi un intero: ");
scanf("%d", &i);

if(i<100) {
  printf("minore di 100\n");
  min_100 = 1;
}
else {
  printf("maggiore o uguale a 100\n");
  mag_100 = 1;
}
}
