# include <stdio.h>

main(){
	unsigned int num=25;
	unsigned int pot2=1;
	for (int i=0; i<16; i++){
		printf("%u & 2^%d = %d\n",num,i,num & pot2);
		pot2 = pot2 << 1;
	}
}
