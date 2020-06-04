#include <math.h>
#include <stdio.h>

double absolute_value(double);
double square(double);
double cube(double); 


int main ()
{
   
  double val1, val_input;
  
  double (* my_func_pointer)(double ); /* declaration of a function pointer */

  /* assignment of a function pointer: both ways work */
//  my_func_pointer = & absolute_value;   /* with reference operator */
    my_func_pointer = absolute_value; 

  /*   We've used the & operator to generate a pointer. However, 
    when generating pointers to functions, the & is optional, because when you mention the name of a function but are not calling it, 
    there's nothing else you could possibly be trying to do except generate a pointer to it.
    So, most programmers write
 
 	my_func_pointer = absolute_value;
 	
 (The fact that a function pointer is generated automatically when a function appears in an expression but is not being called is very similar to, and in fact related to,   the fact that a pointer to the first element of an array is generated automatically when an array appears in an expression.) 
  */
  
  printf("Write the number: ");
  scanf ("%lf", & val_input);

  val1 = val_input;
  
  /* call with function pointer: both ways work */
//   val1 = (* my_func_pointer) (val1);   /* with dereference operator */
  val1 = my_func_pointer (val1);
  
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
