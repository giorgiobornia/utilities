/*
 * gcc forward_euler.c -lm
 * 
 * If you plot the x and y in two columns, then open gnuplot and simply type:
 * plot 'out.txt' using 1:2,  [0:1]  exp(-x)
 * plot 'out.txt' using 1:2,  [0:1]  x * x - 2. * ( (x+1) * log(x+1) - (x+1))
 * plot 'out_euler.txt' using 1:2, 'out_heun.txt' using 1:2, [0:3] exp(-x)

	 

   	y'(x) = f(x,y(x)) ,  x0 <= x <= b ,  y(x0) = y0.
   	
	The function f(x,z) is defined below, along with the true solution y(x).
	The number of the problem to be solved is specified by the input variable 'numde', 
    which is used in the functions 'f' and 'y'.
    The program will request the problem parameters, along with the values of 'h' and 'iprint'.  
    'h' is the stepsize, and 'iprint' is the number of steps between each printing of the solution.
	Use numde=0 to stop the program. This program is in Section 9.2 (Elementary Numerical Analysis, Atkinson)
*/       

#include <stdio.h>
#include <math.h>



 void set_initial_condition(double * const xzero, double * const yzero, int const numde) {
	/*  This prints the analytical problem */



	switch (numde)  
	{
	case 1: * xzero = 0.;
            * yzero = 1.;
			break;
            
	case 2: * xzero = 0.;
            * yzero = 2.;
			break;

    case 3: * xzero = 0.;
            * yzero = 0.;
			break;
	}
	
}


	/*  This defines the right side of the differential equation  */
double f(double x, double z, const int numde) {

	const double one = 1.0, two = 2.0;

	double result;

	switch (numde)  
	{
	case 1: result = -z;
			break;
            
	case 2: result = (z + x*x - two)/(x + one);
			break;
            
	case 3: result = pow(cos(z), 2.0);
			break;
	}
	
	return(result);
}


	/*  This gives the true solution of the initial value problem. */
double true_solution( double x , const int numde) {

	const double one = 1.0, two = 2.0;

	double result, x1;

	switch (numde)  
	{
	case 1: result = exp(-x);
			break;
            
	case 2: x1 = x + one;
			result = x * x - two * ( x1 * log(x1) - x1);
			break;
            
	case 3: result = atan(x);
			break;
	}
	
	return(result);
}


 void print_IVP_and_analytical_solution(const int numde) {
	/*  This prints the analytical problem */

	const double one = 1.0, two = 2.0;


	switch (numde)  
	{
	case 1: printf("y' = -y\n");
            printf("y(0) = 1\n");
            printf("Solution: y(x) = exp(-x)\n");
			break;
            
	case 2: printf("y' = (y + x*x - 2)/(x + 1)\n");
            printf("y(0) = 2\n");
            printf("Solution: y(x) = x * x - 2 * ( (x + 1) * log(x + 1) - (x + 1) )\n");
			break;

    case 3: printf("y' = cos(y)^2\n");
            printf("y(0) = 0\n");
            printf("Solution: y(x) = atan(x)\n");
			break;
	}
	
}



int main() {

	double xzero, yzero, b, h, truevalue, error;
	double x1, y1, x0, y0;
	int iprint, k;
    int numde;
    int method;

                
		/*  Description */
    printf("\n This program uses some numerical methods to solve the Initial Value Problem\n");
    printf(" y'(x) = f(x, y(x)) , \n");
    printf(" y(x0) = y0 , \n");
    printf(" x0 <= x <= b . \n");

        
    printf("\n Choose the numerical method:\n");
    printf("\n 0 = forward Euler:\n");
    printf("\n 1 = Heun (explicit trapezoid)\n");
	scanf("%d", & method);
        
        char filename[31];
        if (method == 0)      sprintf(filename, "euler.out");
        else if (method == 1) sprintf(filename, "heun.out");

            
        FILE * file = fopen(filename, "w");
    
		/*  Input problem parameters */

		printf("\n Number of the ODE = [1, 2, 3]? Give 0 to stop : ");
		scanf("%d", &numde);
        
		if (numde == 0) return 0;
 
        print_IVP_and_analytical_solution(numde);
        
		printf("\n Give the final abscissa b (press Enter after input): ");
		scanf("%lf", &b);

            
		printf("\n Give the stepsize h:");
		scanf("%lf", &h);
            

        printf("\n\n Give how many iterations you want after which you want to print (iprint - press Enter after the input): ");
		scanf("%d", &iprint);
			

		/*  Initialize  */
            set_initial_condition(& xzero, & yzero, numde);

			x0 = xzero;	
			y0 = yzero;
            
			printf("\n\n\n");
			printf("Equation %2d \n", numde);
			printf("xzero = %12.5e\n", xzero);
			printf("yzero = %12.5e\n", yzero);
			printf("b = %12.5e \n", b);
			printf("Stepsize = %12.5e  \n", h);
			printf("Print Parameter = %3d \n", iprint);


			/*  Begin the main loop for computing the solution of the differential equation  */

            x1 = x0;
            
			while ( x1 <= b)  {
                
				for (k = 1; k <= iprint; k++)  
				{
					x1 = x0 + h;
                    
					if (method == 0) y1 = y0 + h * f(x0, y0, numde);
                    else if (method == 1) {
                        double y0_stage0 = y0 + h * f(x0, y0, numde);
    					y1 = y0 + 0.5 * h * ( f(x0, y0, numde) + f(x1, y0_stage0, numde) );
                    }
                    
                    /*  Update for next iteration */
					x0 = x1;
					y0 = y1;
				}


				/*  Calculate error wrt. the analytical solution */
				truevalue = true_solution(x1, numde);
				error = truevalue - y1;
                
				/*  Print results to terminal */
				printf("x = %10.3e     y(x) = %21.10e   true  %21.10e", x1, y1, truevalue);
				printf("     Error = %12.2e\n", error);
                
				/*  Print results to file */
				fprintf(file, " %10.3e %21.10e \n", x1, y1);
                
			}

	
	fclose(file);
    
     return 0;
	
}
