#include <stdio.h>
#include <math.h>
// #include "/usr/lib64/libm.so"   //fantasy, if instead of the prototype I put the whole library...
// #include "/usr/lib64/libm.a"   //would this be working...?!

int main()
{
double x;
 scanf("%lf", &x);
 
 printf("il risultato e' %lf \n", sin(x) ); 
 
return 0;
}
