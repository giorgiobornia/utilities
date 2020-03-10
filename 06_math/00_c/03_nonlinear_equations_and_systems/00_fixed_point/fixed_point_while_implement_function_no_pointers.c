#include <stdio.h>
#include <math.h>
#include <stdlib.h>



    
struct alg_stopping_criteria {
  
  int n_max;
  double eps;
    
};





void fixed_point(/*const*/ FILE * outfile, struct alg_stopping_criteria alg_stop, const double x0, double (*fun)(double) )  {
    
    int  n;
    double  x;

      
    /* initialization */
      n = 0;

      double err = 10.;

      double x_old = x0;
      x = x0;

        
        
    while ( err > alg_stop.eps &&  n < alg_stop.n_max ) {
        
	/* counter update */
	n++;

	/* next iteration */
	x = fun(x_old) + x_old;  /* here you put g(x), the "auxiliary" function */
	
	/* error on abscissa change */
	 err = fabs(x - x_old);
	
	fprintf(outfile, "| %2d | %16.10f | %16.10e | %+e |\n", n, x, err, fun(x));
    
	/* update old with new */
	x_old = x;
    
    }
    
    /* final result to screen */
    fprintf(outfile, "Zero computed starting from x0 = %f with precision %e.\n x = %12.10f in %d iterations \n", x0, alg_stop.eps, x, n);
    
}



/* Function definition */
double func(double);
double func2(double);






int main() {

    /*const*/ FILE * outfile = stdout; 

    struct   alg_stopping_criteria  alg_stop;   /* In C you have to declare it like this */

    
    alg_stop.n_max = 50;
    alg_stop.eps = 1.e-7;
    
    
    double x0 = 0.9;
    
      
    fixed_point(outfile, alg_stop, x0, &func);  /* C passes by copy, so you need to pass the address if you want your variables to survive */

    
    return 0;
    
}





/* f(x), original function */
double func(double x) {
    
    double y;
    
    y =  x * x - x;
    
    return y;
}


double func2(double x) {
    
    double y;
    
    y = x/2 + 2/x - x;
    
    return y;
}
