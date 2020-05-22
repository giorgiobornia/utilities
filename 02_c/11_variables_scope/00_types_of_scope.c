 
#include <stdio.h>

int a = 1;  /* global scope, file scope */

int main() {
    
  int b=2;  /* function scope */ 
  
  {  /* block scope */
	int temp;
	temp = a;
	a = b;
	b = temp;
  }
  
//   printf("%d", temp);
  
  return 0;
}
