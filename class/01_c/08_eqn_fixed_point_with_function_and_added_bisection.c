#include <stdio.h>
#include <math.h>
#include <stdlib.h>

  double  f_two( double x )   {
      
   double y;
   
   y = cos(x) - x;
      
   return y;  
      
  }


  double  f( double x )   {
      
   double y;
   
   y = x*x - x;
      
   return y;  
      
  }

   void bisection(FILE * outfile, 
                   const int counter_max, 
                   const double eps, 
                   const double a0,
                   const double b0,
                   double  (* fun)( double )
                  ) {

      
	int n;
    double a, b, c, err, err_old;
    
    a = a0;
    b = b0;
    
 	if( fun(a) * fun(b) >= 0. ) {
		fprintf(outfile, "f(a) * f(b) > 0!! No zeros in the interval\n");
		abort();
	}
	
	err = 1.e+6; 
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
		
        err = fabs(b - a);


        fprintf(outfile, "Iteration %d, x = %16.10e\n", n, c);
                
	}
	
	printf("The zero is %f (err = %f, iteration %d)\n", c, err, n);    
   }
   
   
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
  

int main() {
 
    
 /*  Declaration of involved variables */

 int  counter_max;
 
 const double x_old = 0.9;
 
 const double eps = 1.e-5;
 
 FILE * outfile = stdout;
 
//  double  (*myf_ptr)( double );  /* function pointer declaration */
 double  (*myf_ptr[2])( double );  /* array of function pointers declaration */
 
  myf_ptr[0] = &f;
  myf_ptr[1] = &f_two;

   printf("Give me the maximum number of iterations\n");

   scanf("%d", & counter_max);
    
//     for (unsigned int i = 0; i < 2; i++) {

   fixed_point(outfile, counter_max, eps, x_old, myf_ptr[0]);
   
   const double a0 = -0.5;
   const double b0 = 0.2;
   
   bisection(outfile, counter_max, eps, a0, b0, myf_ptr[0]);
   
   
//     }

    
}
