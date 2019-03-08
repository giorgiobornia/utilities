#include <stdio.h>

main(){
	FILE *fp;
	fp = fopen ("testo.txt", "wt");
	char car;
	if (fp != NULL){
		car=getchar();
		while (car!=EOF){
			putc(car, fp);
			car=getchar();
		}
		fclose(fp);
	}else{
		printf ("errore di apertura del file in scrittura");
	}
}

