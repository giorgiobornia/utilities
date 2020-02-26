#include <stdio.h>
#include <math.h>

/* function definition whose root you want to compute */
double func(double);

int main() {

    /* iteration counter */
    int n;
    /* punti di partenza, soluzione, soluzioni vecchia, precisione desiderata, errore */
    double a, a0, b0, b, c, c_old, eps, err;

    FILE * infile;
    FILE * outfile;

    /* input file opening */
    infile = fopen("bisez2.in","r");
    if (infile != NULL) {
	fscanf(infile,"%lf", &a0);
	fscanf(infile,"%lf", &b0);
	fscanf(infile,"%lf", &eps);
    }
    else {
      fprintf(stderr, "error in input file!\n");
	return 1;
    }

    /* check per vedere se l'intervallo considerato e' adatto
       all'uitilizzo del metodo di bisezione                  */
    if( func(a0) * func(b0) > 0.) {
    fprintf(stderr, "beware! the interval is not correct!\n");
      return 2;
    }

    /* variable initialization */
    n = 0;
    a = a0;
    b = b0;

    /* output file opening */
    outfile = fopen("bisez2.out","w");
    fprintf(outfile,"-----------------------------------------------------------------------------\n");
    fprintf(outfile,"| it |      c     |      f(c)     |      a     |      b     |       err     |\n");
    fprintf(outfile,"-----------------------------------------------------------------------------\n");
  

    do {
        
	/* counter update */
    	n++;
	    c = 0.5 * (a + b);
    
    	/* test to see if you are to the left or the right */
    	if (func(a) * func(c) < 0.) {
    	    b = c;
     	}
    	else {
	        a = c;
    	}
	
        /* control on abscissas */
    	err = fabs(c - c_old);
    
    	fprintf(outfile,"| %2d | %10.8f | %+e | %10.8f | %10.8f | %+e |\n", n, c, func(c), a, b, err);
    
    	c_old = c;
    }
    while(err > eps);

    /* final result to screen */
    fprintf(stdout, "Zero calcolato nell'intervallo (%f,%f) con precisione %e.\n c = %12.10f in %d iterazioni\n", a0, b0, eps, c, n);

    return 0;
}

/* funzione studiata */
double func(double x) {
    double y;
    y = exp(x) * sin(x) - x * x * x;
    return y;
} 
