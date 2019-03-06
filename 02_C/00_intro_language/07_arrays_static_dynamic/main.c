/* ------------------------------------ *
 * Scrittura e compilazione di c7.c:    *
 * arrays                               *
 * ------------------------------------ */
main ()
{
  int i,j,nt,fib[10],matrix[3][4];
  int media;
  float ave;

  /* calcolo dei primi 10 numeri di
     Fibonacci */
  fib[0] = 0;
  fib[1] = 1;

  for(i=2; i<10; i++)
    fib[i] = fib[i-1] + fib[i-2]; 

  printf("  i  fib(i)\n");
  printf("-----------\n");

  for(i=0; i<10; i++)
    printf(" %2d   %4d\n",i,fib[i]);

  /* matrice bidimensionale di 
     interi: inizializzazione */

  for (i=0; i<3; i++)
    for (j=0; j<=3; j++)
      matrix[i][j] = i+j+2;

  /* calcolo del valor medio */
  ave = 0.;
  media = nt = 0;

  for (i=0; i<3; i++)
    for (j=0; j<=3; j++) {
      ave += matrix[i][j];
      media += matrix[i][j];
      nt++;
    }

  printf("\nRIGHE(i)    COLONNE(j)\n");
  printf("            0  1  2  3\n\n");

  for (i=0; i<3; i++) {
    printf("  %3d     ",i);
    for (j=0; j<=3; j++) 
      printf("%3d",matrix[i][j]);
    printf("\n");
  }

  printf("\nValor medio: %f\n",ave/nt);
  printf("\nValor medio (int): %d\n",media/nt);
  printf("\nValor medio (float): %f\n",(float) (media/nt));
}



/*
raus@birillo --> ./c7
  i  fib(i)
-----------
  0      0
  1      1
  2      1
  3      2
  4      3
  5      5
  6      8
  7     13
  8     21
  9     34

RIGHE(i)    COLONNE(j)
            0  1  2  3

    0       2  3  4  5
    1       3  4  5  6
    2       4  5  6  7

Valor medio: 4.500000*/
