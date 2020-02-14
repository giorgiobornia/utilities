/* Esempio visualizzazione menu e controllo scelte utente */

#include <stdio.h>


int main() {
    
char scelta;
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("\n       MENU DI PROVA\n");
printf("\n   a) Per immettere dati");
printf("\n   b) Per determinare il maggiore");
printf("\n   c) Per determinare il minore");
printf("\n   d) Per ordinare");
printf("\n   e) Per visualizzare");
printf("\n\n                               Scelta: ");
scelta = getchar();

switch(scelta) {
  case 'a':
    printf("\n In esecuzione l'opzione a");
    break;
  case 'b':
    printf("\n In esecuzione l'opzione b");
    break;
  case 'c':
    printf("\n In esecuzione l'opzione c");
    break;
  case 'd':
    printf("\n In esecuzione l'opzione d");
    break;
  case 'e':
    printf("\n In esecuzione l'opzione e");
    break;
  default:
    printf("\n Opzione inesistente");
    break;
}
}
