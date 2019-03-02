/*	
	Title: Test subroutine tridgl
	
	This tests the subroutine 'tridgl' given in section 8.4.
*/
      
#include <stdio.h>
#include <math.h>

#define MAX_N	200

void tridgl(float a[], float b[], float c[], float f[],
				int n, int iflag, int *ier);

main()
{
	float a[MAX_N+1],b[MAX_N+1], c[MAX_N+1], f[MAX_N+1];
	int n, ier, i, j, iflag;

	/*  Input the system to be solved  */
      
	printf("\n What is order n of system? : ");
	scanf("%d", &n);

	printf("\n Give the equation coefficients ");
	printf("\n Give them one equation at a time ");
	printf("\n Give only the elements of the ");
	printf("\n subdiagonal, diagonal, and ");
	printf("\n superdiagonal, as appropriate ");
	printf("\n Also include the equation's right side\n ");

	printf("\n Give b[1], c[1], rhs[1] for equation 1 : ");
	scanf("%f %f %f", &b[1], &c[1], &f[1]);
	for (i=2; i <= n-1; i++)  
	{
		printf("\n Give a[i], b[i], c[i], rhs[i] for equation %d : ", i);
		scanf("%f %f %f %f", &a[i], &b[i], &c[i], &f[i]);
	}
	printf("\n Give a(n), b(n), rhs(n) for equation %d : ", n);
	scanf("%f %f %f", &a[n], &b[n], &f[n]);
	
	/*  Call subroutine tridgl to solve the tridiagonal system  */
      	
	iflag = 0;
	tridgl(a,b,c,f,n,iflag,&ier);
	
	/*  Output the solution of the system  */
      	
	printf("\n Solutions ");
	printf("\n  i      x[i] ");
	for (j=1; j <= n; j++)
		printf("\n %d   %e", j, f[j]);
	printf("\n");
}

      

void tridgl(float a[], float b[], float c[], float f[] ,
			int n, int iflag, int *ier)
{
/*
	This solves a tridiagonal system of linear equations  m*x=f.

	Input:
	The order of the linear system is given by  n.
	The subdiagonal,diagonal, and superdiagonal of  m  are given
	by the arrays  a, b, and c, respectively. more precisely,
		m(i,i-1) = a(i),  i=2,...,n
		m(i,i)   = b(i),  i=1,...,n
		m(i,i+1) = c(i),  i=1,...,n-1
	iflag=0 means that the original matrix  m  is given as
	specified above.
	iflag=1 means that the lu factorization of  m  is already known
	and is stored in  a,b, and c. This will have been accomplished
	by a previous call to this subroutine.

	Output:
	Upon exit, the LU factorization of  m  will be stored
	in  a,b, and c.
	The solution vector  x  will be returned in  f.
	ier=0 means the program was completed satisfactorily.
	ier=1 means that a zero pivot element was encountered, and
	no solution was attempted.
*/

 	const float zero = 0.0;

	int j;
      
	if (iflag == 0)  
	{
		/*  Compute LU factorization of matrix m  */
          
		for (j=2; j <= n; j++)  
		{
			if (b[j-1] == zero)  
			{
				*ier = 1;
				return;
			}
			a[j] = a[j]/b[j-1];
			b[j] = b[j] - a[j]*c[j-1];
			}
			if (b[n] == zero)  
			{
				*ier = 1;
				return;
			}
		}

		/*  Compute solution x to m*x=f  */
      
		for (j=2; j <= n; j++)
			f[j] = f[j] - a[j]*f[j-1];
      	f[n] = f[n]/b[n];

      	for (j=n-1; j >= 1; j--)
			f[j] = (f[j] - c[j]*f[j+1])/b[j];

      	*ier = 0;
      	return;
}

