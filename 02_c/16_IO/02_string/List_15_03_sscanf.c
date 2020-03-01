#include <stdio.h>

int main() {

   double valore;
   char buf[31], nome[31];

   printf("Inserire una variabile nel formato \"nome = <valore>\":");
   gets(buf);

   /* Con sscanf() si separa il nome dal valore */

   sscanf(buf, " %[^=] = %lf", nome, &valore);

   printf("La variabile %s vale %f\n", nome, valore);
}
