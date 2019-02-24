/* ------------------------------------ *
 * Scrittura e compilazione di c5c.c:   *
 * ancora sul for                       *
 * ------------------------------------ */
main ()
{
  int i,j,k,pippo;

  for (i=1; i<=2; i++) {
    printf ("i: %d\n",i);
    for (j=1; j<=2; j++) 
      printf ("     j: %d\n",j);
    printf ("     fine del ciclo j\n");
  }
  printf ("fine del ciclo i\n\n");

  for (i=1; i<=10; i++) 
    for (j=1; j<=10; j++) 
      for (k=1; k<=10; k++)
	pippo = i+j+k;

  printf("pippo: %d\n",pippo);
}

