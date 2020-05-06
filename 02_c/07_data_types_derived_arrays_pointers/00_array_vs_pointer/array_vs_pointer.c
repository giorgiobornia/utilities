#include <stdio.h>

int main() {

 /********* Pointer ********/
 
  char * pointer_to_char = "hello";
  pointer_to_char = "hello4"; //can do assignment also later  //is this the right thing to do?
  
 /********* Array **********/
  char array_of_char[32] = "hello2";
  
//   char array_of_char_2[32] = "hello5";
//   array_of_char_2 = "hello2";  //cannot do assignment later
  
  
  printf("%s\n", pointer_to_char);
  printf("%s\n", array_of_char);
    
    
    return 0.;
    
}
