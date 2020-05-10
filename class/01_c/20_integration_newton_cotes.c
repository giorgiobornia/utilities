
#include <stdio.h>
#include "17_funcs.h"
#include "21_integration_methods.h"


#define NREF  7

   int main() {
       
       FILE * outfile = stdout;
       
       double integrals[NREF];
       
       const double a = 0.;
       const double b = 1.;
       
       int exponent = 1;
       
       for (unsigned j = 0; j < NREF; j++) {
           
//        const int n = 1;
       const int n = 10 * exponent;
//        const int n = 10 * pow(2,j);
       
       const double h = (b - a)/n;
           
       double integral = 0.;
           
       for (unsigned i = 0; i < n; i++) {
           
        double x_lower = a + i*h;    
       
         integral += gauss_2n(x_lower, x_lower + h, f1);
       
       }
       
       exponent *= 2;
       
       integrals[j] = integral;
       
       fprintf(outfile, "The value of the integral with %d subintervals is %25.17e\n", n, integral);
       
       }
       
       
       for (unsigned j = 0; j < NREF - 2; j++) {
       
        double conv_order =  log( fabs( ( integrals[j] - integrals[j+1] ) / (integrals[j+1] - integrals[j+2]) ) ) /log(2.);   
           
       fprintf(outfile, "The convergence order starting at refinement level %d is %25.17e\n", j, conv_order);
       
       }
       
       
       
       
       
    return 0;
    
   }
