#include <stdio.h>

int numeri = 0;
int alfa   = 0;
char buf[80];
int i;

void numAlfa(void);

main()
{
  printf("\nInserisci stringa: ");
  scanf("%s", buf);

  numAlfa();
  printf("Ci sono %2d caratteri numerici\n", numeri);
  printf("Ci sono %2d caratteri alfabetici\n", alfa);
}

void numAlfa(void)
{
  for (i = 0; buf[i] != '\0'; i++)
    switch(buf[i]) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
                numeri++;
                break;
      default:
                alfa++;
                break;
    }
}
