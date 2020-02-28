/*
 * gcc forward_euler.c -lm
 * if you plot the x and y in two columns, then open gnuplot and simply type:
 * plot 'file.txt',  [0:1]  exp(-x)
 * 
	 

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


double f(double x, double z, const int numde);
double y(double x, const int numde);
void print_IVP_and_analytical_solution(const int numde);




int main() {

	double xzero, yzero, b, h, truevalue, error;
	double x1, y1, x0, y0;
	int iprint, k;
    int numde;

    FILE * file = fopen("out.txt", "w");
                
		/*  Description */
    printf("\n This program uses Euler's method to solve the Initial Value Problem\n");
    printf(" y'(x) = f(x, y(x)) , \n");
    printf(" y(x0) = y0 , \n");
    printf(" x0 <= x <= b . \n");
        

		/*  Input problem parameters */

		printf("\n Number of the ODE = ? Give 0 to stop : ");
		scanf("%d", &numde);
		if (numde == 0) return(0);
 
        print_IVP_and_analytical_solution(numde);
        
		printf("\n Give x0, b, and y0 (press Enter after each input): ");
        
		scanf("%lf %lf %lf", &xzero, &b, &yzero);

            
		printf("\n Give the stepsize h:");
		scanf("%lf", &h);
            

        printf("\n\n Give the print parameter iprint (iprint = after how many iterations you want to print - press Enter after the input): ");
		scanf("%d", &iprint);
			

		/*  Initialize  */

			x0 = xzero;	
			y0 = yzero;
            
			printf("\n\n\n");
			printf("Equation %2d \n", numde);
			printf("xzero = %9.2e\n", xzero);
			printf("b = %9.2e \n", b);
			printf("yzero = %12.5e\n", yzero);
			printf("Stepsize = %10.3e  \n", h);
			printf("Print Parameter = %3d \n", iprint);


			/*  Begin the main loop for computing the solution of the differential equation  */

			while (x0 + h <= b)
			{
                
				for (k = 1; k <= iprint; k++)  
				{
					x1 = x0 + h;
                    
					if (x1 > b)	break;
                    
					y1 = y0 + h * f(x0, y0, numde);
					x0 = x1;
					y0 = y1;
				}


				if (x1 > b)  break;  /* "break" exits from the containing loop, but here there are two of them */
                
				/*  Calculate error wrt. the analytical solution */
				truevalue = y(x1, numde);
				error = truevalue - y1;
                
				/*  Print results to terminal */
				printf("x = %10.3e     y(x) = %21.10e   true  %21.10e", x1, y1, truevalue);
				printf("     Error = %12.2e\n", error);
                
				/*  Print results to file */
				fprintf(file, " %10.3e %21.10e \n", x1, y1);
                
			}

	
	fclose(file);
    
//     return 0;
	
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
double y( double x , const int numde) {

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
