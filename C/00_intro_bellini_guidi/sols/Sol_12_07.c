/* Massimo comune divisore di due interi positivi */

#include <stdio.h>
int mcd(int, int);

main()
{
int t, k;
printf("\n\n Calcolo del massimo comune divisore \n\n");
printf("Inser. t: \t");
scanf("%d", &t);
printf("Inser. k: \t");
scanf("%d", &k);
printf("Massimo comune divisore: %d\n", mcd(t, k));
}

/* Funzione ricorsiva per il calcolo del massimo comune divisore */
int mcd(int t, int k)  {
if(k==0)
  return(t);
else
  if(k>t)
    return(mcd(k, t));
  else
    return(mcd(k, t%k));
}
