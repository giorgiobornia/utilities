 
#include <stdio.h>

void strRovR(char str[]){
	char ss=str[0];
	if (ss !='\0') {
		str++;
		strRovR(str);
		printf("%c",ss);
	}
}

main(){
	char stringa[]="1234567";
	strRovR(stringa);
	printf("è rovescia della stringa %s ",stringa);
}
