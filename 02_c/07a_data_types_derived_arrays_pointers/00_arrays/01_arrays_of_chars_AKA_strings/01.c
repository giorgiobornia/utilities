#include <stdio.h>

char stringa[20];

main(){
	printf("Inserisci una stringa: ");
	scanf("%s\n",&stringa);
	int i;
	for (i=0; stringa[i]!='\0'; i++){};
	for (i--; i>=0; i--){
		printf("%c",stringa[i]);
	}
}

// Occorre terminare la stringa in input con ' \0' cioè uno spazio seguito da '\' seguito da '0'

//Sostituire opportunamente nel programma prededente le seguenti istruzioni per lettura della stringa che consente di terminarla in modo più naturale con un a capo.



// int i=0;
// 	stringa[i]=getchar();
// 	while (stringa[i]!='\n'){
// 	  i++;
// 	  stringa[i]=getchar();
// 	}
