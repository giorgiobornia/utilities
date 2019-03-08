/************************************************************
  Filename: scriveNum.cpp
  Author:  Roberto Ricci
  Date:   10/10/'03
  Description: Esercitazione 10
					File binari
					Legge da un file binario di interi
************************************************************/

#include <stdio.h>
main(){
	FILE *fp;
	fp = fopen ("a:numeri.dat", "rb");
	if (fp == NULL){
		printf ("errore di apertura \n");
	}else{
		int vett[100];
		int i=0;
		while(fread(&vett[i],sizeof(int),1,fp)>0){
		  printf("%d\n",vett[i]);
		}
		fclose(fp);
	}
}
