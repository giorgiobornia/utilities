/* Esempio di utilizzo di case */
#include <stdio.h>

int x;
main()
{
printf("Digita una cifra: ");
scanf("%d", &x);

switch(x) {
  case 0:
    printf("zero\n");
    break;
  case 1:
    printf("uno\n");
    break;
  case 2:
    printf("due\n");
    break;
  case 3:
    printf("tre\n");
    break;
  case 4:
    printf("quattro\n");
    break;
  case 5:
    printf("cinque\n");
    break;
  default:
    printf("non compreso\n");
    break;
}
}
