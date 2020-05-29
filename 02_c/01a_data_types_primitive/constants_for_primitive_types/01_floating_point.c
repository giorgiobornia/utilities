#include <stdio.h>

 
int main() {

  double a1 =  -10.49;    /* decimal point format */
  double a2 =  -1.049e1;  /* exponential format */
  double a3 =  -104.9e-0001; /* exponential format */
  double a4 =  -104.9E-1; /* exponential format */
  
  float b1 = -10.4f;
  float b2 = -10.4F;

  long double c1 = -10.4l; 
  long double c2 = -10.4L;
  
  
  /* What about base 8 and 16? */
  
  double d1 =  -010.49; /* Adding a zero in front doesn't make it octal! */
  double d2 =  -0000000000000000000000000000000000000000000000000000000000000000010.49; /* You can add multiple zeros too */
  double d3 =  -010; /* Integer in octal form, implicity converted to double */
  double d4 =  -0x10; /* Integer in hexadecimal form, implicity converted to double */

  
/* Hexadecimal floating constants are defined in C from C99, but not in C++ */
/* Quite confusing:
 * The mantissa is in base 16;
 * p separates the mantissa from the exponent;
 * the exponent is in base 10 but it is the exponent of 2 !!!
 * 
 * Example:
 * 
 *     0x0.3p10  -> 3 * 1/16 * 2^10 = 3 * 1/16 * 1024 = 192
   */
  double d5 =  0x0.3p10;    
  
  /* Octal floating constants are not defined neither in C nor in C++ */
  
  
  printf("%lf\n", d5);
  
  
 return 0;
 
}
