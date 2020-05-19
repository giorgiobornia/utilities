#include <stdio.h>

int main() {
    
		FILE *fp;
        
		fp = fopen ("textfile.txt", "rt");
        
		if (fp != NULL) {
			fseek(fp, 0L, SEEK_END);
			printf ("n° di caratteri del file: %ld", ftell(fp));
			fclose(fp);
		} else {
			printf ("errore di apertura del file in lettura");
		}
		getchar(); getchar();
        
        return 0;
}
