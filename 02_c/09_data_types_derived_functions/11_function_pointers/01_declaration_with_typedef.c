#include <math.h>
#include <stdio.h>

double absolute_value(double);
double square(double);
double cube(double); 

typedef double (* my_func_pointer_type)(double );  /* can be placed outside or inside the main, as long as it is before its use */


int main ()
{
   
  double val1, val_input;
  
  
  my_func_pointer_type   my_func_pointer;   /* declaration of a function pointer */

  /* assignment of a function pointer: both ways work */
  my_func_pointer = & absolute_value;
  /*   my_func_pointer = absolute_value;  */

  printf("Write the number: ");
  scanf ("%lf", & val_input);

  val1 = val_input;
  val1 = my_func_pointer(val1);   /* call with function pointer */
  printf("Value: %lf\n", val1);

  return 0;
    
}

/* ------------------------------------- */
double absolute_value(double x)
{
  if (x < 0.)  x = -x;

  return x;
}

/* ------------------------------------- */
double square(double x)
{
  double y;
   
  y = x*x;

  return y;
}

/* ------------------------------------- */
double cube(double x)
{
  return x*x*x;
}
