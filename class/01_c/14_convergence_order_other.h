#include <stdio.h>
#include <math.h>



        double convergence_order_local(FILE * outfile, const double * x_n, const int counter)  {
            
            int i;
            
            double p;
            
                        
            for (i = 1; i < counter - 2; i++) {
                
              p  = log( fabs( (x_n[i+2] - x_n[i+1]) / (x_n[i+1] - x_n[i]) ) ) / log( fabs( (x_n[i+1] - x_n[i]) / (x_n[i] - x_n[i-1]) ) );

               fprintf(outfile, "Iteration %d, convergence order = %16.10e\n", i, p);

            }
            
            return p;
            
            
        }
        
        
        void   asymptotic_error_constant_local(FILE * outfile, const double * x_n, const int counter, const double p)  {
            
            int i;
            
            double c;
            
   
            
            for (i = 0; i < counter - 2; i++) {
                
              c =     fabs( x_n[i+2] - x_n[i+1]  ) / pow( fabs( x_n[i+1] - x_n[i]  ) , p);
              

              fprintf(outfile, "Iteration %d, asymptotic error constant = %16.10e\n", i, c);

            }
            
            
        }        
        
        
        


        double   convergence_order_global(FILE * outfile, const double * x_n, const int counter)  {
            
            int i;
            
            double p;
            
            const double x_approx = x_n[counter];
                        
            for (i = 0; i < counter - 2; i++) {
                
              p  = log( fabs( (x_n[i+2] - x_approx) / (x_n[i+1] - x_approx) ) ) / log( fabs( (x_n[i+1] - x_approx) / (x_n[i] - x_approx) ) );

               fprintf(outfile, "Iteration %d, convergence order = %16.10e\n", i, p);

            }
            
              return p;

        }
        
        
        
            void   asymptotic_error_constant_global(FILE * outfile, const double * x_n, const int counter, const double p)  {
            
            int i;
            
            double c;
            
            const double x_approx = x_n[counter];
            
            
            for (i = 0; i < counter - 1; i++) {
                
              c =     fabs( x_n[i+1] - x_approx  ) / pow( fabs( x_n[i] - x_approx  ) , p);
              

              fprintf(outfile, "Iteration %d, asymptotic error constant = %16.10e\n", i, c);

            }
            
            
        }    
