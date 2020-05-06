 
# include <stdio.h>

main(){
	unsigned int shift;
	printf("             decimale          ottale    esadecimale \n\n");
	for (int i=0; i<17; i++){
		shift = 1 << i;
		printf("1 << %2d       %6u          %6o         %6X  \n",i, shift,shift,shift);
	}
}
