 
#include <stdio.h>

/*

 The static specifier on a local variable tells the compiler 
 to put the variable at the function call no longer in the stack, 
 but in a permanent memory location for the whole program duration,
as if it was a global variable.

 Unlike a global variable, though, 
 the local static variable will only be visible inside the block  where it was declared.
 The effect is that the local static variable:
 - is initialized only once, the first time the function is called;
 - keeps the value even after the control exited the function,
   and until the same function is called again.
*/


void f() {
    
  static int counter = 0;   /* notice this is not const */
  counter = counter + 1;
  printf("counter = %d\n", counter);
  
}

int main() {
    
int i;

  for( i = 0; i < 100; i++ )  f();

    return 0;
}
