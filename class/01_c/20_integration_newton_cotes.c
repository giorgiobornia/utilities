#include <stdio.h>
#include "17_funcs.h"
#include "21_integration_methods.h"

#define NMETHODS 1

#define NREF  7

   int main() {
       
       FILE * outfile = stdout;
       
       double integrals[NREF];
       
       const double a = 0.;
       const double b = 1.;
       
       const double true_integral = f1_antider(b) - f1_antider(a);
       fprintf(outfile, "The true integral is %25.17e\n", true_integral);
       
//         double (* method_ptr[NMETHODS] )(const double a, const double b, double  (* f)(const  double ));
//        
//        method_ptr[0] = &rectangle_midpoint;
//        method_ptr[1] = &trapezoid;
//        method_ptr[2] = &simpson;
//        method_ptr[3] = &gauss_2n;

       for (unsigned m = 0; m < NMETHODS; m++) {
       
       
       int exponent = 1;
       
       for (unsigned j = 0; j < NREF; j++) {
           
//        const int n = 1;
       const int n = 1 * exponent;
//        const int n = 10 * pow(2,j);
       
       const double h = (b - a)/n;
           
       double integral = 0.;
           
       for (unsigned i = 0; i < n; i++) {
           
        double x_lower = a + i*h;    
       
        if (i%2 == 0)   integral += /*method_ptr[m]*/simpson(x_lower, x_lower + h, f1);
        else            integral += rectangle_midpoint(x_lower, x_lower + h, f1);
       
       }
       
       exponent *= 2;
       
       integrals[j] = integral;
       
       fprintf(outfile, "The value of the integral with %d subintervals is %25.17e\n", n, integral);
       
       
      const double error = fabs(integral - true_integral);  
       
       fprintf(outfile, "The error is %25.17e\n", error);
       
       if ( error < 1.e-5) break;
       }
       
       
       }
       

       
       
       
       
       
       for (unsigned j = 0; j < NREF - 2; j++) {
       
        double conv_order =  log( fabs( ( integrals[j] - integrals[j+1] ) / (integrals[j+1] - integrals[j+2]) ) ) /log(2.);   
           
       fprintf(outfile, "The convergence order starting at refinement level %d is %25.17e\n", j, conv_order);
       
       }
       
       
       fprintf(outfile, "The value of the true integral is %25.17e\n", true_integral);
       
       
       
    return 0;
    
   }
