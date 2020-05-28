/* Never use goto */

#include <stdio.h>

int main() {
    
  PRINT:    printf("Hello world\n");
    
    goto PRINT;
 
    return 0;
}
