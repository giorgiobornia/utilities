 #include <stdio.h>

int main() {

    
    int * ptr;
    int arr[3];
    
    ptr++;           /* you can modify a pointer */ 
    arr++;           /* error: it is like a CONSTANT pointer, you cannot modify it */
    arr = arr + 1;   /* error: it is like a CONSTANT pointer, you cannot modify it */
    
   
    return 0;
    
}    
