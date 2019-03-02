#include <stdio.h>

main()       /* esempio cicli annidati */
{
int n, m, i, j;

printf("Inserire il numero di linee: \t");
scanf("%d", &n);
printf("Inserire il numero di colonne: \t");
scanf("%d", &m);

for(i=1; i<=n; i++) { /* inizio blocco ciclo esterno */
  printf("\n");
  for(j=1; j<=m; j++)
    printf("+");
}                     /* fine blocco ciclo esterno */
}
