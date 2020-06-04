#include <stdio.h>

 
#define TYPE struct
// #define TYPE union

int main() {

 TYPE tnode {
int date;
  TYPE tnode *left;  /* You can put the same struct inside but only if it is a POINTER!!! Otherwise, it gives incomplete type, because you are defining the external struct  with the same struct internally but that wasn't defined yet!!! */
  TYPE tnode *right;
};



    

 return 0;
}    
