#include <stdio.h>

/*  What does this program do? 
 It is used to show that formatting
 can occur at run-time also, with '%*'
 */ 

int main()
{
  int i, n, nn, w;
  
  printf("\nInserire il numero di iterazioni desiderate:\n\t");
  scanf("%d",&n);
  
  nn = n;  /* desired number of iterations */
  w = 0;   /* initialize to zero counter of do-while loop, which will be increased inside */
   i = n;   /* initialize to zero counter of do-while loop, which will be decreased inside */
  
/*first do while loop: The first check on the condition is done at the END of the FIRST CYCLE
 Here we divide by 10 the given number of iterations to know how many decimal digits nn has
 */
  do 
  {
    w++;  
    nn /= 10;
  } while(nn >= 1); 
  
  printf("\n w,i,n,nn: %2d %2d %2d %2d\n\n", w, i, n, nn);
 
  do 
  {
    i--;
    printf("\tcontatore\t:%*d:\n",w,i);
  } while(i > 0);
  
  printf("\n\n");

  return 0;
}
