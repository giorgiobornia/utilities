

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char cognome[20];
	char nome[20];
	char sesso;
	int anno;
} persona;

main(){
	FILE *fp;
	fp = fopen ("a:archivio.txt", "at");
	persona p;
	if (fp == NULL){
		printf ("errore di apertura \n");
	}else{
		int si=1;
		do{
			printf("\nCognome:  "); scanf("%s",&p.cognome);
			printf("\nNome:  "); scanf("%s",&p.nome);
			printf("\nSesso:  "); scanf("%s",&p.sesso);
			printf("\nAnno:  "); scanf("%d",&p.anno);
			fprintf (fp, "\n%s %s %c %d",p.cognome, p.nome, p.sesso, p.anno);
			printf("\nAncora dati da inserire? (1=si 0=no)  "); scanf("%d",&si);
		}while (si);
		fclose(fp);
	}
}

