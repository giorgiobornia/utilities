/* Ricerca di un valore in una matrice */

#include <stdio.h>

#define N 10
#define M 10
char alfa[N][M];

main()
{
int n, m, i, j, k;
char ric;

/* Richiesta delle dimensioni */
do {
  printf("Numero di linee: ");
  scanf("%d", &n);
}
while((n>=N) || (n<1));

do {
  printf("Numero di colonne: ");
  scanf("%d", &m);
}
while((m>=M) || (m<1));

printf("\n \n CARICAMENTO DELLA MATRICE \n \n");
for(i=0; i<n; i++)
  for(j=0; j<m; j++) {
    printf("Ins.carattere nella linea %d colonna %d val:", i, j);
    scanf("%1s", &alfa[i][j]);
};

/* Richiesta del carattere da ricercare */
printf("\n \n Carattere da ricercare: ");
scanf("%1s", &ric);

printf("\n \n VISUALIZZAZIONE DELLA MATRICE \n ");
for(i=0; i<n; i++) {
  printf("\n");
  for(j = 0; j < m; j++)
    printf("%3c", alfa[i][j]);
}
printf("\n\n");

/* Ricerca del carattere all'interno della matrice */
k = 0;
for(i=0; i<n; i++)
  for(j=0; j<m; j++) {
    if(alfa[i][j]==ric) {
      printf("%c in linea %d colonna %d\n", ric, i+1, j+1);
      k = 1;
    }
  };
if(k==0)  printf("%c non presente nella matrice", ric);
}
