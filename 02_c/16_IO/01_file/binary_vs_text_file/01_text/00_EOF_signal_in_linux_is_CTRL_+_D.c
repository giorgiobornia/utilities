

#include <stdio.h>

main(){
	FILE *fp;
	fp = fopen ("textfile.txt", "at");
	char car;
	if (fp == NULL){
		printf ("errore di apertura \n");
	}else{
		car=getchar();
		while (car!=EOF){
			putc (car, fp);
			car=getchar();
		}
		fclose(fp);

		putchar('\n');
		fp = fopen ("textfile.txt", "rt");
		do{
			car=getc(fp);
			putchar(car);
		}while (car!=EOF);
		fclose(fp);
	}
}
