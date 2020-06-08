 
#include <stdio.h>

int main()
{
    
//   Initialization: can the compiler figure out the number of rows and columns? No, all dimensions must be given except the first
    
    int matrix [3][2] =
{
  { 1, 3 } ,
  { 2, 5 } ,
  { 8, 2 }
 };

//     int matrix2[][] =  /* Error if you do like this */
    int matrix2[][2] =   /* This works */
{
  { 1, 3 } ,
  { 2, 5 } ,
  { 8, 2 }
 };
 
        printf("%d\n", matrix[2][1]);
        
        printf("matrix[i][j] picks the component by starting from the address of matrix[0][0] and using the subscript operator with number 'i * NCOLS + j' \n");
 
        printf("%d\n", (& matrix[0][0])[2*2 + 1]);

 
    
 return 0;

}    
