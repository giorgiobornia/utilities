#include <stdlib.h>
#include <stdio.h>




/*
  test invalid division and its results
  if for example, a = 0, b = 0 --> print c = -1
  code doesn't crash with invalid division, and user, observing results,
  thinks that all is ok (simulation of tmp variables)
*/

int main(int argc, char *argv[])
{
  float a, b, c, tmp;





  printf("Insert a, b \n");
  scanf("%f",&a);
  scanf("%f",&b);

  tmp = a / b;
  
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
