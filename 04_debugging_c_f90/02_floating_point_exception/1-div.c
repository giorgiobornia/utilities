#include <stdlib.h>
#include <stdio.h>




/*
  test invalid division and its result
  if for example, a = 0, b = 0 --> print c = Nan
  code doesn't crash with invalid division
*/

int main(int argc, char *argv[])
{
  float a, b, c, tmp;





  printf("Insert a, b \n");
  scanf("%f",&a);
  scanf("%f",&b);

  tmp = a / b;
  
  c = tmp;

  printf("c = %f \n", c);
  printf("GOOD END \n");
  
  return(EXIT_SUCCESS);
}
