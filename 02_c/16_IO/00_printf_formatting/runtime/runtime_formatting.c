#include <stdio.h>


/*  What does this program do? 
 It is used to show that formatting can occur at run-time also, with '%*'
 * With that, the number of columns is taken based on the value that is being printed!
 */ 


int main()  {

  int i, n, nn, w;
  
  printf("\nInsert the number of iterations desired:\n\t");
  scanf("%d", &n);
  
 /*first do while loop: The first check on the condition is done at the END of the FIRST CYCLE
 Here we divide by 10 the given number of iterations to know how many decimal digits nn has
 */

  nn = n;  /* desired number of iterations */
  w = 0;   /* initialize counter of first do-while loop, which will be increased inside */

  do  {
    w++;  
    nn /= 10;
  } while(nn >= 1);
  
  printf("\n w, n, nn: %2d %2d %2d\n\n", w, n, nn);
 

   i = n;   /* initialize counter of second do-while loop, which will be decreased inside */
 
   do {
    i--;
    printf("\tcounter\t:%*d:\n", w, i);
  } while(i > 0);
  

  return 0;
}
