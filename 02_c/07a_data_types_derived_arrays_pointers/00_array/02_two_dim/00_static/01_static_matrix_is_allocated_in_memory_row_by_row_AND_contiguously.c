 
#include <stdio.h>

#define NROWS 3
#define NCOLS 2

int main() { 
    
 int i, j;
    int matrix [3][2] =
{
  { 1, 3 } ,
  { 2, 5 } ,
  { 8, 2 }
 };
 
 for(i = 0; i < NROWS; i++) {
   for(j = 0; j < NCOLS; j++) {
       printf("%d\n", &(matrix[i][j]) );
    }
 }
    
    return 0;

}  
