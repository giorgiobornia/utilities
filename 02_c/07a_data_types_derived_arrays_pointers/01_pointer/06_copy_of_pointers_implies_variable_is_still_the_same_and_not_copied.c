#include <stdio.h>
 
int main() {
 
  int * p1;
  int * p2;
  
  int x;  /* This is like static allocation, you avoid using malloc */
  p1 = &x;  

  * p1 = 5;
  
   printf("%d\n", x);
   
//   you are making a copy of the pointer, but the variable pointed-to is still the same! 
  p2 = p1;
  
  * p2 = 7;
  
   printf("%d\n", x);
   
    
 return 0;   
}
