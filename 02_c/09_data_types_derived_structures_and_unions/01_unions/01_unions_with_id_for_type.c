#include <stdio.h>

#define IS_A  1
#define IS_B  2
#define IS_C  3


struct A { int idA; char fieldA_1[15]; char fieldA_2[18]; char fieldA_3[58]; };
struct B { int idB; char fieldB_1[8];  char fieldB_2[11]; };
struct C { int idC; char fieldC_1[12]; char fieldC_2[25]; char fieldC_3[20]; };


int main() {
    

union ABC {
  struct A a;
  struct B b;
  struct C c;
};

union ABC abc = {IS_A, "string1", "string2", "string3"};
// When you initialize a union, it doesn't initialize the separate members but a single chunk of memory!
// The compiler knows that there are AT MOST 4 arguments.

// This union is a sort of way to "switch" between similar structures.
// It contains structures that have an ID variable in the same memory location,
// so that this ID creates the switch between one structure and another

 if ( abc.a.idA == IS_A ) { 
     printf("%s\n", abc.a.fieldA_3);
     printf("%s\n", abc.a.fieldA_1); 
     printf("%s\n", abc.b.fieldB_1); /* Still works, because fieldB_1 is aligned with fieldA_1 */
     printf("%s\n", abc.b.fieldB_2); /* Doesn't work, because at the position of fieldB_2 there is no variable that starts */
 }
 
 return 0;
 
}
