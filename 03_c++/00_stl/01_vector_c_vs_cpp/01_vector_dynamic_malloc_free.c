#include <stdio.h>
#include <stdlib.h>


int main() {
    
   int i;
   int vector_size;
   double * vector_c;
   
   vector_size = 8;
   
   vector_c = malloc(vector_size);
   
   for (i = 0; i < 8; i++) { 
       vector_c[i] = i; 
       printf("%f\n", vector_c[i]);
   }
   
   
   free(vector_c);
   
  return 0;
  
}
