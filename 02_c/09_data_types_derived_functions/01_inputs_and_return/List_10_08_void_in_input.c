#include <stdio.h>

void messErr( void );

main()
{
  int a, b, c;

  printf("Inserire dividendo:");
  scanf("%d", &a);
  printf("Inserire divisore:");
  scanf("%d", &b);
  if (b != 0) {
    c = a/b;
    printf("%d diviso %d = %d\n", a, b, c);
  }
else
  messErr();
}

void messErr( void )
{
  int i;
  char c;

  for (i = 0; i <= 20; i++) printf("\n");
  printf("                  ERRORE! DENOMINATORE NULLO");
  printf("\n Premere un tasto per continuare\n");
  scanf("%c%c", &c, &c);
}
