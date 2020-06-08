#include <stdio.h>


int main() {
    
    
   printf("For an array of pointers to char (pointers to char = strings) you can initialize STATICALLY with this syntax\n"); 
    char * array_of_pointers[3] = {
   
      "John",
      "Francis",      
      "Huckleberry"      
      
  };

   printf("The same cannot be done for an array of pointers to int: this gives warning\n"); 
   
//   int * array_of_pointers[3] = {
//    
//       {1,6},
//       {3,2,4},      
//       {1,3,7,9,4}      
//       
//   }; 

  
 return 0;
}    
    
