/* #include <math.h> */
#include <stdio.h>
#include "mio.h"


main()

{
  /* dichiarazione delle variabili */
  int sum;
  float a,b;
  double c;

  /* assegnazione */
  sum = 20 + constint;
  printf("la somma di 20 e constint e':");
  printf(" %15d \n\n",sum);

  printf("la somma di 20 e %1d e':",constint);
  printf(" %15d \n\n",sum);
  b = acosf(0.0);
  a = sinf(b);
  printf("1- pigreco (float)        :");
  printf(" %.6f \n",2.*b);
  printf("   il seno di 90° e' : %.6f \n",
	 a);

  c = b; /* float to double */
  printf("2- pigreco (float->double):");
  printf(" %.14f \n",2.*c);
  c = sin(c);
  printf("   il seno di 90° e' : %.14f \n",
	 c);

  c = acos(0.0);
  printf("3- pigreco (double)       :");
  printf(" %.14f \n",2.*c);
  c = sin(c);
  printf("   il seno di 90° e' : %.14f \n",
	 c);

}




/*
raus--> gcc -o c3 c3.c -lm
raus--> c3
la somma di 20 e constint e':              25

la somma di 20 e 5 e':              25

1- pigreco (float)        : 3.141593
   il seno di 90° e' : 1.000000
2- pigreco (float->double): 3.14159274101257
   il seno di 90° e' : 1.00000000000000
3- pigreco (double)       : 3.14159265358979
   il seno di 90° e' : 1.00000000000000
raus--> 
raus--> gcc -o c3 c3.c 
/tmp/cckKSF4C.o: In function `main':
: undefined reference to `acosf'
/tmp/cckKSF4C.o: In function `main':
: undefined reference to `sinf'
/tmp/cckKSF4C.o: In function `main':
: undefined reference to `sin'
/tmp/cckKSF4C.o: In function `main':
: undefined reference to `acos'
/tmp/cckKSF4C.o: In function `main':
: undefined reference to `sin'
collect2: ld returned 1 exit status
raus--> 
raus--> gcc -o c3 c3.c -lm 
[senza #include <math.h>]
raus--> c3
la somma di 20 e 15 e':              35

1- pigreco (float)        : 576.000000
   il seno di 90° e' : -0.855504
2- pigreco (float->double): 576.000000...
   il seno di 90° e' : -0.85550437075082
3- pigreco (double)       : 29248.0000...
   il seno di 90° e' : 0.11355697689315
raus--> nm c3.o
         U acos
         U acosf
00000000 T main
         U printf
         U sin
         U sinf
raus-->  

Note:
- senza il caricamento della libreria
  matematica il loader non risolve
  le funzioni trigonometriche
- anche caricata la libreria, le
  funzioni DEVONO essere dichiarate
  attraverso dei prototipi della
  chiamata (nel file math.h), 
  prima della funzione che le usa 
  (ANSI C)
- %d, %f: formati per stampare interi
  e float
- +,-,*,/: operatori binari 


- esempio di una dichiarazione in math.h:

extern float sinf (float __x) ;*/
