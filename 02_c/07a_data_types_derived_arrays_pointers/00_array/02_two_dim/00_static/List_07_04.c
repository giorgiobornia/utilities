#include <stdio.h>

#define MAXLINEE 100
#define MAXCOLONNE 100

int main()
{
    
int mat[MAXLINEE][MAXCOLONNE];

int n, m;
int i, j;

/* Richiesta delle dimensioni */
do {
  printf("\nNumero di linee: ");
  scanf("%d", &n);
}
while((n>=MAXLINEE) || (n<1));

do {
  printf("Numero di colonne: ");
  scanf("%d", &m);
}
while((m>=MAXCOLONNE) || (m<1));

printf("\n \n CARICAMENTO DELLA MATRICE \n \n");
for(i=0; i<n; i++)
  for(j=0; j<m; j++) {
    printf("Inserisci linea %d colonna %d val:", i, j);
    scanf("%d", &mat[i][j]);
  };

/* Visualizzazione */
for(i=0; i<n; i++) {
  printf("\n");
  for(j=0; j<m; j++)
    printf("%5d", mat[i][j]);
}

 return 0;

}
