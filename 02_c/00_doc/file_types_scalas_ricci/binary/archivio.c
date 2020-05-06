

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char cognome[20];
	char nome[20];
	int eta;
} persona;

main(){
	FILE *fp;
	fp = fopen ("archivio.dat", "ab");
	persona p;
	if (fp == NULL){
		printf ("errore di apertura \n");
	}else{
		int fine=0;
		do{
			printf("Cognome:  "); scanf("%s",&p.cognome);
			printf("Nome:  "); scanf("%s",&p.nome);
			printf("Eta':  "); scanf("%d",&p.eta);
			fine = (p.eta<0);
			if (! fine)
				fwrite (&p, sizeof(persona), 1, fp);
		}while (!fine);
		fclose(fp);

		fp = fopen ("archivio.dat", "rb");
		while (fread (&p, sizeof(persona), 1, fp)>0)
					printf("nome: %s;  cognome: %s;  eta': %d \n",p.nome,p.cognome,p.eta);
		fclose(fp);
	}
}
