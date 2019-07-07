#include <stdio.h>

void messaggio (int, int);

char messaggio[] = "Ciao, baby";

main()
{
  int riga = 10;
  int colonna = 20; 
  messaggio (riga, colonna);
}

void messaggio(int r, int c)
{
  while(c--)  printf("\n");
  while(r--)  putchar(' ');
  printf("%s\n\n", messaggio);
}
