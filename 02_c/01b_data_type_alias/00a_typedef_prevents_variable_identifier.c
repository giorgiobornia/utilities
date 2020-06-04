#include <stdio.h>


  typedef double real_number;  /* typedef can also be outside of functions */


int main() {
    
 
 typedef int integer;  /* integer is an alias for int */

 integer var_i = 84;

//  integer integer = 73; /* from now on, integer becomes unavailable as a variable identifier */
  
 real_number var_d = 32.7;   
    
 return 0;
  
}

  typedef float real_float; /* not seen before this point */  
