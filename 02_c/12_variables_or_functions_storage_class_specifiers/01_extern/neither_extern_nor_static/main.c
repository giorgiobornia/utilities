// gcc main.c other.c
#include <stdio.h>

/* what happens if you don't put extern? */

// extern int A;        //works
// extern int A = 9; //multiple definition
// int A;         //works, same as writing extern?
// int A = 9;  //multiple definition
 


int B = 4;

void f(int c){ printf("variable = %d\n",c); } 

int main() {
    
    f(A);
    f(B);

}
