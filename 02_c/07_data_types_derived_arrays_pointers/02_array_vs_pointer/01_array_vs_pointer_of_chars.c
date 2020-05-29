#include <stdio.h>

int main() {

 /********* Pointer ********/
 
  char * pointer_to_char = "hello";
  pointer_to_char = "helwdnwoejfo"; //can do assignment also later
  pointer_to_char[2] = 'q'; //cannot do this on a single component - gives segmentation fault
  
 /********* Array **********/
  char array_of_char[32] = "hello2";
  
//   char array_of_char_2[32] = "hello5";
//   array_of_char_2 = "hello2";  //cannot do assignment later
  
  
  printf("%s\n", pointer_to_char);
  printf("%s\n", array_of_char);
    
    
    return 0;
    
}
