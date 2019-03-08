#include <stdio.h>

char str[] = "BATUFFO";
int strlen(char *);

main()
{
printf("la stringa %s ha lunghezza %d\n", str, strlen(str));
}

int strlen(char *p)
{
  int i = 0;
  while (*p++) i++;
  return i;
}
