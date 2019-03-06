/* Calcolo dei numeri di Fibonacci */

#include <stdio.h>

long int fibo(int);

main()
{
int n;

printf("Successione di Fibonacci f(0)=1 f(1)=1 f(n)=f(n-1)+f(n-2)");
printf("\nInserire n: \t");
scanf("%d", &n);
printf("Termine della successione di argomento %d: %d\n", n, fibo(n));
}

long int fibo(int n)
{
if(n==0)      return(0);
else if(n==1) return(1);
     else     return(fibo(n-1)+fibo(n-2));
}
