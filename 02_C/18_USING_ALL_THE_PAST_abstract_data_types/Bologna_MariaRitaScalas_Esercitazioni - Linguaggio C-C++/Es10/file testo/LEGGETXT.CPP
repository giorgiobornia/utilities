#include <stdio.h>

main(){
		FILE *fp;
		int car;
		fp = fopen ("testo.txt", "rt");
		if (fp != NULL){
			do{
				car=getc(fp);
				putchar(car);
			}while (car!=EOF);
			fclose(fp);
		}else{
			printf ("errore di apertura del file in lettura");
		}
}
