/*
	This is a demonstration program for the
	rootfinding subroutine 'bisect', given
	in Section 4.1. (Elementary Numerical Analysis, Atkinson)
*/

#include <stdio.h>
#include <math.h>


float fcn(float);
float sign(float, float);
void bisect(float(*f)(float), float, float, float, float *, int *);
 

int main()
{

	float a, b, epsilon, root;
	int ier;
 

	while (1)  {
	
		/*  Input problem parameters  */

		printf("\n\n What are a,b,epsilon");
		printf("\n to stop, let epsilon=0 : \n");
		scanf("%f %f %f", &a, &b, &epsilon);
		if (epsilon == 0.0)
			return 0;
		
		/*  Calculate root  */

		bisect(fcn, a ,b ,epsilon, &root, &ier);

		/*  Print answers  */

		printf("\n\n a = %11.4e     b = %11.4e     epsilon = %9.3e", a, b, epsilon);
		printf("\n root = %14.7e     ier = %1d", root, ier);
	} 
	return 0;
}



float fcn(float x)
{
	float result;

	result = x - exp(-x);
	return(result);
}


float sign(float a, float b)
{
	if (b < 0.0)
		return(-fabs(a));
	else
		return(fabs(a));
}
		

void bisect(float(*f)(float), float a, float b, float eps, 
				float *root, int *ier)
{
/*
	The program uses the bisection method to solve the equation
		f(x) = 0.
	The solution is to be in [a,b] and it is assumed that
		f(a)*f(b) <= 0.
	The solution is returned in root, and it is to be in error by at most eps.
	
	ier is an error indicator.
	If ier=0 on completion of the routine, then the solution has been computed satisfactorily.
	If ier=1, then f(a)*f(b) was greater than 0, contrary to assumption.
*/

	const float zero = 0.0, one = 1.0, two = 2.0;
	float c, fa, fb, fc, sfa, sfb, sfc;


	/* Initialize  */

	fa = (*f)(a);
	fb = (*f)(b);
	sfa = sign(one, fa);
	sfb = sign(one, fb);
	if (sfa * sfb > zero)  
	{

		/*  The choice of a and b is in error  */

		*ier = 1;
		return;
	}

	/* Create a new value of c, the midpoint of [a,b]  */

	while (1)  {
        
		c = (a + b)/two;
        
		if (fabs(b-c) <= eps)  
		{
			
			/* c is an acceptable solution of f(x)=0  */
			
			*root = c;
			*ier = 0;
			return;
		}
		
		/* The value of c was not sufficiently accurate.
			Begin a new iteration  */

		fc = (*f)(c);
		if (fc == zero)  
		{
			
			/* c is an acceptable solution of f(x)=0  */
			
			*root = c;
			*ier = 0;
			return;
		}

		sfc = sign(one, fc);
		if (sfb*sfc > zero)  
		{
			
			/*  The solution is in [a,c]  */

			b = c;
			sfb = sfc;
		}
		else  
		{

			/*  The solution is in [c,b]  */
			
			a = c;
			sfa = sfc;
		}
	}
}


