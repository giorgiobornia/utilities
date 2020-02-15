#include <stdio.h>

/* Overflow:
 * What happens if I sum
 * two very large float variables,
 * or two very large double variables,
 * or two very large integer variables?
 */

int main() {

  double a, b, c;
  int x, y, z;
  
  a = 1.42534645647e308;
  b = 1.5553434123345e308;

  c = a + b;
  
  y = 1e9; /*2^31*/
  z = 2e9;

  x = y + z;
  
  printf("Il risultato e' %.18e\n", c);
  printf("Il risultato intero e' %.d\n", x);

return 0;

}

/*Arithmetic properties
 * 
 * Here is another example of overflow.
 * Just sum two very big numbers and you may get an inf
 * 
 * What about summing two very high INTEGER numbers?
 * No overflow occurs, simply the bit sign gets a 1 instead of a 0,
 * so negative integers are represented when having too high integers!
 * Clearly no underflow concept exists for integers,
 * and the overflow concept happens in this way.

 * Overflow and underflow are typically remembered for double numbers.
 * 
 * 
 * If the numbers have similar orders of magnitude, nothing bad happens.
 * If the numbers have very different orders, then you may have a loss of precision.
 * If you have various numbers with very different orders of magnitude, 
   it would be good to REORDER them so that you avoid roundings.
 * 
 * First show that for ASSOCIATIVITY of the sum
 * if you use few significant digits then things 
 * (a + b) + c and a + (b + c) give the same number.
 * What is the criterion to generate the error? 
 * Use numbers of different orders of magnitude
 
 */
