/* Esempio di utilizzo di case */
#include <stdio.h>

char x;
main()
{
printf("Digita una cifra: ");
scanf("%c", &x);

switch(x) {
  case '2':
  case '4':
  case '6':
    printf("pari\n");
    break;
  case '1':
  case '3':
  case '5':
    printf("dispari\n");
    break;
  default:
    printf("altro\n");
}
}
