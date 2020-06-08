#include <stdio.h> 

 int main() {
  
     int * p;
     int arr[] = { 2, 7, 9, 3};
     
  printf("Address of array and address of pointer are two totally different things\n");
  printf("Address of array is the address of its first component\n");
  printf("Address of pointer is the address of the memory location where the pointer is stored\n");
  
  printf("Address of array\n");
  printf("%d\n", arr);/* address of array: equivalent ways */    
  printf("%d\n", &arr);/* address of array: equivalent ways */    
  printf("%d\n", &(arr[0]));/* address of array: equivalent ways */    
     
  printf("Address of pointer - before\n");
  printf("%d\n", &p); /* address of pointer: the pointer is located in a memory position */  
  printf("%d\n", p); /* random */
  
  printf("Address of pointer - after\n");
     p = arr;
  printf("%d\n", &p); /* address of pointer doesn't change */  
  printf("%d\n", p);
  
  /* From now on, you can access the array 
     - both by using the array itself 
     - and by using the pointer
  */
  
  /* How to access the array */
  printf("How to access the array with the array\n");
  
  printf("%d\n", arr[2]);       /* through subscript operator */
  printf("%d\n", *(arr + 2) );  /* through pointer arithmetic */
  printf("%d\n", *((&arr[0]) + 2) );
  printf("%d\n", *((&arr) + 2) );  /* This one doesn't do what you may expect... It doesn't seem to follow pointer arithmetic but standard arithmetic... */
  printf("%d\n", (&arr) + 2 ); /* Seems like you cannot dereference it... */
  
  printf("How to access the array with the pointer\n");
  printf("%d\n", p[2]);       /* through subscript operator */
  printf("%d\n", *(p + 2) );  /* through pointer arithmetic */
  
  
     return 0;
     
 }
