#include <stdio.h>

char buf[128];
void minMaiusc (void);

main()
{
  printf("\nInserisci stringa: ");
  scanf("%s", buf);

  minMaiusc();
  printf("%s\n", buf);
 }

void minMaiusc(void)
{
  int i;

  for (i = 0; buf[i] != '\0'; i++)
    if (buf[i] >= 'a' && buf[i] <= 'z')
      buf[i] = buf[i] - 'a' + 'A';
}
