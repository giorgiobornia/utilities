#include <stdio.h>
#include <math.h>

/* Zero of a function with fixed point method */

/* Function definition */

double func(double);


int main() {

    /* counter */
    int n, n_max;
    /* starting point, current iterate, previous iterate, tolerance, error */
    double x0, x, x_old, eps, err;
    FILE *outfile; 

    /* initialization */
    n_max = 50;
    
      x0 = -0.1;
     eps = 0.0000001;

    x     = x0;
    x_old = x0;
    err   = 10.;
    n     = 0;
  
    /* opening of the output file and header writing */
//     outfile = fopen("fixed_point.out","w");
//     fprintf(outfile,"----------------------------------------------------\n");
//     fprintf(outfile,"| it |       x      |     err      |      f(x)     |\n");
//     fprintf(outfile,"----------------------------------------------------\n");
  
    /* la condizione del while e' determinata dalla precisione cercata */
    while(err > eps && n < n_max) {
	/* aggiornamento del numero di iterazioni eseguite */
	n++;

	/* next iteration */
	x = func(x_old) + x_old;  /*qui ci va g(x), la funzione "ausiliaria"*/
	
	/* absolute error */
	 err = fabs(x - x_old);
	
// 	fprintf(outfile,"| %2d | %16.10f | %16.10e | %+e |\n", n, x, err, func(x));
    
	/* update old with new */
	x_old = x;
    
    }

    /* final result to screen */
    fprintf(stdout, "Zero computed starting from x0 = %f with precision %e.\n x = %12.10f in %d iterations \n",
	    x0, eps, x, n);       

    return 0;
}

/* f(x), original function */
double func(double x) {
    
    double y;
    
//     y = sin(x - 0.1);
    y =  x*x - x;
    
    return y;
}
