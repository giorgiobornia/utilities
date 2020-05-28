 
# include <stdio.h>

 void from_base_2_to_base_10() {
     
	unsigned long int num2;
	unsigned long int pot2 = 1;
	unsigned long int num10 = 0;
	
    printf("Insert a natural number in base 2: ");
	scanf("%lu", & num2);
    
	while (num2 > 0) {
		num10 = num10 + num2%10*pot2;
		num2 = num2 / 10;
		pot2 = 2*pot2;
	}
	
	printf("\nIn base 10 it becomes %lu\n",num10);
    
}


int main() {
    
 from_base_2_to_base_10();
    
  return 0;
  
}

// modificarlo introducendo un controllo preliminare sulle cifre di num2: se ce ne sono diverse da 0 o 1 non eseguire il resto del programma


// aggiungere l'output di num10 in ottale e esadecimale
