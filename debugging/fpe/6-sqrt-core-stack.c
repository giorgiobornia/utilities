#include <stdlib.h>
#include <stdio.h>

#include "fpe_x87_sse.h"


/*
  test invalid sqrt and its result
  export decfort_dump_flag=yes    (fortran)
  ulimit -c unlimited
  link with set_fpe_x87_sse_ (and -lm)
  if for example, a = 1, b = 2 --> 
  code crashes with invalid sqrt and creates core (gdb)
  code crashes into sqrtf(), gdb shows stacktrace
*/

int main(int argc, char *argv[])
{
  float a, b, c, tmp;


  set_fpe_x87_sse_();


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
