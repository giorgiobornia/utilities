 
#include <stdio.h>

char c;
unsigned long int n=0;

int main() {

    printf("Vuoi che scriva qualcosa o no?  (s=si n=no) ");
    
	c = getchar();
        switch (c) {
	case 's':
	case 'S':	
	 	printf("\n qualcosa");
		break;
	case 'n':
	case 'N':	
	 	printf("\n no");
	default:
		printf("\n come non detto!");
	}
	
	return 0;
    
}
