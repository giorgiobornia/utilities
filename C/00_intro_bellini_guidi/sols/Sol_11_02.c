#include <stdio.h>

char *vet[] = {"Messaggio #1\n",
               "Messaggio #2\n",
               "Messaggio #3\n",               
               "Messaggio #4\n",
               "Messaggio #5\n",
               NULL
              };
char **p = vet;

main()
{
  while(*p != NULL)
    printf("%s", *p++);
}
