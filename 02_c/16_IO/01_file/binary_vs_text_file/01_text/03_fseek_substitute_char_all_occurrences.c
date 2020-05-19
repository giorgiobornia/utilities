#include <stdio.h>

main(){
		FILE *fp;
		char car, car1,car2;
		printf ("Quale carattere vuoi sostituire? ");
		scanf("%c",&car1);
		getchar();
		printf ("Con quale carattere vuoi sostituirlo? ");
		scanf("%c",&car2);
		fp = fopen ("textfile.txt", "r+");
		if (fp != NULL){
			do{
				car=fgetc(fp);
				if (car==car1){
							fseek(fp,-1,SEEK_CUR);
							fputc(car2,fp);
				}
            fseek(fp,0,SEEK_CUR);
			}while (car!=EOF);
			fclose(fp);
		}else{
			printf ("errore di apertura del file in lettura/scrittura");
		}
}
