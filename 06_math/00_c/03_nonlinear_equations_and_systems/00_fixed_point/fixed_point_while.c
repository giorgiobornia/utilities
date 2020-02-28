#include <stdio.h>
#include <math.h>

/* Zero of a function with fixed point method */

/* INTRODUCED FEATURES of C
 * - While loop
 * - fprintf(outfile,...)
 * - printf vs. fprintf(stdout,...)
 * - pointer to FILE type
 * - ++ operator to increase the counter
 * - Function definition all above main; next split prototype with implementation
 */ 


/*Cercare altre funzioni f(x) tali che lo zero z_0 abbia |g'(z_0)| < 1 
 Chiaramente, dato un limite sulla derivata,
 la funzione primitiva puo' avere infiniti valori
 - Aggiunta di una costante
 Chiaramente, se aggiungo una costante a f(x) , g'(x) = f'(x) + 1 non cambia.
 Il problema e' che se f(z_0)= 0, allora "f(z_0) + c != 0"
 Quindi gli zeri CAMBIANO! Potrebbero essercene ancora due,
 oppure sposti tutto in alto e non ce n'e' piu' nemmeno uno!
 - Per capire se lo zero e' stabile, devo vedere se |g'(z_0)| < 1
 
 
 - Prendi la stessa funzione e falla con il metodo di tangenti, secanti, punto fisso, bisezione
  E vedi le differenze di comportamento.
 
 x*x +2.*x + 1 : converge ma lentamente, perche' ha due zeri coincidenti!
 
  x0 = -0.8;
   x*x +2.*x + 0.9 
                                      Una radice, x=-1.3,  e' stabile, l'altra e' probabilmente instabile.
                                      Pero' il fatto di non soddisfare una condizione sufficiente
                                      non significa che il punto sia instabile.
                                      Se non soddisfassi una condizione necessaria allora potrei dirlo.
 */



/* Function definition */
double func(double);


int main() {

    /* counter */
    int n, n_max;
    /* starting point, current iterate, previous iterate, tolerance, error */
    double x0, x, x_old, eps, err;
    FILE * outfile; 

    /* initialization */
    n_max = 50;
    
      x0 = 0.9;
     eps = 1.e-7;

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
	
	/* error on abscissa change */
	 err = fabs(x - x_old);
	
	fprintf(stdout/*outfile*/, "| %2d | %16.10f | %16.10e | %+e |\n", n, x, err, func(x));
    
	/* update old with new */
	x_old = x;
    
    }

    /* final result to screen */
    fprintf(stdout, "Zero computed starting from x0 = %f with precision %e.\n x = %12.10f in %d iterations \n", x0, eps, x, n);       

    return 0;
}


/* f(x), original function */
double func(double x) {
    
    double y;
    
//     y = sin(x - 0.1);
    y =  x * x - x;
    
    return y;
}
