#include <stdio.h>


 void pass_static_array_1d(int a[]) { /* with the notation "int a[]" you cannot put const for the pointer */
  
     printf("%d\n",  a[0]);

     return;
     
 }

 
 void pass_static_array_1d_alternative_syntax(int * a ) { 
 
      pass_static_array_1d(a);
     
 }
 
 void pass_static_array_1d_alternative_syntax_with_const(int * const a ) {  /* with the notation "int * a" you can put const for the pointer */
 
//      a = NULL; /* not allowed */
      pass_static_array_1d(a);
      
 }
 
 void pass_static_array_2d(int a[][3] ) {  /* If the array has dimension "n", you need to specify the last "n-1" sizes. 
                                              In fact, it needs to know the offset of each row: [i][j] -> i*NCOL + j */
     
     printf("%d\n",  a[0][0]);
     a[0][0] = 7;
          printf("%d\n",  a[0][0]);

     return;
     
 }
 
  void pass_static_array_2d_alternative_syntax(int ** a) { 
 
     printf("%d\n",  a[0][0]);  /* he probably doesn't like that he doesn't know what the OFFSET is, while in the previous case he knew it */
      
  }
  
  
int main ()
{
    
    int a[4] = {0, 0, 0, 0};
    int b[2][3] = { {1, 1, 1} , {2, 2, 2} };
    
      pass_static_array_1d(a);
      pass_static_array_1d_alternative_syntax(a);
      pass_static_array_1d_alternative_syntax_with_const(a);
      
      pass_static_array_2d(b);
     printf("%d\n",  b[0][0]); /* content is kept because by passing the array we passed its ADDRESS */
      pass_static_array_2d_alternative_syntax(b); /* Gives a warning in compilation, and a segmentation fault in execution */
  
  return 0;
    
}    
