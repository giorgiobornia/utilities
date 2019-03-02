#include <stdlib.h>
#include <stdio.h>




/*
  test invalid sqrt and its result
  if for example, a = 1, b = 2 --> 
  code doesn't crash with invalid sqrt
*/

int main(int argc, char *argv[])
{
  float a, b, c, tmp;





  printf("Insert a, b \n");
  scanf("%f",&a);
  scanf("%f",&b);

  tmp = sqrtf(a - b);
  
  if(tmp > 2.)
    {
      c = +1.;
    }
  else
    {
      c = -1.;
    }

  printf("c = %f \n", c);
  printf("GOOD END \n");

  return(EXIT_SUCCESS);
}
