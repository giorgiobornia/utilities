#include <stdio.h>

char *menu[] = {
  "1. Voce di menu 1\n",
  "2. Voce di menu 2\n",
  "3. Voce di menu 3\n",
  "...\n"
  "N. Voce di menu N\n",
  NULL
};

char **ppc = menu;

main()
{
char *pausa;
while(*ppc!=NULL)
  printf("%s", *ppc++);
gets(pausa);
}
