#include <stdio.h>

char str[] = "Lupus in fabula";

int lung_string(void);

main()
{
  int l;

  l = lung_string();
  printf("La stringa %s ha %d caratteri\n", str, l);
}

int lung_string(void)
{
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}
