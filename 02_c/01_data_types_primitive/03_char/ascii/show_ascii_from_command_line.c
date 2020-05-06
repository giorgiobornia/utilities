#include <stdio.h>

void main(){
	 char C,CM;
	 printf("Introduci un carattere:  ");
	 scanf("%c",&C);
	 printf("\nIl codice ASCII del carattere '%c' è %d\n",C,C);
	 if (C >= 'a' && C<='z'){
		 CM = C - ('a' - 'A');
		 printf("Il maiuscolo '%c' ha codice ASCII  %d\n",CM,CM);
	 } else {
		 if (C >= 'A' && C<='Z'){
			 CM = C - ('A' - 'a');
			 printf("Il minuscolo '%c' ha codice ASCII  %d\n",CM,CM);
		 }
	 }
}
