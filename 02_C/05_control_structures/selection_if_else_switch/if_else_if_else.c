#define AND &&
/* ------------------------------------ *
 * Scrittura e compilazione di c6a.c:   *
 * if - else if - else                  *
 * ------------------------------------ */
main ()
{
  int a;
  char c;

  printf("Scrivi un carattere: ");
  scanf ("%c",&c);

  if (c >= 'a' && c <= 'z')
    printf("lettera minuscola: %c \n",c);
  else if (c >= 'A' && c <= 'Z')
    printf("lettera maiuscola: %c \n",c);
  else if (c >= '0' && c <= '9')
    printf("cifra: %c \n",c);
  else 
    printf("carattere speciale: %c \n",c);


  printf("Scrivi un altro carattere: ");
  scanf ("\n%c",&c);

  if (c >= 'a' AND c <= 'z')
    printf("lettera minuscola: %c \n",c);
  else if (c >= 'A' AND c <= 'Z')
    printf("lettera maiuscola: %c \n",c);
  else if (c >= '0' AND c <= '9')
    printf("cifra: %c \n",c);
  else 
    printf("carattere speciale: %c \n",c);

    printf("\nEspressioni vere o false\n");

    if(2<3)
      printf("2<3: vero! \n");
    if(2+3)
      printf("2+3: vero! \n");
    if(a=2)
      printf("a=2: vero! \n");

    if(2-2)
      printf("0: vero! \n");
    if(a=0)
      printf("0: vero! \n");

    if(!(2-2))
      printf("0: falso! \n");
    if(!(a=0))
      printf("0: falso! \n");

    if (a==0)
      printf("a e' uguale a 0: vero! \n");
}
