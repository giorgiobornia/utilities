#include <stdio.h>

 
#define TYPE struct
// #define TYPE union

int main() {

 TYPE tnode {
int date;
  TYPE tnode *left;  /* You can put the same struct inside but only if it is a POINTER!!! Otherwise, it gives incomplete type, because you are defining the external struct  with the same struct internally but that wasn't defined yet!!!
  Since here I have a pointer, the compiler knows that it occupies the space of one integer,
  so the compiler knows by how much memory to offset, so it knows how to define the pointer arithmetic for this struct */
  TYPE tnode *right;
};



    

 return 0;
}    
