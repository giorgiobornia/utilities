#include <stdio.h>
#include <math.h>

  double  f( double x )   {
      
   double y;
   
   y = x*x - x;
      
   return y;  
      
  }


int main() {
 
    
 /*  Declaration of involved variables */

 int counter, counter_max;
 
 double x_new, x_old, err, eps;
 
 FILE * outfile;
 
  outfile = fopen("out.txt", "w");
 
    eps = 1.e-5;
    err = eps + 10.;
 
    x_old = 0.9;
    
//     counter_max = 50;

   printf("Give me the maximum number of iterations\n");

   scanf("%d", & counter_max);
    
   counter = 0;

    
    x_new = x_old;
        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);

    
    while ( err > eps && counter < counter_max ) {
        
        /* recursive formula for fixed point method */
        x_new = f(x_old) + x_old;
        
        /* error update */
        err = sqrt( (x_new - x_old) * (x_new - x_old) );
//         err = fabs( x_new - x_old );
        
        x_old = x_new;
        
        
        counter++;

        //         printf("Iteration %d, x_new %16.10e\n", counter, x_new);
        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
        
        
    }
 
 

    
}
