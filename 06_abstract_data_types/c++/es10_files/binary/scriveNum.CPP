/************************************************************
  Filename: scriveNum.cpp
  Author:  Roberto Ricci
  Date:   10/10/'03
  Description: Esercitazione 10
					File binari
					Scrive su file binario un vettore di interi
************************************************************/


#include <stdio.h>
main(){
	FILE *fp;
	fp = fopen ("a:numeri.dat", "wb");
	if (fp == NULL){
		printf ("errore di apertura \n");
	}else{
		int vet[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
		fwrite (vet, sizeof(int), 13, fp);
		fclose(fp);
	}
}
