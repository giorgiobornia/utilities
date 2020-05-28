 
#include <stdio.h> 

 
void exit_from_nested_for_with_goto()
{
    
        printf("With goto\n");
        
    int x, y, z;
    
   for ( y=1; ; y++ ) {
      for ( x=1; ; x++ ) {
        for ( z=10; z < 13; z++ ) {
            
            printf("%d, %d, %d\n", y, x, z);

            if ( x == 5) goto exit_label;

       }
     }
  }

  exit_label: ;

}

/* Equivalent way to do this without a goto */
void exit_from_nested_for_without_goto() {
    
    int x, y, z;

        printf("Without goto\n");
    
   for ( y=1; ; y++ ) {
      for ( x=1; ; x++ ) {
        for ( z = 10; z < 13; z++ ) {
            
            printf("%d, %d, %d\n", y, x, z);

            if ( x == 5) break;

         }
         
      if ( x == 5) break;
     }
     
   if ( x == 5) break;
  }
  

}


int main() {
    
    exit_from_nested_for_with_goto();
    
    exit_from_nested_for_without_goto();
    
  return 0;

}
