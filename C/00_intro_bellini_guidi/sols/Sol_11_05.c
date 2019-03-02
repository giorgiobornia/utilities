#include <stdio.h>
#include <malloc.h>

main()
{
  char *s;
  int  n;
  printf("Inserire dimensione del buffer : ");
  scanf("%d", &n);
  s = (char*) malloc(n+1);
  ...
}
