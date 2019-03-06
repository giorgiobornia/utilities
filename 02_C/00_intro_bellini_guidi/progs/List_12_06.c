/* Ordinamento quicksort di un array di int */

#include <stdio.h>

#define N 10 /* numero elementi dell'array */
int v[N];    /* array contenente gli interi immessi */

void quick(int, int);
void scambia(int *, int *);

main()
{
int i;
for(i=0; i<N; i++) {
  printf("\nImmettere un intero n.%d: ",i);
  scanf("%d", &v[i]);
}

quick(0,N-1);            /* chiamata della procedura quick */

for(i=0; i<N; i++)       /* sequenza ordinata */
  printf("\n%d", v[i]);
putchar('\n');
}

/* Procedura ricorsiva "quick" */
void quick(int sin, int des)
{
  int i, j, media;
  media= (v[sin]+v[des]) / 2;
  i = sin;
  j = des;

  do {
    while(v[i]<media) i = i+1;
    while(media<v[j]) j = j-1;
    if(i<=j) {
      scambia(&v[i], &v[j]);
      i = i+1;
      j = j-1;
    }
  }
  while (j>=i);

if(sin<j) quick(sin, j);  /* invocazione ricorsiva */
if(i<des) quick(i, des);  /* invocazione ricorsiva */
}

void scambia(int *a, int *b)
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
