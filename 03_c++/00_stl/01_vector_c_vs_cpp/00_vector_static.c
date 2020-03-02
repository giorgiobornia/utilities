#include <stdio.h>


int main() {
    
   int i;
   double vector_c[8];
   
   for (i = 0; i < 8; i++) { 
       vector_c[i] = i; 
       printf("%f\n", vector_c[i]);
   }
   
  return 0;
  
}
