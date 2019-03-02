/* Determina il maggiore tra quattro valori */

#include <stdio.h>
main()
{
int a, b, c, d;
printf("\nDigita quattro valori interi distinti: ");
scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &c);
scanf("%d", &d);

if(a>b)
  if(a>c)
    if(a>d)
      printf("Il maggiore e': %d\n", a);
    else
      printf("Il maggiore e': %d\n", d);
  else
    if(c>d)
      printf("Il maggiore e': %d\n", c);
    else
      printf("Il maggiore e': %d\n", d);
else
  if(b>c)
    if(b>d)
      printf("Il maggiore e': %d\n", b);
    else
      printf("Il maggiore e': %d\n", d);
  else
    if(c>d)
      printf("Il maggiore e': %d\n", c);
    else
      printf("Il maggiore e': %d\n", d);
}
