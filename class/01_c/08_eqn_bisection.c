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
   
   

  

int main() {
 
    
 /*  Declaration of involved variables */

 int  counter_max;
 
 const double eps = 1.e-10;
 
 FILE * outfile = stdout;
 
//  double  (*myf_ptr)( double );  /* function pointer declaration */
 double  (*myf_ptr[2])( double );  /* array of function pointers declaration */
 
  myf_ptr[0] = &f;
  myf_ptr[1] = &f_two;

//    printf("Give me the maximum number of iterations\n");
// 
//    scanf("%d", & counter_max);
  
   counter_max = 50;

   
   const double a0 = -0.5;
   const double b0 = 0.4;
   
   bisection(outfile, counter_max, eps, a0, b0, myf_ptr[0]);
   

    
}
