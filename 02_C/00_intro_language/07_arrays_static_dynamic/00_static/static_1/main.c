
main ()
{
  int i,j,nt,fib[10],matrix[3][4];
  int media;
  float ave;

  /* first 10 Fibonacci numbers */
  fib[0] = 0;
  fib[1] = 1;

  for(i=2; i<10; i++)
    fib[i] = fib[i-1] + fib[i-2]; 

  printf("  i  fib(i)\n");
  printf("-----------\n");

  for(i=0; i<10; i++)
    printf(" %2d   %4d\n",i,fib[i]);

  /* two-dimensional matrix with integers: 
     initialization */

  for (i=0; i<3; i++)
    for (j=0; j<=3; j++)
      matrix[i][j] = i+j+2;

  /* mean value */
  ave = 0.;
  media = nt = 0;

  for (i=0; i<3; i++)
    for (j=0; j<=3; j++) {
      ave += matrix[i][j];
      media += matrix[i][j];
      nt++;
    }

  printf("\nROWS(i)    COLUMNS(j)\n");
  printf("            0  1  2  3\n\n");

  for (i=0; i<3; i++) {
    printf("  %3d     ",i);
    for (j=0; j<=3; j++) 
      printf("%3d",matrix[i][j]);
    printf("\n");
  }

  printf("\nMean value: %f\n",ave/nt);
  printf("\nMean value (int): %d\n",media/nt);
  printf("\nMean value (float): %f\n",(float) (media/nt));
}



/*
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




/* Array o matrici
Consentono di compattare dei dati 
fra di loro omogenei, riservando
celle in memoria fra di loro contigue
e un indirizzamento di tipo indiciale.

Facciamo il caso bidimensionale di una
matrice A di 3 x 4 = 12 elementi

FORTRAN: A(3,4)
vengono riservate dodici celle contigue, 
le dimensioni di ogni cella
dipendono da A (se intero, in virgola
mobile con precisione singola o doppia)

     RIGHE(i)     COLONNE (j)
		  1  2  3  4

        1	  *  *  *  *
        2	  *  *  *  *
        3	  *  *  *  *

|01|02|03|04|05|06|07|08|09|10|11|12|

L'ordinamento e' per colonne!!!, quindi
i dati vengono memorizzati cosi:

A(1,1) -> A(2,1) -> A(3,1) -> A(1,2) ->

...... -> A(3,4)

Il primo indice e' quello che scorre
piu' velocemente!!!

C: A[3][4]

     RIGHE[i]     COLONNE [j]
		  0  1  2  3  

        0	  *  *  *  *
        1	  *  *  *  *
        2	  *  *  *  *


L'ordinamento e' per righe!!!, quindi
i dati vengono memorizzati cosi:

A[0][0] -> A[0][1] -> A[0][2] -> A[0][3] ->

......  -> A[2][3]

L'ultimo indice (quello piu' a destra) e' 
quello che scorre piu' velocemente!!!
 */
