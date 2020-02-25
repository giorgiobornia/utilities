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
 
    eps = 1.e-5;
    err = eps + 10.;
 
    x_old = 0.1;
     
    
    while ( err > eps) {
        
        x_new = f(x_old) + x_old;
        
        /* error update */
        err = sqrt( (x_new - x_old) * (x_new - x_old) );
//         err = fabs( x_new - x_old );
        
        x_old = x_new;
        
        printf("%16.10e\n", x_new);
        
    }
 
 

    
}
