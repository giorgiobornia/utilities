
#include <stdio.h>

int mat[4][3];

main()
{
int i, j;

printf("\n \n CARICAMENTO DELLA MATRICE \n \n");
for(i=0; i<4; i++)
  for(j=0; j<3; j++) {
    printf("Inserisci linea %d colonna %d val: ", i, j);
    scanf("%d", &mat[i][j]);
  };

/* Visualizzazione */
for(i=0; i<4; i++) {
  printf("\n");
  for(j=0; j<3; j++)
    printf("%5d", mat[i][j]);
}
}
