#include <stdio.h>

main(){
		FILE *fp;
		fp = fopen ("textfile.txt", "r+t");
		if (fp != NULL){
			while (fgetc(fp)!='a');
			fseek(fp,0,SEEK_CUR);
			printf("incontrata 'a' dopo %ld byte",ftell(fp));
			fclose(fp);
		}else{
			printf ("errore di apertura del file in lettura/scrittura");
		}
		getchar(); getchar();
}
