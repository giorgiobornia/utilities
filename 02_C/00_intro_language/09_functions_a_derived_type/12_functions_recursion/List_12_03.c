/* Calcolo delle combinazioni semplici di n oggetti presi k a k */

#include <stdio.h>

int comb(int, int);
int dispo(int, int, int);
int fat(int);

main()
{
int n, k;

printf("Combinazioni semplici di k su n oggetti\n");
printf("Inserire n: \t");
scanf("%d", &n);
printf("Inserire k: \t");
scanf("%d", &k);
printf("Le combin. sempl. di %d su %d sono: %d\n",k,n,comb(k,n));
}

comb(int k, int n)
{
return(dispo(k, n, n)/fat(k));
}

int dispo(int k, int n, int m)
{
if(n==m-k)
  return(1);
else
  return(n*dispo(k, n-1, m));
}

fat(int n)
{
if(n==0)
  return(1);
else
  return(n*fat(n-1));
}
