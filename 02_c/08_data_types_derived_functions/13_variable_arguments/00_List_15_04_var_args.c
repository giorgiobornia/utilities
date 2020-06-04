#include <stdio.h>
#include <stdarg.h>


int somma(int, ...);

int main()  {

int a=3, b=100, c=321, d=400, e=711;
 printf("\n%d %d %d %d %d \n", a, b, c, d, e);
 printf("%d ", somma(2, a, b));
 printf("%d ", somma(3, a, b, c));
 printf("%d ", somma(4, a, b, c, d));
 printf("%d ", somma(5, a, b, c, d, e));

}

int somma(int argNum, ...)  {
 int totale = 0;
 va_list ap;
 va_start(ap, argNum);

  while(argNum--)
    totale=totale + va_arg(ap, int);

  va_end(ap);

return(totale);
}
