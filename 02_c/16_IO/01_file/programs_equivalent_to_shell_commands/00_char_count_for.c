#include <stdio.h>

// EOF is Ctrl+D
// Tale funzione e' bloccante nel senso che quando una linea di caratteri
// precedentemente data in input e' finita, rimane in attesa che dallo
// standard input arrivi una nuova linea di dati.


int main() {

    long nc;

    for(nc = 0; getchar() != EOF; ++nc);

    printf("%ld\n",nc);

   return 0;
   
}
