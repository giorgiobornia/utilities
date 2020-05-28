#include <stdio.h>

int main()
{ 
  int x;

    
    for ( x = 1; x < 10; x++ ) {
        printf("x = %d\n", x );
      }

      
  /*
   * empty for:
   * - initial assignment
   * - condition check is not met
   */
  
    for ( x = 1; x < -9; x++ ) {
        printf("x = %d\n", x );
      }
      
  /*
   * infinite loop, minimal for
   */
  
//     for ( ; ; ) {
//         printf("Hello Earth\n");
//     }

  /*
   * infinite loop, other forms
   */
    
    for ( x = 1; x < 10 ; ) {
        printf("Hello Mars\n");
    }

    
    
 return 0;

}
