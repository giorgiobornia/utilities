#include <stdio.h>
#include <stdlib.h>


//  void pass_static_array_1d(int a[]) { /* with the notation "int a[]" you cannot put const for the pointer */
//   
//      printf("%d\n",  a[0]);
// 
//      return;
//      
//  }
// 
//  
//  void pass_static_array_1d_alternative_syntax(int * a ) { 
//  
//       pass_static_array_1d(a);
//      
//  }
//  
//  void pass_static_array_1d_alternative_syntax_with_const(int * const a ) {  /* with the notation "int * a" you can put const for the pointer */
//  
// //      a = NULL; /* not allowed */
//       pass_static_array_1d(a);
//       
//  }
//  
//  void pass_static_array_2d(int a[][3] ) {  /* If the array has dimension "n", you need to specify the last "n-1" sizes. 
//                                               In fact, it needs to know the offset of each row: [i][j] -> i*NCOL + j */
//      
//      printf("%d\n",  a[0][0]);
//      
//      return;
//      
//  }
//  
//   void pass_static_array_2d_alternative_syntax(int ** a) { 
//  
//      printf("%d\n",  a[0][0]);  /* he probably doesn't like that he doesn't know what the OFFSET is, while in the previous case he knew it */
//       
//   }
  
  
int main ()
{
    
    int * a;
    int ** b;
    
    int size0_a = 4;
    int size0_b = 2;
    int size1_b = 3;
    
    a = (int *) malloc( size0_a * sizeof(int) );
    b = (int **)  malloc( size0_b * sizeof(int*) );
    
    for (int i = 0; i < size0_b; i++) {
      b[i] =  (int *) malloc( size1_b * sizeof(int) );   
    }

    
    
//  I have to free it all
    for (int i = 0; i < size0_b; i++) {
        free(b[i]);   
    } 
     free(b);
     
   free(a);  
      
  return 0;
    
}    
