#include <stdio.h>

#define MAGGIORE(a, b) ((a) > (b) ? (a) : (b))

int i, j;
double x, y;
char c1, c2;
main()
{
i=88;    j=55;
x=83.54; y=96.2;
c1='c';  c2='z';
printf("Maggiore: %d\n", MAGGIORE(i, j));
printf("Maggiore: %f\n", MAGGIORE(x, y));
printf("Maggiore: %c\n", MAGGIORE(c1, c2));
}
