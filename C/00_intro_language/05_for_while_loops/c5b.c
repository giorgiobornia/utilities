/* ------------------------------------ *
 * Scrittura e compilazione di c5.c:    *
 * ciclo con il do                      *
 * ------------------------------------ */
main ()
{
  int in,digit,tmp;
  int out = 0;

  printf("Enter your number: ");
  scanf("%d",&in);

  tmp = in;
  do {
    digit = in%10;
    out = out*10 + digit;
    in /= 10;
  } while (in != 0);

  printf("%d \n",out);

  /* una piccola variazione */ 
  in = tmp;
  do {
    digit = in%10;
    printf("%d",digit);
    in = in/10;
  } while (in != 0);

  printf("\n");
}

