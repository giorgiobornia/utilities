#include <stdio.h>

/*
 * La cosiddetta precisione di macchina 
  indica il massimo errore relativo
  che puo' essere commesso con l'arrotondamento
  Chiaramente se parto da 1. ho un risultato
  Se parto da un altro numero ne ho un altro.
  Non e' da confondere con il minimo numero rappresentabile.
  Indica qual e' la massima escursione tra gli 
  ordini di grandezza di due addendi
  tale che il piu' piccolo sia nullo rispetto al piu' grande

 E' legato alla somma tra numeri di ordini di grandezza molto diversi
 
*/

#define MYTYPE  float
/*
#define MYTYPE  float
#define MYTYPE  double
#define MYTYPE  long double  //Put an L in the format
*/

int main() {
  
	MYTYPE eps,res;
	
  printf("\n\n Il programma calcola automaticamente la precisione di macchina\n");
	
	eps=1.;
	
	do  {
		res = 1.;
                eps= eps/2.;
		res += eps;
		printf("\teps=%e\t\tres=%e\n",eps,res);
	} while(res!=1.);
	
	printf("\t\teps = %e \n\n",eps);

  return 0;
}

/* QUADRUPLE PRECISION
 * since GCC 4.3 there is support for __float128 handled via the soft_fp library
      this concerns operations, but no print function is available
 * since GCC 4.6 the quadmath library is introduced, that handles quadruple precision arithmetic
      also, printing functions are available
      
#include <quadmath.h>
#include <iostream>
int main()
{
  char* y = new char[1000];
  quadmath_snprintf(y, 1000, "%Qf", 1.0q);
  std::cout << y << std::endl;
  return 0;
}
      
    */

/* Program to compute machine precision
 eps= the smallest floating point positive number that added to 1. gives a floating point number different from 1.
 It represents the upper bound in the RELATIVE error in the ROUNDING process in floating point arithmetic
 The relative error between a number and its rounding cannot be higher than machine precision
 Clearly, with 64 bit, machine precision is better. i.e. the rounding process is subject to less error
 If you use the HARDWARE structure of your computer, this is the machine precision you get
 If you want to have a HIGHER precision, you can use a SOFTWARE that does the operations in RAM
 rather than in the processor.

 Floating point types are:
        float: 32 bit precision
       double: 64 bit precision
  long double: 80 bit precision (extended precision) IMPLEMENTED IN HARDWARE
   For some compilers long double can be "128 bit precision", which is performed VIA SOFTWARE
        C++ could see a long double as a 128 bit floating number
   __float128: 128 bit precision (quadruple precision)
   
   
Depending on the FLOATING POINT DATA TYPE,
        we get a DIFFERENT NUMBER of AVAILABLE bits for the representation of base and exponent
              - so we get DIFFERENT MAXIMUM and MINIMUM REPRESENTABLE NUMBERS (so DIFFERENT OVERFLOW or UNDERFLOW)
              - so we get a DIFFERENT PRECISION  of the corresponding arithmetic
  
  PRECISION of a FLOATING POINT ARITHMETIC is DIFFERENT from
  SMALLEST POSITIVE (NON-ZERO...) REPRESENTABLE NUMBER

  - To get the smallest representable number you take
      - the highest exponent with NEGATIVE sign
      - 1 in the digit to the right
//every floating point representation has SIGN,EXPONENT,FRACTION
//sign refers to the sign of the basis
//how about the sign of the exponent, can you do that? Yes, with the exponent bias.
//So, given x = a 2^p, the smallest representable number is given by:
// ne = number of bits for the EXPONENT
// nm = number of bits for the MANTISSA
// set a=2^(-nm), p=-(2^(ne-1)-1)
// float : putting p=-(2^7-1)(smallest exponent), a=2^(-23+1) (smallest decimal number):
//putting p=-(2^10-1), a=2^(-52+1) 
//let us do the HIGHEST FP REPRESENTABLE:
//simply, you put all 1 in the exp and all 1 in the mantissa
//p=2^8-1
//q=




      float                  eps=2^(-23)/2=5.96046447754e-08
   double                    eps=2^(-52)/2=1.11022302462e-16
   long double (80 bit)      eps=2^(-64)=5.42101086243e-20


Tutti i numeri RAZIONALI che hanno una PARTE FRAZIONARIA (parte decimale),
cioe' tutti i numeri razionali che portati ai MINIMI TERMINI
hanno che il NUMERATORE NON E' MULTIPLO del DENOMINATORE,
cioe' quelli che RIDOTTI AI MINIMI TERMINI NON HANNO 1 AL DENOMINATORE, 
sono NUMERI PERIODICI!
Ora posso decidere di rappresentare questi numeri in un modo DIVERSO dalla COPPIA 
di numeri naturali NUMERATORE-DENOMINATORE. 
Posso decidere di trovare un modo che mi AIUTI NELLE OPERAZIONI.
Per questo uso la rappresentazione POSIZIONALE come ALLINEAMENTO DECIMALE in UNA CERTA BASE,
ad esempio ALLINEAMENTO DECIMALE IN BASE 10. 
La rappresentazione POSIZIONALE riguarda non solo i decimali, ma anche le parti intere.
Per rappresentazione posizionale si intende una rappresentazione in POTENZE POSITIVE E NEGATIVE
di una certa BASE, moltiplicate ciascuna per un coefficiente naturale che e' un elemento 
della base del sistema di numerazione usato.
Allora, se ho una data frazione, es 64/99,
posso rappresentarla ad es. come allineamento decimale in base 10 
                          o come allineamento decimale in base 2.
In entrambi i casi avro' un PERIODO? Se si', quale?



   */

