/* Determina il maggiore e il minore fra tre valori */

#include <stdio.h>
main()
{
int a, b, c;
printf("\nDigita tre valori interi distinti: ");
scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &c);

if(a>b)
  if(a>c) {
    printf("Il maggiore e': %d\n", a);
    if(b<c)
      printf("Il minore e': %d\n", b);
    else
      printf("Il minore e': %d\n", c);
  }
  else {
    printf("Il maggiore e': %d\n", c);
    printf("Il minore e': %d\n", b);
  }
else
  if(b>c) {
    printf("Il maggiore e': %d\n", b);
    if(a<c)
      printf("Il minore e': %d\n", a);
    else
      printf("Il minore e': %d\n", c);
  }
  else {
    printf("Il maggiore e': %d\n", c);
    printf("Il minore e': %d\n", a);
  }
}
