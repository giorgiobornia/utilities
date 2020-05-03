#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#include "10_zero_methods.h"


  double  f( double x )   {
      
   double y;
   
   y = x*x - x;
      
   return y;  
      
  }
  

  double  f_der( double x )   {
      
   double y;
   
   y = 2. * x - 1.;
      
   return y;  
      
  }
  

   
   


int main() {
 
    
 /*  Declaration of involved variables */

 int  counter_max;
 
 const double x_old = 0.45;
 const double x_oldold = 0.2;

 const double a0 = -0.5;
 const double b0 = 0.7;
 
 const double eps = 1.e-5;
 
 FILE * outfile = stdout;
 
//  double  (*myf_ptr)( double );  /* function pointer declaration */
 double  (*myf_ptr[2])( double );  /* array of function pointers declaration */
 
  myf_ptr[0] = &f;
  myf_ptr[1] = &f_der;

   printf("Give me the maximum number of iterations\n");

   scanf("%d", & counter_max);
    

   fixed_point(outfile, counter_max, eps, x_old, myf_ptr[0]);

   bisection(outfile, counter_max, eps, a0, b0, myf_ptr[0]);

   newton(outfile, counter_max, eps, x_old, myf_ptr[0], myf_ptr[1]);
   
   secant(outfile, counter_max, eps, x_old, x_oldold, myf_ptr[0]);

    
}
