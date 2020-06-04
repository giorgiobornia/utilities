#include <math.h>
#include <stdio.h>

double absolute_value(double);
double square (double);
double cube(double); 


int main ()
{
   
  double val1, val_input;

  printf("Write the number: ");
  scanf ("%lf", & val_input);

  val1 = val_input;
  val1 = absolute_value(val1);
  printf("Absolute value: %lf\n", val1);

  val1 = val_input;
  val1 = square(val1);
  printf("Square: %lf\n", val1);

  val1 = val_input;
  val1 = cube(val1);
  printf("Cube: %lf\n", val1);
  
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
