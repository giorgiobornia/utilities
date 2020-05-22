// gcc main.c other.c

#include <stdio.h>

 extern int A;
 extern int C;
 
void f(int c){ printf("variable = %d\n",c); } 

int main() {
    
    f(A); /* correct */
//     f(B); /* wrong in compiling: B must be declared somehow in this file */
    f(C); /* wrong in linking: C declared here as extern, but somewhere else as static */

}
