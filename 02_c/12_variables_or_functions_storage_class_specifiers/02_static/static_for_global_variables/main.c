// gcc main.c other.c

#include <stdio.h>

//  extern int C; /* extern means "the variable is in some other translation unit": error, because C is static in the other file */
 int C = 7; /* The variable C is global in this file, the other one is not used at all, you can even avoid linking */
 
void f(int c){ printf("variable = %d\n", c); } 

int main() {
    
    f(C);

}
