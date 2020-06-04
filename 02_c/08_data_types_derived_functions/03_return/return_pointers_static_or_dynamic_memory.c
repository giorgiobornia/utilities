#include <stdio.h>
#include <stdlib.h>

 
 int * return_pointer_to_static_array() {
   
    int a[4];
        printf("%d\n", a);
        
  /* The space allocated here DOES NOT survive the function call */

    return a;  /* warning: function returns address of local variable */
      
  }
  
  
 int * return_pointer_to_dynamic_array() {
   
    int * a = (int *) malloc( 4 * sizeof(int) );  /* If you do the malloc here, you have to do the free somewhere else */
            printf("%d\n", a);

  /* The space allocated here survives the function call */
   
     return a;
      
  }
  
  void clear_dynamic_array(int * a) {
     free(a);
  }
  
  
  
     int a_global[4];

  int * return_pointer_to_static_array_global() {
   
        printf("%d\n", a_global);
        
  /* The space allocated here DOES NOT survive the function call */

    return a_global;  /* warning: function returns address of local variable */
      
  }
 
 
  
int main() {
 
//     static array, local
    int * a1 = return_pointer_to_static_array();
    printf("%d\n", a1);
    
//     dynamic array, local
    int * a2 = return_pointer_to_dynamic_array();
    printf("%d\n", a2);
    clear_dynamic_array(a2);
    
//     static array, global
    int * a3 = return_pointer_to_static_array_global();
    printf("%d\n", a3);
    
//     dynamic array, global: cannot do it! Cannot put things such as a malloc outside of all function!


    
  return 0;
}
