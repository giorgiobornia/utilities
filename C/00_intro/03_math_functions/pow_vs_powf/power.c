#include <math.h>
#include <stdio.h>


#define   VAR_TYPE double
#define PRINT_TYPE 1
#define      MYPOW powf
/* 0=float, 1=double, 2=long double */
/* 
 This example shows that the functions pow,powf,powl
 must be used with the appropriate types
       double pow(double x, double y);
       float powf(float x, float y);
 long double powl(long double x, long double y);

if you use powf or powl, it gives "implicit declaration of function" 
 The result is: 
 always use "pow"! it works with float,double and long double

 In the math.h file, they removed the header of the function powf and powl
 But, in the library the implementation is still there
 So you should put the prototypes for powf and powl explicitly
 The fact that these functions were removed from the headers but
 not from the library means that those two functions are DEPRECATED
 but they are left in the library for compatibility
 
 The fact is that powf doesnt act well on floats, nor on doubles!
 */


int main () {

VAR_TYPE a,b,c;

a=2.;
b=4.;
c=MYPOW(a,b);
 
#if (PRINT_TYPE == 0)
 printf("%f\n", c);
#elif (PRINT_TYPE == 1)
 printf("%f\n", c);
 #elif (PRINT_TYPE == 2)
 printf("%Lf\n", c);
 #endif

return 0;
}