/*Operator precedence
 * è: no stray in string
 *   yes stray in variable
 Do not use -Wall first...
 */

#include <stdio.h>

int main() {
  
  int i;
  i=1;

  while (0<i && i<10) {
    
  printf("Il numero %d è minore di 10\n",i); 

  i=i+1;
  }
  
 printf("Fine\n");
  
 return 0; 
}