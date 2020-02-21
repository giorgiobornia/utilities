/* Calcolo delle disposizioni semplici di n oggetti presi k a k */

#include<stdio.h>

int dispo(int, int, int);

main()
{
int n, k;

printf("Disposizioni semplici di k su n oggetti\n");
printf("Inser. n: \t");
scanf("%d", &n);
printf("Inser. k: \t");
scanf("%d", &k);
printf("Le dispos. sempl. di %d su %d sono: %d\n", k, n, dispo(k, n, n));
}

int dispo(int k, int n, int m)
{
if(n==m-k)
  return(1);
else
  return(n*dispo(k, n-1, m));
}
