#include <stdio.h>

main(){
		FILE *fp;
		char car;
		fp = fopen ("a:testo.txt", "r+");
		if (fp != NULL){
			do
				car=fgetc(fp);
			while (car!='a');
			fseek(fp,-1,SEEK_CUR);
			fputc('X',fp);
			fclose(fp);
		}else{
			printf ("errore di apertura del file in lettura/scrittura");
		}
}
