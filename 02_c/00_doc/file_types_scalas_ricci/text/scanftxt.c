#include <stdio.h>

main(){
	FILE *fp;
	char str[20];
	fp = fopen ("testo.txt", "rt");
	if (fp == NULL){
		printf ("errore di apertura \n");
	}else{
		do{
			fscanf(fp,"%s",&str);
			printf("%s\n",str);
		}while (! feof(fp));
		fclose(fp);
		scanf("%s",str);
	}
}
