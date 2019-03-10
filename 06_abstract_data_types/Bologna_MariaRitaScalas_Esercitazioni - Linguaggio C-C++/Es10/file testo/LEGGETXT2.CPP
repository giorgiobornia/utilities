#include <stdio.h>

main(){
		FILE *fp;
		int car;
		char nomeFile[20];
		printf ("Quale file vuoi leggere ? ");
		scanf("%s",nomeFile);
		fp = fopen (nomeFile, "rt");
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
