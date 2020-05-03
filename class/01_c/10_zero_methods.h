#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
 
   void fixed_point(FILE * outfile, 
                    const int counter_max, 
                    const double eps, 
                    const double x_in,
                    double  (* myf_ptr)(const double ),
                    double * x_n,
                    unsigned int * counter_end
                   ) {
      
       fprintf(outfile, "***** Fixed point method *****\n");

       
       double x_old = x_in;
      
      double x_new = x_old;
       
       
      double  err = eps + 10.;

      
       int  counter = 0;

      x_n[counter] = x_new;
      fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
      
      
          while ( err > eps && counter < counter_max ) {
        
        /* recursive formula for fixed point method */
        x_new = myf_ptr(x_old) + x_old;
        
        /* error update */
        err = sqrt( (x_new - x_old) * (x_new - x_old) );
//         err = fabs( x_new - x_old );
        
        x_old = x_new;
        
        
        counter++;
        
        x_n[counter] = x_new;


        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
        
        
    }
 
        fprintf(outfile, "Conclusion: Iteration %d, x = %16.10e\n", counter, x_new);
   
      * counter_end = counter;
      
      
  }
  
  
  
    void bisection(FILE * outfile, 
                   const int counter_max, 
                   const double eps, 
                   const double a0,
                   const double b0,
                   double  (* fun)(const double ),
                   double * x_n,
                   unsigned int * counter_end
                  ) {

       fprintf(outfile, "***** Bisection method *****\n");
     
	int counter;
    double a, b, c, err;
    
    a = a0;
    b = b0;
    
 	if( fun(a) * fun(b) >= 0. ) {
		fprintf(outfile, "f(a) * f(b) > 0!! No zeros in the interval\n");
		abort();
	}
	
	err = eps + 10.; 
    
	counter = 0;
    
    c = a;

    x_n[counter] = c;
      fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, c);

    
	while(err > eps && counter < counter_max) {
        
        
		c = .5 * (a + b);
        

		if( fun(a) * fun(c) < 0.) {
			b = c;
		}
		else {
			a = c;
		}
		
//         err = fabs(b - a);
        err = fabs(fun(c));  /*measure error based on ordinate*/

		counter++;
        x_n[counter] = c;

        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, c);
                
	}
	
        fprintf(outfile, "Conclusion: Iteration %d, x = %16.10e\n", counter, c);
        
      * counter_end = counter;
      
   }
   
 
  
    void newton(FILE * outfile, 
                   const int counter_max, 
                   const double eps, 
                   const double x_in,
                   double  (* myf_ptr)(const double ),
                   double  (* myf_ptr_der)(const double ),
                    double * x_n,
                    unsigned int * counter_end
                  ) {
      
      fprintf(outfile, "***** Newton's method *****\n");
   
        
        
      double x_old = x_in;
      
      double x_new = x_old;
       
      double  err = eps + 10.;
      
       int  counter = 0;
        x_n[counter] = x_new;
      fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
      
          while ( err > eps && counter < counter_max ) {
        
        x_new = x_old - myf_ptr(x_old)/myf_ptr_der(x_old);
        
        /* error update */
        err = fabs( x_new - x_old );
        
        x_old = x_new;
        
        
        counter++;
        x_n[counter] = x_new;

        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
        
        
    }
 
        fprintf(outfile, "Conclusion: Iteration %d, x = %16.10e\n", counter, x_new);
   
      
      * counter_end = counter;
      
  }
  
  
  
  
    void secant(FILE * outfile, 
                   const int counter_max, 
                   const double eps, 
                   const double x_old_in,
                   const double x_oldold_in,
                   double  (* myf_ptr)(const double ),
                    double * x_n,
                    unsigned int * counter_end
                  ) {
      
      fprintf(outfile, "***** Secant method *****\n");
      
      double x_old = x_old_in;
      double x_oldold = x_oldold_in;
      
      double x_new = x_old;
       
      double  err = eps + 10.;
      
       int  counter = 0;
        x_n[counter] = x_new;
      fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
      
          while ( err > eps && counter < counter_max ) {
        
        x_new = x_old - myf_ptr(x_old) * (x_old - x_oldold) / ( myf_ptr(x_old) - myf_ptr(x_oldold) ) ;
        
        /* error update */
        err = fabs( x_new - x_old );
        
      x_oldold =  x_old;
      x_old = x_new;

        
        counter++;
        x_n[counter] = x_new;

        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
        
        
    }
 
        fprintf(outfile, "Conclusion: Iteration %d, x = %16.10e\n", counter, x_new);
   
      * counter_end = counter;
      
      
  }
  

  
  
      void chord(FILE * outfile, 
                   const int counter_max, 
                   const double eps, 
                   const double x_old_in,
                   const double a0,
                   const double b0,
                   double  (* myf_ptr)(const double ),
                    double * x_n,
                    unsigned int * counter_end
                  ) {
      
      fprintf(outfile, "***** Chord method *****\n");
      
      double x_old = x_old_in;
      
      double x_new = x_old;
       
      double  err = eps + 10.;
      
       int  counter = 0;
        x_n[counter] = x_new;
      fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
      
      const double q = (b0 - a0) / ( myf_ptr(b0) - myf_ptr(a0) );
      
          while ( err > eps && counter < counter_max ) {
        
        x_new = x_old - myf_ptr(x_old) * q;
        
        /* error update */
        err = fabs( x_new - x_old );
        
      x_old = x_new;

        
        counter++;
        x_n[counter] = x_new;

        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
        
        
    }
 
        fprintf(outfile, "Conclusion: Iteration %d, x = %16.10e\n", counter, x_new);
   
      * counter_end = counter;
      
      
  }
