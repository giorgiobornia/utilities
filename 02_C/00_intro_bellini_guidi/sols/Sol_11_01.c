#include <stdio.h>
int a[5] = { 1, 2, 3, 4, 5 };

main()
{
  int i, *p;
  p = a;
  printf("Gli elementi del vettore sono:\n\n");

  for (i = 0; i <= 4; i++)
    printf("a[%d] = %d\n", i, *p++);
}
