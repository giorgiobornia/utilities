/* Fusione di due sequenze ordinate */

#include <stdio.h>
#define MAX_ELE 1000

main()
{
char vet1[MAX_ELE];      /* prima sequenza */
char vet2[MAX_ELE];      /* seconda sequenza */
char vet3[MAX_ELE*2];    /* merge */

int n;                   /* lunghezza prima sequenza */
int m;                   /* lunghezza seconda sequenza */

char aux;                /* variabile di appoggio per lo scambio */

int i, j, k, p, n1, m1;

do {
  printf("Lunghezza prima sequenza: ");
  scanf("%d", &n);
}
while(n<1 || n>MAX_ELE);

/* Caricamento prima sequenza */
for(i = 0;i <= n-1; i++) {
  printf("vet1 elemento n. %d: ",i+1);
  scanf("%1s", &vet1[i]);
}

do {
  printf("Lunghezza seconda sequenza: ");
  scanf("%d", &m);
}
while(m<1 || m>MAX_ELE);


/* Caricamento seconda sequenza */
for(i=0; i<=m-1; i++) {
  printf("vet2 elemento n. %d: ",i+1);
  scanf("%1s", &vet2[i]);
}

/* Ordinamento prima sequenza */
p = n; n1 = n;
do {
  k = 0;
  for(i = 0; i < n1-1; i++) {
    if(vet1[i]> vet1[i+1]) {
      aux = vet1[i]; vet1[i] = vet1[i+1]; vet1[i+1] = aux;
      k = 1; p = i+1;
    }
  }
n1 = p;
}
while(k==1);

/* Ordinamento seconda sequenza */
p = m; m1 = m;
do {
  k = 0;
  for(i=0; i<m1 - 1; i++) {
    if(vet2[i]>vet2[i+1]) {
      aux = vet2[i]; vet2[i] = vet2[i+1]; vet2[i+1] = aux;
      k = 1; p = i+1;
    }
  }
m1 = p;
}
while(k==1);

/* Fusione delle due sequenze (merge) */
i = 0; j = 0; k = 0;
do {
  if(vet1[i]<=vet2[j])
    vet3[k++] = vet1[i++];
  else
    vet3[k++] = vet2[j++];
}
while(i<n && j<m);

if(i<n)
  for(; i<n; vet3[k++] = vet1[i++])
    ;
else
  for(; j<m; vet3[k++] = vet2[j++])
    ;

/* Visualizzazione della fusione */
for(i=0; i<k; i++)
  printf("\n%c", vet3[i]);
}
