/* ------------------------------------ *
 * Scrittura e compilazione di c5.c:    *
 * cicli for e while                    *
 * ------------------------------------ */
main ()
{
  int i, trian;

  printf("TABLE OF TRIANGULAR NUMBERS \n");
  printf("\n i     sum from 1 to i \n");
  printf("---    ---------------\n");

  /* scrittura originaria */
  trian=0;
  for (i=1; i<=10; i +=1) {
    trian = trian + i;
    printf(" %3d         %3d\n",i,trian);
  }
  printf("---    ---------------\n");

  /* prima variante */
  i=1; trian=0;
  while (i<=10) {
    trian = trian + i;
    printf(" %3d         %3d\n",i,trian);
    i = i + 1;
  }
  printf("---    ---------------\n");
  
  /* seconda variante */
  i = trian = 0;
  while (i<10) {
    trian += ++i;
    printf(" %3d         %3d\n",i,trian);
  }
  printf("---    ---------------\n");
}
