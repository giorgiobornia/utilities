#include <stdio.h>

/*
 * This declaration only gives warning: if no type for arguments or for return is given, the default type is int.
NEVER do this, ALWAYS declare types EXPLICITLY!
*/


 f(b) {
 
    printf("%d\n", b);
}


int main() {
 
    f(7);
    
  return 0;
}
