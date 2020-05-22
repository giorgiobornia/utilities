#include <stdio.h>
#include <stdlib.h>

char stringa[20];
int nCar=0;

main(){
	randomize()
	printf("Inserisci una stringa: ");
	int i=0;
	stringa[i]=getchar();
	while (stringa[i-1]!='\n'){
	  stringa[i]=getchar();
	  i++;
	}
	char temp;
	int k;
	for (i--; i>=0; i--){
		for (k=i-1; k>=0; k--){
		  if (random(100)>50){
				temp=stringa[i];
				stringa[i]=stringa[k];
				stringa[k]=temp;
		  }
		}
	}
	printf("La stringa ora è %s",stringa);
}
