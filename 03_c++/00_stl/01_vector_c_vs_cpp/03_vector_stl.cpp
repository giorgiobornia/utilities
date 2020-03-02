#include <vector>
#include <iostream>

// Notice that this compiles quite slower than the pure C alternative


int main() {
    
   std::vector< double > vector_cpp(8);
   
   for (unsigned int i = 0; i < vector_cpp.size(); i++) { 
	   vector_cpp[i] = i;
	   std::cout << vector_cpp[i] << std::endl; 
   }

  return 0;
  
}
