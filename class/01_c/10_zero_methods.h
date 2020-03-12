#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
 
   void fixed_point(FILE * outfile, 
                   const int counter_max, 
                   const double eps, 
                   const double x_in,
                   double  (* myf_ptr)( double )
                  ) {
      
      double x_old = x_in;
      
      double x_new;
       
       
      double  err = eps + 10.;

      
       int  counter = 0;

      
      
          while ( err > eps && counter < counter_max ) {
        
        /* recursive formula for fixed point method */
        x_new = myf_ptr(x_old) + x_old;
        
        /* error update */
        err = sqrt( (x_new - x_old) * (x_new - x_old) );
//         err = fabs( x_new - x_old );
        
        x_old = x_new;
        
        
        counter++;

        //         printf("Iteration %d, x_new %16.10e\n", counter, x_new);
        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
        
        
    }
 
       x_new = x_old;
        fprintf(outfile, "Conclusion: Iteration %d, x = %16.10e\n", counter, x_new);
   
      
      
  }
  
  
  
    void bisection(FILE * outfile, 
                   const int counter_max, 
                   const double eps, 
                   const double a0,
                   const double b0,
                   double  (* fun)( double )
                  ) {

      
	int n;
    double a, b, c, err;
    
    a = a0;
    b = b0;
    
 	if( fun(a) * fun(b) >= 0. ) {
		fprintf(outfile, "f(a) * f(b) > 0!! No zeros in the interval\n");
		abort();
	}
	
	err = eps + 10.; 
	n = 0;
    
	while(err > eps && n < counter_max) {
        
		n++;
        
		c = .5 * (a + b);
        

		if( fun(a) * fun(c) < 0.) {
			b = c;
		}
		else {
			a = c;
		}
		
//         err = fabs(b - a);
        err = fabs(fun(c));  /*measure error based on ordinate*/


        fprintf(outfile, "Iteration %d, x = %16.10e\n", n, c);
                
	}
	
	printf("The zero is %f (err = %f, iteration %d)\n", c, err, n);    
   }
   
 
  
    void newton(FILE * outfile, 
                   const int counter_max, 
                   const double eps, 
                   const double x_in,
                   double  (* myf_ptr)( double ),
                   double  (* myf_ptr_der)( double )
                  ) {
      
      double x_old = x_in;
      
      double x_new;
       
      double  err = eps + 10.;
      
       int  counter = 0;
      
          while ( err > eps && counter < counter_max ) {
        
        x_new = x_old - myf_ptr(x_old)/myf_ptr_der(x_old);
        
        /* error update */
        err = fabs( x_new - x_old );
        
        x_old = x_new;
        
        
        counter++;

        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
        
        
    }
 
       x_new = x_old;
        fprintf(outfile, "Conclusion: Iteration %d, x = %16.10e\n", counter, x_new);
   
      
      
  }
  
