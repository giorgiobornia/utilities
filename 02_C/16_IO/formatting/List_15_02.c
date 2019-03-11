#include <stdio.h>

int    i = 80;
double d = 3.14546;
main()
{
   int  numUsc;
   char bufUsc[81];

   numUsc = sprintf(bufUsc, "Il valore di i = %d e \
   il valore di d = %g\n", i, d);

   printf("sprintf() ha scritto %d caratteri e il \
   buffer contiene:\n%s", numUsc, bufUsc);
}
