#include <stdlib.h>
#include <stdio.h>

#include "fpe_x87_sse.h"


/*
  test invalid division and its result
  export decfort_dump_flag=yes    (fortran)
  ulimit -c unlimited
  link with set_fpe_x87_sse_ (and -lm)
  if for example, a = 0, b = 0 --> 
  code crashes with invalid division and creates core (gdb)
*/

int main(int argc, char *argv[])
{
  float a, b, c, tmp;


  set_fpe_x87_sse_();


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
