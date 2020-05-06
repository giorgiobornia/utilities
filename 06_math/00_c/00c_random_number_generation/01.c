#include <stdlib.h>
#include <stdio.h>

void main() {
	 int tot6=0;
	 randomize();
	 for(int i=0; i<10000; i++)
				if (random(6)==5) tot6++;
	 printf("Il sei e' uscito %d volte su 10000", tot6);

}


// modificare il programma precedente per determinare la frequenza di tutte le facce e così rendersi conto se tale simulazione è quella di un dado regolare
