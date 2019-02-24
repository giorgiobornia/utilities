#include <stdio.h>
#include <math.h>

/*******************************************
 * Programma per la soluzione di equazioni *
 * di secondo grado                        *
 *******************************************/

int main() {

        float a,b,c;
	float Delta;
	float x1,x2;

 	x1=0.1;/*0.100000001490116119384765625 float*/
               /*0.1000000000000000055511151231257827021181583404541015625 double*/
x1=acos(0.);  /*3.1415927410125732421875 float*/
              /*3.141592653589793115997963468544185161590576171875 double*//**/
          printf("\n Numero c=%.85f \n",x1);
	  printf("\n Numero c=%.85e \n",x1);
	  printf("\n Numero c=%.85g \n",x1);

	  printf("\n Inserire i coefficienti a,b,c della equazione di secondo grado nella forma \n a*x**2+b*x+c=0:   \n");
		scanf("%f %f %f",&a,&b,&c);
	  
	  printf("\n Coefficienti della equazione:\n \t a=%.15f \t b=%.15f \t c=%.15f \n",a,b,c);
	
	if (a!=0) { /*divide all the equation by a*/
		b /= (2.*a);
		c /= a;
    Delta = b*b-c;
		
		printf("\n Delta = %.15g \n",Delta);
		
		if(Delta>0.) {
			x1 = -b-sqrt(Delta);
                        x2 = -c/(b+sqrt(Delta));
			printf("\n L\'equazione presenta due radici reali distinte: \n \t x1 = %.15g \t x2 = %.15g \n\n",x1,x2);
		}
		else if(Delta==0.) {
			x1=-b;
			printf("\n L\'equazione presenta due radici reali coincidenti: \n \t x1 = x2 = %.15g \n\n",x1); 
		}
		else {
			printf("\n L'equazione presenta due radici complesse \n\n");
		}
	}
	else {
		printf("\n Errore: il coefficiente a della equazione e' nullo. \n L'equazione di primo grado presenta una sola radice: \n \t %.15g \n\n",-c/b);
	}
	
	return 0;
}


/*E' un esempio di DIVERSO ALGORITMO NUMERICO per uno STESSO PROBLEMA NUMERICO
 Qui si dovrebbe mostrare che questo algoritmo e' STABILE,
 perche' non ci sono le perturbazioni dovute alla cancellazione numerica.
 E' stato formulato un altro algoritmo che sia PIU' STABILE del precedente.
 Come si fa a confrontare questo?
 Si considera il caso in cui b >> c.
 Ci si aspetta di avere una soluzione x~0, e l'altra  x~ -b/a.
 Si prende il programma vecchio e il programma nuovo e 
 si mettono in entrambi i casi due uguali valori di b e c.
 Poi si vede se cambiando di poco b e/o c, allo stesso modo,
 come cambiano le due soluzioni dei due algoritmi.
 L'unica cosa da stare attenti e' che la perturbazione che introduci ti faccia
 possibilmente rimanere in campo reale, cosi' che la gente capisca...
 
 -Cerchiamo di RAGIONARE
       - per dato TIPO assegnato (float o double), 
             -- quali sono i massimi e minimi numeri positivi che posso rappresentare
             -- qual e' il MASSIMO NUMERO di CIFRE SIGNIFICATIVE in BASE DECIMALE che posso avere
                      Un float ha  23 cifre della mantissa in base 2 => rappresento un numero decimale con 
                      Un double ha 52 cifre della mantissa in base 2 => rappresento un numero decimale con 
 
 Sembra che il compilatore mi traduca i float in double, come faccio ad avere un float?
 
 Il numero di cifre significative dipende dalla base scelta?
 Ho provato a stampare acos(1.) e acosf(1.), sembra che il numero di cifre significative 
 nel passaggio da una base ad un'altra sia sempre lo stesso...
 float acosf(float x);
 long double acosl(long double x);
 Attenzione, ma per quale motivo mi stampa PIGRECO con MOLTO PIU' di 16 cifre significative?
 Si vede che la precisione del calcolo di PIGRECO e' implementata via software......
 

 Se ho un double, quindi 64 bit, ha 52 cifre decimali in base 2, piu' un 1 implicito => 53 cifre
                      che corrisponde a circa log10(2^53) = 16 cifre decimali in base 10
 Se ho un 32 bit, ho log10(2^24) = 7 cifre significative 
       Quindi si', dipendo dalla base che uso.
       Questo non significa che i numeri in base 2 siano PIU' PRECISI dei numeri in base 10,
       entrambi raggiungono lo stesso livello di precisione
 
 La formattazione %A.B c'entra in qualche modo con il fatto di avere float o double?
 La formattazione si occupa solo di mettere degli spazi e degli zeri
 Prendimi A spazi, DI QUESTI dedicane B dopo la virgola.

 Chiaramente lasciano piu' o meno spazi posso vedere piu' o meno cose in base a quante cifre ho a disposizione...
 
 Differenza fra RAPPRESENTAZIONE FLOATING POINT nella CPU e FORMATTAZIONE su file/terminale
 Chiaramente ci si aspetta che una formattazione possa vedere l'effetto di un cambiamento nella 
 rappresentazione floating point.
 
 */


/*TYPE CASTING
 when you CAST a variable from one type to another, it doesnt mean that the variable changes its nature
 It changes how the variable is represented inside I think.
 But if you change a variablee from double to int, then it will not be represented as floating point any longer...
 But the compiler clearly still considers the variable as a double, so i think the executable will.
 So it will still be loaded into the registry for floating points even if it was casted as int...
 Does it correspond to DYNAMIC ALLOCATION? 
 Are castings from HIGHER to LOWER memory space or also from LOWER to HIGHER?
 It seems like castings from int(32bit) to double (64bit) are possible... so the variables should be MORE DYNAMIC...
 But I dont think they do dynamic allocation at all..but they should cope with a change in the memory requirement,
 so that they could MOVE the variables in another memory position... static cast VS dynamic cast...
 */

/* SIGNIFICANT DIGITS
 * Why is it possible that different numbers are written with a variable number of significant digits ?
 * Shouldnt the maximum be 7 or 15?
 * You have to consider that in the program you insert as input data numbers that are in base 10
 * So the program (can the compiler do that for me... for const variables?) has to convert them to 2 base, do the computations
 * and then re-convert back to base 10 for output
 * This conversion gives ROUNDING ERRORS (is BASE CONVERSION a well-conditioned problem as a micro-step ?)
 * This conversion also gives a VARIATION in the NUMBER of SIGNIFICANT DIGITS, in BOTH DIRECTIONS
 
 */