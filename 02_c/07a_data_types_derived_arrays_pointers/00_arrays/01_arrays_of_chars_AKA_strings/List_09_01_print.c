
#include <stdio.h>


int main() {
    
char frase[] = "Analisi, requisiti ";
    
int i = 0;

while( frase[i] != '\0' ) {
  printf("%c = %d = %o \n", frase[i], frase[i], frase[i]);
  i++;
}

}
