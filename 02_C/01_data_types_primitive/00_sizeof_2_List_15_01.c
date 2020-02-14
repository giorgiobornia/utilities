#include <stdio.h>

int main()
{
   int ch, in, sh, lo, fl, dd, ld;

   ch = sizeof(char);
   in = sizeof(int);
   sh = sizeof(short);
   lo = sizeof(long);
   fl = sizeof(float);
   dd = sizeof(double);
   ld = sizeof(long double);

   printf("La dimensione di un char  e'       %d\n", ch);
   printf("La dimensione di uno short e'      %d\n", sh);
   printf("La dimensione di un int e'         %d\n", in);
   printf("La dimensione di un long e'        %d\n", lo);
   printf("La dimensione di un float e'       %d\n", fl);
   printf("La dimensione di un double e'      %d\n", dd);
   printf("La dimensione di un long double e' %d\n", ld);

}
