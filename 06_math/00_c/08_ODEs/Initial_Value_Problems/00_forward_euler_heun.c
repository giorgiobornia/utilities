/*
 * gcc forward_euler.c -lm
 * 
 * If you plot the x and y in two columns, then open gnuplot and simply type:
 * plot 'out.txt' using 1:2,  [0:1]  exp(-x)
 * plot 'out.txt' using 1:2,  [0:1]  x * x - 2. * ( (x+1) * log(x+1) - (x+1))
 * plot 'out_euler.txt' using 1:2, 'out_heun.txt' using 1:2, [0:3] exp(-x)

	 

   	y'(x) = f(x,y(x)) ,  x0 <= x <= b ,  y(x0) = y0.
   	
	The function f(x,y) is defined below, along with the true solution y(x).
	The number of the problem to be solved is specified by the input variable 'numde', 
    which is used in the functions 'f' and 'y'.
    The program will request the problem parameters, along with the values of 'h' and 'iprint'.  
    'h' is the stepsize, and 'iprint' is the number of steps between each printing of the solution.
	Use numde=0 to stop the program. This program is in Section 9.2 (Elementary Numerical Analysis, Atkinson)
*/       

#include <stdio.h>
#include <math.h>




	/*  This defines the right side of the differential equation  */
double f(double x, double y, const int numde) {

	const double one = 1.0, two = 2.0;

	double rhs;

	switch (numde)  
	{
	case 1: rhs = -y;
			break;
            
	case 2: rhs = (y + x*x - two)/(x + one);
			break;
            
	case 3: rhs = cos(y) * cos(y);
			break;
            
	case 4: rhs = (y - 1) * (y - 1);
			break;
            
	case 5: rhs = (3. * y) / x;
			break;
	}
	
	return(rhs);
}



 void set_initial_condition(double * const xzero, double * const yzero, int const numde) {


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

    case 4: * xzero = 0.;
            * yzero = 2.;
			break;

    case 5: * xzero = -1.;
            * yzero = -1.;
			break;
	}
	
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
            
	case 4: result = 1 - 1./(x - 1.);
			break;
            
	case 5: result =  x * x * x;
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

    case 4: printf("y' = (y-1)^2\n");
            printf("y(0) = 2\n");
            printf("Solution: y(x) = 1 - 1./(x - 1.)\n");
			break;

    case 5: printf("y' = 3. * y / x\n");
            printf("y(-1) = -1\n");
            printf("Solution: y(x) = x^3\n");
			break;
	}
	
}




int main() {

	double xzero, yzero, b, h, truevalue, error;
	double x1, y1, x0, y0;
	int iprint, k;
    int i_numde, numde;
    int method;
    int compute_error;

                
		/*  Description */
    printf("\n This program uses some numerical methods to solve the Initial Value Problem\n");
    printf(" y'(x) = f(x, y(x)) , \n");
    printf(" y(x0) = y0 , \n");
    printf(" x0 <= x <= b . \n");
    printf("\n The reason to have an upper bound \"b\" on the interval is to avoid infinitely many iterations\n");

    
		/*  Input problem parameters */
		printf("\n These are the implemented IVPs\n ");
        for (i_numde = 1; i_numde <= 5; i_numde = i_numde + 1) {
			printf("******* IVP # %3d \n", i_numde);
           print_IVP_and_analytical_solution(i_numde);       
		printf("\n ");       }
        
		printf("\n Number of the ODE = [1, 2, 3, 4, 5]? Give 0 to stop : ");
		scanf("%d", &numde);
        
		if (numde == 0) return 0;
 
        print_IVP_and_analytical_solution(numde);
        
		printf("\n Give the final abscissa b (press Enter after input): ");
		scanf("%lf", &b);

            
		printf("\n Give the stepsize h:");
		scanf("%lf", &h);
            

        printf("\n\n Give the number of iterations after which you want to print (press Enter after the input): ");
		scanf("%d", &iprint);
			
		/*  **************************** */
    printf("\n Choose the numerical method:\n");
    printf("\n 0 = forward Euler:\n");
    printf("\n 1 = Heun (explicit trapezoid)\n");
	scanf("%d", & method);
        
        char filename[31];
        if (method == 0)      sprintf(filename, "euler.out");
        else if (method == 1) sprintf(filename, "heun.out");
		/* ******************************  */

            
        FILE * file = fopen(filename, "w");

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


		printf("\n Would you like to compute the absolute error? 1 = yes, 0 = no ");
		scanf("%d", &compute_error);
        
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


//             printf("\n Print abscissas and ordinates to file \n");
				fprintf(file, " %10.3e %21.10e \n", x1, y1);

                
        
		if (compute_error == 0) return 0;
				/*  Calculate error wrt. the analytical solution */
				truevalue = true_solution(x1, numde);
				error = truevalue - y1;
                
				/*  Print  to terminal */
				printf("x = %10.3e     y(x) = %21.10e       f(x,y) = %21.10e   true  %21.10e", x1, y1, f(x1,y1, numde), truevalue);
				printf("     Error = %12.2e\n", error);
                
                
			}

	
	fclose(file);
    
     return 0;
	
}
