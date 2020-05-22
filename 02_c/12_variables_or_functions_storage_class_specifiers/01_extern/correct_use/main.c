// gcc main.c other.c
#include <stdio.h>

extern int A; /* you tell the compiler that the variable is defined somewhere, and the linker will take care of finding it */

extern int B;

void f(int c){ printf("variable = %d\n",c); } 

int main() {
    
    f(A);
    f(B);

}
