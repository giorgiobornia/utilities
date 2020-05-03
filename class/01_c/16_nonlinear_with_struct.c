#include <stdio.h>
#include <math.h>
#include <stdlib.h> /* for malloc/free */


#include "10_zero_methods.h"
#include "14_convergence_order.h"

#include "17_funcs.h"




int main() {
 
    
 /*  Declaration of involved variables */

 int  counter_max;
 
 const double eps = 1.e-8;
 
 FILE * outfile = stdout;
 FILE * outfile2;
 
 
  double * x_n;
  unsigned int counter_end = 0;
 
  
  //Implementation
//   struct func_data f_data_var[2]; //instantiation of array of variables of structure type
  struct func_data f_data_var; //instantiation of variable of structure type
  
  f_data_var.func         = & f0;
  f_data_var.func_der     = & f0_der;
  f_data_var.newt_x_old   = f0_newt_x_old;
  f_data_var.sec_x_old    = f0_sec_x_old; 
  f_data_var.sec_x_oldold = f0_sec_x_oldold;

//    printf("Give me the maximum number of iterations\n");
// 
//    scanf("%d", & counter_max);
    counter_max = 50;
    
    
    
    
   x_n = (double *) malloc(counter_max * sizeof(double) );  /*dynamic memory allocation */
    
   
   for (unsigned int n = 0; n < counter_max; n++) {       x_n[n] = 0.;   }
   newton(outfile, counter_max, eps, f_data_var.newt_x_old, f_data_var.func, f_data_var.func_der, x_n, & counter_end);
   compute_convergence_order(outfile, x_n, counter_end);
   
   /* Print to file for gnuplot */
   outfile2 = fopen("file_newton.out", "w");

       for (unsigned int m = 0; m <= counter_end; m++) {
           fprintf(outfile2, "%d  %25.17e\n", m, x_n[m]);
       }
   
       fclose(outfile2);
   /* Print to file for gnuplot - end */

       
   for (unsigned int n = 0; n < counter_max; n++) {       x_n[n] = 0.;   }
   secant(outfile, counter_max, eps, f_data_var.sec_x_old, f_data_var.sec_x_oldold, f_data_var.func, x_n, & counter_end);
   compute_convergence_order(outfile, x_n, counter_end);
   
   
   free(x_n); /* deallocation */
   
   return 0;
   
}

