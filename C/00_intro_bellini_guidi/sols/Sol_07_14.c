/* Calcolo media voti per studente e per prova
   Nell’esemplificazione utilizziamo 3 studenti e 4 prove */

#include <stdio.h>

#define n 4
#define m 5
float voti[n][m];

main()
{
int i, j;

printf("\n \n CARICAMENTO DEI VOTI \n \n");
for(i=0; i<n-1; i++)
  for(j=0; j<m-1; j++) {
    printf("Ins. studente %d prova %d: ", i+1, j+1);
    scanf("%f", &voti[i][j]);
  };

/* Calcolo medie per studente */
for(i=0; i<n-1; i++) {
  voti[i][m-1] = 0;
  for(j = 0; j < m-1; j++)
    voti[i][m-1] = voti[i][m-1] + voti[i][j];
  voti[i][m-1] = voti[i][m-1] / (m-1);
}

/* Calcolo medie per prova */
for(j=0; j<m; j++) {
  voti[n-1][j] = 0;
  for(i=0; i<n-1; i++)
    voti[n-1][j] = voti[n-1][j] + voti[i][j];
  voti[n-1][j] = voti[n-1][j]/(n-1);
}

printf("\n \n VISUALIZZAZIONE DELLA MATRICE \n ");
for(i=0; i<n; i++) {
  printf("\n");
  for(j=0; j<m; j++)
    printf("%8.3f", voti[i][j]);
}
putchar('\n'); putchar('\n');
}
