#include <stdio.h>

#define FATTORE 25173
#define MODULO         65535
#define INCREMENTO     13849
#define SEME_INIZIALE      8
#define LOOP 10

unsigned rand(void);

int main() {
    
int i;

 for( i = 0; i < LOOP; i++) printf("The random number %d is %6u\n\n", i + 1, rand() );

 return 0;

}

unsigned rand(void) {
    
  static unsigned seme = SEME_INIZIALE;  
     /* with static, this initialization happens ONLY ONCE, so this number will then be different!
      * without static, this initialization happens EVERY TIME the function is called, so it always deterministically generate the same number! */
  seme = (FATTORE * seme + INCREMENTO) % MODULO;
  
  return seme;

}
