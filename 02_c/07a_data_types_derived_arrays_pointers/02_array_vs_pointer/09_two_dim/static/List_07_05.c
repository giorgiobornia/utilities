
#include <stdio.h>

#define N 4
#define P 3
#define M 5

int mat1[N][P];         /* prima matrice */
int mat2[P][M];         /* seconda matrice */
int pmat[N][M];         /* matrice prodotto */

main()
{
int i, j, k;

printf("\n \n CARICAMENTO DELLA PRIMA MATRICE \n \n");
for(i=0; i<N; i++)
  for(j=0; j<P; j++) {
    printf("Inserisci linea %d colonna %d val:", i, j);
    scanf("%d", &mat1[i][j]);
  };

printf("\n \n CARICAMENTO DELLA SECONDA MATRICE \n \n");
for(i=0; i<P; i++)
  for(j=0; j<M; j++) {
    printf("Inserisci linea %d colonna %d val:", i, j);
    scanf("%d", &mat2[i][j]);
  };

/* Calcolo del prodotto */
for(i=0; i<N; i++)
  for(j=0; j<M; j++) {
    pmat[i][j] = 0;
    for(k=0; k<P; k++)
      pmat[i][j] = pmat[i][j] + mat1[i][k] * mat2[k][j];
  };

printf("\n \n PRIMA MATRICE \n ");
for(i=0; i<N; i++) {
  printf("\n");
  for(j=0; j<P; j++)
    printf("%5d", mat1[i][j]);
}

printf("\n \n SECONDA MATRICE \n ");
for(i=0; i<P; i++) {
  printf("\n");
  for(j=0; j<M; j++)
    printf("%5d", mat2[i][j]);
}

printf("\n \n MATRICE PRODOTTO \n ");
for(i=0; i<N; i++) {
  printf("\n");
  for(j=0; j<M; j++)
    printf("%5d", pmat[i][j]);
}
}
