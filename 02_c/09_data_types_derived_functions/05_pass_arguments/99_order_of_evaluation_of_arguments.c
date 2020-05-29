#include <stdio.h>

/* First arguments to the right are evaluated, then to the left */

/* Expressions that are passed as function arguments are first evaluated,
 * and the result of the evaluation is written to the stack so that is it available to the function.
 * 
 Two questions arise:
- in what order are the expressions evaluated?
- in what order are the results written in the stack?

 The answer for both is:
  expressions to the RIGHT (last function argument) are first evaluated, and their result written to the stack,
  then the ones going left.
  
  Why was it chosen like this? Because of the default arguments that go to the end?
*/


void print3( int a, int b, int c) {
  printf("a=%d b=%d c=%d\n", a, b, c);
  printf("&a=%p &b=%p &c=%p\n", &a, &b, &c);
}


int main() {

int x=0;

print3 (x++, x++, x++);

return 0;

}
