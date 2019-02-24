#include <stdio.h>
#include <math.h>

/*******************************************
 * Programma per la soluzione di equazioni *
 * di secondo grado                        *
 *******************************************/
int main() {
	double a,b,c;
	double Delta;
	double x1,x2;
	
	printf("\n Inserire i coefficienti a,b,c della equazione di secondo grado nella forma \n a*x**2+b*x+c=0:   \n");
	scanf("%lf %lf %lf",&a,&b,&c);
	printf("\n Coefficienti della equazione:\n \t a=%f \t b=%f \t c=%f \n",a,b,c);
	
	if (a!=0) {
		Delta = b*b-4.*a*c;
		
		printf("\n Delta = %f \n",Delta);
		
		if(Delta>0.) {
			x1=(-b-sqrt(Delta))/(2.*a);
			x2=(-b+sqrt(Delta))/(2.*a);
			printf("\n L\'equazione presenta due radici reali distinte: \n \t x1 = %g \t x2 = %g \n\n",x1,x2);
		}
		else if(Delta==0.) {
			x1=-b/(2.*a);
			printf("\n L\'equazione presenta due radici reali coincidenti: \n \t x1 = x2 = %f \n\n",x1); 
		}
		else {
			printf("\n L'equazione presenta due radici complesse \n\n");
		}
	}
	else {
		printf("\n Errore: il coefficiente a della equazione e' nullo. \n L'equazione di primo grado presenta una sola radice: \n \t %g \n\n",-c/b);
	}
	
	return 0;
}
