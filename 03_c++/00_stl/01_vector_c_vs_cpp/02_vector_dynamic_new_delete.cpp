#include <iostream>

// Notice that this compiles quite slower than the pure C alternative


int main() {
    
       int vector_size;
   double * vector_cpp;
    
    vector_size = 8;
    vector_cpp = new double[vector_size];
   
   for (unsigned int i = 0; i < vector_size; i++) { 
	   vector_cpp[i] = i;
	   std::cout << vector_cpp[i] << std::endl; 
   }
   
   delete vector_cpp;

  return 0;
  
}
