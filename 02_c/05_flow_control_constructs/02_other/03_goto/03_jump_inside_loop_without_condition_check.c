#include <stdio.h>

int main()
{ 
  int x = 93;

    goto inside_loop;
    
    for ( x=1; x < 40; x++ ) {
        inside_loop: printf("landing: x = %d\n", x );
    }
    
  /*  this is like a do-for if you will...
   * It skips the for initial assignment
   */

return 0;

}
